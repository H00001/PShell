#include "command.h"
#define ICALL 2
#define HOME "/home/frank"
struct command_ command_table[] = {{"exit",__exit},{"cd",cd}};

void cd(char *argv[]){
	if(chdir(argv[1]?argv[1]:HOME)){
		printf("%d",errno);
	}
}

void __exit(char *argv[]){
	exit(0);
}

int compare(const char *call,char *argv[]){
	for(int i = 0;i<ICALL;i++){
		if(!strcmp(command_table[i].name,call)){
			command_table[i].p(argv);
			return 1;
		}
	}
	return 0;
}
