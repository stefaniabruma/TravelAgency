#include <stdio.h>
#include "UI.h"
#include "TESTING.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	testeDomain();
	testeValidator();
	testeRepository();
	testeService();
	printf_s("Teste rulate cu succes!\n");
	
	userInt ui = creeazaUI();
	
	while (1)
	{
		menu();
		int cmd = getComanda();
		ruleaza(&ui, cmd);
		if (cmd == 0)
		{
			distrugeUi(&ui);
			_CrtDumpMemoryLeaks();
			return 0;
		}
	}
	return 0;
}