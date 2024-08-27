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

// Alocação Sequencial - Lista Ordenada - 2º Método - Busca Binária

/* Consiste basicamente em fazer uma busca binária pelo número correspondente a chave desejada, "partindo" o vetor no meio e movimentado para esquerda e direita
conforme for necessário, retornará -1 caso não exista número associado a chave buscada e retornará o valor desejado caso ele exista.*/

int busca_bin(int TAM, lista L[], int y){
    int busca_bin = -1;
    int i = 0;
    int meio = 0;

    while(i <= TAM){
        meio = (int)(i + TAM)/2;
        if(L[meio].chave == y){
            busca_bin = meio;
            i = TAM + 1;
        }else if(L[meio].chave < y){
            i = meio + 1;
        }else{
            TAM = meio - 1;
        }
    }

    return busca_bin;
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

    int y = 0;
    printf("\nAlgoritmo 2 - Digite a chave do número que você deseja encontrar no vetor: ");
    scanf("%d", &y);

    int num_Encontrado2 = busca_bin(TAM, L,y);
    if(num_Encontrado2 != -1){
        printf("\nO algarismo encontrado no vetor foi: %d\n", L[num_Encontrado2].valor);
    }else{
        printf("\nNão existe nenhum número no vetor associado a chave desejada!\n");
    }

    return 0;
}