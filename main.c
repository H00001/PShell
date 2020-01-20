#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(){
	char buf[20];
	while (1){
		buf[strlen(fgets(buf,20,stdin))-1] = 0;
		pid_t p;
		if((p=fork())==0){
			execlp(buf,buf,NULL);
		}
		else{
			waitpid(p,NULL,0);
		}
	}
}
