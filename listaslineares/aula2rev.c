#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int chave;
    int valor;
}lista;

int busca1(int tam, lista L[], int x){
    int busca1 = -1;
    int i = 0;

    while(i < tam){
        if(L[i].chave == x){
            busca1 = i;
            i = tam + 1;
        }else{
            i++;
        }
    }
    
    return busca1;
}

int busca2(int tam, lista L[], int y){
    int busca2 = -1;
    int i = 0;
    L[tam + 1].chave = y;

    while(L[i].chave != y){
        i++;
    }
    if(i != tam + 1){
        busca2 = i;
    }

    return busca2;
}

int main(){
    int tam = 10;
    lista L[tam];

    for(int i = 0; i < tam; i++){
        L[i].chave = i;
        L[i].valor = 10 + i + i;
    }

    printf("\nVetor Completo: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", L[i].valor);
    }

    int x = 0;
    printf("\nInsira a chave do número que você deseja encontrar no vetor: ");
    scanf("%d", &x);

    int num_Encontrado = busca1(tam, L, x);

    if(num_Encontrado != -1){
        printf("\nO número correspondente a chave escolhida é: %d\n", L[num_Encontrado].valor);
    }else{
        printf("\nNão existe nenhum algarismo com a chave correspondente no vetor!\n");
    }

    int y = 0;
    printf("\nAlgoritmo 2 - Insira a chave do número que você deseja encontrar no vetor: ");
    scanf("%d", &y);
    int num_Encontrado2 = busca2(tam, L, y);

     if(num_Encontrado2 != -1){
        printf("\nO número correspondente a chave escolhida é: %d\n", L[num_Encontrado2].valor);
    }else{
        printf("\nNão existe nenhum algarismo com a chave correspondente no vetor!\n");
    }

    return 0;
}