#include <stdio.h>
#include <stdlib.h>

// Renomeamos uma struct de noArvore_ para noArvore, poder utilizar noArvore como nome de structs dentro da struct principal.
typedef struct noArvore_ noArvore;
struct noArvore_{
    int valor;
    noArvore *esq; // Nó esquerdo.
    noArvore *dir; // Nó direito.
};

// Alocar um nó na Árvore Binária.
noArvore *alocaNo(int valor){
    // Alocamos o espaço da struct noArvore em um ponteiro n, definimos o valor que queremos inserir e deixamos os nós adjacentes nulos.
    noArvore *n = malloc(sizeof(noArvore));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    
    return n;
}

// Inserir um elemento na Árvore Binária.
noArvore *insere(noArvore * raiz, noArvore *n){
    // A primeira execução do programa sempre irá parar aqui, definir a raiz da árvore.
    if(raiz == NULL)return n;
    if(raiz->valor > n->valor){
        raiz->esq = insere(raiz->esq, n);
    }else{
        raiz->dir = insere(raiz->dir, n);
    }
}

// Buscar um elemento na Árvore Binária.
noArvore *busca(noArvore * raiz, int k){
    // Se raiz == NULL, não temos árvore, sem raiz. Se raiz-> valor == k, o nó correto foi encontrado
    if(raiz == NULL || raiz->valor == k)return raiz;
    // Se raiz > k, o número a ser buscado fica na esquerda, visto que uma árvore binária sempre tem um num menor a esquerda e um maior a direita.
    if(raiz->valor > k){
        return busca(raiz->esq, k);
    }else{
        return busca(raiz->dir,k);
    }
}

// Remover um nó da Árvore Binária.
noArvore *removeNo(noArvore *raiz, int valor){
    noArvore * n = busca(raiz,valor);
    if(n){  // Checa se o nó existe, if n != NULL.
        noArvore * pai = buscaPai(raiz, n);  // Descobre quem é o nó pai do nó a ser removido.
        if(pai){  // Caso tenha nó pai, if pai != NULL.
            if(pai->dir == n){ // Se  nó a ser removido é o filho a direita.
                pai->dir = removeRaiz(n);
            }else{ // Se  nó a ser removido é o filho a esquerda.
                pai->esq=removeRaiz(n);
            }
        }else{ // Não possui nó pai, logo, o nó a ser removido é a raiz.
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}

int main(){
    // Iniciamos a árvore com raiz nula.
    noArvore * raiz = NULL;

    int op = 0;
    int valor = 0;
    do{
        printf("\n**********Árvore Binária**********\n");
        printf("\n1. Inserir Nó");
        printf("\n2. Buscar Nó");
        printf("\n3. Remover Nó");
        printf("\n4. Imprimir Árvore");
        printf("\n5. Sair\n");
        printf("\nEscolha a opção desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\nInsira o valor que você deseja adicionar a árvore: ");
                scanf("%d", &valor);
                raiz = insere(raiz,alocaNo(valor));
                break;
            case 2:
                printf("\nInsira o valor que você deseja buscar na árvore: ");
                scanf("%d", &valor);
                busca(raiz, valor);
                break;
            case 3:
                printf("\nInsira o valor que você deseja remover da árvore: ");
                scanf("%d", &valor);
                removeNo(raiz, valor);
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Opção Inválida! Insira novamente: ");
                scanf("%d", &op);
                break;
        }
    }while(op != 5);

    return 0;
}