#include <stdio.h>
#include <stdlib.h>

#define N 10

// Pilha que irá armazenar o caminho a ser percorrido no labirinto.
typedef struct Pilha{
    int x;
    int y;
    struct Pilha *prox;
}pilha;


void adPilha(pilha *topo){
    pilha *P = malloc(sizeof(pilha));

    topo->prox = P;
    
}

// Função que realiza a imressão do labirinto na tela.
void printlab(char L[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            printf("%c", L[i][j]);
        printf("\n");
    }
}

int main(int argc, char* argv[]){
    // Inicialização da matriz que irá armazenar o labirinto 10x10.
    char lab [N][N];

    // Condicional para conferir se a passagem de argumentos foi realizada corretamente. (O inicial sendo o próprio arquivo em execução e o 2º o labirinto escolhido).
    if(argc != 2){
        printf("\nVocê utilizou um número inválido de argumentos!");
    }else{
        printf("\nLabirinto Resolvido:\n");
    }
    
    // Abrindo o arquivo.txt pra leitura e verificando se o acesso foi feito corretamente.
    FILE* arq = fopen(argv[1], "r");
    if(arq == NULL){
        printf("O arquivo procurado não existe!\n");
        return 1;
    }

    // Lendo os caracteres do labirinto e preenchendo a matriz.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            lab[i][j] = fgetc(arq);
        }
        fgetc(arq);
    }

    // Fechando o arquivo.txt passado como argumento após leitura.
    fclose(arq);

    pilha *topo = NULL;

    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(lab[i][j] == 'E'){

            }
        }
    }

    printlab(lab);

    return 0;
}