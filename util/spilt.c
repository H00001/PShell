#include "spilt.h"
#include <stdio.h>

const char** createNULL(int len,const char* name){
	const char ** sv = malloc(sizeof(char*)*len);    
	*sv = name;
	*(sv+len-1) = NULL;
	return sv;
}
int len_p(const char *p){
	int len = 1;
	for(int i = 0;p[i]!=0;i++)                                                
		len = p[i]==' ' ?len+1:len;
	return len;
}
void put_param(const char **p,int i,const char *m){
	*(p+i) = m;
}
const char **_params(char *p,const char* name){
	int len = len_p(p);
	const char **sv = createNULL(len+2,name);
	int c = 1;
	if(len==c){
		*(sv+c) = p;
		return sv;
	}
	for(int i = 0;p[i]!=0;i++){
       		if(p[i]==' '){
       			p[i] = 0;
			put_param(sv,c++,p);
			p = p + i + 1;
 		}
  	}
	return sv;
}


struct param* spilt(char *c){
	struct param *p = malloc(sizeof(struct param));
	p->call = c;
	int now = 0;
	for(;c[now]!=0;now++){
		if(c[now] == ' '){
			c[now] = 0;
			break;
		}
	}
	p->params = c[now+1]?_params(c+now+1,p->call):createNULL(2,p->call);
	return p;
}

