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
	T_NAME = 1,		   ///普通单词
	T_NUMBER,		   ///单词为数字
	T_STRING,		   ///单词为字符串
	T_ADD,			   ///加
	T_SUB,			   ///减
	T_MUL,			   ///乘
	T_DIV,			   ///除
	T_MOD,			   ///求余数
	T_LT,              ///小于
	T_LE,			   ///小于等于
	T_GT,			   ///大于
	T_GE,			   ///大于等于
	T_EQ,			   ///等于
	T_COPY,            ///赋值运算
	T_EOF        	   ///文件结束符
};

extern char *nlex_token[];

typedef struct NLex
{
	NFile *nFile;

	char tokenBuffer[LEX_SIZE];   ///分析当前单词
	int tokenSize;                ///单词包含字符个数
	enum TokenType tokenType;     ///单词的类型
}NLex;

///从文件中读取一个单词
extern void readToken(NLex *lex);
///复位状态
extern void resetToken(NLex *lex);
///保存单词
extern void saveChar(NLex *lex, char ch);
///预读一个字符
extern char preReadChar(NLex *lex);
///读取一个字符
extern char readChar(NLex *lex);

#endif
