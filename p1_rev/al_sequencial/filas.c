#include <stdio.h>
#include <stdlib.h>

typedef struct no_ {
    int chave;
    int valor;
}no;

int inserir(no fila[], int M, int *f, int *r, int x) {
    int prox = (*r + 1) % M;

    if (prox == *f) {
        printf("Fila cheia!\n");
        return -1; 
    }

    *r = prox;
    fila[*r].valor = x;
    if (*f == -1) {
        *f = *r;
    }

    return *r;
}
int remover(no fila[], int M, int *f, int *r){
    int *remove = NULL;
    if(*f != 0){
        *remove = fila[*f].chave;
        if(*f == *r){
            f = r = 0;
        }else{
            *f = *f %(M + 1);
        }
    }
    return *remove;
}

void imprimir(no fila[], int M){
    printf("\nLista Completa: ");
    for(int i = 0; i < M; i++){
        printf("%d ", fila[i].valor);
    }
    printf("\n");
}

int main(){
    int M = 5;
    no fila[M];
    int f = -1, r = -1, op, x;

    do{
        printf("\n**************MENU**************");
        printf("\n1. Inserir Elemento");
        printf("\n2. Remover Elemento");
        printf("\n3. Imprimir Fila");
        printf("\n4. Sair\n");
        printf("\nEscolha a Opção desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\nInsira o elemento que você deseja adicionar a lista: ");
                scanf("%d", &x);
                inserir(fila,M,&f,&r,x);
                break;
            case 2:
                printf("\nInsira o elemento que você deseja remover da lista: ");
                scanf("%d", &x);
                remover(fila, M, &f, &r);
                break;
            case 3:
                imprimir(fila,M);
                break;
            case 4:
                break;
            default:
                printf("\nOpção Inválida! Insira novamente: ");
                scanf("%d", &op);
        }
    }while(op != 4);

    return 0;
}