#ifndef _NOBJECT_HEAD
#define _NOBJECT_HEAD

#define NTypeNull      0
#define NTypeNumber    1
#define NTypeString    2
#define NTypeFunction  3
#define NTypeObject    4

#define StackSize 1024   ///定义默认栈大小

///数字类型
typedef float NNumber;
///字符串类型
typedef struct NString
{
	char buf[1024];
	int nsize;
}NString;

///////////////////////////////////对象//////////////////////////////////////////////
typedef struct NObject
{
	union
	{
		NNumber number;
		NString string;
	}Value;

	int ttype;  ///对象类型

}NObject;

#define setObjNumber(obj) setObjectType(obj, NTypeNumber)
#define isObjNumber(obj) isObjectType(NTypeNumber)
#define setObjString(obj) setObjectType(obj, NTypeString)
#define isObjString(obj) isObjectType(NTypeString)

extern void setObjectType(NObject obj, int type);
extern int isObjectType(NObject obj, int type);
extern void setObjTo2(NObject *obj, NObject *other);
///////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////虚拟机的栈///////////////////////////////////////////
typedef struct NStack
{
	NObject *stack[StackSize];			 ///栈空间
	NObject **currIndex;                 ///当前栈顶位置
}NStack;

extern void initStack(NStack *);
extern void pushStack(NStack *, NObject *obj);
extern NObject *popStack(NStack *);
///////////////////////////////////////////////////////////////////////////////////////

#endif