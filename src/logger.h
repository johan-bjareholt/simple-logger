#include <stdio.h>
#include <time.h>
#include <stdbool.h>

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


int log_level;

FILE * logfile;

bool logfile_output = true;
bool stdout_output = false;

time_t rawtime;
struct tm * timeinfo;

/*
	Function declarations
*/

int log_init(int);
void log_close();


void log_debug(const char* message);
void log_info(const char* message);
void log_warning(const char* message);
void log_error(const char* message);
void log_critical(const char* message);