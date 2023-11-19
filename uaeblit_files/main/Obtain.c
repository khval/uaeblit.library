/* :ts=4
 *  $VER: Obtain.c $Revision$ (10-Nov-2023)
 *
 *  This file is part of uaeblit.
 *
 *  Copyright (c) 2023 LiveForIt-Software.
 *  All Rights Reserved.
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

/****** uaeblit/main/Obtain ******************************************
*
*   NAME
*      Obtain -- Description
*
*   SYNOPSIS
*      ULONG Obtain(void);
*
*   FUNCTION
*
*   INPUTS
*
*   RESULT
*       The result ...
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

ULONG _uaeblit_Obtain(struct uaeblitIFace *Self)
{
    return Self -> Data.RefCount++;
}

