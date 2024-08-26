#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int chave;
    int valor;
}L;

// Alocação Sequencial - Busca de um elemento na lista L.

/* A ideia consiste em percorrer o vetor completo em busca do elemento com a chave desejada, iterando sobre o contador i conforme são verificados os números
ou é encontrado diretamente o algarismo desejado. *Modifiquei para que retornasse -1 caso o número não seja presente no vetor, não divergir com posição 0.*/

int busca1(int tam, L lista[], int x){
    int i = 0;
    int busca1 = -1;

    while(i <= tam){
        if(lista[i].chave == x){
            busca1 = i;
            i = tam + 1;
        }else{
            i++;
        }
    }

    return busca1;
}

// Alocação Sequencial - Busca de um elemento na Lista L (2º Método).

/* Consiste em adicionar a chave desejada uma posição à frente do limite de casas do vetor, após isso, comparar todas as posições do vetor com essa nova
que acabou de ser criada, retornando o elemento associado originalmente a ela caso seja encontrada e matendo busca = -1 caso o elemento só exista com nossa
criação e inserção dele fora do vetor.*/

int busca2(int tam, L lista[], int y){
    int i = 0;
    int busca2 = -1;
    lista[tam + 1].chave = y;
    
    while(lista[i].chave != y){
        i++;
    }
    if(i != tam + 1){
        busca2 = i;
    }

    return busca2;
}

int main(){
    int tam = 10;
    L lista[tam];

    for(int i = 0; i < tam; i++){
        lista[i].chave = i;
        lista[i].valor = 10 + i + i;
    }

    printf("\nVetor Completo: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", lista[i].valor);
    }

    int x = 0;
    printf("\nInsira a chave do elemento que você deseja encontrar no vetor: ");
    scanf("%d", &x);

    int num_Encontrado = busca1(tam,lista,x);
    if(num_Encontrado != -1){
        printf("\nO número encontrado foi: %d\n", lista[num_Encontrado].valor);
    }else{
        printf("\nNão existe nenhum algarismo no vetor com a chave desejada!\n");
    }

    int y = 0;
    printf("\nAgora, testando o 2 algoritmo de busca:");
    printf("\nInsira a chave do elemento que você deseja encontrar no vetor: ");
    scanf("%d", &y);
    int num_Encontrado2 = busca2(tam,lista,y);
    if(num_Encontrado2 != -1){
        printf("\nO número encontrado foi: %d", lista[num_Encontrado2].valor);
    }else{
        printf("\nNão existe nenhum algarismo no vetor com a chave desejada!");
    }

    return 0;
}