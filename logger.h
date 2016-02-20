#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>

/*
	Variable declarations
*/

// Levels of message severity
enum Severity {
	DEBUG    = 0,
	INFO     = 1,
	WARNING  = 2,
	ERROR    = 3,
	CRITICAL = 4,
};

extern int log_level;

extern bool logfile_output;
extern bool stdout_output;

/*
	Function declarations
*/

int log_init(int);
void log_close();


void log_debug(const char*);
void log_info(const char*);
void log_warning(const char*);
void log_error(const char*);
void log_critical(const char*);

#ifdef __cplusplus
}
#endif
