
#define __USE_INLINE__
#include <proto/exec.h>

#include "sysconfig.h"
#include "events.h"

#include <stdbool.h>


int vpos = 0;
int dmacon = 0;
unsigned long currcycle = 0;

struct currprefs_t currprefs;
struct regstruct regs;
int savestate_state;

struct ev eventtab[ev_max];

int m68k_getpc( struct regstruct *regs )
{
	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);
}

void write_log( const char *fmt, ... )
{
	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);
}

void set_special( struct regstruct *regs, uae_u32 flag )
{
	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);
}

void unset_special( struct regstruct *regs, uae_u32 flag )
{
	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);
}

void blitter_done_notify()
{
	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);
}

void INTREQ( unsigned int x )
{
	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);
}

extern void blitter_handler (void);

void events_schedule()
{
	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);
	if (eventtab[ev_blitter].active)
	{
		blitter_handler();
		eventtab[ev_blitter].active = false;
	}
}

frame_time_t uae_gethrtime ()
{
	DebugPrintF("%s:%d\n",__FUNCTION__,__LINE__);
}

