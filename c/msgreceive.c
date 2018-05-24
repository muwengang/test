#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/msg.h>
#include <string.h>
#define BUFSIZE 1024
struct msg_st{
	long int msg_type;
	char text[BUFSIZE];
};

int main(int argc, char **argv){
	int running = 1;
	int msgid = -1;
	struct msg_st data;
	long int msgtype = 0;

	msgid = msgget((key_t)1234, 0666 |IPC_CREAT);
	if(msgid == -1){
		fprintf(stderr, "msgget fialed with error:%d\n",errno);
	}
	while(running){
		if(msgrcv(msgid, (void*)&data, BUFSIZE, msgtype, 0) == -1){
			fprintf(stderr, "msgrcv failed with errno:%d\n", errno);
			exit(EXIT_FAILURE);
		}
		printf("You  write:%s\n", data.text);
		if(strncmp(data.text, "end", 3) == 0)
			running = 0;
	}

	if(msgctl(msgid,  IPC_RMID, 0) == -1){
		fprintf(stderr, "msgctl(IPC_RMID) failed!\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
