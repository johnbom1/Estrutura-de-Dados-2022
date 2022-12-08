/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//Criando a estrutura
typedef struct Lista{
    int info;
    struct Lista *prox; 
}Lista; 
//função para criar um novo nó.
Lista *criaNO (int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista)); // número de bytes que precisa para alocar para um tipo Lista.
    if(novo != NULL){ //if(novo)
        novo -> info = valor;
        novo -> prox = NULL;
    }
    else{
        printf("\nFalha de alocacao de moemoria");
        exit(1); //sai do programa
        }
    return novo;
}
// Função recursiva que imprime os elementos da Lista.
void imprimeRec(Lista *prim){
    if(prim){
        printf(" %d ", prim->info);
        imprimeRec(prim->prox);
    }
}
// QESTÃO 1)
// Função que insere um elemento no fim da Lista.
Lista *insereFim(Lista *prim, int valor){
    Lista *aux;
    Lista *novo = criaNO(valor);
    if (prim == NULL){
        prim = novo;
    }
    else{
        aux = prim;
        while(aux->prox)
            aux = aux->prox;
        aux->prox = novo;
    }
    return prim;
}

// QESTÃO 2)
// Função que insere um elemento na lista e à mantêm ordenada.
Lista *insereOdenada(Lista *prim, int valor){
    Lista *aux;
    Lista *novo = criaNO(valor);
    if (prim == NULL){
        prim = novo;
    }
    else if(novo->info < prim->info){
        novo->prox = prim;
        prim = novo;
    }
    else{
        aux = prim;
        while(aux->prox && novo->info > aux->prox->info)
            aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    return prim;
}
    
int main(){
    Lista *prim = NULL; //Cirando uma Lista vazia
    prim = insereOdenada(prim, 12);
    prim = insereOdenada(prim, 5);
    prim = insereOdenada(prim, 9);
    prim = insereOdenada(prim, 22);
    
    imprimeRec(prim);
    
    return 0;
}
