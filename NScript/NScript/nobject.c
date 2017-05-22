#include "nobject.h"

void initStack(NStack *nstack)
{
	nstack->currIndex = nstack->stack;
}

void pushStack(NStack *nstack, NObject *obj)
{
	*(nstack->currIndex) = obj;
	nstack->currIndex++;
}

NObject *popStack(NStack *nstack)
{
	NObject *r = *nstack->currIndex;
	nstack->currIndex--;

	return r;
}

void setObjectType(NObject obj, int type)
{
	obj.ttype = type;
}

int isObjectType(NObject obj, int type)
{
	if (obj.ttype == type)
		return 1;

	return 0;
}

void setObjTo2(NObject *obj, NObject *other)
{
	if (obj == other)
		return ;

	obj->Value = other->Value;
	obj->ttype = other->ttype;
}