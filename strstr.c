#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int my_strlen(const char *src){
	if(src == NULL || *src == '\0')
		return 0;
	return 1+my_strlen(++src);
}
char *my_strstr(char *src, char *search){
	if(src == NULL || search == NULL)
		return NULL;
	char *temp_src = src;
	char *temp_search = search;
	int len = my_strlen(search);
	int len1 = my_strlen(src);
	int i = 0, j = 0;
	while(temp_src != '\0' && j < len1){
		if(*temp_src == *temp_search){
			while(i < len){
				if(temp_src[i] != temp_search[i]){
					printf("i = %d\n",i);
					i = 0;
					break;
				}
				i++;
			}
			if(i != 0)
				return temp_src;
		}
		++j;
		temp_src++;
	}
	printf("%s", temp_src);
	return NULL;
}
int main(int argc, char **argv){
	char *buf  = "hello world,are you ok?";
	char *result = my_strstr(buf, "word");
	if(result)
		printf("%s\n", result);
	return 0;
}
