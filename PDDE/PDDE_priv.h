#include "PDDE.h"


typedef struct noPDDE
{void *dados;
 struct noPDDE *abaixo;
 struct noPDDE *acima;
}NoPDDE,*pNoPDDE;

typedef struct PDDE
{ int tamInfo;
  pNoPDDE topo;
}PDDE;

