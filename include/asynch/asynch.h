//
// asynch.h    Asynchronous operations using threads.
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
#ifndef __ASYNCH_H__
#define __ASYNCH_H__

/* define message id for asynchronous callbacks */
#ifdef WIN32
#define ASYNCH_CALL_MSG         (WM_USER + 0x0001)
#endif

/* define procedure type for asynchronous callbacks. */
typedef void (* ASYNCH_CALLBACK) (long status, void *data, void *context);

/** ASYNCH_CALL_RESULT structure */
typedef struct _ASYNCH_CALL_RESULT {
    unsigned long target_thread_id;
    ASYNCH_CALLBACK callback;
    void *context;
    long status;
    void *data; 
}ASYNCH_CALL_RESULT;

#ifdef __cplusplus
extern "C" {
#endif

/* asynchronous operations API */

/** creates a new result used for asynchronous operation */
ASYNCH_CALL_RESULT *asynch_create_result (size_t size, ASYNCH_CALLBACK callback, void *context);

/** posts the asynchronous call result to its starter / owner thread */
void asynch_post_result (ASYNCH_CALL_RESULT *result);

/** dispatches the asynchronous call result to its callback */
void asynch_dispatch_result (ASYNCH_CALL_RESULT *result);

/** fres the asynchronous call result allocated using asynch_create_result */
void asynch_free_result (ASYNCH_CALL_RESULT *result);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* __ASYNCH_H__ */
