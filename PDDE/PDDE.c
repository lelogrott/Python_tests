#include "PDDE_priv.h"

/*************** CRIA ***************/
int cria(ppPDDE pp, int tamInfo)
{   int ret = FRACASSO;
    ppDDE p1= (ppDDE)pp;
	if((*(p1))=(pPDDE)malloc(sizeof(PDDE)))==NULL)
		ret = FRACASSO;
	else
	{	*(p1)->topo=NULL;
        *(p1)->tamInfo=tamInfo;
        ret = SUCESSO;
	}
    return ret;
}

/*************** Empilha ***************/
int insere(pPDDE p, void *novo)
{  pNoPDDE temp;
   int ret = FRACASSO;
   if((temp=(NoPDDE *)malloc(sizeof(NoPDDE)))!=NULL)
   { if((temp->dados = (void *) malloc(p->tamInfo)) !=NULL )
     {   memcpy(temp->dados,novo,p->tamInfo);
 		 temp->abaixo=p->topo;
         temp->acima=NULL;
 		 if (p->topo!=NULL) // <<< caso seja a primeira inserção
 		    p->topo->acima=temp;
         p->topo=temp;
         ret = SUCESSO;
     }
     else
       free(temp);
	}
   return ret;
}


/*************** DESEMPILHA E COPIA ITEM REMOVIDO P/ O CHAMADOR **************/
int removeElemento(pPDDE p, void *reg)
{  int ret = FRACASSO;
    pNoPDDE aux=NULL;
	if(p->topo != NULL)
	{ aux=p->topo->abaixo;
	  memcpy(reg,p->topo->dados,p->tamInfo);
      free(p->topo->dados);
      free(p->topo);
	  if (aux!=NULL) // caso seja a remoção do unico item
	    aux->acima=NULL;
	  p->topo=aux;
	  ret = SUCESSO;
	}

   return ret;
}



/*************** BUSCA ***************/
int busca(pPDDE p, void *reg)
{  int ret = FRACASSO;
   if(p->topo != NULL)
	{ memcpy(reg,p->topo->dados,p->tamInfo);
      ret = SUCESSO;
	}
   return ret;
}


int testaSeVazia(pPDDE p)
{    if(p->topo != NULL)
        return NAO;
     else
        return SIM;
}


/*************** PURGA ***************/
int reinicia(pPDDE p)
{	//pNoPDDE aux=NULL;
  int cont=0;
    if(p->topo != NULL)
	{
	    while(p->topo->abaixo!= NULL)
		{

		    p->topo=p->topo->abaixo;

            free(p->topo->acima->dados);

		 	free(p->topo->acima);

            cont ++;

		}
	   free(p->topo->dados);
       free(p->topo);
       p->topo = NULL;
	}

}



/*************** DESTROI ***************/
void destroi(ppPDDE pp)
{
	reinicia(*pp);
	free(*pp);
   (*pp)=NULL;
}

/*************** Retorna o tamanho da pilha ***************/
int tamanho(pPDDE p)
{  pNoPDDE aux=NULL;
   int cont=0;
    if(p->topo != NULL)
	{ aux=p->topo;

 	    while(aux->abaixo!= NULL)
		{   cont++;
		    aux=aux->abaixo;

		}
		cont++;


	}
    return cont;
}
