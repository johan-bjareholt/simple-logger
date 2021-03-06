#include "logger.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

// Output settings
bool logfile_output = false;
bool stdout_output = true;
// Time variables
time_t rawtime;
struct tm * timeinfo;
// Loglevel
int log_level;
// Logfilepointer
FILE * logfile = NULL;

int log_init(int loglvl){
	// Get current time
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	// Set logfile name and location
	char logfilename[50];
	strftime(logfilename,50,"./logs/%c", timeinfo);
	// Set loglevel
	log_level = loglvl;
	// Open logfile
	logfile = fopen(logfilename,"w");
	if (logfile_output && logfile == NULL){
		printf("Error opening logfile!\nDisabling logging\n");
		log_level = 5;
	}
}

void log_close(){
	if (logfile != NULL)
		fclose(logfile);
}


static void echo_log_message(int severity, const char* message){
	if (log_level >= severity){
		char full_message[strlen(message)+20];
		// Prepend loglevel and timestamp to message
		switch(severity){
			case DEBUG:
				sprintf(full_message,"DEBUG:%s\n", message);
				break;
			case INFO:
				sprintf(full_message,"INFO:%s\n", message);
				break;
			case WARNING:
				sprintf(full_message,"WARNING:%s\n", message);
				break;
			case ERROR:
				sprintf(full_message,"ERROR:%s\n", message);
				break;
			case CRITICAL:
				sprintf(full_message,"CRITICAL:%s\n", message);
		}
		// Output section
		if (logfile_output){
			fputs(full_message, logfile);
		}
		if (stdout_output){
			printf("%s", full_message);
		}
	}
}


void log_debug(const char* message){
	echo_log_message(DEBUG, message);
}

void log_info(const char* message){
	echo_log_message(INFO, message);
}

void log_warning(const char* message){
	echo_log_message(WARNING, message);
}

void log_error(const char* message){
	echo_log_message(ERROR, message);
}

void log_critical(const char* message){
	echo_log_message(CRITICAL, message);
}

#ifdef __cplusplus
}
#endif
