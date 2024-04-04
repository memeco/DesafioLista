#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura da pilha
typedef struct No
{
    char livro[20];
    struct No *proximo;
} No;

typedef struct
{
    No *topo;
    int tamanho;
} PilhaLivros;

// Funções da Pilha
void inicializarPilha(PilhaLivros *pilha)
{
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

void empilharLivro(PilhaLivros *pilha, char *livro)
{
    No *novoNo = (No *)malloc(sizeof(No));
    strcpy(novoNo->livro, livro);
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    pilha->tamanho++;
}

void desempilharLivro(PilhaLivros *pilha)
{
    if (pilha->topo == NULL)
    {
        printf("Erro: Pilha vazia. Não é possível remover o livro.\n");
        return;
    }
    No *aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(aux);
    pilha->tamanho--;
}

void imprimirPilhaInvertida(PilhaLivros *pilha)
{
    No *atual = pilha->topo;
    while (atual != NULL)
    {
        printf("%s\n", atual->livro);
        atual = atual->proximo;
    }
}

// Função Principal
int main()
{
    PilhaLivros pilha;
    inicializarPilha(&pilha);

    // Empilhando os livros fornecidos
    empilharLivro(&pilha, "Livro A");
    empilharLivro(&pilha, "Livro B");
    empilharLivro(&pilha, "Livro C");
    empilharLivro(&pilha, "Livro D");
    empilharLivro(&pilha, "Livro E");

    // Imprimindo a pilha na ordem inversa
    printf("Livros empilhados na ordem inversa:\n");
    imprimirPilhaInvertida(&pilha);

    return 0;
}
