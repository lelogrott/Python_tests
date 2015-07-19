#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

#define FRACASSO 0
#define SUCESSO 1

#define NAO 0
#define SIM 1



typedef struct PDDE *pPDDE, **ppPDDE;

int cria(ppPDDE pp, int tamInfo);

/*************** Empilha NO TOPO A PARTIR DO ENDEREÇO FORNECIDO PELO O CHAMADOR **************/

int insere(pPDDE p, void *novo);
/*************** RETORNA O TAMANHO DA PILHA **************/
int tamanho(pPDDE p);

/*************** RETORNA A PILHA À CONDIÇÃO "VAZIA" **************/
int reinicia(pPDDE p);


int testaSeVazia(pPDDE p);

void destroi(ppPDDE pp);

/*************** BUSCA NO TOPO E COPIA ITEM P/ O CHAMADOR **************/
int busca(pPDDE p, void *reg);

/*************** Desempilha E COPIA ITEM REMOVIDO P/ O CHAMADOR **************/
int removeElemento(pPDDE p, void *reg);

