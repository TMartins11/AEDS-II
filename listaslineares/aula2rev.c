#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int chave;
    int valor;
}lista;

// Busca em Lista Sequencial - 1.

/*Percorrer o vetor inteiro buscando pela chave correspondente, retornando -1 (posição inexistente), caso o número não esteja no vetor, e o número caso esteja.*/

int busca1(int TAM, lista L[], int x){
    int busca1 = -1;
    int i = 0;
                                                            // Complexidade de Espaço: 3 + n; Complexidade de Tempo: 2 + 5 * (TAM)
    while( i < TAM){
        if(L[i].chave == x){
            busca1 = i;
            i = TAM + 1;
        }else{
            i++;
        }
    }

    return busca1;    
}

// Busca em Lista Sequencial - 2.

/*Inserir a chave desejada uma posição além do vetor, depois comparar os elementos do vetor com esse criado artificalmente, caso seja encontrada igualdade
dentro dos padrões normais, retorna o número, caso não ocorra, retorna -1, posição inexistente no vetor normal.*/
int busca2(int TAM, lista L[], int y){
    int busca2 = -1;
    int i = 0;
    L[TAM + 1].chave = y;

    while(L[i].chave != y){
        i++;
    }
    if(i != TAM + 1){
        busca2 = i;
    }

    return busca2;
}

int main(){
    int TAM = 10;
    lista L[TAM];

    // Associando o vetor com as chaves e valores correspondentes.
    for(int i = 0; i < TAM; i++){
        L[i].chave = i;
        L[i].valor = 10  + i + i;
    }

    printf("\nVetor Completo: ");
    for(int i = 0; i < TAM; i++){
        printf("%d ", L[i].valor);
    }

    int x = 0;
    printf("\nEscolha a chave associada ao número que você deseja encontrar: ");
    scanf("%d", &x);

    int num_Encontrado = busca1(TAM, L,x);

    if(num_Encontrado != -1){
        printf("\nO número encontrado foi: %d\n", L[num_Encontrado].valor);
    }else{
        printf("\nNão há nenhum número no vetor associado com essa chave!\n");
    }

    int y = 0;
    printf("\nTestando o 2º Algoritmo:\n");
    printf("\nEscolha a chave associada ao número que você deseja encontrar: ");
    scanf("%d", &y);
    int num_Encontrado2 = busca1(TAM, L,y);

    if(num_Encontrado2 != -1){
        printf("\nO número encontrado foi: %d\n", L[num_Encontrado2].valor);
    }else{
        printf("\nNão há nenhum número no vetor associado com essa chave!\n");
    }

    return 0;
}