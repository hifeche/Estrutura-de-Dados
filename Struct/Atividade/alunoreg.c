#include <stdio.h>
#define MAX_ALUNOS 40
#define TAM_NOME 41
#define ARQUIVO "alunos.bin"

typedef struct
{
    char nome[TAM_NOME];
    int matricula;
    float prova1;
    float prova2;
    float media;
    int faltas;
    char situacao[12];
} Aluno;

void calcularAluno(Aluno *aluno)
{
    aluno->media = (aluno->prova1 + aluno->prova2) / 2.0;

    if (aluno->media >= 6.0 && aluno->faltas <= 20)
    {
        strcpy(aluno->situacao, "Aprovado");
    }
    else
    {
        strcpy(aluno->situacao, "Reprovado");
    }
}

/* Insere os alunos */
void inserirAlunos(Aluno turma[], int *total)
{
    int quantidade;

    if (*total >= MAX_ALUNOS)
    {
        printf("\nA turma ja possui 40 alunos.\n");
        return;
    }

    printf("\nQuantos alunos deseja inserir? ");
    scanf("%d", &quantidade);
    getchar();

    if (quantidade <= 0)
    {
        printf("Quantidade invalida.\n");
        return;
    }

    if (*total + quantidade > MAX_ALUNOS)
    {
        printf("Nao e possivel inserir %d alunos.\n", quantidade);
        printf("A turma pode ter no maximo %d alunos.\n", MAX_ALUNOS);
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("\n===== Aluno %d =====\n", *total + 1);

        printf("Nome: ");
        fgets(turma[*total].nome, TAM_NOME, stdin);

        /* Remove o \n do final do nome */
        turma[*total].nome[strcspn(turma[*total].nome, "\n")] = '\0';

        printf("Matricula: ");
        scanf("%d", &turma[*total].matricula);

        printf("Prova 1: ");
        scanf("%f", &turma[*total].prova1);

        printf("Prova 2: ");
        scanf("%f", &turma[*total].prova2);

        printf("Faltas: ");
        scanf("%d", &turma[*total].faltas);

        getchar();

        /* Calcula media e situacao */
        calcularAluno(&turma[*total]);

        (*total)++;

        printf("Aluno cadastrado com sucesso!\n");
    }
}


void listarAlunos(Aluno turma[], int total)
{
    if (total == 0)
    {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n--- ALUNOS ---\n");

    for (int i = 0; i < total; i++)
    {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: %s\n", turma[i].nome);
        printf("Matricula: %d\n", turma[i].matricula);
        printf("Prova 1: %.1f\n", turma[i].prova1);
        printf("Prova 2: %.1f\n", turma[i].prova2);
        printf("Media: %.1f\n", turma[i].media);
        printf("Faltas: %d\n", turma[i].faltas);
        printf("Situacao: %s\n", turma[i].situacao);
    }
}

void salvarDados(Aluno turma[], int total)
{
    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "wb");

    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    /* Salva primeiro a quantidade de alunos */
    fwrite(&total, sizeof(int), 1, arquivo);

    /* Salva o vetor de alunos */
    fwrite(turma, sizeof(Aluno), total, arquivo);

    fclose(arquivo);

    printf("\nDados salvos com sucesso!\n");
}


/* Carrega os alunos do arquivo */
void carregarDados(Aluno turma[], int *total)
{
    FILE *alunoreg;

    alunoreg = fopen(ARQUIVO, "rb");

    if (alunoreg == NULL)
    {
        printf("\nNenhum arquivo de dados encontrado.\n");
        return;
    }

    /* Le a quantidade de alunos */
    fread(total, sizeof(int), 1, alunoreg);

    if (*total < 0 || *total > MAX_ALUNOS)
    {
        printf("\nArquivo invalido.\n");
        fclose(alunoreg);
        *total = 0;
        return;
    }

    /* Le os alunos */
    fread(turma, sizeof(Aluno), *total, alunoreg);

    fclose(alunoreg);

    printf("\nDados carregados com sucesso!\n");

    printf("Total de alunos carregados: %d\n", *total);
}

int main()
{
    Aluno turma[MAX_ALUNOS];
    int total = 0;
    int opcao;

    do
    {
        printf("\n--------------------------------\n");
        printf("       SISTEMA DE ALUNOS\n");
        printf("---------------------------------\n");
        printf("1 - Inserir alunos\n");
        printf("2 - Exibir alunos\n");
        printf("3 - Salvar dados\n");
        printf("4 - Carregar dados\n");
        printf("5 - Sair\n");
        printf("----------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
                inserirAlunos(turma, &total);
                break;

            case 2:
                listarAlunos(turma, total);
                break;

            case 3:
                salvarDados(turma, total);
                break;

            case 4:
                carregarDados(turma, &total);
                break;

            case 5:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}