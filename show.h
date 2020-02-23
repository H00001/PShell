#include <stdio.h>
#define SHOWGREEN(DATA...) ( printf("%s\033[32;1m->\033[0m",(DATA)) )
#define SHOWRED(DATA...) ( printf("%s\033[31;1m->\033[0m",(DATA)) )
void show(const char* s,int color){
	if(color){
		SHOWGREEN(s);
	}else{
		SHOWRED(s);
	}
}	
