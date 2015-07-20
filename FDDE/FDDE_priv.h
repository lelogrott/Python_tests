#include "FDDE.h"


typedef struct noFDDE
{void *dados;
 struct noFDDE *prox;
 struct noFDDE *ant;
}NoFDDE,*pNoFDDE;

typedef struct FDDE
{ int tamInfo;
  pNoFDDE fila;
}FDDE;

