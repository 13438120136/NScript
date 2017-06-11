#ifndef _NNFUNCTION_HEAD
#define _NNFUNCTION_HEAD

#include "ncode.h"
#include "nobject.h"
#include "nvm.h"

typedef struct NNFunction
{
	ExecCommand *cmd;
	ExecCommand *pc;
	NObject *content;

	int sizeCmd;
	int sizeContent;
}NNFunction;

#endif
