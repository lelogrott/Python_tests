#include "FDDE_priv.h"

/*************** CRIA ***************/
int cria(ppFDDE pp, int tamInfo)
{   	int ret = FRACASSO;
	if(((*pp)=(pFDDE)malloc(sizeof(FDDE)))==NULL)
		ret = FRACASSO;
	else
	{	(*pp)->fila=NULL;
        	(*pp)->tamInfo=tamInfo;
        	ret = SUCESSO;
	}
    	return ret;
}


/*************** INSERE NA CAUDA ***************/
int insere(pFDDE p, void *novo)
{  	pNoFDDE temp, aux;
   	int ret = FRACASSO;
	if((temp=(pNoFDDE)malloc(sizeof(NoFDDE)))!= NULL)
	{ if((temp->dados = (void *) malloc(p->tamInfo))!=NULL)
     		{   	memcpy(temp->dados,novo,p->tamInfo);
        	 	temp->prox = NULL;
		 	if(p->fila==NULL)
			 {	p->fila=temp;
        			temp->ant=NULL;
		 	 }
		 	else
		 	{	aux=p->fila;
				while(aux->prox!=NULL)
					aux=aux->prox;
				aux->prox=temp;
				temp->ant=aux;
		 	}
         		ret = SUCESSO;
     		}
     		else
      			free(temp);
   	}
   	return ret;
}


/*************** REMOVE DA FRENTE ***************/
int remove_(pFDDE p, void *reg)
{  	int ret = FRACASSO;
	if(p->fila != NULL)
	{  	memcpy(reg,p->fila->dados,p->tamInfo);
      		free(p->fila->dados);
		if(p->fila->prox==NULL)
		{  	free(p->fila);
			p->fila=NULL;
		}
		else
	      	{	p->fila=p->fila->prox;
			free(p->fila->ant);
			p->fila->ant=NULL;
	      	}
      		ret = SUCESSO;
	}
	return ret;
}



/*************** BUSCA NA FRENTE ***************/
int buscaNoInicio(pFDDE p, void *reg)
{  int ret = FRACASSO;
   if(p->fila != NULL)
	{ 	memcpy(reg,p->fila->dados,p->tamInfo);
      		ret = SUCESSO;
	}
   return ret;
}

/*************** VAZIA? ***************/
int testaVazia(pFDDE p)
{  
   if(p->fila == NULL)
		return SIM;
   else
	return NAO;
}

/*************** BUSCA NA CAUDA ***************/
int buscaNoFim(pFDDE p, void *reg)
{	pNoFDDE aux;
	int ret = FRACASSO;
	if(p->fila != NULL)
	{ aux=p->fila;
	  while(aux->prox!=NULL)
      		  aux=aux->prox;
	  memcpy(reg,aux->dados,p->tamInfo);
      	  ret = SUCESSO;
	}
  	return ret;
}


/*************** TAMANHO ***************/
int tamanho(pFDDE p)
{ int tam=0;
  pNoFDDE aux;
  aux=p->fila;
  if(aux==NULL)
    tam=0;
  else
  { while(aux!=NULL)
    { 	aux=aux->prox;
	tam++;
    }
  }
  return tam;
}

/*************** PURGA ***************/
void reinicia(pFDDE p)
{	if(p->fila != NULL)
	{	while(p->fila->prox != NULL)
		{	p->fila=p->fila->prox;
         		free(p->fila->ant->dados);
		 	free(p->fila->ant);
		}
	   	free(p->fila->dados);
	     	free(p->fila);
      		p->fila = NULL;
	}
}

/*************** DESTROI ***************/
void destroi(ppFDDE pp)
{
	reinicia(*pp);
	free(*pp);
   	(*pp)=NULL;
}


