#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ord.h"

// Tamanho máximo de cada campo na struct.  
#define MAX_STRING 100

// Variáveis globais para contagem durante ordenação.
unsigned long long comparacoes = 0;
unsigned long long trocas = 0;

// Função auxiliar para trocar duas posições de um vetor.
void trocar(Jogador *a, Jogador *b){
    Jogador tmp = *a;
    *a = *b;
    *b = tmp;
    trocas++;
}

// Função auxiliar para comparar lexicamente duas strings, indicando a ordem alfabética entre elas.
int comparar(const char *str1, const char *str2){
    comparacoes++; // Incrementando o número de comparações.

    // Verificando qual string é lexicamente maior que a outra.
    while(*str1 && *str2){
        if(*str1 != *str2){
            return(*str1 - *str2);
        }
        // Iterando o ponteiro pra próxima letra das strings.
        str1++;
        str2++;
    }

    // Retornando o resultado. Que será utilizado para fazer as trocas nos algoritmos de ordenação.
    return (*str1 - *str2);
}

// Algoritmo de ordenação simples BubbleSort implementado.
void bubbleSort(Jogador *jogador, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(comparar(jogador[j].nome, jogador[j+1].nome) > 0){
                trocar(&jogador[j], &jogador[j+1]);
            }
        }
    }
}

// Função auxiliar que será chamada recursivamente no MergeSort.
void merge(int arr[], int l, int m, int r){
    int dimL = m - l + 1;
    int dimR = r - m;

    int L[dimL], R[dimR];

    int i,j,k;
    for(i = 0; i < dimL; i++){
        L[i] = arr[l+i];
    }

    for(j = 0; j < dimR; j++){
        R[j] = arr[m+1+j];
    }

    i = 0, j = 0, k = l;

    while(i < dimL && j < dimR){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
            k++;
        }else{
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while(i < dimL){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < dimR){
        arr[k] = R[j];
        j++;
        k++;
    }

}
// Algoritmo de ordenação ótimo MergeSort implementado.
void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}