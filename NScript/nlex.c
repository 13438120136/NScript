#include "nlex.h"
#include <ctype.h>

char *nlex_token[] = {"if", "for", "while"};

char preReadChar(NLex *lex)
{
	NFile *file = lex->nFile;

	char *result = filePreRead(file, 1);
	if (result == NULL)
		return EOF;

	return *result;
}

char readChar(NLex *lex)
{
	NFile *file = lex->nFile;
	return fileGetChar(file);
}

void resetToken(NLex *lex)
{
	lex->tokenSize = 0;
}

void saveChar(NLex *lex, char ch)
{
	lex->tokenBuffer[lex->tokenSize++] = ch;
}

static void readString(NLex *lex)
{
	while (1)
	{
		char ch = readChar(lex);

		if (ch == '"')
		{
			lex->tokenType = T_STRING;
			break;
		}

		saveChar(lex, ch);
	}
}

static void readNumber(NLex *lex)
{
	while (1)
	{
		char ch = readChar(lex);

		if (!isalnum(ch))
		{
			lex->tokenType = T_NUMBER;
			break;
		}

		saveChar(lex, ch);
	}
}

static void readName(NLex *lex)
{
	while (1)
	{
		char ch = readChar(lex);

		if (!isalpha(ch) && !isalnum(ch))
		{
			lex->tokenType = T_NAME;
			break;
		}

		saveChar(lex, ch);
	}
}

void readToken(NLex *lex)
{
	resetToken(lex);

	while (1)
	{
		///¶ÁÈ¡×Ö·û
		char ch = readChar(lex);

		switch(ch)
		{
		case ' ':
			break;
		case '\r':
		case '\n':
			break;
		case EOF:
			{
				lex->tokenType = T_EOF;
				return ;
			}
		case '<':
			{
				ch = preReadChar(lex);
				if (ch == '=')
				{
					readChar(lex);
					lex->tokenType = T_LE;
				}
				else
					lex->tokenType = T_LT;
				return ;
			}
		case '>':
			{
				ch = preReadChar(lex);
				if (ch == '=')
				{
					readChar(lex);
					lex->tokenType = T_GE;
				}
				else
					lex->tokenType = T_GT;
				return ;
			}
		case '=':
			{
				ch = preReadChar(lex);
				if (ch == '=')
				{
					readChar(lex);
					lex->tokenType = T_EQ;
				}
				else
					lex->tokenType = T_COPY;
				return ;
			}
		case '"':
			{
				readString(lex);
				return ;
			}
		case '0': case '1': case '2': case '3': 
		case '4': case '5': case '6': case '7':
		case '8': case '9':
			{
				saveChar(lex, ch);
				readNumber(lex);
				return ;
			}
		default:
			{
				if (isalpha(ch))
				{
					saveChar(lex, ch);
					readName(lex);
					return ;
				}
			}
		}
	}
}
