#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
}*p,*tmp,*tmp1;

void adInicio(int val){
    tmp = p;
    tmp1 = (struct node*) malloc(sizeof(struct node));
    tmp1->data = val;
    tmp1->next = p;
    p = tmp1;
}

void adFim(int val){
    tmp = p;
    tmp1 = (struct node*) malloc(sizeof(struct node));
    tmp1->data = val;
    tmp1->next = NULL;
    if(p == NULL){
        p = tmp1;
        return;
    }else{
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = tmp1;
    }
}

void remover(int val){
    tmp = p;
    struct node *pre = tmp;
    while(p != NULL){
        if(tmp->data == val){
            if(tmp == p){
                p = tmp->next;
                free(tmp);
                return;
            }else{
                pre->next = tmp->next;
                free(tmp);
                return;
            }
        }else{
            pre = tmp;
            tmp = tmp->next;
        }
    }
}

void imprimir(){
    tmp = p;
    printf("\nLista Completa: ");
    while(tmp != NULL){
        printf("%d  ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void main(){
    p = NULL;
    int val, opcao = 0;

    do{
        printf("\n**********MENU**********");
        printf("\n1. Adicionar no Início");
        printf("\n2. Adicionar no Fim");
        printf("\n3. Imprimir Lista");
        printf("\n4. Apagar Elemento\n");
        printf("\n5. Sair\n");
        printf("\nEscolha a Opção desejada: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nInsira o elemento que você deseja adicionar a lista: ");
                scanf("%d", &val);
                adInicio(val);
                break;
            case 2:
                printf("\nInsira o elemento que você deseja adicionar a lista: ");
                scanf("%d", &val);
                adFim(val);
                break;
            case 3:
                imprimir();
                break;
            case 4:
                printf("\nInsira o elemento que você deseja remover da lista: ");
                scanf("%d", &val);
                remover(val);
                break;
            case 5:
                break;
            default:
                printf("\nOpção Inválida! Insira novamente: ");
                scanf("%d", &opcao);
        }

    }while(opcao != 5);
}