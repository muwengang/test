#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_delete_str(char *src, char *dec, char *replance){
	if(src == NULL || dec == NULL || replance == NULL)
		return -1;
	char *tmp = src;
	char *tmp_ptr = tmp;
	int size = strlen(replance);
	tmp = strstr(src, replance);
/*	while(tmp == src){
		tmp = tmp + size;
		tmp_ptr = tmp;
		src = tmp;
		tmp = strstr(tmp, replance);
	}
*/	while(tmp){
		*tmp = '\0';
		strcat(dec, tmp_ptr);
		tmp = tmp + size;
		tmp_ptr = tmp;
		tmp = strstr(tmp, replance);
		if(tmp == NULL)
			strcat(dec, tmp_ptr);
	}
	return 0;
}

int main(int argc, char** argv){
	
	char src[] = "/etc/asterisk/gw_analog.conf,/etc/asterisk/gw_endpoints.conf,/etc/asterisk/sip_endpoints.conf";
	int size = strlen(src);
	char *buf = (char *)malloc(size+1);
	memset(buf, 0, size);
	int res = my_delete_str(src, buf, "/etc/asterisk/");
	if(res < 0)
		return -1;
	printf("reuslt:\n%s\n",buf);	
	free(buf);
	return 0;
}
