#ifndef _NOBJECT_HEAD
#define _NOBJECT_HEAD

#define NTypeNull      0
#define NTypeNumber    1
#define NTypeString    2
#define NTypeFunction  3
#define NTypeObject    4

#define StackSize 1024   ///����Ĭ��ջ��С

///��������
typedef float NNumber;
///�ַ�������
typedef struct NString
{
	char buf[1024];
	int nsize;
}NString;

///////////////////////////////////����//////////////////////////////////////////////
typedef struct NObject
{
	union
	{
		NNumber number;
		NString string;
	}Value;

	int ttype;  ///��������

}NObject;

#define setObjNumber(obj) setObjectType(obj, NTypeNumber)
#define isObjNumber(obj) isObjectType(NTypeNumber)
#define setObjString(obj) setObjectType(obj, NTypeString)
#define isObjString(obj) isObjectType(NTypeString)

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