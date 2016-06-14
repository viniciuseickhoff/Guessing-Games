#include "includes.h"

int initGameMode()
{
	LANG *lang;
	srand(time(NULL));
	int x = rand()%100 + 1	
	int resp;
	while(true){
	display(lang-> ola);
	display(lang -> primeiraguess);
	scanf("%d", resp);
		if (resp == x)
		{
			display(lang-> consegui);
			break;
		}
	}
	return 0;
}
