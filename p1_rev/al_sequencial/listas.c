#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int chave;
    int valor;
}lista;

// Operação Padrão de Busca em uma lista sequencial, percorremos todo o vetor e paramos a busca ao encontrar o número correspondente a chave desejada, retorna -1 se não encontrar.
int busca(lista L[], int tam, int x){
    int i = 0, busca = -1;
    while(i < tam){
        if(L[i].chave == x){
            busca = i;
            i = tam + 1;
        }else{
            i++;
        }
    }
    return busca;
}

// Operação Diferencial de Busca em lista sequencial, inserimos o elemento desejado por fora da lista, percorremos ela até encontrar o número, se for encontrado dentro do escopo normal do vetor, retornamos o índice, caso contrário, -1.
int busca2(lista L[], int tam, int x){
    int i = 0, busca = -1;
    L[tam + 1].chave = x;
    while(L[i].chave != x){
        i++;
    }
    if(i != tam + 1){
        busca = i;
    }
    return busca;
}

// Operação de Busca Binária em Lista Sequencial, definimos o meio da lista por meio de limites inferior e superior, após isso, dividimos a lista em 2, percorrendo somente a parte correspondente ao escopo onde podemos encontrar o elemento desejado. Retornamos -1 caso ele não esteja presente na lista.
int buscabinaria(lista L[], int tam, int x){
    int inf = 0, sup = tam - 1;
    while(inf <= sup){
        int meio = (int) (inf + sup) /2;
        if(L[meio].chave == x){
            return meio;
        }else if(L[meio].chave > x){
            sup = meio - 1;
        }else{
            inf = meio + 1;
        }
    }
    return -1;
}

int main(){
    int tam = 10;
    lista L[tam];

    // Preenchendo a lista com chaves e valores
    for(int i = 0; i < tam; i++){
        L[i].chave = i;
        L[i].valor = i + 10;
    }

    printf("\nLista Completa: ");
    for(int i = 0; i < tam; i++){
        printf("%d  ", L[i].valor);
    }
    printf("\n");

    int op, x, res;
    do{
        printf("\n**************MENU**************");
        printf("\n1. Algoritmo 1 - Busca Sequencial Simples");
        printf("\n2. Algoritmo 2 - Busca Sequencial Alternada");
        printf("\n3. Algoritmo 3 - Busca Binária");
        printf("\n4. Sair\n");
        printf("\nEscolha a Opção desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\nInsira a chave do número que você deseja buscar na lista: ");
                scanf("%d", &x);
                res = busca(L,tam,x);
                if(res == -1){
                    printf("\nNão existe nenhum número com a chave correspondente na lista!\n");
                }else{
                    printf("\nO número encontrado foi: %d\n", L[res].valor);
                }
                break;
            case 2:
                printf("\nInsira a chave do número que você deseja buscar na lista: ");
                scanf("%d", &x);
                res = busca2(L,tam,x);
                if(res == -1){
                    printf("\nNão existe nenhum número com a chave correspondente na lista!\n");
                }else{
                    printf("\nO número encontrado foi: %d\n", L[res].valor);
                }
                break;
            case 3:
                printf("\nInsira a chave do número que você deseja buscar na lista: ");
                scanf("%d", &x);
                res = buscabinaria(L,tam,x);
                if(res == -1){
                    printf("\nNão existe nenhum número com a chave correspondente na lista!\n");
                }else{
                    printf("\nO número encontrado foi: %d\n", L[res].valor);
                }
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