#include <stdio.h>
#include <stdlib.h>

// È importante definir que & colocado antes de uma variável se refere ao endereço dela, e não ao conteúdo.

int main(){
    // Variáveis X Váriaveis Ponteiro
    int num1 = 10;
    int *pont1 = &num1;

    printf("Considerando num1 = 10 e *pont1 = &num1\n");

    // Imprime o valor armazenado na variável num1.
    printf("\nValor de num1: ");
    printf("%d\n", num1);

    // Imprime o endereço da variável num1, o espaço na memória onde está armazenada.
    printf("Endereço de num1: ");
    printf("%p\n", &num1);

    // Imprime o conteúdo de pont1 == endereço de num1, visto que trata-se de uma variável ponteiro.
    printf("\nConteúdo de pont1: ");
    printf("%p\n", pont1);

    // Imprime o endereço da variável ponteiro pont1, visto que & denota endereço.
    printf("Endereço de pont1: ");
    printf("%p\n", &pont1);

    // Podemos observar que qualquer alteração ao valor de num1 não ocasiona nenhuma mudança a seu endereço.
    num1 = 50;
    printf("\nConsiderando agora num1 = 50 e *pont1 = &num1\n");
    printf("\nValor de num1: ");
    printf("%d\n", num1);
    printf("Endereço de num1: ");
    printf("%p\n", &num1);
    printf("\nConteúdo de pont1: ");
    printf("%p\n", pont1);

    // Assim como, nenhuma alteração ao endereço que pont1 armazena altera o endereço do ponteiro que é pont1.
    int num2 = 77;
    pont1 = &num2;
    printf("\nPara finalizar, consideramos num2 = 77 e pont1 = &num2\n");
    printf("\nEndereço de num2: ");
    printf("%p\n", &num2);
    printf("Conteúdo de pont1: ");
    printf("%p\n", pont1);
    printf("\nEndereço de pont1: ");
    printf("%p\n", &pont1);

    return 0;
}