#ifndef _NOBJECT_HEAD
#define _NOBJECT_HEAD

#include "nstring.h"

#define NTypeNull      0
#define NTypeNumber    1
#define NTypeString    2
#define NTypeCFunction 3
#define NTypeNFunction 4
#define NTypeBool      5
#define NTypeObject    6

#define StackSize 1024   ///����Ĭ��ջ��С

///��������
typedef float NNumber;
///��������
typedef char NBool;

///////////////////////////////////����//////////////////////////////////////////////
typedef struct NObject
{
	union
	{
		NNumber number;		
		NString *string;
		NBool b;
	}Value;

	int ttype;  ///��������

}NObject;

#define setObjNumber(obj) setObjectType(obj, NTypeNumber)
#define isObjNumber(obj) isObjectType(NTypeNumber)
#define setObjString(obj) setObjectType(obj, NTypeString)
#define isObjString(obj) isObjectType(NTypeString)
#define setObjBoolean(obj) setObjectType(obj, NTypeBool)
#define isObjBoolean(obj) isObjectType(NTypeBool)

extern void setObjectType(NObject obj, int type);
extern int isObjectType(NObject obj, int type);
extern void setObjTo2(NObject *obj, NObject *other);
///////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////�������ջ///////////////////////////////////////////
typedef struct NStack
{
	NObject *stack[StackSize];			 ///ջ�ռ�
	NObject **currIndex;                 ///��ǰջ��λ��
}NStack;

extern void initStack(NStack *);
extern void pushStack(NStack *, NObject *obj);
extern NObject *popStack(NStack *);
///////////////////////////////////////////////////////////////////////////////////////

#endif