#include <stdio.h>
#include <stdlib.h>

// Alocação de Memória Dinâmica, Aritmética de Ponteiros e (Passagem de parâmetro por referência - 2º Parte)
int main(){
    int num_elementos = 4;

    // malloc é utilizado para reservar um espaço na memória correspondente ao tamanho indicado, retornando o ínício desse endereço reservado.
    int *pont = malloc(sizeof(int));

    // Note que o endereço reservado com malloc não é o endereço do ponteiro, mas sim têm seu endereço armazenado no ponteiro.
    *pont = 100;
    printf("Endereço reservado: %p\n", pont);
    printf("Valor Armazenado no endereço: %d\n", *pont);
    printf("Endereço do Ponteiro: %p\n", &pont);
    printf("-------------------------------------------\n");

    // Observe também que diferentes tipos de variáveis requerem a alocação de espaços diferentes para serem armazenados corretamente.
    printf("Int: %d espaços de memória\n", sizeof(int));
    printf("Long Int: %d espaços de memória\n", sizeof(long int));
    printf("Double: %d espaços de memória\n", sizeof(double));
    printf("Long Double: %d espaços de memória\n", sizeof(long double));
    printf("-------------------------------------------\n");
    
    // Agora, iremos alocar a quantidade da variável num_elementos = 4, em espaços de inteiros, ou seja, alocaremos 4 posições de memória onde caiba um inteiro em cada.
    //  Observação: Como exemplificamos acima, cada inteiro ocupa 4 posições na memória, logo, é esperado que cada um tenha seu endereço distante em 4 "casas".
    int *pont2 = malloc(num_elementos * sizeof(int));
    
    for(int i = 0; i < num_elementos; i++){
        printf("Endereço do %dº inteiro: %p\n", i + 1, pont2 + i); // Endereço contido em pont2 + i * sizeof(int), estrutura padrão incrementação de ponteiros.
    }
    printf("-------------------------------------------\n");

    // Para exemplificar melhor a diferença no tamanho necessário para armazenar cada tipo de variável: int, double, long int e long double. Faremos:
    double *pont3 = malloc(num_elementos * sizeof(double));
    long int *pont4 = malloc(num_elementos * sizeof(long int));
    long double *pont5 = malloc(num_elementos * sizeof(long double));

    for(int i = 0; i < num_elementos; i++){
        printf("Endereço do %dº double: %p\n", i + 1, pont3 + i);
    }
    printf("-------------------------------------------\n");

    for(int i = 0; i < num_elementos; i++){
        printf("Endereço do %dº long int: %p\n", i + 1, pont4 + i);
    }
    printf("-------------------------------------------\n");

    for(int i = 0; i < num_elementos; i++){
        printf("Endereço do %dº long double: %p\n", i + 1, pont5 + i);
    }
    printf("-------------------------------------------\n");

    // É de extrema importância que o espaço alocado dinamicamente com malloc seja liberado ao fim do programa.
    free(pont);
    free(pont2);
    free(pont3);
    free(pont4);
    free(pont5);
    
    return 0;
}