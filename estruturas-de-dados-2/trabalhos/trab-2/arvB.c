#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char telefone[20];
    char email[50];
} TipoContato;

typedef struct celulaContato {
    TipoContato contato;
    struct celulaContato *esq, *dir;
} TipoCelula;

void FAVazia(TipoCelula **raiz) {
    *raiz = NULL;
}

void Insere(TipoCelula **raiz, TipoContato novoContato) {
    if (*raiz == NULL) {
        *raiz = (TipoCelula*)malloc(sizeof(TipoCelula));
        (*raiz)->contato = novoContato;
        (*raiz)->esq = (*raiz)->dir = NULL;
    } else {
        if (strcmp(novoContato.nome, (*raiz)->contato.nome) < 0)
            Insere(&((*raiz)->esq), novoContato);
        else
            Insere(&((*raiz)->dir), novoContato);
    }
}

TipoContato* Pesquisa(TipoCelula *raiz, char nome[]) {
    if (raiz == NULL)
        return NULL;
    else if (strcmp(nome, raiz->contato.nome) == 0)
        return &(raiz->contato);
    else if (strcmp(nome, raiz->contato.nome) < 0)
        return Pesquisa(raiz->esq, nome);
    else
        return Pesquisa(raiz->dir, nome);
}

void Retira(TipoCelula **raiz, char nome[]) {
    if (*raiz == NULL)
        return;
    if (strcmp(nome, (*raiz)->contato.nome) < 0)
        Retira(&((*raiz)->esq), nome);
    else if (strcmp(nome, (*raiz)->contato.nome) > 0)
        Retira(&((*raiz)->dir), nome);
    else {
        TipoCelula *aux = *raiz;
        if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
            free(aux);
            *raiz = NULL;
        } else if ((*raiz)->esq == NULL) {
            *raiz = (*raiz)->dir;
            free(aux);
        } else if ((*raiz)->dir == NULL) {
            *raiz = (*raiz)->esq;
            free(aux);
        } else {
            aux = (*raiz)->esq;
            while (aux->dir != NULL)
                aux = aux->dir;
            (*raiz)->contato = aux->contato;
            Retira(&((*raiz)->esq), aux->contato.nome);
        }
    }
}

void ExibeInOrdem(TipoCelula *raiz) {
    if (raiz != NULL) {
        ExibeInOrdem(raiz->esq);
        printf("Nome: %s\nTelefone: %s\nEmail: %s\n\n", raiz->contato.nome, raiz->contato.telefone, raiz->contato.email);
        ExibeInOrdem(raiz->dir);
    }
}

void ExibeMenu() {
    printf("\nMenu de Opcoes:\n");
    printf("1. Inserir Contato\n");
    printf("2. Pesquisar Contato\n");
    printf("3. Remover Contato\n");
    printf("4. Exibir Todos os Contatos\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    TipoCelula *raiz;
    TipoContato contato;
    int opcao;
    char nome[100];

    FAVazia(&raiz);

    do {
        ExibeMenu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\nDigite o nome do contato: ");
                fgets(contato.nome, 100, stdin);
                contato.nome[strcspn(contato.nome, "\n")] = '\0';
                printf("Digite o telefone do contato: ");
                fgets(contato.telefone, 20, stdin);
                contato.telefone[strcspn(contato.telefone, "\n")] = '\0';
                printf("Digite o email do contato: ");
                fgets(contato.email, 50, stdin);
                contato.email[strcspn(contato.email, "\n")] = '\0';
                Insere(&raiz, contato);
                break;
            case 2:
                printf("\nDigite o nome do contato a ser pesquisado: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                TipoContato *resultado = Pesquisa(raiz, nome);
                if (resultado != NULL)
                    printf("\nNome: %s\nTelefone: %s\nEmail: %s\n", resultado->nome, resultado->telefone, resultado->email);
                else
                    printf("\nContato nao encontrado.\n");
                break;
            case 3:
                printf("\nDigite o nome do contato a ser removido: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                Retira(&raiz, nome);
                break;
            case 4:
                printf("\nContatos existentes na arvore (em ordem alfabética):\n");
                ExibeInOrdem(raiz);
                break;
            case 5:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
