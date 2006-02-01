//////////////////////////  -*-C++-*- /////////////////////////////////////////
//
// JobStatisticsReadWrite.cpp
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
#include "JobStatisticsReadWrite.h"


///////////  JobStatisticsReadWrite::JobStatisticsReadWrite()  ////////////////
JobStatisticsReadWrite::JobStatisticsReadWrite()
{
#ifdef USE_THREADS
   pthread_mutex_init(&mMutex, NULL);
#endif
   this->init();
}


///////////  JobStatisticsReadWrite::JobStatisticsReadWrite()  ////////////////
JobStatisticsReadWrite::JobStatisticsReadWrite(const JobStatisticsReadWrite &rhs)
{
#ifdef USE_THREADS
   pthread_mutex_init(&mMutex, NULL);
#endif
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


///////////////////  JobStatisticsReadWrite::init()  //////////////////////////
void JobStatisticsReadWrite::init()
{
   this->lock();

   JobStatistics::init();
   mJobBytesTransferred = 0;
   mHackRowBytesTransferred = 0;
   mTransferBytesTransferred = 0;
   mNumTransfersWithDataIntegrityErrors = 0;

   this->unlock();
}


///////////////  JobStatisticsReadWrite::getJobStartTime()  ///////////////////
TimeHack JobStatisticsReadWrite::getJobStartTime() const
{
   TimeHack time;

   this->lock();
   time = mJobStartTime;
   this->unlock();

   return time;
}


///////////////  JobStatisticsReadWrite::setJobStartTime()  ///////////////////
void JobStatisticsReadWrite::setJobStartTime()
{
   this->lock();
   mJobStartTime.setTimeNow();
   this->unlock();
}


///////////////  JobStatisticsReadWrite::getJobEndTime()  /////////////////////
TimeHack JobStatisticsReadWrite::getJobEndTime() const
{
   TimeHack time;

   this->lock();
   time = mJobEndTime;
   this->unlock();

   return time;
}


///////////////  JobStatisticsReadWrite::setJobEndTime()  /////////////////////
void JobStatisticsReadWrite::setJobEndTime()
{
   this->lock();
   mJobEndTime.setTimeNow();
   this->unlock();
}


///////////////  JobStatisticsReadWrite::getJobBytesTransferred()  ////////////
capacity_t JobStatisticsReadWrite::getJobBytesTransferred() const
{
   capacity_t bytes;

   this->lock();
   bytes = mJobBytesTransferred;
   this->unlock();

   return bytes;
}


///////////////  JobStatisticsReadWrite::setJobBytesTransferred()  ////////////
void JobStatisticsReadWrite::setJobBytesTransferred(capacity_t bytes)
{
   this->lock();
   mJobBytesTransferred = bytes;
   this->unlock();
}


///////////////  JobStatisticsReadWrite::addToJobBytesTransferred()  //////////
void JobStatisticsReadWrite::addToJobBytesTransferred(capacity_t bytes)
{
   this->lock();
   mJobBytesTransferred += bytes; 
   this->unlock();
}


///////////////  JobStatisticsReadWrite::getHackRowStartTime()  ///////////////
TimeHack JobStatisticsReadWrite::getHackRowStartTime() const 
{
   TimeHack time;

   this->lock();
   time = mHackRowStartTime;
   this->unlock();

   return time;
}


///////////////  JobStatisticsReadWrite::setHackRowStartTime()  ///////////////
void JobStatisticsReadWrite::setHackRowStartTime()
{
   this->lock();
   mHackRowStartTime.setTimeNow(); 
   this->unlock();
}


///////////////  JobStatisticsReadWrite::getHackRowEndTime()  /////////////////
TimeHack JobStatisticsReadWrite::getHackRowEndTime() const 
{
   TimeHack time;

   this->lock();
   time = mHackRowEndTime;
   this->unlock();

   return time;
}


///////////////  JobStatisticsReadWrite::setHackRowEndTime()  /////////////////
void JobStatisticsReadWrite::setHackRowEndTime() 
{
   this->lock();
   mHackRowEndTime.setTimeNow();
   this->unlock();
}


///////////////  JobStatisticsReadWrite::getHackRowBytesTransferred()  ////////
capacity_t JobStatisticsReadWrite::getHackRowBytesTransferred() const 
{
   capacity_t bytes;

   this->lock();
   bytes = mHackRowBytesTransferred;
   this->unlock();

   return bytes;
}


///////////////  JobStatisticsReadWrite::setHackRowBytesTransferred()  ////////
void JobStatisticsReadWrite::setHackRowBytesTransferred(capacity_t bytes) 
{
   this->lock();
   mHackRowBytesTransferred = bytes;
   this->unlock();
}


///////////  JobStatisticsReadWrite::addToHackRowBytesTransferred()  //////////
void JobStatisticsReadWrite::addToHackRowBytesTransferred(capacity_t bytes)
{
   this->lock();
   mHackRowBytesTransferred += bytes;
   this->unlock();
}


///////////////  JobStatisticsReadWrite::getTransferStartTime()  /////////////
TimeHack JobStatisticsReadWrite::getTransferStartTime() const 
{
   TimeHack time;

   this->lock();
   time = mTransferStartTime;
   this->unlock();

   return time;
}


///////////////  JobStatisticsReadWrite::setTransferStartTime()  //////////////
void JobStatisticsReadWrite::setTransferStartTime() 
{
   this->lock();
   mTransferStartTime.setTimeNow();
   this->unlock();
}


///////////////  JobStatisticsReadWrite::getTransferEndTime()  ///////////////
TimeHack JobStatisticsReadWrite::getTransferEndTime() const 
{
   TimeHack time;

   this->lock();
   time = mTransferEndTime;
   this->unlock();

   return time;
}


///////////////  JobStatisticsReadWrite::setTransferEndTime()  ///////////////
void JobStatisticsReadWrite::setTransferEndTime() 
{
   this->lock();
   mTransferEndTime.setTimeNow();
   this->unlock();
}


//////////  JobStatisticsReadWrite::getTransferBytesTransferred()  ////////////
capacity_t JobStatisticsReadWrite::getTransferBytesTransferred() const
{
   capacity_t bytes;
   
   this->lock();
   bytes = mTransferBytesTransferred;
   this->unlock();

   return bytes;
}


/////////  JobStatisticsReadWrite::setTransferBytesTransferred()  /////////////
void JobStatisticsReadWrite::setTransferBytesTransferred(capacity_t bytes)
{
   this->lock();
   mTransferBytesTransferred = bytes;
   this->unlock();
}


//////  JobStatisticsReadWrite::addToTransferBytesTransferred()  //////////////
void JobStatisticsReadWrite::addToTransferBytesTransferred(capacity_t bytes)
{
   this->lock();
   mTransferBytesTransferred += bytes;
   this->unlock();
}


////  JobStatisticsReadWrite::getNumTransfersWithDataIntegrityErrors()  ///////
capacity_t JobStatisticsReadWrite::getNumTransfersWithDataIntegrityErrors() const 
{
   capacity_t bytes;

   this->lock();
   bytes = mNumTransfersWithDataIntegrityErrors;
   this->unlock();

   return bytes;
}


////  JobStatisticsReadWrite::setNumTransfersWithDataIntegrityErrors()  ///////
void JobStatisticsReadWrite::setNumTransfersWithDataIntegrityErrors(capacity_t errors)
{
   this->lock();
   mNumTransfersWithDataIntegrityErrors = errors;
   this->unlock();
}


/////  JobStatisticsReadWrite::incNumTransfersWithDataIntegrityErrors()  //////
void JobStatisticsReadWrite::incNumTransfersWithDataIntegrityErrors() 
{
   this->lock();
   mNumTransfersWithDataIntegrityErrors++; 
   this->unlock();
}

#ifdef USE_THREADS
//////////////////////  JobStatisticsReadWrite::lock()  ///////////////////////
void JobStatisticsReadWrite::lock() const 
{
   pthread_mutex_lock(&mMutex);
}


//////////////////////  JobStatisticsReadWrite::unlock()  /////////////////////
void JobStatisticsReadWrite::unlock() const 
{
   pthread_mutex_unlock(&mMutex);
}
#endif // USE_THREADS


//////////////  JobStatisticsReadWrite::~JobStatisticsReadWrite()  ////////////
JobStatisticsReadWrite::~JobStatisticsReadWrite()
{
#ifdef USE_THREADS
   pthread_mutex_destroy(&mMutex);
#endif
}


