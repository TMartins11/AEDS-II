#include <stdio.h>
#include <stdlib.h>

//Passagem de parâmetros: Por valor X Por referência - "Uma casa tem mudança de moradores, não de endereço"

//Passagem de parâmetro por valor, não altera a variável original, utliza outro espaço de memória para armazenar o conteúdo.
void dobra_v(int n){
    n = n * 2;
    printf("Valor de n_v: %d\n", n);
    printf("Endereço de n_v: %p\n", &n);
    printf("--------------------------------\n");
}

//Passagem de parâmetro por referência, altera o valor original, utiliza apontamento ao endereço da variável e altera seu valor globalmente.
void dobra_r(int *n){
    *n = (*n) * 2;
    printf("Valor de n_r: %d\n", *n);
    printf("Endereço de n_r: %p\n", n);
    printf("--------------------------------\n");
}

int main(){
    int num1 = 7;

    printf("Valor de num1: %d\n", num1);
    printf("Endereço de num1: %p\n", &num1);

    printf("--------------------------------\n");
    
    dobra_v(num1);

    dobra_r(&num1);
    
    printf("Valor de num1: %d\n", num1);
    printf("Endereço de num1: %p\n", &num1);

    /*Podemos perceber que, ao passar parâmetros por valor, não alteramos o valor da variável original, apenas o guardamos e modificamos em um novo espaço na memória.
    Já quando passamos parâmetros por referência, alteramos globalmente o valor da variável, utilizando-se de apontamentos ao seu endereço para realizar mudanças.*/
    
    return 0;
}