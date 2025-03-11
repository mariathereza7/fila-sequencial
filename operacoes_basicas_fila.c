#include <stdio.h>
#include <stdlib.h>

#define MAX 5//Tamanho máximo da fila

//Estrutura da fila
typedef struct {
    int itens[MAX];
    int frente;
    int tras;
} Fila;

//Função para criar uma fila vazia
void criarFila(Fila *f) {
    f->frente = -1;
    f->tras = -1;
}

//Função para verificar se a fila está vazia
int filaVazia(Fila *f) {
    return (f->frente == -1);
}

//Função para verificar se a fila está cheia
int filaCheia(Fila *f) {
    return (f->tras == MAX - 1);
}

//Função para enfileirar (inserir um item atrás)
void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    if (f->frente == -1) {
        f->frente = 0;  //A fila estava vazia, então o primeiro elemento já é a frente
    }
    f->tras++;
    f->itens[f->tras] = valor;
    printf("Elemento %d enfileirado.\n", valor);
}

//Função para desenfileirar (remover um item da frente)
int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; //Valor de erro
    }
    int valor = f->itens[f->frente];
    if (f->frente == f->tras) {
        //Se havia apenas um item na fila, ela ficará vazia após desenfileirar.
        f->frente = f->tras = -1;
    } else {
        f->frente++;
    }
    printf("Elemento %d desenfileirado.\n", valor);
    return valor;
}

//Função para exibir os elementos da fila
void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    for (int i = f->frente; i <= f->tras; i++) {
        printf("%d ", f->itens[i]);
    }
    printf("\n");
}

int main() {
    Fila f;
    criarFila(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);
    enfileirar(&f, 40);
    enfileirar(&f, 50);

    exibirFila(&f);

    desenfileirar(&f);
    exibirFila(&f);

    enfileirar(&f, 60);
    exibirFila(&f);

    return 0;
}
