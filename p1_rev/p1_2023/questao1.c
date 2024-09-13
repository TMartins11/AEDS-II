#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * O presente programa tem como objetivo implementar uma lista duplamente encadeada.
 * Algumas funÃ§Ãµes foram deixadas incompletas.
 * Seu trabalho Ã© completÃ¡-las de modo que o programa funcione da maneira esperada.
 *
 * Importante: ao executar o programa compilado vocÃª deve utilizar-se do script executar.sh.
 * Exemplo: supondo que vocÃª tenha compilado o cÃ³digo fonte da seguinte forma:
 * gcc Q1.c -o Q1
 *
 * VocÃª deve chamar o script da seguinte forma:
 * ./executar.sh Q1
 *
 * Ou seja, o nome do executÃ¡vel gerado deve ser passado como argumento para o script.
 * Neste caso, Q1.
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
    struct no_ *ant;
    struct no_ *prox;
} no;

no *buscar(no *ptlista, int x)
{
    no *ultimo = ptlista->ant;

    if (ultimo != ptlista && x <= ultimo->chave)
    {
        no *pont = ptlista->prox;
        while (pont->chave < x)
        {
            pont = pont->prox;
        }
        return pont;
    }
    return ptlista;
}

/**
 * Complete a funÃ§Ã£o a seguir.
 * Ela deve retornar uma das seguintes opÃ§Ãµes:
 *  - caso ocorra a inserÃ§Ã£o:
 *      --> retorna NULL
 *  - caso nÃ£o ocorra a inserÃ§Ã£o:
 *      --> retorna o endereÃ§o retornado pela funÃ§Ã£o buscar
 *
 * Sua funÃ§Ã£o deve ter no mÃ¡ximo 9 ; (ponto e vÃ­rgula).
 */
no *inserir(no *ptlista, no *novo_no)
{
    no *pont = buscar(ptlista, novo_no->chave);

    if(pont == ptlista || novo_no->chave != pont->chave){
        novo_no->ant = pont->ant;
        novo_no->prox = pont;
        pont->ant->prox = novo_no;
        pont->ant = novo_no;
        return NULL;
    }
    return pont;
}

/**
 * Complete a funÃ§Ã£o a seguir.
 * Ela deve retornar uma das seguintes opÃ§Ãµes:
 *  - caso ocorra a remoÃ§Ã£o:
 *      --> endereÃ§o do nÃ³ removido
 *  - caso nÃ£o ocorra a remoÃ§Ã£o (nÃ³ nÃ£o encontrado):
 *      --> NULL
 *
 * Sua funÃ§Ã£o deve ter no mÃ¡ximo 7 ; (ponto e vÃ­rgula).
 */
no *remover(no *ptlista, int x)
{
    no *pont = buscar(ptlista, x);
    if(pont != ptlista && pont->chave == x){
        pont->ant->prox = pont->prox;
        pont->prox->ant = pont->ant;
        return pont;
    }
    return NULL;
}
// 1 2 3 ; pont = 2

void imprimir_crescente(no *ptlista, char *arq_saida)
{
    FILE *saida = fopen(arq_saida, "a");

    no *proximo = ptlista->prox;
    if (proximo == ptlista)
    {
        fprintf(saida, "<lista vazia!>");
    }
    else
    {
        while (proximo != ptlista)
        {
            fprintf(saida, "%d:%d", proximo->chave, proximo->valor);
            proximo = proximo->prox;
            if (proximo != ptlista)
                fprintf(saida, " -> ");
        }
    }
    fprintf(saida, "\n");
    fclose(saida);
}

void imprimir_decrescente(no *ptlista, char *arq_saida)
{
    FILE *saida = fopen(arq_saida, "a");

    no *anterior = ptlista->ant;
    if (anterior == ptlista)
    {
        fprintf(saida, "<lista vazia!>");
    }
    else
    {
        while (anterior != ptlista)
        {
            fprintf(saida, "%d:%d", anterior->chave, anterior->valor);
            anterior = anterior->ant;
            if (anterior != ptlista)
                fprintf(saida, " -> ");
        }
    }
    fprintf(saida, "\n");
    fclose(saida);
}

void desalocar_lista(no *ptlista)
{
    no *proximo = ptlista->prox;
    while (proximo != ptlista)
    {
        no *temp = proximo->prox;
        free(proximo);
        proximo = temp;
    }
    free(ptlista);
}

int ler_valor(FILE *entrada)
{
    int valor;
    fscanf(entrada, "%d", &valor);
    return valor;
}

no *alocar_no(int chave, int valor)
{
    no *novo_no = malloc(sizeof(no));
    novo_no->chave = chave;
    novo_no->valor = valor;
    novo_no->prox = NULL;
    novo_no->ant = NULL;
    return novo_no;
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

void inicia_lista(no **ptlista)
{
    *ptlista = malloc(sizeof(no));

    (*(*ptlista)).ant = (*ptlista);
    (*(*ptlista)).prox = (*ptlista);
}

void main(int argc, char **argv)
{
    no *ptlista;
    inicia_lista(&ptlista);

    char arq_entrada[14];
    char arq_saida[12];
    gera_nomes_arquivos(arq_entrada, arq_saida, argv[1]);
    FILE *entrada = fopen(arq_entrada, "r");

    int resposta = 1;
    while (resposta != 0)
    {
        resposta = ler_valor(entrada);

        if (resposta == 0)
        {
            // sair
            desalocar_lista(ptlista);
            fclose(entrada);
            return;
        }
        else if (resposta == 1)
        {
            // inserir
            int chave = ler_valor(entrada);
            int valor = ler_valor(entrada);
            no *novo_no = alocar_no(chave, valor);
            if (inserir(ptlista, novo_no) != NULL)
            {
                free(novo_no);
            }
        }
        else if (resposta == 2)
        {
            // remover
            int chave = ler_valor(entrada);
            no *no_removido = remover(ptlista, chave);
            if (no_removido != NULL)
            {
                free(no_removido);
            }
        }
        else if (resposta == 3)
        {
            // imprimir ordem crescente
            imprimir_crescente(ptlista, arq_saida);
        }
        else if (resposta == 4)
        {
            // imprimir ordem decrescente
            imprimir_decrescente(ptlista, arq_saida);
        }
    }
}