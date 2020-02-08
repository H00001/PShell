#define COMMAND_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void __exit(int argc,char * argv);
void cd(int argc,char * argv);
void compare(const char *call);
struct command_ {
	char *name;
	void (*p)(int argc,char * argv);
};
