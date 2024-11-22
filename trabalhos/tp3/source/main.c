#include <stdio.h>
#include <stdlib.h>
#include "ord.h"

#define MAX_STRING 50

typedef struct{
    char nome[MAX_STRING];
    char posicao[MAX_STRING];
    char naturalidade[MAX_STRING];
    char clube[MAX_STRING];
    int idade;
}Jogador;

int main(int argc, char* argv[]){
    // Conferindo se a quantidade de argumentos é válida.
    if(argc != 2){
        printf("\nA quantidade de argumentos é inválida!");
        return 1;
    }
        
    int alg = atoi(argv[1]);
    switch(alg){
        case 1:
            printf("\nO algoritmo escolhido foi BubbleSort - Ordenação Simples!\n");
            break;
        case 2:
            printf("\nO algoritmo escolhido foi MergeSort - Ordenação Ótima!\n");
            break;
        case 3:
            printf("\nO algoritmo escolhido foi Counting Sort - Ordenação em Tempo Linear!\n");
            break;
        default:
            printf("\nVocê escolheu um algoritmo inválido!\n");
            printf("\nVocê deve escolher um dos algoritmos abaixo:");
            printf("\n1 - BubbleSort - Ordenação Simples.");
            printf("\n2 - MergeSort - Ordenação Ótima.");
            printf("\n3 - Counting Sort - Ordenação em Tempo Linear.\n");
            return 1;
    }    
    
    // Abrindo o arquivo e checando se foi aberto corretamente.
    FILE *arq = fopen("jogadores.csv", "r");
    if(!arq){
        printf("\nO arquivo selecionado não existe!");
        return 1;
    }

    // Variáveis para realizar a leitura e armazenar os dados na struct.
    Jogador jogadores[1149];
    int i = 0;
    char linha[256]; // Buffer para armazenar as linhas lidas do arquivo.

    fgets(linha, 256, arq); // Lendo e ignorando a primeira linha do arquivo (cabeçalho).

    // Lendo o arquivo e armazenando os dados dos jogadores em um vetor.
    while(fgets(linha,256,arq)){
        if(sscanf(linha, "%[^,],%[^,],%[^,],%[^,],%d", jogadores[i].nome, jogadores[i].posicao, jogadores[i].naturalidade, jogadores[i].clube, &jogadores[i].idade) == 5){
            i++; // Incrementando o índice do vetor.
        }else{
            break; // Quebra o looping caso não seja possível ler uma linha ou o arquivo tenha acabado.
        }
    }
    
    // Fechando o arquivo após leitura.
    fclose(arq);


    return 0;
}