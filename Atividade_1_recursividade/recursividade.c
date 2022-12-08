/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

// 1) Seja A um vetor de inteiros. Apresente algoritmos recursivos para calcular:
// a) O elemento máximo do vetor:

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

// b) O elemento mínimo do vetor:

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

// c) a soma dos elementos do vetor:

int vSoma(int v[],int tamanho){
    if(tamanho == 0)
        return 0;
    else
        return v[tamanho-1] + vSoma(v, tamanho-1);
}

// d) o produto dos elementos do vetor:

int vProduto(int v[],int tamanho){
    if(tamanho == 0)
        return 1;
    else
        return v[tamanho-1] * vProduto(v, tamanho-1);
}

// e)  a média dos elementos do vetor:

float vMedia(int v[], int tamanho, int soma, float aux){
    if(tamanho == 0)
        return soma / aux;
    else
        return vMedia(v, tamanho-1, soma + v[tamanho-1], aux += 1);
}
int X (int n) {
   if (n == 1 || n == 2) return n;
   else return X(n-1) + n * X(n-2);
}

// 3) Escreva uma função recursiva que imprima os elementos de um vetor
// v[0..n-1] ao contrário, ou seja, primeiro v[n-1], depois v[n-2]
// e assim por diante. Para que valores de n o problema faz sentido?

void vInverso(int v[], int tamanho){
    if (tamanho > 0){
        printf("%d, ", v[tamanho-1]);
        vInverso(v, tamanho-1);
    }
}

// 4) Escreva uma função recursiva que receba um inteiro positivo N
// e devolva o número [log2 N], ou seja, o piso do logaritmo de N
// na base 2.

int vLog(int n){
    if (n == 1)
        return 0;
    else
        return vLog(n/2) + 1;
}

// 5) Escreva uma função recursiva que receba um inteiro positivo
// n e devolva a soma dos dígitos decimais de n
// (a soma dos valores absolutos dos algarismos).
//  Por exemplo, ao receber 1729 sua função deve devolver 19 = 1+7+2+9.
int somaDecimais(int n){
    if(n == 0)
        return 0;
    else
        return (n %10 ) + somaDecimais(n / 10);
}


int main() {
    // VETOR PARA TODAs As QUESTÕES.
    int vetor[] = {2,8,5,3,10};

    //QUESTÃO 1
    printf("QUESTAO 01) Seja A um vetor de inteiros. Apresente algoritmos recursivos para calcular: \n\n");
    printf("Vetor: [2,8,5,3,10]\n\n");

    // LETRA A
    printf("a) O elemento maximo do vetor;\n\n");
    printf("Resposta: %d\n", vMaior(vetor, 5, 0));

    // LETRA B
    printf("\nb) O elemento minimo do vetor;\n\n");
    printf("Resposta: %d\n", vMenor(vetor, 5, 0));

    // LETRA C
    printf("\nc) A soma dos elementos do vetor;\n\n");
    printf("Resposta: %d\n", vSoma(vetor, 5));

    // LETRA D
    printf("\nd) o produto dos elementos do vetor;\n\n");
    printf("Resposta: %d\n", vProduto(vetor, 5));

    // LETRA E
    printf("\ne) A média dos elementos do vetor.\n\n");
    printf("Resposta: %.2f\n\n", vMedia(vetor, 5, 0, 0));

    //QUESTÃO 2
    printf("\nQUESTAO 02) Qual o valor de X(5)?\n");
    printf("Sendo: \n");
    printf("int X (int n) { \n");
    printf("  if (n == 1 || n == 2) return n;\n");
    printf("else return X(n-1) + n * X(n-2);\n");
    printf("}\n\n");

    printf("Resposta: %d\n", X(5));

    //QUESTÃO 3
    printf("\nQUESTAO 03) Escreva uma função recursiva que imprima os elementos \nde um vetor v[0..n-1] ao contrário, ou seja, \nprimeiro v[n-1], depois v[n-2] e assim por diante. \nPara que valores de n o problema faz sentido?\n\n");
    printf("Resposta: ");
    vInverso(vetor, 5);
    printf("\n\n");



    // QUESTÃO 4

    // DEBUGANDO O CÓDIGO
    // log(31) = log(15) +1 // 3+1 = 4
    // log(15) = log(7) +1 // 2+1 = 3
    // log(7) = log(3) +1 // 1+1 = 2
    // log(3) = log(1) +1 // = 0+1 = 1
    // log(1) = 0
    int n = 31;
    printf("\nQUESTAO 04: Escreva uma função recursiva que receba um inteiro positivo N\ne devolva o número ⌊log2 N⌋, ou seja, o piso do logaritmo de N na base 2.\n");
    printf("Sendo N = 31\n\n");
    printf("Resposta: %d\n",vLog(n));

    // QUESTÃO 5

    // DEBUGANDO O CÓDIGO
    // 1729 / 10 = 172,9 (resto = 9) // 9 + f(172) = 19
    // 172 / 10 = 17,2 (resto = 2) // 2 + f(17) = 10
    // 17 / 10 = 1,7 (resto = 7) // 7 + f(1) = 8
    // 1 / 10 = 0,1 (resto = 1) // 1+ f(0) = 1
    // 0 - retorna 0
    printf("\nQUESTAO 05: Escreva uma função recursiva que receba um inteiro positivo n\ne devolva a soma dos dígitos decimais de n(a soma dos valores absolutos dos algarismos).\nPor exemplo, ao receber 1729 sua função deve devolver 19 = 1+7+2+9.\n\n");
    int p = 25987;
    printf("usando %d como paramentro...\n\n",p);
    printf("Resposta: %d\n", somaDecimais(p));

    return 0;
}
