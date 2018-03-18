#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/socket.h>

void get_ip_port( char *url, char *ip, char *port){
	char *pos = NULL;
	char *ip_pos = NULL;
	char *port_pos = NULL;
	//pos = strstr(url, "//:");
	if(strstr(url, "//:")){
		ip_pos = url + 3;
	}else{
		ip_pos = url;
	}
	pos = strstr(ip_pos, "/");
	if(pos){
		port_pos = strstr(ip_pos)	
	}
}

int main(int argc, char **argv){
	if(argc < 2){
		printf("usage\n");
		printf("  %s url\n", argv[1]);
	}
	
	return 0;

}
