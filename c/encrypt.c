#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt(char *buf){
	char key=0x12;
	int size = strlen(buf);
	char *tmp = (char *)malloc(size+1);
	strcpy(tmp, buf);
	int i = 0;
	for(i = 0; i< size-1; i++){
		tmp[i] = tmp[i+1]^tmp[i];
	}
	tmp[size] = tmp[size]^key;
	return tmp;
}
char* dencrypt(char *buf){
	char key=0x12;
	int size = strlen(buf);
	char *tmp = (char *)malloc(size+1);
	strcpy(tmp, buf);
	int i = 0;
	tmp[size] = tmp[size]^key;
	for(i = size;i >0;--i){
		tmp[i-1] = tmp[i-1]^tmp[i];	
	}
	return tmp;
}

int main(int argc, char **argv){
	if(argc < 2)
		return -1;
	printf("encryt before:%s\n",argv[1]);
	char *encrypt_data = encrypt(argv[1]);
	printf("encryt end:%s\n",encrypt_data);
	char *dencrypt_data = dencrypt(encrypt_data);
	printf("dencryt before:%s\n",dencrypt_data);
	free(encrypt_data);
	free(dencrypt_data);
	return 0;
}
