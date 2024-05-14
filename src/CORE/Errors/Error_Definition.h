#pragma once

#ifdef ENABLE_ERROR_LOG

#ifndef LOG_PATH

#define LOG_PATH "bin/log.txt"

#endif

#ifndef DEBUG_PATH

#define DEBUG_PATH LOG_PATH

#endif


//To make error logging easier
#define ErrorOrigin __FILE__, __FUNCTION__, __LINE__


/*
* For the error logging file to be included ENABLE_ERROR_LOG should be defined
* To define a different path to log the errors to define LOG_PATH to your desired path
* To enable logging debug information define ENABLE_DEBUG_LOG
* By default debug information is logged to the error log.
* If you want to the log the debug information to a different file the define DEBUG_PATH
* You can also log all the errors to the heap.
* To enable that define ENABLE_HEAP_LOG
*/

#endif