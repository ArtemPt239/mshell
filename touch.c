#include "stdio.h"


int main(int argc, char** argv){
	if( argc < 2 ){
		perror("too few arguments");
		return 1;
	}
	if( fopen(argv[1],"a") == NULL){
		perror("can't create file");
		return 1;
	}
	return 0;
}


