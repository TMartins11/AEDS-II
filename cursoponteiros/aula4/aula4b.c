#include <stdio.h>
#include <stdlib.h>

// Finalizando aula 4 com a passagem de parâmetros por referência.

// Com a passagem de parâmetros por referência, é possível preencher os espaços alocados com malloc por meio de funções. Além de ser viável imprimir os valores.
void preenche_valores(int *p, int tamanho){
    for(int i = 0; i < tamanho; i++){
        p[i] = i + i + i;
    }
}

void imprime_valores(int *p, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Conteúdo do %dº inteiro: %d\n", i + 1, *(p + i));
    }
}

// É possível também que o próprio usuário insira os valores que serão armazenados nos espaços alocados dinamicamente.
void insira_valores(int *p, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Insira o conteúdo do %d inteiro: ", i + 1);
        scanf("%d", (p + i)); // Como p já se trata de um endereço, não é necessário adicionar &, o valor inserido pelo usuário já é armazenado no endereço desejado.
    }
}

int main(){
    int num_elementos = 4;
    int *pont = malloc(num_elementos * sizeof(int));

    // Passando o endereço alocado com malloc como referência, podemos realizar a inserção de valores nesses espaços de memória apenas com apontamentos.
    for(int i = 0; i < num_elementos; i++){
        *(pont + i) = i + i; // Endereço apontado por pont + i recebe i + i.
        printf("Conteúdo do %dº inteiro: %d\n", i + 1, *(pont + i));
    }
    printf("----------------------------------\n");

    //Note que é possível representar a operação acima como vetores (A alocação de memória entre ponteiros e vetores é diferente independentemente da representação).
    for(int i = 0; i < num_elementos; i++){
        pont[i] = i + i;// Endereço apontado por pont + i recebe i + i.
        printf("Conteúdo do %dº inteiro: %d\n", i + 1, pont[i]);
    }
    printf("----------------------------------\n");

    //Finalizando a passagem de parâmetros por referência, preencher o espaço alocado utilizando funções e depois imprimir os valores atribuídos aos endereços.
    preenche_valores(pont, num_elementos);
    imprime_valores(pont, num_elementos);
    
    printf("----------------------------------\n");

    // É importante notar que também é possível que o próprio usuário preencha os espaços alocados dinamicamente.
    insira_valores(pont, num_elementos);
    printf("----------------------------------\n");
    imprime_valores(pont, num_elementos);

    // Reforçando, após a execução do programa, lembre-se sempre de liberar os espaços que você alocou dinamicamente.
    free(pont);

    return 0;
}