#include <stdio.h>
#include "PDDE.h"

int main(){
	pPDDE pP;

	cria((&pP), sizeof(int));
	int x=7;
	insere(pP, &x);
	x=9;
	busca(pP, &x);
	printf(">>%d\n", x);

	return 0;
}
