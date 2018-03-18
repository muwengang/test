#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


static int debugLevel = 3;
#include <stdarg.h>
static int DebugPrintf(const char *format, ...){
	if(debugLevel <= 3){
		va_list argPtr;
		int count;

		va_start(argPtr, format);
		fflush(stdout);
		count = vfprintf(stderr, format, argPtr);
		va_end(argPtr);
	}
}

//#include <stdarg.h>
static int WarryPrintf(const char *format, ...){
	if(debugLevel <= 2){
		va_list argPtr;
		int count;

		va_start(argPtr, format);
		fflush(stdout);
		count = vfprintf(stderr, format, argPtr);
		va_end(argPtr);
	}
}
static int ErrorPrintf(const char *format, ...){
	if(debugLevel <= 1){
		va_list argPtr;
		int count;

		va_start(argPtr, format);
		fflush(stdout);
		count = vfprintf(stderr, format, argPtr);
		va_end(argPtr);
	}
}
int debug_init(){
	int fd = open("log.conf", O_RDONLY);
	char buf[128] = {0};
	read(fd, buf, 128);
	close(fd);
	char *pos = strstr(buf, "=");
	if(pos){
		if(pos+1){
			if(!strcmp(pos + 1, "error\n"))
				debugLevel = 1;
			else if(!strcmp(pos + 1, "wall\n"))
				debugLevel = 2;
			else if(!strcmp(pos + 1, "debug\n"))
				debugLevel = 3;
			else
				debugLevel = 4;
		}else
			debugLevel = 5;
	}else{
		debugLevel = 6;	
	}
}
int main(int argc, char *argv[]){
	debug_init();
	DebugPrintf("Debug\n");
	WarryPrintf("Warry\n");
	ErrorPrintf("Error\n");
	return 0;
}
