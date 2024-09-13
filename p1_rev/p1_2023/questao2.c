#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * O objetivo do programa Ã© manipular uma lista com alocaÃ§Ã£o sequencial
 * cujos valores serÃ£o inseridos em ordem crescente.
 * A funÃ§Ã£o de busca binÃ¡ria foi deixada incompleta, e Ã© seu trabalho Ã© completÃ¡-la
 * de modo que o programa funcione da maneira esperada.
 * Todas as entradas de dados realizam as inserÃ§Ãµes jÃ¡ em ordem crescente, de modo
 * que a busca binÃ¡ria possa funcionar sem problemas.
 * Ou seja, vocÃª deve assumir que o vetor a ser recebido pela funÃ§Ã£o de busca binÃ¡ria
 * terÃ¡ sempre os nÃºmeros jÃ¡ previamente ordenados em ordem crescente.
 *
 * Importante: ao executar o programa compilado vocÃª deve utilizar-se do script executar.sh.
 * Exemplo: supondo que vocÃª tenha compilado o cÃ³digo fonte da seguinte forma:
 * gcc Q2.c -o Q2
 *
 * VocÃª deve chamar o script da seguinte forma:
 * ./executar.sh Q2
 *
 * Ou seja, o nome do executÃ¡vel gerado deve ser passado como argumento para o script.
 * Neste caso, Q2.
 *
 * Dentro do diretÃ³rio vocÃª encontrarÃ¡ diversos casos de teste, nomeados como:
 *  - entrada_1.txt
 *  - entrada_2.txt
 *  ...
 *
 * Para cada arquivo de entrada existirÃ¡ um gabarito correspondente. ou Seja:
 *  - gabarito_1.txt
 *  - gabarito_2.txt
 *  ...
 *
 *  VocÃª NÃƒO deve alterar estes arquivos.
 *
 * Ao executar o script executar.sh ele compararÃ¡ a saÃ­da produzida pelo seu programa com os gabaritos.
 * VocÃª terÃ¡ o resultado do teste para cada entrada.
 */

typedef struct no_
{
    int chave;
    int valor;
} no;

/**
 * Complete a funÃ§Ã£o a seguir, capaz de realizar a busca binÃ¡ria.
 * Ela deve retornar uma das seguintes opÃ§Ãµes:
 *  - cenÃ¡rio de inserÃ§Ã£o:
 *    -> caso a chave passada nÃ£o esteja presente na lista:
 *          --> retorna -1
 *  - cenÃ¡rio de nÃ£o inserÃ§Ã£o:
 *    -> caso a chave passada esteja presente na lista:
 *          --> retorna o Ã­ndice do elemento que contÃ©m a chave
 *
 * Sua funÃ§Ã£o deve ter no mÃ¡ximo 8 ; (ponto e vÃ­rgula).
 */

int busca_bin(no L[], int n, int x)
{
    int inf = 0, sup = n - 1; 
    
    while(inf <= sup){
        int meio = (int) (inf + sup) / 2;
        if(L[meio].chave == x){
            return meio;
        }else if(L[meio].chave > x){
            sup = meio - 1;
        }else{
            inf = meio + 1;
        }
    }
    
    return -1;
}

int inserir(no L[], int n, int m, no d)
{
    if (n < m)
    {
        if (busca_bin(L, n, d.chave) == -1)
        {
            L[n].chave = d.chave;
            L[n].valor = d.valor;
            return n + 1;
        }
        return 0;
    }
    return -1;
}

no *remover(int x, no L[], int *n)
{
    no *retorno = NULL;
    if (n != 0)
    {
        int indice = busca_bin(L, *n, x);
        if (indice >= 0)
        {
            retorno = malloc(sizeof(no));
            (*retorno).chave = L[indice].chave;
            (*retorno).valor = L[indice].valor;

            for (int i = indice; i < (*n) - 1; i++)
            {
                L[i].chave = L[i + 1].chave;
                L[i].valor = L[i + 1].valor;
            }
            *n = (*n) - 1;
        }
    }

    return retorno;
}

void imprimir(no L[], int n, char *arq_saida)
{
    FILE *saida = fopen(arq_saida, "a");
    if (!n)
    {
        fprintf(saida, "<lista vazia!>");
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(saida, "%d:%d", L[i].chave, L[i].valor);
        if (i < n - 1)
            fprintf(saida, " | ");
    }
    fprintf(saida, "\n");
    fclose(saida);
}

void gera_nomes_arquivos(char *arq_entrada, char *arq_saida, char *comp)
{
    strcpy(arq_entrada, "entrada_");
    strcat(arq_entrada, comp);
    strcat(arq_entrada, ".txt");

    strcpy(arq_saida, "saida_");
    strcat(arq_saida, comp);
    strcat(arq_saida, ".txt");
}

int ler_valor(FILE *entrada)
{
    int valor;
    fscanf(entrada, "%d", &valor);
    return valor;
}

void main(int argc, char **argv)
{
    char arq_entrada[14];
    char arq_saida[12];
    gera_nomes_arquivos(arq_entrada, arq_saida, argv[1]);
    FILE *entrada = fopen(arq_entrada, "r");

    int m = ler_valor(entrada);
    int n = 0;
    int resposta = 1;

    no L[m];

    while (resposta != 0)
    {
        resposta = ler_valor(entrada);

        if (resposta == 0)
        {
            // sair
            fclose(entrada);
            return;
        }
        else if (resposta == 1)
        {
            // inserir
            no novo_no;
            novo_no.chave = ler_valor(entrada);
            novo_no.valor = ler_valor(entrada);

            int valor_retornado = inserir(L, n, m, novo_no);
            if (valor_retornado > 0)
            {
                n = valor_retornado;
            }
        }
        else if (resposta == 2)
        {
            // remover
            int chave = ler_valor(entrada);

            no* no_removido = remover(chave, L, &n);
            if(no_removido != NULL){
                free(no_removido);
            }
        }
        else if (resposta == 3)
        {
            // imprimir
            imprimir(L, n, arq_saida);
        }
    }
}