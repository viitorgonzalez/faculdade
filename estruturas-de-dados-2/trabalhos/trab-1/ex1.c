#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

void inserirDados(Aluno *aluno) {
    printf("Digite o nome:\n");
    scanf("%s", aluno->nome);

    printf("Digite a idade:\n");
    scanf("%d", &aluno->idade);

    printf("Digite a nota:\n");
    scanf("%f", &aluno->nota);
}

void imprimirAluno(Aluno aluno) {
    printf("\nNome: %s\nIdade: %d\nNota: %.2f\n", aluno.nome, aluno.idade, aluno.nota);
}

float calculaMedia(Aluno alunos[]) {
    float media = 0;
    for(int i = 0; i < 5; i++) 
        media += alunos[i].nota;

    media /= 5;

    return media;
}

int main() {
    Aluno alunos[5];

    for(int i = 0; i < 5; i++)
        inserirDados(&alunos[i]);

    for(int i = 0; i < 5; i++)
        imprimirAluno(alunos[i]);

    printf("\nMédia das notas: %.2f\n", calculaMedia(alunos));

    return 0;
}
