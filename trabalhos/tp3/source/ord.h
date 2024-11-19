#ifndef ORD_H

#define ORD_H

void swap(int *xp, int *yp); // Função auxiliar para trocar duas posições de um vetor.
void bubbleSort(int arr[], int n); // Algoritmo de ordenação BubbleSort - Ordenação simples.

void merge(int arr[], int l, int m, int r); // Função recursiva que será usada no algoritmo MergeSort.
void mergeSort(int arr[], int l, int r); // Algoritmo de ordenação MergeSort - Ordenação Ótima.

#endif