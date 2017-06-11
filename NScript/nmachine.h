#ifndef _NMACHINE_HEAD
#define _NMACHINE_HEAD

#include "nobject.h"
#include "nlex.h"
#include "nhashtable.h"
#include "nvm.h"
#include "nstring.h"

typedef struct NMachine
{
	NFile m_file;			      //文件对象
	NLex m_nLex;			      //词法分析对象
	NStack stack;			      //堆栈
							      //
	NTable m_table;			      //全局对象表格
	NTableStr strTable;           //全局字符串
}NMachine;

extern NMachine *newMachine();
extern void initMachine(NMachine *machine);

#endif
