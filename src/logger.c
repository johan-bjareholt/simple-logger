#include "logger.h"

#include <stdio.h>
#include <time.h>


int log_init(int loglvl=INFO){
	// Get current time
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	// Set logfile name and location
	char logfilename[50];
	strftime(logfilename,50,"./logs/%c", timeinfo);
	// Open logfile
	logfile = fopen(logfilename,"w");
	// Set loglevel
	log_level = loglvl;
	printf("%i\n", log_level);
}

void log_close(){
	fclose(logfile);
}


static void echo_log_message(Severity severity, const char* message){
	if (log_level >= severity){
		char full_message[255];
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