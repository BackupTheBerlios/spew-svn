//////////////////////////  -*-C++-*- /////////////////////////////////////////
//
// CumulativeStatistics.h
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

#ifndef CUMULATIVESTATISTICS_H
#define CUMULATIVESTATISTICS_H

#include "common.h"
#include "Statistics.h"
#include "TimeHack.h"


///////////////////////////////////////////////////////////////////////////////
///////////////////////////  Class CumulativeStatistics  //////////////////////
///////////////////////////////////////////////////////////////////////////////
class CumulativeStatistics: public Statistics
{
public:
   CumulativeStatistics();

   void init();
   
   unsigned int getIterations() const { return mIterations; };
   void setIterations(unsigned int iter) { mIterations = iter; };
   void incIterations() { mIterations++; };
   
   TimeHack getTotalReadTransferTime() const { return mTotalReadTransferTime; };
   void setTotalReadTransferTime(const TimeHack &hack) { mTotalReadTransferTime = hack; };
   void addToTotalReadTransferTime(const TimeHack &hack) { mTotalReadTransferTime += hack; };

   TimeHack getTotalWriteTransferTime() const { return mTotalWriteTransferTime; };
   void setTotalWriteTransferTime(const TimeHack &hack) { mTotalWriteTransferTime = hack; };
   void addToTotalWriteTransferTime(const TimeHack &hack) { mTotalWriteTransferTime += hack; };

   capacity_t getTotalBytesRead() const { return mTotalBytesRead; };
   void setTotalBytesRead(capacity_t bytes) { mTotalBytesRead = bytes; };
   void addToTotalBytesRead(capacity_t bytes) { mTotalBytesRead += bytes; };


   capacity_t getTotalBytesWritten() const { return mTotalBytesWritten; };
   void setTotalBytesWritten(capacity_t bytes) { mTotalBytesWritten = bytes; };
   void addToTotalBytesWritten(capacity_t bytes) { mTotalBytesWritten += bytes; };

   capacity_t getTotalReadOps() const { return mTotalReadOps; };
   void setTotalReadOps(capacity_t ops) { mTotalReadOps = ops; };
   void addToTotalReadOps(capacity_t ops) { mTotalReadOps += ops; };

   capacity_t getTotalWriteOps() const { return mTotalWriteOps; };
   void setTotalWriteOps(capacity_t ops) { mTotalWriteOps = ops; };
   void addToTotalWriteOps(capacity_t ops) { mTotalWriteOps += ops; };

   ~CumulativeStatistics();

private:
   CumulativeStatistics(const CumulativeStatistics& stats);
   CumulativeStatistics& operator=(const CumulativeStatistics &rhs);

private:
   unsigned int mIterations;
   TimeHack mTotalReadTransferTime;
   TimeHack mTotalWriteTransferTime;
   capacity_t mTotalBytesRead;
   capacity_t mTotalBytesWritten;
   capacity_t mTotalReadOps;
   capacity_t mTotalWriteOps;

};

#endif // CUMULATIVESTATISTICS_H
