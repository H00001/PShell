#define COMMAND_H
#include <stdlib.h>
 #include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void __exit(char * argv[]);
void cd(char * argv[]);
int compare(const char *call,char * argv[]);
struct command_ {
	char *name;
	void (*p)(char * argv[]);
};
