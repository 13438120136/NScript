#ifndef _NSTRING_HEAD
#define _NSTRING_HEAD

///�ַ�������
typedef struct NString
{
	int nsize;			 //��ǰ�ַ�������
	char buf[1];		 //ʵ���ַ������׵�ַ
}NString;

NString *strNewString(char *str, int size);

#endif
