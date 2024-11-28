#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ord.h"

// Contadores globais para comparações e trocas.
unsigned long long int comparacoes = 0;
unsigned long long int trocas = 0;

// Troca a posição de dois jogadores no vetor e incrementa contador de trocas.
void trocar(Jogador *a, Jogador *b) {
    if (a == NULL || b == NULL) return;
    
    Jogador temp = *a;
    *a = *b;
    *b = temp;
    trocas++;  // Incrementa contador de trocas a cada troca realizada.
}

// Compara lexicograficamente dois nomes de jogadores.
int comparar(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) return 0;
    
    // Incrementa comparações para rastrear número de comparações.
    comparacoes++;
    
    // Compara caractere por caractere, considerando ordem alfabética.
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    
    // Retorna diferença do último caractere.
    return *str1 - *str2;
}

// Implementação do algoritmo BubbleSort com contagem precisa de comparações.
void bubbleSort(Jogador *jogador, int n) {
    if (jogador == NULL || n <= 0) return;
    
    // Reinicia contadores de comparação e troca.
    comparacoes = 0;
    trocas = 0;
    
    // Percorre o vetor, comparando e trocando nomes adjacentes.
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Incrementa comparações explicitamente para cada comparação.
            comparacoes++;
            
            // Troca se o nome atual for lexicograficamente maior
            if (comparar(jogador[j].nome, jogador[j+1].nome) > 0) {
                trocar(&jogador[j], &jogador[j+1]);
            }
        }
    }
}

// Função de fusão para o algoritmo MergeSort com contagem de comparações e trocas.
void merge(Jogador *jogadores, int inicio, int meio, int fim) {
    // Calcula tamanho dos subvetores.
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Aloca vetores temporários para divisão.
    Jogador *esquerda = malloc(n1 * sizeof(Jogador));
    Jogador *direita = malloc(n2 * sizeof(Jogador));
    
    if (esquerda == NULL || direita == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        free(esquerda);
        free(direita);
        return;
    }

    // Copia dados para vetores temporários.
    memcpy(esquerda, jogadores + inicio, n1 * sizeof(Jogador));
    memcpy(direita, jogadores + meio + 1, n2 * sizeof(Jogador));

    // Mescla os vetores temporários.
    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        // Incrementa comparações para cada comparação.
        comparacoes++;
        
        if (comparar(esquerda[i].nome, direita[j].nome) <= 0) {
            jogadores[k] = esquerda[i];
            i++;
        } else {
            jogadores[k] = direita[j];
            j++;
            // Incrementa trocas ao mover elementos.
            trocas++;
        }
        k++;
    }

    // Copia elementos restantes do subvetor esquerdo.
    while (i < n1) {
        jogadores[k] = esquerda[i];
        i++;
        k++;
        trocas++;  // Incrementa trocas ao mover elementos.
    }

    // Copia elementos restantes do subvetor direito.
    while (j < n2) {
        jogadores[k] = direita[j];
        j++;
        k++;
        trocas++;  // Incrementa trocas ao mover elementos.
    }

    // Libera memória temporária.
    free(esquerda);
    free(direita);
}

// Implementação recursiva do MergeSort.
void mergeSort(Jogador *jogadores, int inicio, int fim) {
    if (inicio < fim) {
        // Encontra ponto médio.
        int meio = inicio + (fim - inicio) / 2;

        // Ordena recursivamente as duas metades.
        mergeSort(jogadores, inicio, meio);
        mergeSort(jogadores, meio + 1, fim);

        // Mescla as metades ordenadas.
        merge(jogadores, inicio, meio, fim);
    }
}

// Wrapper para MergeSort para reiniciar contadores.
void mergeSortWrapper(Jogador *jogadores, int totalJogadores) {
    if (jogadores == NULL || totalJogadores <= 0) return;
    
    // Reinicia contadores de comparação e troca.
    comparacoes = 0;
    trocas = 0;

    // Chama MergeSort recursivo.
    mergeSort(jogadores, 0, totalJogadores - 1);
}

// Counting Sort adaptado para ordenação de strings (nomes) com contagem de comparações.
void countingSort(Jogador *jogadores, int totalJogadores) {
    if (jogadores == NULL || totalJogadores <= 0) return;
    
    // Reinicia contadores de comparação e troca.
    comparacoes = 0;
    trocas = 0;

    // Aloca vetor de saída.
    Jogador *output = malloc(totalJogadores * sizeof(Jogador));
    if (output == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        return;
    }

    // Encontra comprimento máximo dos nomes.
    int max_len = 0;
    for (int i = 0; i < totalJogadores; i++) {
        int len = strlen(jogadores[i].nome);
        if (len > max_len) {
            max_len = len;
        }
        comparacoes++;  // Incrementa comparações ao encontrar comprimento máximo.
    }

    // Ordena por posição de caractere, do menos significativo ao mais significativo.
    for (int pos = max_len - 1; pos >= 0; pos--) {
        // Vetor de contagem para caracteres.
        int count[256] = {0};
        
        // Conta ocorrências de caracteres na posição atual.
        for (int i = 0; i < totalJogadores; i++) {
            // Obtém caractere na posição, ou 0 se ultrapassar tamanho do nome.
            int index = (pos < (int)strlen(jogadores[i].nome)) ? 
                        (unsigned char)jogadores[i].nome[pos] : 0;
            count[index]++;
            comparacoes++;  // Incrementa contagem de comparações.
        }
        
        // Modifica vetor de contagem para posição real.
        for (int i = 1; i < 256; i++) {
            count[i] += count[i - 1];
        }
        
        // Constrói vetor de saída.
        for (int i = totalJogadores - 1; i >= 0; i--) {
            int index = (pos < (int)strlen(jogadores[i].nome)) ? 
                        (unsigned char)jogadores[i].nome[pos] : 0;
            output[count[index] - 1] = jogadores[i];
            count[index]--;
            trocas++;  // Incrementa trocas ao mover elementos.
        }
        
        // Copia de volta para o vetor original.
        memcpy(jogadores, output, totalJogadores * sizeof(Jogador));
    }

    // Libera memória alocada.
    free(output);
}