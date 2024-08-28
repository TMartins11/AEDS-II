#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*p,*tmp,*tmp1;

/* Ponteiros são declarados para poderem apontar para qualquer parte da struct: struct node *p; struct node *tmp...*/

void inserir_fim(int elemento){
    tmp = p;
    tmp1= (struct node*) malloc(sizeof(struct node));
    tmp1->data = elemento;
    /* Agora, após a adição, o ponteiro next fica vazio, visto que não existem posições subsequentes.*/
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
    tmp1 = (struct node*) malloc(sizeof(struct node));
    tmp1->data = elemento;
    tmp1->next = p;
    p = tmp1;
}

void apagar(int elemento){
    tmp = p;
        struct node *pre = tmp;
        while(tmp != NULL){
            if(tmp->data ==  elemento){
                if(tmp == p){
                    p = (*tmp).next;
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
        
        printf("\n Valor não encontrado! ");
}

void apagar_inicio(){
    tmp = p;
    if(p == NULL){}
}


int main(){

    return 0;
}