/* :ts=4
 *  $VER: BLTCPTL.c $Revision$ (11-Nov-2023)
 *
 *  This file is part of uaeblit.
 *
 *  Copyright (c) 2023 LiveForIt Software.
 *  Freeware License..
 *
 * $Id$
 *
 * $Log$
 *
 *
 */


#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <exec/interrupts.h>
#include <exec/libraries.h>
#include <proto/uaeblit.h>
#include <stdarg.h>
#include <hardware/custom.h>

/****** uaeblit/main/BLTCPTL ******************************************
*
*   NAME
*      BLTCPTL -- Description
*
*   SYNOPSIS
*      void BLTCPTL(struct Custom * custom);
*
*   FUNCTION
*
*   INPUTS
*       custom - 
*
*   RESULT
*       This function does not return a result
*
*   EXAMPLE
*
*   NOTES
*
*   BUGS
*
*   SEE ALSO
*
*****************************************************************************
*
*/

void _uaeblit_BLTCPTL(struct euae_blitIFace *Self,
       struct Custom * custom)
{
  BLTCPTL( (ULONG) custom -> bltcpt & 0xFFFF );
}

