/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc, free

typedef struct Lista{
    int info;
    struct Lista *prox; //endereço do próximo nó
}Lista;  // tipo Lista

Lista *criaNO (int valor){
    //alocar memória
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

Lista *insereIni(Lista *prim, int valor){
    Lista *novo = criaNO(valor);
    novo->prox = prim;
    prim = novo;
    
    return prim;
}

void imprime(Lista *prim){
    Lista *aux = prim;
    while (aux){ // enquanto aux diferente de null aux!NULL.
        printf(" %d ", aux->info);
        aux = aux->prox;
    }
}

void imprimeRec(Lista *prim){
    if(prim){
        printf(" %d ", prim->info);
        imprimeRec(prim->prox);
    }
}
    
int main(){
    Lista *prim = NULL; // Lista vazia
    prim = insereIni(prim, 7);
    prim = insereIni(prim, 10);
    prim = insereIni(prim, 3);
    prim = insereIni(prim, 90);
    prim = insereIni(prim, 1);
    
    imprime(prim);
    printf("\n");
    imprimeRec(prim);
    
    return 0;
}
