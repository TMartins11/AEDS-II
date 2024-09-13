#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int chave;
    int valor;
    struct no_ *ant;
    struct no_ *prox;
}no;

no *buscar(int x, no *ptlista){
    no *ultimo = ptlista->ant;

    if(ultimo != ptlista && x <= ultimo->chave){
        no * pont = ptlista->prox;
        while(pont->chave < x){
            pont = pont->prox;
        }
        return pont;
    }
    return ptlista;
}

no *inserir(no *novo_no, no *ptlista){
    no *pont = buscar(novo_no,ptlista);
    if(pont == ptlista || pont->chave != novo_no->chave){
        novo_no->ant = pont->ant;
        novo_no->prox = pont;
        pont->ant->prox = novo_no;
        pont->ant = novo_no;
        return NULL;
    }
    return pont;
}
// 2 3 5 ; pont = 5 