#include "stdio.h"

int myEcho(int argc, char** args){
	int i;
	for(i = 1; i < argc; i++){
		printf("%s ", args[i]);
	}
	printf("\n"); 
	return 0;
}
