#include <stdio.h>
#include <stdlib.h>

/*Podemos realizar apontamentos com ponteiros utilizando o operador *, deste modo, referenciaremos o conteúdo armazenado no endereço guardado,
no entanto, atenção com o tipo de dado, valores int irão requerer %d, endereços ainda necessitam de %p.*/

int main(){
    // Variáveis ponteiro de ponteiro, (é importante ressaltar que não temos um limite, podemos ter ponteiro de ponteiro de ponteiro de ponteiro...)
    int num1 = 7;
    int *pont1 = &num1;
    int **pont2 = &pont1;

    //relembrando, pont1 armazena o endereço de num1.
    printf("%p\n", &num1);
    printf("%p\n", pont1);
    printf("---------------\n");

    //pont2 é um ponteiro de ponteiro, armazena o endereço de pont1.
    printf("%p\n", &pont1);
    printf("%p\n", pont2);
    printf("---------------\n");
    
    //como pont1 faz referência ao endereço de num1, se apontarmos a pont1, ele exibirá o valor do endereço nele apresentado, ou seja, num1.
    printf("%d\n", num1);
    printf("%d\n", *pont1);
    printf("---------------\n");
    
    //apontando pont2 podemos chegar a 2 resultados, 1 apontamento = valor em pont1 == endereço de num1; 2 apontamentos = valor no endereço registrado em pont1 == num1.
    printf("%p\n", *pont2);
    printf("%d\n", **pont2);
    printf("---------------\n");

    /*A utilização de ponteiros é particularente útil porque armazena endereços, logo, podemos ter os valores das variáveis sempre atualizados 
    utilizando apenas apontamentos, sem a necessidade de chamar a mesma variável novamente. Algo que eu imagino ser mais prático em casos onde temos o usuário
    modificando dados constantemente, ou em listas com alocação de memória encadeada.*/
    num1 = 77;
    printf("%d\n", *pont1);

    return 0;
}