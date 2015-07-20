#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define FRACASSO 0
#define SUCESSO 1
#define SIM 1
#define NAO 0


typedef struct FDDE *pFDDE, **ppFDDE;

int cria(ppFDDE pp, int tamInfo);

int insere(pFDDE p, void *novo);

int tamanho(pFDDE p);
void reinicia(pFDDE p);
void destroi(ppFDDE pp);

int buscaNoFim(pFDDE p, void *reg);
int buscaNoInicio(pFDDE p, void *reg);


int remove_(pFDDE p, void *reg);

int testaVazia(pFDDE p);
