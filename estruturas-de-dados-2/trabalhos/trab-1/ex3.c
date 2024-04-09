#include <stdio.h>

typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
} Contato;

void inserirDados(Contato *contato) {
    printf("Digite o nome:\n");
    scanf("%s", contato->nome);

    printf("Digite o telefone:\n");
    scanf("%s", contato->telefone);

    printf("Digite a email:\n");
    scanf("%s", contato->email);
}

void pesquisarContato(Contato contatos[]) {
    int i = 0;
    printf("Digite o índice do contato:\n");
    scanf("%d", &i);

    printf("\nNome: %s\nTelefone: %s\nEmail: %s\n", contatos[i].nome, contatos[i].telefone, contatos[i].email);
}

void imprimirContatos(Contato contatos[]) {
    for(int i = 0; i < 5; i++)
        printf("\nNome: %s\nTelefone: %s\nEmail: %s\n", contatos[i].nome, contatos[i].telefone, contatos[i].email);
}

int main() {
    Contato contatos[5];

    for(int i = 0; i < 5; i++)
        inserirDados(&contatos[i]);

    pesquisarContato(contatos);

    imprimirContatos(contatos);

    return 0;
}
