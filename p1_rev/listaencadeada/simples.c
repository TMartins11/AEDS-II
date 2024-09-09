#include <stdio.h>
#include <stdlib.h>

struct node{
    int chave;
    int valor;
    struct node *next;
}*p,*tmp,*tmp1;

void adInicio(int elemento){
    tmp = p;
    tmp1 = (struct node*) malloc(sizeof(struct node));
    tmp1->valor = elemento;
    tmp1->next = p;
    p = tmp1;
}

void apagar(int elemento){
    tmp = p;
    struct node *pre = (struct node*) malloc(sizeof(struct node));
    while(tmp != NULL){
        if(tmp->valor == elemento){
            
        }
    }
}

void imprimir(){
    tmp = p;
    printf("\nLista Completa: ");
    while(tmp != NULL){
        printf("%d ", tmp->valor);
        tmp = tmp->next;
    }
}

void main(){
    p = NULL;
    int val, opcao = 0;

    do{
        printf("\n**********MENU**********");
        printf("\n1. Adicionar no Início");
        printf("\n2. Apagar elemento");
        printf("\n3. Imprimir Lista");
        printf("\n4. Sair\n");
        printf("\nEscolha a Opção desejada: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nInsira o elemento que você deseja adicionar a lista: ");
                scanf("%d", &val);
                adInicio(val);
                break;
            case 2:
                break;
            case 3:
                imprimir();
                break;
            case 4:
                break;
            default:
                printf("\nOpção Inválida! Insira novamente: ");
                scanf("%d", &opcao);
        }

    }while(opcao != 4);
}