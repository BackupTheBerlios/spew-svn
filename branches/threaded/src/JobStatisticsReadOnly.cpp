//////////////////////////  -*-C++-*- /////////////////////////////////////////
//
// JobStatisticsReadOnly.cpp
//
// Spew
//
// Copyright (C) 2006 Hewlett-Packard Corp.
//
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the
// Free Software Foundation version 2 of the License.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 675 Mass Ave, Cambridge, MA 02139, USA.

using namespace std;

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "common.h"
#include "JobStatisticsReadOnly.h"


////////////////  JobStatisticsReadOnly::JobStatisticsReadOnly()  /////////////
JobStatisticsReadOnly::JobStatisticsReadOnly()
{
   this->init();
}


///////////////  JobStatisticsReadOnly::JobStatisticsReadOnly()  //////////////
JobStatisticsReadOnly::JobStatisticsReadOnly(const JobStatisticsReadOnly &rhs)
{
   mJobStartTime = rhs.mJobStartTime;
   mJobEndTime = rhs.mJobEndTime;
   mJobBytesTransferred = rhs.mJobBytesTransferred;

   mHackRowStartTime = rhs.mHackRowStartTime;
   mHackRowEndTime = rhs.mHackRowEndTime;
   mHackRowBytesTransferred = rhs.mHackRowBytesTransferred;

   mTransferStartTime = rhs.mTransferStartTime;
   mTransferEndTime = rhs.mTransferEndTime;
   mTransferBytesTransferred = rhs.mTransferBytesTransferred;

   mNumTransfersWithDataIntegrityErrors = rhs.mNumTransfersWithDataIntegrityErrors;
}


///////////////////  JobStatisticsReadOnly::init()  ///////////////////////////
void JobStatisticsReadOnly::init()
{
   mJobBytesTransferred = 0;
   mHackRowBytesTransferred = 0;
   mTransferBytesTransferred = 0;
   mNumTransfersWithDataIntegrityErrors = 0;
}


/////////////////  JobStatisticsReadOnly::~JobStatisticsReadOnly()  ///////////
JobStatisticsReadOnly::~JobStatisticsReadOnly()
{
}


