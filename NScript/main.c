#include <stdio.h>
#include "nmachine.h"

#include "nhashtable.h"

int main(int argc, char *argv[])
{
	NString *v = (NString *)realloc(NULL, sizeof(NString) + 5);
	v->nsize = 5;
	memcpy(v->buf, "xxx", 5);
	return 0;
}
