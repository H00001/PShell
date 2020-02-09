#define _GNU_SOURCE
#define _GUNPLAN_TOP_
#define BUFFERLEN 40
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include "show.h"
#include "./util/spilt.h"
#include "./internal/command.h"
#define PS_NAME "PShell-Fork"
void register_env();
void func_signal(int s);
int main(){
	register_env();
	char buf[BUFFERLEN];
	int next = 1;
	while (1){
		show(get_current_dir_name(),next);
		buf[strlen(fgets(buf,BUFFERLEN,stdin))-1] = 0;
		struct param* c= spilt(buf);
		if(compare(c->call,c->params)){
			continue;
		}
		pid_t p;
		if((p=fork())==0){
			prctl(PR_SET_NAME, PS_NAME, NULL, NULL, NULL);
			exit(execvp(c->call,c->params));
		}
		else{
			int result;
			waitpid(p,&result,0);
			next = WIFEXITED(result);
		}
	}
}

void register_env(){
	signal(SIGINT,func_signal);
}

void func_signal(int s){
	exit(2);	
}

