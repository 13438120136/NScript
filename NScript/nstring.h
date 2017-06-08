#ifndef _NSTRING_HEAD
#define _NSTRING_HEAD

///字符串类型
typedef struct NString
{
	int nsize;			 //当前字符串长度
	char buf[1];		 //实际字符串的首地址
}NString;

NString *strNewString(char *str, int size);

#endif
