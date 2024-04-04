#include <stdio.h>
#include <stdlib.h>

/*==========================ESTRUTURA==========================*/

typedef struct 
{
    int chave;
    /*outros componentes*/
} TipoItem;

typedef struct Celula *TipoApontador; 

typedef struct Celula
{
    TipoItem item;
    TipoApontador esq, dir;
} TipoCelula;

/*==========================OPERAÇÕES==========================*/

void FAVazia(TipoApontador *arvore)
{
    *arvore = NULL;
}

int Vazia(TipoApontador *arvore)
{
    return (*arvore == NULL);
}

void Insere(TipoApontador *arvore, TipoItem i)
{
    if (*arvore == NULL)
    {
        *arvore = (TipoApontador) malloc(sizeof(TipoCelula));
        (*arvore)->esq = NULL;
        (*arvore)->dir = NULL;
        (*arvore)->item = i;
        printf("\nChave inserida com sucesso!");
    }
    else
    {
        if (i.chave < (*arvore)->item.chave)
        {
            Insere(&(*arvore)->esq, i); //Faz a chamada recursiva com 2 parâmetros: endereço de memória da subárvore da esquerda e o TipoItem
        }
        else if (i.chave > (*arvore)->item.chave)
        {
            Insere(&(*arvore)->dir, i); //Faz a chamada recursiva com 2 parâmetros: endereço de memória da subárvore da direita e o TipoItem
        }
        else printf("\nChave existente dentro da arvore!");
    }
}

int Pesquisa(TipoApontador *a, TipoItem item)
{
    if ((*a) == NULL)
    {
        return 0; //chegou a um nó folha e não encontrou o item
    }
    else
    {
        if (item.chave < (*a)->item.chave)
        {
            Pesquisa(&(*a)->esq, item); 
        }
        else if (item.chave > (*a)->item.chave)
        {
            Pesquisa(&(*a)->dir, item);
        }
        else {
            return 1; //encontrou o item pesquisado
        }
    }
}

void ExibePreOrdem(TipoApontador *a)
{
    if (*a != NULL)
    {
        printf("\n%d", (*a)->item.chave); //Imprime raiz, chama a esquerda e em seguinda a direita
        ExibePreOrdem(&(*a)->esq);
        ExibePreOrdem(&(*a)->dir);
    }
}

void ExibeInOrdem(TipoApontador *a)
{
    if (*a != NULL)
    {
        ExibeInOrdem(&(*a)->esq); //Faz a chamada para a subárvore à esquerda, imprime a raiz depois chama à direita - Order Crescente
        printf("\n%d", (*a)->item.chave);
        ExibeInOrdem(&(*a)->dir);
    }
}

void ExibePosOrdem(TipoApontador *a)
{
    if (*a != NULL)
    {
        ExibePosOrdem(&(*a)->esq); //Faz a chamada à esquerda, chama à direita e por fim imprime a raiz
        ExibePosOrdem(&(*a)->dir); 
        printf("\n%d", (*a)->item.chave);
    }
}

//Implementar o Retira aqui

void Menu()
{
    printf("\n|---------------------------------------|");
	printf("\n|-----------------MENU------------------|");
	printf("\n| 1- Inserir na Arvore                  |");
    printf("\n| 2- Pesquisar na Arvore                |");
//	printf("\n| 3- Retirar da Arvore                  |");
	printf("\n| 4- Exibir Arvore                      |");
//    printf("\n| 5- Buscar Parente                     |");
	printf("\n| 0- Sair                               |");
	printf("\n|---------------------------------------|");
	printf("\n Digite a opcao desejada: ");
}

int main()
{
    TipoApontador arvore;
    TipoItem i;
    int op, x;

    FAVazia(&arvore);

    do
    {
        Menu();
        scanf("%d", &op);

        if (op == 1)
        {
            printf("\nDigite o valor da chave: ");
            scanf("%d", &i.chave);

            Insere(&arvore, i);

            printf("\nTecle ENTER para continuar...");
            //__fpurge(stdin); //Limpar buffer do teclado no Linux
            fflush(stdin); //Limpar buffer do teclado no Windows
            getchar();
        }
        else if (op == 2)
        {
            printf("\nDigite o valor que deseja pesquisar: ");
            scanf("%d", &i.chave);

            if (Pesquisa(&arvore, i) == 1) {
                printf("\nChave encontrada!");
            }
            else printf("\nChave nao encontrada!");

            printf("\nTecle ENTER para continuar...");
            //__fpurge(stdin); //Limpar buffer do teclado no Linux
            fflush(stdin); //Limpar buffer do teclado no Windows
            getchar();
        }
        /* Implementar a chamada do Retira aqui */
        else if (op == 4)
        {
            ExibePreOrdem(&arvore);

            printf("\nTecle ENTER para continuar...");
            //__fpurge(stdin); //Limpar buffer do teclado no Linux
            fflush(stdin); //Limpar buffer do teclado no Windows
            getchar();
        }
        /* Implementar a busca do parente aqui */
    } while (op != 0);
    
    return 0;
}