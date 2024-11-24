#include <stdio.h>
#include <stdlib.h>
#include "ord.h"

// Função para ler o arquivo instância e preencher a struct com os dados.
int leitura(Jogador *jogadores, int *totalJogadores){

    // Abrindo o arquivo e checando se foi aberto corretamente.
    FILE *arq = fopen("./instancia/jogadores.csv", "r");
    if(!arq){
        printf("\nO arquivo selecionado não existe!");
        return 1;   
    }

    // Variáveis para realizar a leitura e armazenar os dados na struct.
    int i = 0;
    char linha[MAX_LINE_SIZE]; // Buffer para armazenar as linhas lidas do arquivo.

    fgets(linha, MAX_LINE_SIZE, arq); // Lendo e ignorando a primeira linha do arquivo (cabeçalho).

    // Lendo o arquivo e armazenando os dados dos jogadores em um vetor.
    while(fgets(linha, MAX_LINE_SIZE, arq)){
        if(sscanf(linha, "%[^,],%[^,],%[^,],%[^,],%d", jogadores[i].nome, jogadores[i].posicao, jogadores[i].naturalidade, jogadores[i].clube, &jogadores[i].idade) == 5){
            i++; // Incrementando o índice do vetor.
        }else{
            break; // Quebra o looping caso não seja possível ler uma linha ou o arquivo tenha acabado.
        }
    }

    // Fechando o arquivo após leitura.
    fclose(arq);
    
    *totalJogadores = i;
    
    return 0; // Indicar que a leitura foi bem sucedida
}

int main(int argc, char* argv[]){
    // Conferindo se a quantidade de argumentos é válida.
    if(argc != 2){
        printf("\nA quantidade de argumentos é inválida!");
        return 1;
    }
    
    // Convertendo o argumento passado para inteiro e escolhendo o algoritmo de ordenação.
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
    

    // Variáveis necessárias para a leitura. 
    Jogador jogadores[MAX_PLAYERS];
    int totalJogadores = 0;

    // Realizando a leitura e verificando se foi bem sucedida
    if(leitura(jogadores, &totalJogadores) != 0) {
        printf("\nErro na leitura do arquivo!");
        return 1;
    }
    
    
    return 0;
}