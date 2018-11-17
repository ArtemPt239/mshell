#include "stdio.h"

int main(int argc, char ** argv){
	if( argc < 2){
		perror("to few arguments");
		return 1;
	}	
	if( remove(argv[1]) != 0){
		perror("an error occured");
		return 1;
	}
	return 0;
}

