#ifndef _NMACHINE_HEAD
#define _NMACHINE_HEAD

#include "nobject.h"
#include "nlex.h"
#include "nhashtable.h"
#include "nvm.h"

typedef struct NMachine
{
	NFile m_file;			//�ļ�����
	NLex m_nLex;			//�ʷ���������
	NStack stack;			//��ջ
							//
	NTable m_table;			//ȫ�ֱ��
}NMachine;

extern NMachine *newMachine();
extern void initMachine(NMachine *machine);

#endif
