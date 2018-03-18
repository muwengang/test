#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv){
	struct stat buf;
	stat(argv[1], &buf);
	char name_buf[128] = {0};
	if(S_ISDIR(buf.st_mode)){
		char *name=strrchr(argv[1], '/');
		sprintf(name_buf, "tar zcf /tmp/%s.tar.gz %s",name,argv[1]);
		system(name_buf);
		printf("is dir!\n");
	}
	return 0;
}
