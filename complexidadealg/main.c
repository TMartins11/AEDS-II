/*  Existem duas características que são de extrema importância em algoritmos:
    
    – Tempo de execução - (Complexidade de Tempo).
    – Quantidade de memória utilizada - (Complexidade de Espaço).
*/

#include <stdio.h>
#include <stdlib.h>

/* Podemos definir o seguinte algoritmo para inverter um vetor como:
    -> 4 + n (Complexidade de Espaço); "Número de Variáveis Utilizadas" + tamanho do vetor

    -> 2 + 4 * (n/2) (Complexidde de Tempo); Número de atribuições antes e dentro do looping (2 antes e 4 dentro, contando o índice) * tamanho/2 vetor, nesse caso.

    Podemos simplificar para:

    -> n
    -> 2 + 2n

    (Visto que 2 ou 4 unidades singulares não impactam muito na execução real do programa).
*/
void invertervetor(int tam, int v[]){
/**/int aux = 0;
    int lim = tam/2;
    for(int i = 0; i < lim; i++){
        aux = v[i];
        v[i] = v[tam - i - 1];
        v[tam - i - 1]= aux;
    }
/**/

    printf("\nVetor invertido: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }

}

int main(){
    int tam = 10;
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10};

    printf("\nVetor Normal: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }

    invertervetor(tam, v);

    return 0;
}