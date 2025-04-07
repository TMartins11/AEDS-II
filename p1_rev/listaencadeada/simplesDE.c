#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int chave;
    int valor;
    struct no_ *prox;
}no;

void busca_enc(int x, no **ant, no **pont, no *ptlista ){
    *ant = ptlista;
    *pont = NULL;
    no *ptr = ptlista->prox;
    while(ptr != NULL){
        if(ptr->chave < x){
            *ant = ptr;
            ptr = ptr->prox;
        }else{
            if(ptr->chave == x){
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}

int insere_enc(no *no_inserir, no *ptlista){
    no *ant;
    no *pont;
    busca_enc(no_inserir->chave,&ant,&pont,ptlista);
    if(pont == NULL){
        no_inserir->prox = ant;
        ant->prox = no_inserir;
        return 0;
    }
    return -1;
}

no *remover(int x, no *ptlista){
    no *ant;
    no *pont;
    no *removido = NULL;
    busca_enc(x,&ant,&pont,ptlista);
    if(pont != NULL){
        ant->prox = pont->prox;
        removido = pont;
        return removido;
    }
    return removido;
}

void imprimir(no *ptlista){
    no *p = ptlista->prox;
    while(p != NULL){
        printf("\nChave: %d | Valor: %d", p->chave, p->valor);
        p = p->prox;
    }
}

int main(){
    no *ptlista = malloc(sizeof(no));
    ptlista->prox = NULL;

    int op = 0, x = 0;
    no *ant;
    no *pont;
    do{
        printf("\n**************MENU**************\n");
        printf("\n1. Inserir Elemento");
        printf("\n2. Apagar Elemento");
        printf("\n3. Imprimir Lista");
        printf("\n4. Buscar Elemento");
        printf("\n5. Sair\n");
        printf("\nEscolha a opçaõ desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                no *no_inserir = malloc(sizeof(no));
                printf("\nInsira a chave do elemento que você deseja adicionar a lista: ");
                scanf("%d", &no_inserir->chave);
                printf("\nInsira o valor do elemento que você deseja adicionar a lista: ");
                scanf("%d", &no_inserir->valor);
                if(insere_enc(no_inserir, ptlista) == 0){
                    printf("\nElemento inserido com sucesso!\n");
                }else{
                    printf("\nNão foi possível inserir o elemento desejado.\n");
                }
                break;
            case 2:
                printf("\nInsira a chave do elemento que você deseja remover da lista: ");
                scanf("%d", &x);
                no *removido = remover(x, ptlista);
                if(removido != NULL){
                    printf("\nO elemento -> Chave: %d | Valor: %d, foi removido com sucesso!\n", removido->chave, removido->valor);
                }else{
                    printf("\nNão existe nenhum elemento com a chave correspondente na Lista.\n");
                }
                break;
            case 3:
                imprimir(ptlista);
                break;
            case 4:
                printf("\nInsira a chave do elemento que você deseja buscar na lista: ");
                scanf("%d", &x);
                busca_enc(x, &ant, &pont, ptlista);
                if(pont != NULL){
                    printf("\nO elemento com a chave correspondente é -> Chave: %d | Valor: %d\n", pont->chave, pont->valor);
                }else{
                    printf("\nNão existe nenhum elemento com a chave correspondente na Lista.\n");
                }
                break;
            case 5:
                break;
            default:
                printf("\nOpção Inválida! Insira novamente: ");
                scanf("%d", &op);
        }   
    }while(op != 5);

    return 0;
}