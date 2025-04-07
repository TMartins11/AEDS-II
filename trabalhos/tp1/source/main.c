#include <stdio.h>
#include <stdlib.h>

#define N 10

// Pilha para armazenar cada passo na solução do labirinto.
typedef struct Pilha{
    int x;
    int y;
    struct Pilha *prox;
}pilha;

// Adicionar cada paaso correto a pilha.
void adPilha(int xl, int yl, pilha** t){
    pilha *node = malloc(sizeof(pilha));
    if(node == NULL){
        printf("\nErro na alocação de memória, não foi possível adicionar o elemento!");
        return;
    }
    node->x = xl;
    node->y = yl;
    node->prox = *t;
    *t = node;
}

// Realiza a remoção na pilha (Pilha = Sò é possível remover o topo atual), retornando o nó removido e atualizando o topo.
pilha* rmPilha(pilha** t){
    pilha* tmp = *t;
    if(*t != NULL){
        *t = (**t).prox;
        return tmp;
    } else{
        return NULL;
    }
}

// Imprime o caminho correto para resolver o labirinto.
void printPilha(pilha *t){
    while(t != NULL){
        printf("%d, %d\n", t->x, t->y);
        t = t->prox;
    }
}

// Imprime o labirinto.
void printLab(char lab[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("%c", lab[i][j]);
        printf("\n");
    }
}

/* A utilização de argc e argv ocorre para que os labirintos possam ser passados ao programa como argumentos, possibilitando o agrupamento dos arquivos.txt em
uma pasta separada do código principal */

int main(int argc, char* argv[]){

    // Inicialização da matriz que irá armazenar o labirinto 10x10.
    char lab [N][N];

    // Condicional para conferir se a passagem de argumentos foi realizada corretamente. (O inicial sendo o próprio arquivo em execução e o 2º o labirinto escolhido).
    if(argc != 2){
        printf("\nA quantidade de Argumentos é inválida!\n");
        return 1;
    }else{
        printf("\nLabirinto Original:\n");
    }
    // Abrindo o arquivo.txt pra leitura e verificando se o acesso foi feito corretamente.
    FILE* arq = fopen(argv[1], "r");
    if(arq == NULL){
        printf("O arquivo procurado não existe!\n");
        return 1;
    }

    // Lendo os caracteres e preenchendo a matriz.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            lab[i][j] = fgetc(arq);
        }
        fgetc(arq);
    }

    // Fechando o arquivo.txt passado como argumento após leitura.
    fclose(arq);

    // Labirinto Original.
    printLab(lab);

    // RESOLUÇÂO DO LABIRINTO

    pilha *path = NULL; // Caminho correto para a resolução do problema.
    pilha *wp = NULL; // Pontos de Bifurcação.

    // Encontrando a Entrada
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(lab[i][j] == 'E'){
                adPilha(i,j, &path); // Armazenando a posição da entrada como primeiro elemento da pilha.
            }
        }
    }

    int saida = 1; // Iniciamos a saída com 0 e atualizamos quando for encontrada percorrendo o labirinto.
    int ncam; // Armazena o número de caminhos possíveis.
    char pos; // Guarda a posição que está sendo analisada no momento.
    pilha *tmp;

    while(saida == 1){
        ncam = 0;

        int xn = path->x; // xn = X analisado no momento.
        int yn = path->y; // yn = Y analisado no momento.
    
         if(xn > 0){ // Se Xn > 0, logo, a posição analisada não está na 1º linha, existe casa acima.
            pos = lab[xn-1][yn]; // Atribuímos o valor da posição acima a pos.

            switch(pos){
                case '0': 
                {
                    adPilha(xn-1, yn, &wp);
                    ncam++;
                    break;
                }
                case 'S': // 83 = 'S' ; Tabela ASCII
                {  
                    adPilha(xn-1, yn, &path);
                    saida = 0;
                    ncam++;
                    break;
                }
            }
        }

        if(yn > 0){ // Se yn > 0, logo, a posição analisada não é o primeiro elemento da linha, ou seja, existe casa à esquerda.
            pos = lab[xn][yn-1]; // Atribuimos o valor da posição à esquerda como pos.

            switch(pos){
                case '0': // 48 = '0'
                {
                    adPilha(xn, yn-1, &wp);
                    ncam++;
                    break;
                }
                case 'S': // 83 = 'S'
                {
                    adPilha(xn, yn-1, &path);
                    saida = 0;
                    ncam++;
                    break;
                }
            }
        }

        if(xn < N - 1){ // Se xn < N - 1, logo, não estamos na última linha, ou seja, existe casa abaixo.
            pos = lab[xn+1][yn]; // Atribuimos a pos o valor da casa abaixo.

            switch(pos){
                case '0': // 48 = '0'
                {
                    adPilha(xn+1, yn, &wp);
                    ncam++;
                    break;
                }
                case 'S': // 83 = 'S'
                {
                    adPilha(xn+1, yn, &path);
                    saida = 0;
                    ncam++;
                    break;
                }
            }
        }

        if(yn < N - 1){ // Se yn < N-1, logo, y não é o último elemento da linha, ou seja, existe casa à direita.
            pos = lab[xn][yn+1]; // Atribuimos o valor da posição à direita como pos.

            switch(pos){
                case '0': // 48 = '0'
                {   
                    adPilha(xn, yn+1, &wp);
                    ncam++;
                    break;
                }
                case 'S': // 83 = 'S'
                {
                    adPilha(xn, yn+1, &path);
                    saida = 0;
                    ncam++;
                    break;
                }
            }
        }

        if(saida == 1){
            switch(ncam){
                case 1: // Se ncam = 1, só temos um caminho a ser percorrido.
                {
                    lab[xn][yn] = 64; // A posição atual recebe @, denotar o caminho correto pelo labirinto.
                    tmp = rmPilha(&wp);
                    adPilha(tmp->x, tmp->y, &path);
                    break;
                }

                case 2: // Existem 2 caminhos a serem percorridos.
                {
                    lab[xn][yn] = 64; // A posição atual recebe @.
                    tmp = rmPilha(&wp);
                    adPilha(tmp -> x, tmp -> y, &path);
                    adPilha(xn, yn, &wp); 
                    break;
                }

                case 0: // Não existem mais caminhos a serem percorridos.
                {
                    while(path-> x != wp->x || path->y != wp->y){ // Retorna a última bifurcação.
                        tmp = rmPilha(&path);
                        free(tmp); // Retira o valor no topo de path.
                    }
                    rmPilha(&wp); // Retirar o endereço da bifurcação
                    tmp = rmPilha(&wp); // Fornece o endereço do próximo caminho a path.
                    adPilha(tmp->x, tmp->y, &path);
                    break;
                }

                default:
                {
                    printf("erro\n");
                    saida = 0;
                    break;
                }
            }
        }
    }


    while(wp != NULL){ // Esvazia wp, encarregada de armazenar bifurações e caminhos incorretos.
        tmp = rmPilha(&wp);
        free(tmp);
    }

    while(path != NULL){ // inverte a ordem de path em wp.
        tmp = rmPilha(&path);
        adPilha(tmp->x, tmp->y, &wp);
        free(tmp);
    }

    printf("\nSolução:\n");
    printPilha(wp);
    printf("\nCaminho Percorrido:\n");
    printLab(lab);

    return 0;
}