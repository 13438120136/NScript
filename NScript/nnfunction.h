#ifndef _NNFUNCTION_HEAD
#define _NNFUNCTION_HEAD

#include "ncode.h"
#include "nobject.h"

typedef struct NNFunction
{
	NCommand *cmd;
	NObject *content;

	int sizeCmd;
	int sizeContent;
}NNFunction;

#endif
