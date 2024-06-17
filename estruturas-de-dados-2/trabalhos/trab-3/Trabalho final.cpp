#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Definição das estruturas do grafo
typedef struct NoAdj* ApontadorNo;

typedef struct NoAdj {
    int destino;
    ApontadorNo prox;
} TNoAdj;

typedef struct ListaAdj* ApontadorLista;

typedef struct ListaAdj {
    ApontadorNo cabeca;
} TListaAdj;

typedef struct Grafo {
    int n; // número de vértices
    TListaAdj array[MAX_VERTICES]; // array de listas de adjacências
} TGrafo;

// Função para criar um novo nó da lista de adjacências
ApontadorNo novoNo(int destino) {
    ApontadorNo no = (ApontadorNo) malloc(sizeof(TNoAdj));
    no->destino = destino;
    no->prox = NULL;
    return no;
}

// Função para adicionar uma aresta ao grafo não direcionado
void novaAresta(TGrafo* grafo, int origem, int destino) {
    // Adiciona uma aresta de origem para destino
    ApontadorNo no = novoNo(destino);
    no->prox = grafo->array[origem].cabeca;
    grafo->array[origem].cabeca = no;
}

// Função para imprimir as menores distâncias a partir de um vértice usando BFS
void BFS(TGrafo* grafo, int origem) {
    int visitado[MAX_VERTICES] = {0}; // vetor para marcar os vértices visitados
    int distancia[MAX_VERTICES]; // vetor de distâncias
    int fila[MAX_VERTICES]; // fila para a BFS
    int frente = 0, tras = 0;

    // Inicializa todas as distâncias como -1 (não alcançável)
    for (int i = 0; i < grafo->n; ++i)
        distancia[i] = -1;

    // Começa a BFS a partir do vértice de origem
    fila[tras++] = origem;
    visitado[origem] = 1;
    distancia[origem] = 0;

    while (frente != tras) {
        int u = fila[frente++];
        ApontadorNo no = grafo->array[u].cabeca;
        while (no) {
            int v = no->destino;
            if (!visitado[v]) {
                fila[tras++] = v;
                visitado[v] = 1;
                distancia[v] = distancia[u] + 1;
            }
            no = no->prox;
        }
    }

    // Imprime as distâncias
    printf("Menores distancias a partir do vertice %d:\n", origem);
    for (int i = 0; i < grafo->n; ++i) {
        printf("Vertice %d: ", i);
        if (distancia[i] == -1)
            printf("Nao alcancavel\n");
        else
            printf("%d\n", distancia[i]);
    }
}

int main() {
    int n = 5; // Número de vértices do grafo
    TGrafo* graph = (TGrafo*) malloc(sizeof(TGrafo));
    graph->n = n;

    // Inicializa as listas de adjacências
    for (int i = 0; i < n; ++i)
        graph->array[i].cabeca = NULL;

    // Adiciona as arestas
    novaAresta(graph, 0, 1);
    novaAresta(graph, 0, 4);
    novaAresta(graph, 1, 2);
    novaAresta(graph, 1, 3);
    novaAresta(graph, 1, 4);
    novaAresta(graph, 2, 3);
    novaAresta(graph, 3, 4);
    novaAresta(graph, 0, 2);

    // Chama a BFS a partir do vértice 0
    BFS(graph, 0);

    return 0;
}
