//==============================================================================
//
// Copyright (C) 2008 by Vinnie Falco, this file is part of VFLib.
// See the file GNU_GPL_v2.txt for full licensing terms.
// 
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option)
// any later version.
// 
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
// 
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
// 
//==============================================================================

#ifndef VF_PERFORMEDATEXIT_VFHEADER
#define VF_PERFORMEDATEXIT_VFHEADER

#include "../containers/vf_LockFreeStack.h"

//==============================================================================
/** 
    Perform an action at program exit

    To use, derive your class from PerformedAtExit, and override performAtExit().
    The call will be made during the destruction of objects with static storage
    duration, before LeakChecked performs its diagnostics.

    \ingroup vf_core
*/
class PerformedAtExit : LockFreeStack <PerformedAtExit>::Node
{
protected:
  explicit PerformedAtExit ();

private:
  virtual void performAtExit () = 0;

private:
  class Performer;

  PerformedAtExit* m_next;
};

#endif
