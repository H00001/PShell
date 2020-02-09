#define SPILT_H
#include <stdlib.h>

struct param{
	const char *call;
	char * const *params;
};

struct param* spilt(char *c);
