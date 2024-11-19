#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ord.h"

// Função auxiliar para trocar duas posições de um vetor.
void swap(int *xp, int *yp){
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

// Algoritmo de ordenação simples BubbleSort implementado.
void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for(i = 0; i < n-1; i++){
        swapped = false;
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] < arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
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