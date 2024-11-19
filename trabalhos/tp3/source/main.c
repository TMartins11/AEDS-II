#include <stdio.h>
#include <stdlib.h>
#include "ord.h"

#define MAX_STRING 50

typedef struct{
    char nome[MAX_STRING];
    char posição[MAX_STRING];
    char naturalidade[MAX_STRING];
    char clube[MAX_STRING];
    int idade;
}Jogador;

int main(int argc, char* argv[]){
    // Conferindo argumentos.
    if(argc != 2){
        printf("\nA quantidade de argumentos é inválida!");
        printf("\nVocê deve inserir o algoritmo de ordenação que deseja utilizar: ");
        printf("\n1 - BubbleSort - Ordenação Simples.");
        printf("\n2 - MergeSort - Ordenação Ótima.");
        printf("\n3 - Counting Sort - Ordenação em Tempo Linear.\n");
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
            return 1;
    }    

    // Ponteiro para a struct que será utilizada, faremos alocação dinâmica de memória para preencher o vetor com as leituras do arquivo.
    Jogador *jogadores = NULL;
    int njog = 0;
    int total = 0;
    
    // Abrindo o arquivo e checando se foi aberto corretamente.
    FILE *arq = fopen("jogadores.csv", "r");
    if(!arq){
        printf("\nO arquivo selecionado não existe!");
        return 1;
    }

    // Leitura dinâmica do arquivo.
    while(1){
        if(njog >= total){
            total = total == 0 ? 10 : total * 2; // Se njog >= capacidade total, dobra a capacidade total e realoca a memória no ponteiro.
            Jogador *tmp  = realloc(jogadores, total *sizeof(Jogador));
            if(!tmp){
                printf("\nErro de Alocação!");
                free(jogadores);
                fclose(arq);
                return 1;
            }
            jogadores = tmp;
        }    
            if(fscanf(arq, "%49[^;];%49[^;];%49[^;];%49[^;];%d\n",
                            jogadores[njog].nome,
                            jogadores[njog].posição,
                            jogadores[njog].naturalidade,
                            jogadores[njog].clube,
                            &jogadores[njog].idade) != 5){
                break;                    
            }
            njog++;
    }
    
    // Fechando o arquivo após leitura.
    fclose(arq);

    for(int i = 0; i < njog; i++){
        printf("Jogador %d: %s | %s | %s | %s | %d\n", 
               i+1, 
               jogadores[i].nome, 
               jogadores[i].posição, 
               jogadores[i].naturalidade, 
               jogadores[i].clube,
               jogadores[i].idade);
    }
    
    printf("%d", njog);
    free(jogadores);

    return 0;
}