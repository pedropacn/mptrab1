#include <stdio.h>
#include <stdlib.h>
#include "string_soma.h"

int main()
{
	int i = 0;
	char str[20], ch;
	FILE * fp;

	fp = fopen("soma.txt", "r");
	str[0] = fgetc(fp);
	while(str[i] != EOF){
		i++;
		str[i] = fgetc(fp);
	}
	str[i+1] = '\0';
	puts(str);
	int d = soma_string(str);
	printf("%d\n", d);
	return 0;
}