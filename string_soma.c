#include <stdio.h>
#include <stdlib.h>

int ehNum(char ch){
	if(ch >= 48 && ch <= 57)
		return 1;
	return 0;
}

int ehDelimitador(char ch){
	if(ch == ',')
		return 1;
	return 0;
}

int soma_string(char * string_entrada){
	int a = 0, b = 0;
	if(ehNum(string_entrada[0])){
		a = atoi(& string_entrada[0]);
		if(ehDelimitador(string_entrada[1])){
			if(ehNum(string_entrada[2])){
				b = atoi(& string_entrada[2]);
			}
		}else{
			return -1;
		}
	}else{
		return -1;
	}
	return a+b;
}
