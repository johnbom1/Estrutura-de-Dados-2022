#include<stdio.h>
#include<stdlib.h>

// a) O elemento máximo do vetor;

int vMaior(int v[], int tamanho, int indice){
    if(tamanho == 0)
        return v[indice];
    else{
        if(v[tamanho-1] > v[indice])
            return vMaior(v, tamanho-1, tamanho-1);
        else
            return vMaior(v, tamanho-1, indice);
    }


}

// b) O elemento mínimo do vetor;

int vMenor(int v[], int tamanho, int indice){
    if(tamanho == 0)
        return v[indice];
    else{
        if(v[tamanho-1] < v[indice])
            return vMenor(v, tamanho-1, tamanho-1);
        else
            return vMenor(v, tamanho-1, indice);
    }


}

// c) a soma dos elementos do vetor;

int vSoma(int v[],int tamanho){
    if(tamanho == 0)
        return 0;
    else
        return v[tamanho-1] + vSoma(v, tamanho-1);
}

int main() {
    int vetor[10] = {10,43,983,674,74,234,767,90,83,12};

    printf("O maior elemento do vetor eh: %d\n", vMaior(vetor, 10, 0));

    printf("O menor elemento do vetor eh: %d\n", vMenor(vetor, 10, 0));

    printf("A soma dos elementos do vetor eh: %d\n", vSoma(vetor, 10));



    return 0;


}
