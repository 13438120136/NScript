#ifndef _NOBJECT_HEAD
#define _NOBJECT_HEAD

#define NTypeNull      0
#define NTypeNumber    1
#define NTypeString    2
#define NTypeFunction  3
#define NTypeObject    4

typedef struct NObject
{
	union
	{
		float number;
	}Value;

	int type;
}NObject;

#endif