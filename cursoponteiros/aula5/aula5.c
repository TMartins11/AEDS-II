#include <stdio.h>
#include <stdlib.h>

// Relação entre ponteiros e dimensões.
int main(){
    int num_linhas = 2;
    int num_colunas = 4;
    
    // Declaramos um double pointer para armazenar os endereços onde serão guardados os endereços dos espaços alocados para conter as linhas da matriz.
    //  Tal "confusão" é necessária, pois uma matriz é bidimensional. Logo, o double pointer aponta para  endereço onde fica o endereço do espaço alocado pra 1º linha.
    int **pont;
    pont = malloc(num_linhas * sizeof(int *));

    // Com esse laço de repetição inicial, reservamos no espaço apontado pelo ponteiro o endereço para alocar o tamanho das colunas da matriz.
    //  Pode parecer confuso, mas é basicamente "outro ponteiro" para as colunas.
    for(int i = 0; i < num_linhas; i++){
        *(pont + i) = malloc(num_colunas * sizeof(int));
        for(int j = 0; j < num_colunas; j++){
            // Aqui, conferimos valores para os elementos da matriz, apontando o endereço (pont + i) e depois apontando de novo o endereço (pont + i) + j.
            *(*(pont + i) + j) = i + j;
        }
    }

    // Imprimir a matriz na tela
    for(int i = 0; i < num_linhas; i++){
        for(int j = 0; j < num_colunas; j++){
            printf("%4d", *(*(pont + i) + j));
        }
        printf("\n");
    }

    // LEMBRE-SE, para cada malloc, devemos ter um free, evitar erro de segmentação e ocupação desnecessária da memória.
    for(int i = 0; i < num_linhas; i++){
        free(*(pont + i));
    }
    free(pont);

    // Note que devemos liberar primeiro o espaço das colunas e depois o das linhas.

    return 0;
}