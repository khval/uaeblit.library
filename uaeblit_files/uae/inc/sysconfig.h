
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <proto/exec.h>

#define STATIC_INLINE static inline

typedef signed char uae_s8;
typedef signed short uae_s16;

typedef unsigned char uae_u8;
typedef unsigned short uae_u16;
typedef unsigned int uae_u32 ;

typedef int frame_time_t;

typedef uae_u32        uaecptr;

#define chipmem_wget(ptr) *((short *) (ptr))
#define chipmem_wput(ptr,data) *((short *) (ptr)) = (data)

struct regstruct
{
	ULONG spcflags;
};

extern struct regstruct regs;
extern int savestate_state;

struct currprefs_t
{
	int immediate_blits;
	int blitter_cycle_exact;
	ULONG chipset_mask;
};

extern struct currprefs_t currprefs;

extern int m68k_getpc( struct regstruct *regs );

extern void set_special( struct regstruct *addr, uae_u32 flag ); 

