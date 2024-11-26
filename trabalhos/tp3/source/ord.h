#ifndef ORD_H

#define ORD_H

// Definindo constantes para o limite de dados a serem interpretados pelo programa.
#define MAX_STRING 100
#define MAX_PLAYERS 1149
#define MAX_LINE_SIZE 256

// Variáveis globais para armazenar o número de trocas e comparações durante a ordenação.
extern unsigned long long int comparacoes;
extern unsigned long long int trocas;

// Struct para armazenar um jogador.
typedef struct{
    char nome[MAX_STRING];
    char posicao[MAX_STRING];
    char naturalidade[MAX_STRING];
    char clube[MAX_STRING];
    int idade;
}Jogador;

void trocar(Jogador *a, Jogador *b); // Função auxiliar para trocar duas posições de um vetor.
int comparar(const char *str1, const char *str2); // Função auxiliar para comparar lexicamente duas strings.

void bubbleSort(Jogador *jogador, int n); // Algoritmo de ordenação BubbleSort - Ordenação simples.

void merge(int arr[], int l, int m, int r); // Função recursiva que será usada no algoritmo MergeSort.
void mergeSort(int arr[], int l, int r); // Algoritmo de ordenação MergeSort - Ordenação Ótima.

#endif