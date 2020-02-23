#include "command.h"
#define ICALL 3
#define HOME "/home/frank"
struct command_ command_table[] = {{"exit",__exit},{"cd",cd},{"su",su}};

void cd(char *argv[]){
	if(chdir(argv[1]?argv[1]:HOME)){
		printf("%d",errno);
	}
}

void su(char *argv[]){
	printf("you are a super user\n");	
}
void __exit(char *argv[]){
	exit(0);
}

int compare(const char *call,char *argv[]){
	if(call[0]==0){
		return 1;
	}
	for(int i = 0;i<ICALL;i++){
		if(!strcmp(command_table[i].name,call)){
			command_table[i].p(argv);
			return 1;
		}
	}
	return 0;
}
