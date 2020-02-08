#include "command.h"
#define ICALL 2
struct command_ command_table[] = {{"exit",__exit},{"cd",cd}};

void cd(int argc,char *argv){
}

void __exit(int argc,char *argv){
	exit(0);
}

void compare(const char *call){
	for(int i = 0;i<1;i++){
		if(!strcmp(command_table[i].name,call)){
			command_table[i].p(0,NULL);
		}
	}
}
