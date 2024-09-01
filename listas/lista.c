#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
}*p,*tmp,*tmp1;

/* Ponteiros são declarados para poderem apontar para qualquer parte da struct: struct node *p; struct node *tmp...*/

void inserir_fim(int elemento){
    // Começar a percorrer o vetor pela posição inicial.
    tmp = p;
    tmp1= (struct node*) malloc(sizeof(struct node));
    /* tmp1->data == (*tmp1).data */
    tmp1->data = elemento;
    /* Agora, após a adição, o ponteiro next fica vazio, visto que não existem posições subsequentes.*/
    tmp1->next = NULL;

    if(p == NULL){
        // Caso p == NULL, não há nenhum número na lista, logo, p deve ser atualizado, indicando o último nó da lista.
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
            if(tmp->data == elemento){
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
    if(p == NULL){
        printf("\nLista Vazia! Nenhum elemento deletado.");
    }else{
        printf("\nElemento deletado - %d", p-> data);
        p = p->next;
    }
}

void apagar_fim(){
    tmp = p;
    struct node *pre;
    if(p == NULL){
        printf("\n Nenhum elemento deletado ");
    }else if(p->next == NULL){
        printf("\nElemento deletado - %d", p->data);
        p = NULL;
    }else{
        while(tmp->next != NULL){
            pre=tmp;
            tmp=tmp->next;
        }
        pre->next = NULL;
        printf("\nElemento deletado - %d", tmp->data);
    }
}

bool ehVazia(){
    if(p == NULL){
        return (1);
    }else{
        return (0);
    }
}

void imprimir(){
    tmp = p;
    while(tmp != NULL){
        printf("\n %d", tmp->data);
        tmp = tmp->next;
    }
}

int obter_primeiro(){
    tmp = p;
    if(p == NULL){
        printf("\nNenhum elemento encontrado! Lista vazia.");
    }else{
        return (p->data);
    }
}

int obter_ultimo(){
    tmp = p;
    struct node* pre;
    if(p == NULL){
        printf("\n Nenhum elemento encontrado! Lista vazia.");
        return (0);
    }else if(p->next == NULL){
        return (p->data);
    }else{
        while(tmp->next != NULL){
            pre=tmp;
            tmp=tmp->next;
        }
        pre->next == NULL;
        return(tmp->data);
    }
}

void main(){
    int val,n;
    p = NULL;
    do{
        printf("\n*************** MENU ***************");
        printf("\n1. Inserir no fim");
        printf("\n2. Inserir no início");
        printf("\n3. Apagar um elemento em particular");
        printf("\n4. Apagar do início");
        printf("\n5. Apagar do fim");
        printf("\n6. Imprimir Lista");
        printf("\n7. É vazia?");
        printf("\n8. Obter primeiro");
        printf("\n9. Obter Último");
        printf("\n0. Sair");

        printf("\nEntre sua opção: ");
        scanf("%d", &n);
        switch(n){
            case 1:
                printf("\nDigite o valor: ");
                scanf("%d", &val);
                inserir_fim(val);
                break;
            case 2:
                printf("\nDigite o valor: ");
                scanf("%d", &val);
                inserir_inicio(val);
                break;
            case 3:
                printf("\nDigite o valor: ");
                scanf("%d", &val);
                apagar(val);
                break;
            case 4:
                apagar_inicio();
                break;
            case 5:
                apagar_fim();
                break;
            case 6:
                imprimir();
                break;
            case 7:
                if(ehVazia() == 1){
                    printf("\nLista Vazia");
                }else{
                    printf("\nLista não vazia");
                }
                break;
            case 8:
                val = obter_primeiro();
                if(val != 0){
                    printf("%d", val);
                }
                break;
            case 9:
                val = obter_ultimo();
                if(val != 0){
                    printf("%d", val);
                }
                break;
            case 0: 
                exit(0);
                break;
            default:
                printf("\nOpção Inválida!");
                break;
        }
    }while(1);
}