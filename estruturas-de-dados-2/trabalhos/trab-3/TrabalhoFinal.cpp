#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Estruturas e funções anteriores
typedef struct NoAdj* ApontadorNo;

typedef struct NoAdj {
    int destino;
    ApontadorNo prox;
} TNoAdj;

typedef struct ListaAdj* ApontadorLista;

typedef struct ListaAdj {
    ApontadorNo cabeca;
    int grau;
} TListaAdj;

typedef struct Grafo {
    int n; // número de vértices
    ApontadorLista array;
} TGrafo;

ApontadorNo novoNo(int destino) {
    ApontadorNo no = (ApontadorNo) malloc(sizeof(TNoAdj));
    no->destino = destino;
    no->prox = NULL;
    return no;
}

TGrafo* novoGrafo(int n) {
    TGrafo* grafo = (TGrafo*) malloc(sizeof(TGrafo));
    grafo->n = n;

    grafo->array = (ApontadorLista) malloc(n * sizeof(TListaAdj));

    for (int i = 0; i < n; ++i) {
        grafo->array[i].cabeca = NULL;
        grafo->array[i].grau = 0;
    }

    return grafo;
}

void novaAresta(TGrafo* grafo, int origem, int destino) {
    ApontadorNo no = novoNo(destino);
    no->prox = grafo->array[origem].cabeca;
    grafo->array[origem].cabeca = no;
    grafo->array[origem].grau++;

    no = novoNo(origem);
    no->prox = grafo->array[destino].cabeca;
    grafo->array[destino].cabeca = no;
    grafo->array[destino].grau++;
}

void imprimir(TGrafo* grafo) {
    for (int v = 0; v < grafo->n; ++v) {
        ApontadorNo no = grafo->array[v].cabeca;
        printf("Lista de adjacencias do vertice %d(grau=%d) ", v, grafo->array[v].grau);
        while (no) {
            printf("-> %d", no->destino);
            no = no->prox;
        }
        printf("\n");
    }
}

// Função para executar a BFS
void BFS(TGrafo* grafo, int verticeInicial) {
    int *distancia = (int*) malloc(grafo->n * sizeof(int));
    for (int i = 0; i < grafo->n; i++) {
        distancia[i] = INT_MAX; // Inicializa todas as distâncias como infinito
    }
    distancia[verticeInicial] = 0; // Distância do vértice inicial para si mesmo é 0

    int *fila = (int*) malloc(grafo->n * sizeof(int));
    int inicio = 0, fim = 0;

    // Enfileira o vértice inicial
    fila[fim++] = verticeInicial;

    while (inicio < fim) {
        int vertice = fila[inicio++]; // Desenfileira um vértice

        // Percorre todos os vértices adjacentes
        ApontadorNo noAdj = grafo->array[vertice].cabeca;
        while (noAdj) {
            int destino = noAdj->destino;

            // Se o vértice não foi visitado
            if (distancia[destino] == INT_MAX) {
                distancia[destino] = distancia[vertice] + 1;
                fila[fim++] = destino;
            }

            noAdj = noAdj->prox;
        }
    }

    // Imprime as distâncias
    for (int i = 0; i < grafo->n; i++) {
        printf("Distancia do vertice %d para o vertice %d: %d\n", verticeInicial, i, distancia[i]);
    }

    free(distancia);
    free(fila);
}

int main() {
    int n = 10; // Número de vértices do grafo
    TGrafo* graph = novoGrafo(n);

    // Adiciona as arestas
    novaAresta(graph, 0, 1);
    novaAresta(graph, 0, 2);
    novaAresta(graph, 1, 6);
    novaAresta(graph, 1, 4);
    novaAresta(graph, 2, 4);
    novaAresta(graph, 2, 3);
    novaAresta(graph, 6, 9);
    novaAresta(graph, 6, 5);
    novaAresta(graph, 6, 4); 
    novaAresta(graph, 4, 7);
    novaAresta(graph, 9, 5);
    novaAresta(graph, 7, 8);
    novaAresta(graph, 5, 3);
    novaAresta(graph, 8, 3);

    // Imprime a lista de adjacências do grafo
    imprimir(graph);

    // Executa a BFS a partir do vértice 0
    BFS(graph, 2);

    return 0;
}
