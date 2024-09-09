#include <stdio.h>
#include <stdlib.h>

// Nesse Código, abordaremos todas as opções de busca em uma Lista Sequencial.
typedef struct Lista{
    int chave;
    int valor;
}lista;

// Busca Sequencial, percorremos o vetor completo, parando imediatamente quando encontramos o número desejado ou retornando -1 quando ele não está na lista.
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

/* Inserimos o elemento desejado na 1º posição fora do vetor, depois percorremos o vetor completo em busca do número desejado. Se encontrado dentro do tamanho
original do vetor, retornamos ele, se não, retornamos -1.*/
int busca2(lista L[], int tam, int x){
    int i = 0, busca = -1;
    L[tam + 1].chave = x;
    while(L[i].chave != x){
        i++;
    }
    if( i != tam + 1){
        busca = i;
    }
    return busca;
}

/* Busca binária, consiste em definir o meio da lista, estabelecendo se o elemento procurado é =, < ou > do que o meio. A partir disso, atualizamos os limites
superior e inferior a fim de encontrar o número desejado.*/
int buscabinaria(lista L[], int tam, int x){
    int inf = 0, sup = tam - 1;
    while(inf <= sup){
        int meio = (int) (inf + sup) / 2;
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

    // Preenchendo a lista.
    for(int i = 0; i < tam; i++){
        L[i].chave = i;
        L[i].valor = i + i + 10;
    }

    // Imprimindo a Lista Completa
    for(int i = 0; i < tam; i++){
        printf("%d  ",L[i].valor);
    }
    printf("\n");

    int opcao, x;
    do{
        printf("\n**********************MENU**********************\n");
        printf("\n1. Busca Sequencial Padrão");
        printf("\n2. Busca Sequencial Alternada");
        printf("\n3. Busca Binária");
        printf("\n4. Sair\n");
        printf("\nEscolha a opção desejada: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nInsira a chave do elemento que você deseja buscar na lista: ");
                scanf("%d", &x);
                printf("\nO número encontrado foi: %d", L[busca(L,tam,x)].valor);
                break;
            case 2:
                printf("\nInsira a chave do elemento que você deseja buscar na lista: ");
                scanf("%d", &x);
                printf("\nO número encontrado foi: %d", L[busca2(L,tam,x)].valor);
                break;
            case 3:
                printf("\nInsira a chave do elemento que você deseja buscar na lista: ");
                scanf("%d", &x);
                printf("\nO número encontrado foi: %d", L[buscabinaria(L,tam,x)].valor);
                break;
            case 4:
                break;
            default:
                printf("\nOpção Inválida! Insira novamente: ");
                scanf("%d", &opcao);
        }
    }while(opcao != 4);


    return 0;
}