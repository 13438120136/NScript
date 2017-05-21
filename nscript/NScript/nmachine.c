#include "nmachine.h"
#include <stdlib.h>

NMachine *newMachine()
{
	NMachine *mac = (NMachine *)malloc(sizeof(NMachine));
	initMachine(mac);

	return mac;
}

void initMachine(NMachine *machine)
{
	machine->m_nLex.nFile = &machine->m_file;

	initNTable(&machine->m_table);
}
