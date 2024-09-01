#include <stdio.h>
#include <stdlib.h>

// !n = n * (n-1)! -> Definição de Fatorial, !3 = 3 . !2 = 6...
unsigned long long int fatorial(int n){
    if(n == 1){
        return 1;
    }
    return n * fatorial(n-1);
}

// Fibonacci = 0 1 1 2 3 5... -> n = n-1 + n-2
unsigned long long int fibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Soma dos 5 primeiros inteiros = 5 + 4 + 3 + 2 + 1
unsigned long long int somainteiros(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return n + somainteiros(n-1);
    }
}

int main(){
    int n = 0;
    printf("\nInsira o número do qual você quer obter o fatorial: ");
    scanf("%d", &n);
    printf("\nResultado: %lld\n", fatorial(n));
    printf("\nInsira a ordem do número que você deseja obter em Fibonacci: ");
    scanf("%d", &n);
    printf("\nResultado: %lld\n", fibonacci(n));
    printf("\nEscolha de quantos números você quer saber a soma entre inteiros: ");
    scanf("%d", &n);
    printf("\nResultado: %lld\n", somainteiros(n));

    return 0;
}