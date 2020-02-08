#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include "show.h"
#define PS_NAME "PShell-Fork"
void register_env();
void func_signal(int s);
int main(){
	register_env();
	char buf[20];
	char dir[40];
	while (1){
		char *d = getcwd(dir,40);
		SHOWGREEN(d);
		buf[strlen(fgets(buf,20,stdin))-1] = 0;
		pid_t p;
		if((p=fork())==0){
			prctl(PR_SET_NAME, PS_NAME, NULL, NULL, NULL);
			execlp(buf,buf,NULL);
		}
		else{
			int result;
			waitpid(p,&result,0);
			if (WIFEXITED(result)) {
				printf("cc");
			}else{
				printf("cd");
			}
		}
	}
}

void register_env(){
	signal(SIGINT,func_signal);
}

void func_signal(int s){
	
}

