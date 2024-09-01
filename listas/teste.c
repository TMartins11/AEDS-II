#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
}*p,*tmp,*tmp1;

// *p vai ser usado sempre pro início da lista, *tmp como auxiliar pra percorrer a lista e *tmp1 como reserva de espaço para inserir a lista.
void inserir_inicio(int elemento){
    tmp = p;
    tmp1 = (struct node*)malloc(sizeof(struct node));

    tmp1->data = elemento;
    tmp1->next = NULL;

    if(p == NULL){
        p = tmp1;
    }else{
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = tmp1;
    }

}

void inserir_inicio(int elemento){
    tmp = p;
    tmp1 = (struct node*)malloc(sizeof(struct node));
    tmp1->data = elemento;
    tmp1->next = p;
    p = tmp1;
}

void apagar(int elemento){
    tmp = p;
    struct node *pre = tmp;
    while(tmp != NULL){
        if(tmp == p){
            p = tmp->next;
            free(tmp);
            return;
        }else{
            pre->next = tmp->next;
            free(tmp);
            return;
        }
    }
}

void main(){
    p = NULL;
}