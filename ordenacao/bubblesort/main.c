#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função auxiliar para trocar duas posições de um vetor.
void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para conferir se um número já existe no vetor.
int exists(int arr[], int x, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return 1;
    }

    return 0;
}

// Algoritmo de Ordenação BubbleSort.
void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // Se não houve a troca de elementos
        if (!swapped)
            break;
    }
}

// Função auxiliar para imprimir o vetor após ordenação.
void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d  ", arr[i]);
    }
}

int main(){
    // Definindo o tamanho do vetor.
    int n = 10;
    int arr[n];

    // Auxiliares para contar e inserir os valores.
    int count = 0;
    int x = -1;

    // Inicializando o vetor de maneira inválida.
    for(int i = 0; i < n; i++){
        arr[i] = -69;
    }

    // Preenchendo o vetor corretamente.
     while (count < n) {
        printf("Digite um número: ");
        scanf("%d", &x);

        if (exists(arr, x, n) == 0) {
            printf("\nInserindo número no vetor!\n");
            arr[count] = x;
            count++;
        } else {
            printf("\nNúmero já existe.\n");
        }
    }

    // Imprimindo o vetor inicial.
    printf("\nVetor Inicial: ");
    print(arr,n);

    // Ordenando o vetor via BubbleSort.
    bubbleSort(arr,n);

    // Imprimindo o vetor Ordenado.
    printf("\n\nVetor Ordenado: ");
    print(arr, n);
    return 0;
}