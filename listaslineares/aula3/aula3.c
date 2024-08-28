#include <stdio.h>
#include <stdlib.h>

// Operações de Inserção e Remoção - Alocação Sequencial

typedef struct Lista{
    int chave;
    int valor;
}lista;

// Função para Inserir números no vetor.

/* Consiste em armazenar o topo da pilha, permitindo a adição de novos números enquanto topo != tam, caso topo seja igual ao tamanho, teremos uma lista cheia, o que
terá a função retornando -1, não permitindo a adição de novos algarismos.*/
int inserir(int tam, int *topo, lista L[], int no){
    int insere = -1;
    if(*topo != tam){
        L[*topo].valor = no;
        *topo = *topo + 1;
        insere = *topo;
    }

    return insere;
}

// Função para remover números do vetor.

/* Consiste em checar a posição do topo, caso não esteja na inicial(0), temos uma lista com elementos, logo, podemos e iremos remover um elemento do vetor.*/
int remover(int tam, int *topo, lista L[]){
    int *remove = NULL;
    int aux = 0;
    if(*topo != 0){
        remove = &L[*topo].valor;
        *topo = *topo - 1;
    }

    return *remove;
}

int main(){
    int tam = 10;
    lista L[tam];
    
    // Armazenando o topo da pilha
    int *topo = &L[0].chave;

    // Preenchendo inicialmente o vetor
    for(int i = 0; i < tam - 2; i++){
        L[i].chave = i;
        L[i].valor = 10 + i + i;
        *topo = *topo + 1;
    }

    printf("\nVetor Completo: ");
    for(int i = 0; i < tam - 2; i++){
        printf("%d ",L[i].valor );
    }

    int no = 0;
    printf("\nInsira o número que você deseja acrescentar ao vetor: ");
    scanf("%d", &no);

    inserir(tam,topo,L,no);

    printf("\nVetor Atual: ");
    for(int i = 0; i < *topo; i++){
        printf("%d ",L[i].valor );
    }

    remover(tam, topo, L);
    printf("\nVetor Finalizado: ");
    for(int i = 0; i < *topo; i++){
        printf("%d ",L[i].valor );
    }

    return 0;
}