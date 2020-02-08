#include <stdio.h>
#define SHOWGREEN(DATA...) ( printf("\033[32,1m%s\033[0m>",(DATA)) )
#define SHOWRED(DATA...) ( printf("\033[31,1m%s\033[0m>",(DATA)) )
