#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int conteudo;
    struct no *esq, *dir;
} No;

typedef struct {
    No *raiz;
} ArvB;

void inserirEsq(No *no, int valor) {
    if(no->esq == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->esq = novo;
    }
    else {
        (valor < no->esq->conteudo) ? inserirEsq(no->esq, valor) : inserirDir(no->esq, valor);
    }
}

void inserirDir(No *no, int valor) {
    if(no->dir == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->dir = novo;
    }
    else {
        (valor > no->dir->conteudo) ? inserirEsq(no->dir, valor) : inserirDir(no->dir, valor);
    }
}

void inserir(ArvB *arv, int valor) {
    if(arv->raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        arv->raiz = novo;
    } 
    else 
        (valor < arv->raiz->conteudo) ? inserirEsq(arv->raiz, valor) : inserirDir(arv->raiz, valor);
}

int main() {


    return 0;
}
