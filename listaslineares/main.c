#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int chave;
    int valor;
}ListaL;

// Algoritmo 1 de Busca em uma Lista Linear (Percorrendo o Vetor Normalmente) - Alocação Sequencial
//     A ideia consiste em percorrer o vetor normalmente, interrompendo a busca assim que o elemento é encontrado.
int busca1(ListaL lista[], int tam, int x)
{
    int i = 0;
    int busca1 = 0;

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

// Algoritmo 2 de Busca em uma Lista Linear (Inserindo o Elemento Desejado por Fora do Vetor) - Alocação Sequencial
//  A ideia consiste em inserir o elemento desejado por fora do vetor, e interromper a busca no vetor assim que encontrar o elemento na posição correta
//      Retornando 0 caso o elemento não esteja presente no vetor.
int busca2(ListaL lista[], int tam, int x)
{   
    int i = 0;
    int busca2 = 0;
    lista[tam + 1].chave = x;
   

    while(lista[i].chave != x){
        i++;
    }
    if(i != tam + 1){
        busca2 = i;
    }else{
        busca2 = 0;
    }

    return busca2;
}

int main()
{
    // Programa para exemplificar Listas Lineares - Alocação de Memória Sequencial
    int tam = 10;
    ListaL lista[tam];
    srand(time(NULL));
    
    // Adicionando chaves (Identificador de cada Vetor)
    for(int i = 0; i < tam; i++){
        lista[i].chave = i;
    }

    // Adicionando um valor a cada posição do vetor 
    for(int i = 0; i < tam; i++){
        lista[i].valor = rand()%100;
    }   

    // Exibindo o Vetor Completo
    printf("\nVetor Completo: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", lista[i].valor);
    }

    // Introduzindo Algoritmos de Busca no vetor
    int x = 0;
    printf("\nEscolha a posição do elemento que você deseja encontrar: ");
    scanf("%d",&x);

    // Algoritmo 1 - Alocação Sequencial
    busca1(lista, tam, x);
    printf("\nO Elemento na posição encontrada é: %d", lista[x].valor);

    // Algoritmo 2 - Alocação Sequencial
    int y = 0;
    printf("\nEscolha a posição do elemento que você deseja encontrar: ");
    scanf("%d",&y);
    printf("\nO Elemento na posição encontrada é: %d", lista[y].valor);




    return 0;
}