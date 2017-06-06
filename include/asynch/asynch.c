//
// asynch.c    Asynchronous operations using threads.
// 
// This file is part of glScript project.
//
//   glScript is free software: you can redistribute it and/or modify
//   it under the terms of the GNU Lesser General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   glScript is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU Lesser General Public License for more details.
//
//   You should have received a copy of the GNU Lesser General Public License
//   along with glScript. If not, see <http://www.gnu.org/licenses/>.
//
//   Copyright (c) 2012 Bal Bahadur Chettri
//
//   Author: Bal Bahadur Chettri (balu.chettri@gmail.com)
//
//   Version:    1.0
//
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

/* have windows.h if required */
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <asynch/asynch.h>

/* posts the asynchronous result to its owner thread */
void asynch_post_result (ASYNCH_CALL_RESULT *result) {
#ifdef WIN32
    /*
    The result structure contains the target_thread_id member storing the thread id
    of the owner thread that started the asynchronous call. Post a message to this thread
    passing the result structure as a parameter. 

    Note that the message loop of the owner thread must process this message and dispatch,
    using asynch_dispatch_result function, the result to the acutal callback set during the 
    asynchronous call invocation.
    */
    PostThreadMessage (result->target_thread_id, ASYNCH_CALL_MSG, 0, (LPARAM)result);
#endif
}

/* create and return an asynch result structure that is used for posting the result back
   to the owner thread asynchronously */
ASYNCH_CALL_RESULT *asynch_create_result (size_t size, ASYNCH_CALLBACK callback, void *context) {
    ASYNCH_CALL_RESULT *result;
    
    /* allocate memory for the asynchronous result. The size should not be less than 
       sizeof(ASYNCH_CALL_RESULT) */
#ifdef _DEBUG
    assert(size >= sizeof(ASYNCH_CALL_RESULT));
#endif  
    result = (ASYNCH_CALL_RESULT *)(malloc(size));
    
#ifdef WIN32
    /* save the owner (current) thread's ID */
    result->target_thread_id = GetCurrentThreadId ();
#endif

    /* initialize rest of the fields */
    result->callback = callback;
    result->context = context;
    result->status = 0;
    result->data = NULL;

    /* return pointer to the new asynch result structure */
    return result;
}

/* dispatch the asynch result to the callback. This function must be invoked
   from a message loop of the owner thread i.e the the thread that actually 
   started the asynchronous call. */
void asynch_dispatch_result (ASYNCH_CALL_RESULT *result) {
    /* it is upto the callback to interpret and free the data if required. */
    result->callback (result->status, result->data, result->context);

    /* free the asynch result */
    asynch_free_result (result);
}

/* free the result structure allocated by asynch_create_result(). */
void asynch_free_result (ASYNCH_CALL_RESULT *result) {
    free (result);
}
