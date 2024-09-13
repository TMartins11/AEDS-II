#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * O objetivo do programa Ã© funcionar como uma fila circular de alocaÃ§Ã£o sequencial.
 * As funÃ§Ãµes de inserir e remover foram deixadas incompletas, e Ã© seu trabalho Ã© completÃ¡-las
 * de modo que o programa funcione da maneira esperada.
 *
 * Importante: ao executar o programa compilado vocÃª deve utilizar-se do script executar.sh.
 * Exemplo: supondo que vocÃª tenha compilado o cÃ³digo fonte da seguinte forma:
 * gcc Q3.c -o Q3
 *
 * VocÃª deve chamar o script da seguinte forma:
 * ./executar.sh Q3
 *
 * Ou seja, o nome do executÃ¡vel gerado deve ser passado como argumento para o script.
 * Neste caso, Q3.
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
 * Complete a funÃ§Ã£o a seguir, capaz de realizar a inserÃ§Ã£o.
 * Ela deve retornar uma das seguintes opÃ§Ãµes:
 *  - cenÃ¡rio de inserÃ§Ã£o:
 *      --> retorna a posiÃ§Ã£o em que foi inserido
 *  - cenÃ¡rio fila cheia:
 *      --> retorna -1
 *
 * Sua funÃ§Ã£o deve ter no mÃ¡ximo 8 ; (ponto e vÃ­rgula).
 */

int inserir(no F[], int *f, int *r, int M, no d)
{
    int insere = -1, prov = (*r + 1) % M;
    
    if(*f != prov){
        *r = prov;
        F[*r].chave = d.chave;
        F[*r].valor = d.valor;
        insere = *r;
        if(*f == -1){
            (*f)++;
        }
    }

    return insere;
}

/**
 * Complete a funÃ§Ã£o a seguir, capaz de realizar a remoÃ§Ã£o.
 * Ela deve retornar uma das seguintes opÃ§Ãµes:
 *  - cenÃ¡rio de remoÃ§Ã£o:
 *      --> retorna o endereÃ§o para o nÃ³
 *  - cenÃ¡rio de fila vazia:
 *      --> NULL
 *
 * Sua funÃ§Ã£o deve ter no mÃ¡ximo 8 ; (ponto e vÃ­rgula).
 */

no *remover(no F[], int *f, int *r, int M)
{
    no *retorno = NULL;

    if(*f != -1){
        retorno = &F[*f];
        if(*f == *r){
            *f = *r = -1;
        }else{
            *f = (*f + 1) % M;
        }
    }

    return retorno;
}

//  5  4  3  2 1


void imprimir(no F[], int f, int r, int M, char *arq_saida)
{
    FILE *saida = fopen(arq_saida, "a");

    if (f == -1)
    {
        fprintf(saida, "<fila vazia!>");
    }
    else
    {
        fprintf(saida, "f-> ");
        while (f != r)
        {
            fprintf(saida, "%d:%d", F[f].chave, F[f].valor);
            f = (f + 1) % M;
            fprintf(saida, " | ");
        }
        fprintf(saida, "r-> %d:%d", F[f].chave, F[f].valor);
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

    int M = ler_valor(entrada);
    int resposta = 1;
    int f = -1, r = -1;

    no F[M];

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
            inserir(F, &f, &r, M, novo_no);
        }
        else if (resposta == 2)
        {
            // remover
            no *no_removido = remover(F, &f, &r, M);
            if (no_removido != NULL)
            {
                free(no_removido);
            }
        }
        else if (resposta == 3)
        {
            // imprimir
            imprimir(F, f, r, M, arq_saida);
        }
    }
}