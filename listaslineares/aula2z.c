#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int chave;
    int valor;
}lista;

// Alocação Sequencial - Lista Ordenada - 1º Método

/* Consiste basicamente no mesmo conceito aplicado na 2º forma anterior, adicionar artificalmente a chave desejada fora do vetor, realizando comparações
entre essa posição criada e as existentes originalmente no vetor.*/
int busca_ord(int TAM, lista L[], int x){
    int i = 0;
    int busca_ord = -1;
    L[TAM + 1].chave = x;

    while(L[i].chave < x){
        i++;
    }
    if(L[i].chave == x){
        busca_ord = i;
    }

    return busca_ord;
}
int main(){
    int TAM = 10;
    lista L[TAM];

    // Preenchendo o vetor com as chaves e valores correspondentes.
    for(int i = 0; i < TAM; i++){
        L[i].chave = i;
        L[i].valor = 10 + i;
    }

    printf("\nVetor Completo: ");
    for(int i = 0; i < TAM; i++){
        printf("%d ", L[i].valor);
    }

    int x = 0;
    printf("\nDigite a chave do número que você deseja encontrar no vetor: ");
    scanf("%d", &x);

    int num_Encontrado1 = busca_ord(TAM, L,x);
    if(num_Encontrado1 != -1){
        printf("\nO algarismo encontrado no vetor foi: %d\n", L[num_Encontrado1].valor);
    }else{
        printf("\nNão existe nenhum número no vetor associado a chave desejada!\n");
    }

    return 0;
}