#include "string.h"
#define Maxitem 10
#define Tamitem 20
typedef char tpLista[Maxitem][Tamitem];

tpLista L1;

void criaLista(tpLista l)
{
int i;
for (i=0; i<Maxitem; i++)
l[i][0] = '\0';
}

void insereLista(tpLista l, char *item)
{
int i;
for(i=0; i<Maxitem && strlen(l[i])>0; i++);
if (i<Maxitem)
strcpy(l[i], item);
else
printf("Lista cheia, não pode inserir");
}

void imprimeLista(tpLista l)
{
int i;
printf("\nItens da lista\n");
for(i=0; i<Maxitem && strlen(l[i])>0; i++)
printf("\n%s", l[i]);
}

void retiraLista(tpLista l, char *item)
{
int i;
for(i=0; i<Maxitem && strlen(l[i])>0 &&
(strcmp(l[i],item) != 0); i++);
if (i<Maxitem && (strcmp(l[i],item) == 0))
{ // Encontrou o elemento buscado
printf("\nItem (%s) encontrado, removendo", item);
if (i < (Maxitem-1))
{ // Tem elementos depois dele, puxa para cima
for (;i<(Maxitem-1) && strlen(l[i])>0;i++)
strcpy(l[i],l[i+1]);
}
// Zera o último elemento do espaço da lista
l[Maxitem-1][0] = '\0';
}
else // Não encontrou o elemento buscado
printf("\nItem (%s) não encontrado",item);
}

int contaLista(tpLista l)
{
int i;
for (i=0; i<Maxitem && strlen(l[i])>0; i++);
return(i);
}

int main(){
    switch ()
    {
    case constant expression:
        /* code */
        break;
    
    default:
        break;
    }

}
