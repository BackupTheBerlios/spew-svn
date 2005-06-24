//////////////////////////  -*-C++-*- /////////////////////////////////////////
//
// JobStatistics.h
//
// Spew
//
// Copyright (C) 2005 Hewlett-Packard Corp.
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

#ifndef JOBSTATISTICS_H
#define JOBSTATISTICS_H

#include "common.h"
#include "Statistics.h"
#include "TimeHack.h"


///////////////////////////////////////////////////////////////////////////////
///////////////////////////  Class JobStatistics  /////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class JobStatistics: public Statistics
{
public:
   JobStatistics();

   void init();
   
   TimeHack getJobStartTime() const { return mJobStartTime; };
   void setJobStartTime() { mJobStartTime.setTimeNow(); };
   TimeHack getJobEndTime() const { return mJobEndTime; };
   void setJobEndTime() { mJobEndTime.setTimeNow(); };
   capacity_t getJobBytesTransferred() const { return mJobBytesTransferred; };
   void setJobBytesTransferred(capacity_t bytes) { mJobBytesTransferred = bytes; };
   void addToJobBytesTransferred(capacity_t bytes) { mJobBytesTransferred += bytes; };

   TimeHack getHackStartTime() const { return mHackStartTime; };
   void setHackStartTime() { mHackStartTime.setTimeNow(); };
   TimeHack getHackEndTime() const { return mHackEndTime; };
   void setHackEndTime() { mHackEndTime.setTimeNow(); };
   capacity_t getHackBytesTransferred() const { return mHackBytesTransferred; };
   void setHackBytesTransferred(capacity_t bytes) { mHackBytesTransferred = bytes; };
   void addToHackBytesTransferred(capacity_t bytes) { mHackBytesTransferred += bytes; };

   TimeHack getTransferStartTime() const { return mTransferStartTime; };
   void setTransferStartTime() { mTransferStartTime.setTimeNow(); };
   TimeHack getTransferEndTime() const { return mTransferEndTime; };
   void setTransferEndTime() { mTransferEndTime.setTimeNow(); };
   capacity_t getTransferBytesTransferred() const { return mTransferBytesTransferred; };
   void setTransferBytesTransferred(capacity_t bytes) { mTransferBytesTransferred = bytes; };
   void addToTransferBytesTransferred(capacity_t bytes) { mTransferBytesTransferred += bytes; };


   capacity_t getNumTransfersWithDataIntegrityErrors() const { return mNumTransfersWithDataIntegrityErrors; };
   void setNumTransfersWithDataIntegrityErrors(capacity_t errors) { mNumTransfersWithDataIntegrityErrors = errors; };
   void incNumTransfersWithDataIntegrityErrors() { mNumTransfersWithDataIntegrityErrors++; };

   virtual ~JobStatistics();

private:
   JobStatistics(const JobStatistics& stats);
   JobStatistics& operator=(const JobStatistics &rhs);

private:
   TimeHack mJobStartTime;
   TimeHack mJobEndTime;
   capacity_t mJobBytesTransferred;

   TimeHack mHackStartTime;
   TimeHack mHackEndTime;
   capacity_t mHackBytesTransferred;

   TimeHack mTransferStartTime;
   TimeHack mTransferEndTime;
   capacity_t mTransferBytesTransferred;

   capacity_t mNumTransfersWithDataIntegrityErrors; // Number of transfers
                                                    // with any number of data 
                                                    // integrity errors.
};

#endif // JOBSTATISTICS_H
