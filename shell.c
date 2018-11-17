#include "stdio.h"
#include "string.h"
#include "sys/types.h"
#include "stdlib.h"

#include "shell.h"


#define PROMPT "\nenter_your_command>"
#define DELIMITERS " \t\r\n\0"


//TODO move from functional pointers to execV
const char* pathToCommands = "/home/hououin/mipt_2_sem/shell/bin";
int numOfBuiltins = 1;
char* builtinNames[] = { "echo" };
int (*builtinPtrs[])(int, char **) = { &myEcho };

int perr(char * msg){
	printf("Error occured: %s\n",msg);
	return 0;
}

int perrarg(char * msg,char * arg){
        printf("Error occured: %s %s\n",msg,arg);
        return 0;
}



int execCmd(int argc, char ** args){
	if(args[0] == NULL){
		return 1;
	}
	int i;
	for(i =0; i < numOfBuiltins; i++){
		if(strcmp(args[0],builtinNames[i])==0){
			return (builtinPtrs[i])(argc, args);
		}
	}
	char filename [4048];
	filename[0] = '\0';
	strcat(filename, "/home/hououin/mipt_2_sem/shell/bin/");
	//strcat(filename, "/usr/bin/");
	strcat(filename, args[0]);
	pid_t childPid = fork();
	if( childPid == 0 ){
		if(execvp(filename, args) == -1){
			perrarg("can't open exec file", filename);
		}else{
			printf("execvp worked\n");
			
		}
		exit(0);
	}else{
		int status;
		waitpid(childPid, &status, 0);
		return 0;
	}	

	printf("Error: no such builtin or command\n");	
	return 1;
}

int main(){
char buffer[1000];
char * command;
int temp = 1 ;
do{
		//command = " ";
		printf( PROMPT );
		fgets(buffer,1000,stdin);
		// Parsing input
		char* args[100];
		int i;
		//printf("command number:%d\n",temp);
		args[0] = strtok(buffer,DELIMITERS);
		if(args[0] != NULL){
		int argc = 0;
		for( i = 1; args[i-1] != NULL; i++){
			args[i] = strtok(NULL,DELIMITERS);	
			argc++;
		}
		command = args[0];
		// Execute command
		if(strcmp(command, "exit")){
			execCmd(argc, args);		
		}
		temp++;
		}			
	}while(strcmp(command, "exit"));
	
	

	return 0;
}

