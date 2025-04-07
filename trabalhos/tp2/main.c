#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"

/*
****************************************************DESCRIÇÃO DO PROJETO******************************************************************************* 
Este código implementa uma árvore binária não balanceada e uma árvore binária balanceada do tipo AVL. O objetivo é medir o tempo, em milissegundos, 
gasto para realizar todas as operações de inserção e remoção descritas nas instâncias fornecidas. O programa imprime apenas dois números em ponto 
flutuante: o primeiro representa o tempo necessário para realizar as operações na árvore não balanceada, enquanto o segundo indica o tempo das mesmas 
operações na árvore AVL. O código foi totalmente desenvolvido em linguagem C, sem o uso de bibliotecas externas ou da STL do C++. O projeto é compilado 
por meio de um makefile, utilizando o comando "make all", e deve ser executado com a passagem de um argumento indicando a instância desejada.

Alunos: Thiago Martins da Silva - 2024.1.08.023 | Pedro Augusto de Souza Finochio - 2024.1.08.023

*******************************************************************************************************************************************************
*/


int main(int argc, char* argv[]) {
    // Verifica se um argumento foi passado
    if (argc < 2) {
        printf("Por favor, forneça um número de instância como argumento.\n");
        return 1;
    }

    ///////////////////////////////////////////////////////////
    /////////////////// Leitor de instâncias //////////////////
    ///////////////// Não deve ser modificado /////////////////
    ///////////////////////////////////////////////////////////
    int instancia_num = atoi(argv[1]);
    if (instancia_num <= 0 || instancia_num > 10) {
        printf("Para executar o código, digite ./arvores x\n \nonde x é um número entre 1 e 10 que simboliza a instância utilizada\n");
        exit(0);
    }
    
    double tempo_n_balanceada = arvore_binaria(instancia_num);
    double tempo_balanceada = arvore_balanceada(instancia_num);

    // Exibe os tempos de cada árvore.
    printf("Tempo da árvore não balanceada: %f\n", tempo_n_balanceada);
    printf("Tempo da árvore balanceada: %f\n", tempo_balanceada);

    return 0;
}
