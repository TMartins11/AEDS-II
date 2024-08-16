#include <stdio.h>
#include <stdlib.h>

int main(){
    int num_linhas = 7;
    int num_colunas = 7;
    int **pont;

    pont = malloc(num_linhas * sizeof(int *));

    for(int i = 0; i < num_linhas; i++){
        pont[i] = malloc(num_colunas * sizeof(int));
        for(int j = 0; j < num_colunas; j++){
            pont[i][j] = i + j;
        }
    } 

    for(int i = 0; i < num_linhas; i++){
        for(int j = 0; j < num_colunas; j++){
            printf("%4d", pont[i][j]);
        }
        printf("\n");
    } 


    return 0;
}