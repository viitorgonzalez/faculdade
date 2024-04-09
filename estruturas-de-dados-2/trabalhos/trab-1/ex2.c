#include <stdio.h>

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void inserirDados(Produto *produto) {
    printf("Digite o nome: \n");
    scanf("%s", produto->nome);

    printf("Digite a quantidade: \n");
    scanf("%d", &produto->quantidade);

    printf("Digite o preço: \n");
    scanf("%f", &produto->preco);
}

void autalizarQuantidade(Produto produtos[], int i) {
    int novaQ = 0;
    printf("Digite a nova quantidade: \n");
    scanf("%d", &novaQ);

    produtos[i].quantidade = novaQ;
}

void imprimirProduto(Produto produto) {
    printf("\nNome: %s\nQuantidade: %d\nPreço: %.2f\n", produto.nome, produto.quantidade, produto.preco);
}

int main() {
    Produto produtos[5];
    int op = 0;

    for(int i = 0; i < 5; i++)
        inserirDados(&produtos[i]);

    printf("Digite o índice do produto: \n");
    scanf("%d", &op);

    autalizarQuantidade(produtos, op);

    printf("Digite o índice do produto que deseja ver\n");
    scanf("%d", &op);

    imprimirProduto(produtos[op]);

    return 0;
}
