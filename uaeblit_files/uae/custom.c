 /*
  * UAE - The Un*x Amiga Emulator
  *
  * Custom chip emulation
  *
  * Copyright 1995-2002 Bernd Schmidt
  * Copyright 1995 Alessandro Bissacco
  * Copyright 2000-2004 Toni Wilen
  */

#define __USE_INLINE__
#include <proto/exec.h>

#include "sysconfig.h"
#include "sysdeps.h"
#include "blitter.h"

#warning ignoreing some stuff, I think is useless...

#define maybe_blit(x,y)
#define CSMASK_ECS_AGNUS 0

static int current_hpos()
{
	// this ignores vpos!!!
	return 0;
}

void BLTADAT (uae_u16 v)
{
    maybe_blit (current_hpos(), 0);

    blt_info.bltadat = v;
}

/*
 * "Loading data shifts it immediately" says the HRM. Well, that may
 * be true for BLTBDAT, but not for BLTADAT - it appears the A data must be
 * loaded for every word so that AFWM and ALWM can be applied.
 */


void BLTBDAT (uae_u16 v)
{
    maybe_blit (current_hpos(), 0);

    if (bltcon1 & 2)
	blt_info.bltbhold = v << (bltcon1 >> 12);
    else
	blt_info.bltbhold = v >> (bltcon1 >> 12);
    blt_info.bltbdat = v;
}

void BLTCDAT (uae_u16 v) { maybe_blit (current_hpos(), 0); blt_info.bltcdat = v; reset_blit (0); }
void BLTAMOD (uae_u16 v) { maybe_blit (current_hpos(), 1); blt_info.bltamod = (uae_s16)(v & 0xFFFE); reset_blit (0); }
void BLTBMOD (uae_u16 v) { maybe_blit (current_hpos(), 1); blt_info.bltbmod = (uae_s16)(v & 0xFFFE); reset_blit (0); }
void BLTCMOD (uae_u16 v) { maybe_blit (current_hpos(), 1); blt_info.bltcmod = (uae_s16)(v & 0xFFFE); reset_blit (0); }
void BLTDMOD (uae_u16 v) { maybe_blit (current_hpos(), 1); blt_info.bltdmod = (uae_s16)(v & 0xFFFE); reset_blit (0); }
void BLTCON0 (uae_u16 v) { maybe_blit (current_hpos(), 2); bltcon0 = v; blinea_shift = v >> 12; reset_blit (1); }

/* The next category is "Most useless hardware register".
 * And the winner is... */

void BLTCON0L (uae_u16 v)
{

    if (! (currprefs.chipset_mask & CSMASK_ECS_AGNUS))
	return;


    maybe_blit (current_hpos(), 2); bltcon0 = (bltcon0 & 0xFF00) | (v & 0xFF);
    reset_blit (1);
}

void BLTCON1 (uae_u16 v) { maybe_blit (current_hpos(), 2); bltcon1 = v; reset_blit (2); }

void BLTAFWM (uae_u16 v) { maybe_blit (current_hpos(), 2); blt_info.bltafwm = v; reset_blit (0); }
void BLTALWM (uae_u16 v) { maybe_blit (current_hpos(), 2); blt_info.bltalwm = v; reset_blit (0); }

void BLTAPTH (uae_u16 v) { maybe_blit (current_hpos(), 0); bltapt = (bltapt & 0xffff) | ((uae_u32)v << 16); }
void BLTAPTL (uae_u16 v) { maybe_blit (current_hpos(), 0); bltapt = (bltapt & ~0xffff) | (v & 0xFFFE); }
void BLTBPTH (uae_u16 v) { maybe_blit (current_hpos(), 0); bltbpt = (bltbpt & 0xffff) | ((uae_u32)v << 16); }
void BLTBPTL (uae_u16 v) { maybe_blit (current_hpos(), 0); bltbpt = (bltbpt & ~0xffff) | (v & 0xFFFE); }
void BLTCPTH (uae_u16 v) { maybe_blit (current_hpos(), 0); bltcpt = (bltcpt & 0xffff) | ((uae_u32)v << 16); }
void BLTCPTL (uae_u16 v) { maybe_blit (current_hpos(), 0); bltcpt = (bltcpt & ~0xffff) | (v & 0xFFFE); }
void BLTDPTH (uae_u16 v) { maybe_blit (current_hpos(), 0); bltdpt = (bltdpt & 0xffff) | ((uae_u32)v << 16); }
void BLTDPTL (uae_u16 v) { maybe_blit (current_hpos(), 0); bltdpt = (bltdpt & ~0xffff) | (v & 0xFFFE); }

void BLTSIZE (uae_u16 v)
{
	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);

    maybe_blit (current_hpos(), 0);

    blt_info.vblitsize = v >> 6;
    blt_info.hblitsize = v & 0x3F;

    if (!blt_info.vblitsize) blt_info.vblitsize = 1024;

	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);

    if (!blt_info.hblitsize) blt_info.hblitsize = 64;

	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);

    do_blitter (current_hpos());
}

void BLTSIZV (uae_u16 v)
{
    if (! (currprefs.chipset_mask & CSMASK_ECS_AGNUS))
	return;
    maybe_blit (current_hpos(), 0);
    blt_info.vblitsize = v & 0x7FFF;
}

void BLTSIZH (uae_u16 v)
{
    if (! (currprefs.chipset_mask & CSMASK_ECS_AGNUS))
	return;
    maybe_blit (current_hpos(), 0);
    blt_info.hblitsize = v & 0x7FF;
    if (!blt_info.vblitsize)
	blt_info.vblitsize = 32768;
    if (!blt_info.hblitsize)
	blt_info.hblitsize = 0x800;
    do_blitter (current_hpos());
}
