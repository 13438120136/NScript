#ifndef _NLEX_HEAD
#define _NLEX_HEAD

#include "nfile.h"

#define LEX_SIZE 64

enum nLexKey
{
	KeyNone, KeyIF, KeyFor, KeyWhile, KeyBreak, KeyContinue, KeyReturn,
};

enum TokenType
{
	T_NAME = 1,		   ///��ͨ����
	T_NUMBER,		   ///����Ϊ����
	T_STRING,		   ///����Ϊ�ַ���
	T_ADD,			   ///��
	T_SUB,			   ///��
	T_MUL,			   ///��
	T_DIV,			   ///��
	T_MOD,			   ///������
	T_LT,              ///С��
	T_LE,			   ///С�ڵ���
	T_GT,			   ///����
	T_GE,			   ///���ڵ���
	T_EQ,			   ///����
	T_COPY,            ///��ֵ����
	T_EOF        	   ///�ļ�������
};

extern char *nlex_token[];

typedef struct NLex
{
	NFile *nFile;

	char tokenBuffer[LEX_SIZE];   ///������ǰ����
	int tokenSize;                ///���ʰ����ַ�����
	enum TokenType tokenType;     ///���ʵ�����
}NLex;

///���ļ��ж�ȡһ������
extern void readToken(NLex *lex);
///��λ״̬
extern void resetToken(NLex *lex);
///���浥��
extern void saveChar(NLex *lex, char ch);
///Ԥ��һ���ַ�
extern char preReadChar(NLex *lex);
///��ȡһ���ַ�
extern char readChar(NLex *lex);

#endif
