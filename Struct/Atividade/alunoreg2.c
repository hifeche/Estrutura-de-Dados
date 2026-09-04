#include <stdio.h>
#include <string.h>

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


/* Calcula a media e a situacao do aluno */
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


/* Insere alunos */
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

        calcularAluno(&turma[*total]);

        (*total)++;

        printf("Aluno cadastrado com sucesso!\n");
    }
}


/* Lista todos os alunos */
void listarAlunos(Aluno turma[], int total)
{
    if (total == 0)
    {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n========== LISTA DE ALUNOS ==========\n");

    for (int i = 0; i < total; i++)
    {
        printf("\nAluno %d\n", i + 1);
        printf("ID/Matricula: %d\n", turma[i].matricula);
        printf("Nome: %s\n", turma[i].nome);
        printf("Nota 1: %.1f\n", turma[i].prova1);
        printf("Nota 2: %.1f\n", turma[i].prova2);
        printf("Media: %.1f\n", turma[i].media);
        printf("Faltas: %d\n", turma[i].faltas);
        printf("Situacao: %s\n", turma[i].situacao);
    }
}


/* Busca aluno pela matricula */
int buscarPorMatricula(Aluno turma[], int total, int matricula)
{
    for (int i = 0; i < total; i++)
    {
        if (turma[i].matricula == matricula)
        {
            return i;
        }
    }

    return -1;
}


/* Busca aluno pelo nome
   Agora mostra todos os alunos com o mesmo nome */
void buscarPorNome(Aluno turma[], int total, char nome[])
{
    int encontrou = 0;

    for (int i = 0; i < total; i++)
    {
        if (strcmp(turma[i].nome, nome) == 0)
        {
            printf("\n===== ALUNO ENCONTRADO =====\n");
            printf("ID/Matricula: %d\n", turma[i].matricula);
            printf("Nome: %s\n", turma[i].nome);
            printf("Nota 1: %.1f\n", turma[i].prova1);
            printf("Nota 2: %.1f\n", turma[i].prova2);
            printf("Media: %.1f\n", turma[i].media);
            printf("Faltas: %d\n", turma[i].faltas);
            printf("Situacao: %s\n", turma[i].situacao);

            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("\nAluno nao encontrado.\n");
    }
}


/* Exibe os dados de um aluno */
void exibirAluno(Aluno *aluno)
{
    printf("\n========== DADOS DO ALUNO ==========\n");
    printf("ID/Matricula: %d\n", aluno->matricula);
    printf("Nome: %s\n", aluno->nome);
    printf("Nota 1: %.1f\n", aluno->prova1);
    printf("Nota 2: %.1f\n", aluno->media);
    printf("Media: %.1f\n", aluno->media);
    printf("Faltas: %d\n", aluno->faltas);
    printf("Situacao: %s\n", aluno->situacao);
}


/* Permite buscar um aluno */
void buscarAluno(Aluno turma[], int total)
{
    int opcao;
    int matricula;
    int posicao;
    char nome[TAM_NOME];

    if (total == 0)
    {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n===== BUSCAR ALUNO =====\n");
    printf("1 - Buscar por matricula\n");
    printf("2 - Buscar por nome\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1)
    {
        printf("Digite a matricula: ");
        scanf("%d", &matricula);

        posicao = buscarPorMatricula(turma, total, matricula);

        if (posicao != -1)
        {
            exibirAluno(&turma[posicao]);
        }
        else
        {
            printf("\nAluno nao encontrado.\n");
        }
    }
    else if (opcao == 2)
    {
        printf("Digite o nome: ");
        fgets(nome, TAM_NOME, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        buscarPorNome(turma, total, nome);
    }
    else
    {
        printf("\nOpcao invalida.\n");
    }
}


/* Altera os dados cadastrais do aluno */
void alterarDados(Aluno turma[], int total)
{
    int matricula;
    int posicao;
    int opcao;

    if (total == 0)
    {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &matricula);
    getchar();

    posicao = buscarPorMatricula(turma, total, matricula);

    if (posicao == -1)
    {
        printf("\nAluno nao encontrado.\n");
        return;
    }

    do
    {
        printf("\n===== ALTERAR DADOS =====\n");
        printf("1 - Alterar nome\n");
        printf("2 - Alterar matricula\n");
        printf("3 - Alterar faltas\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
                printf("Novo nome: ");
                fgets(turma[posicao].nome, TAM_NOME, stdin);
                turma[posicao].nome[strcspn(turma[posicao].nome, "\n")] = '\0';

                printf("Nome alterado com sucesso!\n");
                break;

            case 2:
            {
                int novaMatricula;

                printf("Nova matricula: ");
                scanf("%d", &novaMatricula);
                getchar();

                if (buscarPorMatricula(turma, total, novaMatricula) != -1)
                {
                    printf("Essa matricula ja esta sendo utilizada.\n");
                }
                else
                {
                    turma[posicao].matricula = novaMatricula;
                    printf("Matricula alterada com sucesso!\n");
                }

                break;
            }

            case 3:
                printf("Nova quantidade de faltas: ");
                scanf("%d", &turma[posicao].faltas);
                getchar();

                calcularAluno(&turma[posicao]);

                printf("Faltas alteradas com sucesso!\n");
                break;

            case 0:
                printf("Voltando ao menu...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);
}


/* Altera as notas do aluno */
void alterarNotas(Aluno turma[], int total)
{
    int matricula;
    int posicao;

    if (total == 0)
    {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &matricula);
    getchar();

    posicao = buscarPorMatricula(turma, total, matricula);

    if (posicao == -1)
    {
        printf("\nAluno nao encontrado.\n");
        return;
    }

    printf("\nAluno encontrado: %s\n", turma[posicao].nome);

    printf("Nova nota da Prova 1: ");
    scanf("%f", &turma[posicao].prova1);

    printf("Nova nota da Prova 2: ");
    scanf("%f", &turma[posicao].prova2);

    getchar();

    calcularAluno(&turma[posicao]);

    printf("\nNotas alteradas com sucesso!\n");
    printf("Nova media: %.1f\n", turma[posicao].media);
    printf("Nova situacao: %s\n", turma[posicao].situacao);
}


/* Lista alunos aprovados ou reprovados */
void consultarSituacao(Aluno turma[], int total)
{
    int opcao;
    int encontrou = 0;

    if (total == 0)
    {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n===== CONSULTAR SITUACAO =====\n");
    printf("1 - Aprovados\n");
    printf("2 - Reprovados\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1)
    {
        printf("\n========== ALUNOS APROVADOS ==========\n");

        for (int i = 0; i < total; i++)
        {
            if (strcmp(turma[i].situacao, "Aprovado") == 0)
            {
                printf("\nID/Matricula: %d\n", turma[i].matricula);
                printf("Nome: %s\n", turma[i].nome);
                printf("Nota 1: %.1f\n", turma[i].prova1);
                printf("Nota 2: %.1f\n", turma[i].prova2);
                printf("Media: %.1f\n", turma[i].media);
                printf("Situacao: %s\n", turma[i].situacao);

                encontrou = 1;
            }
        }
    }
    else if (opcao == 2)
    {
        printf("\n========== ALUNOS REPROVADOS ==========\n");

        for (int i = 0; i < total; i++)
        {
            if (strcmp(turma[i].situacao, "Reprovado") == 0)
            {
                printf("\nID/Matricula: %d\n", turma[i].matricula);
                printf("Nome: %s\n", turma[i].nome);
                printf("Nota 1: %.1f\n", turma[i].prova1);
                printf("Nota 2: %.1f\n", turma[i].prova2);
                printf("Media: %.1f\n", turma[i].media);
                printf("Situacao: %s\n", turma[i].situacao);

                encontrou = 1;
            }
        }
    }
    else
    {
        printf("\nOpcao invalida.\n");
        return;
    }

    if (!encontrou)
    {
        printf("\nNenhum aluno encontrado nessa situacao.\n");
    }
}


/* Remove um aluno */
void removerAluno(Aluno turma[], int *total)
{
    int matricula;
    int posicao;
    int opcao;

    if (*total == 0)
    {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\nDigite a matricula do aluno que deseja remover: ");
    scanf("%d", &matricula);
    getchar();

    posicao = buscarPorMatricula(turma, *total, matricula);

    if (posicao == -1)
    {
        printf("\nAluno nao encontrado.\n");
        return;
    }

    printf("\nAluno encontrado: %s\n", turma[posicao].nome);

    printf("Deseja realmente remover este aluno?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1)
    {
        /* Desloca os alunos seguintes uma posicao para tras */
        for (int i = posicao; i < *total - 1; i++)
        {
            turma[i] = turma[i + 1];
        }

        (*total)--;

        printf("\nAluno removido com sucesso!\n");
    }
    else
    {
        printf("\nOperacao cancelada.\n");
    }
}


/* Salva os dados no arquivo */
void salvarDados(Aluno turma[], int total)
{
    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "wb");

    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, arquivo);
    fwrite(turma, sizeof(Aluno), total, arquivo);

    fclose(arquivo);

    printf("\nDados salvos com sucesso!\n");
}


/* Carrega os alunos do arquivo */
void carregarDados(Aluno turma[], int *total)
{
    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "rb");

    if (arquivo == NULL)
    {
        printf("\nNenhum arquivo de dados encontrado.\n");
        return;
    }

    fread(total, sizeof(int), 1, arquivo);

    if (*total < 0 || *total > MAX_ALUNOS)
    {
        printf("\nArquivo invalido.\n");

        fclose(arquivo);

        *total = 0;

        return;
    }

    fread(turma, sizeof(Aluno), *total, arquivo);

    fclose(arquivo);

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
        printf("\n====================================\n");
        printf("          SISTEMA DE ALUNOS\n");
        printf("====================================\n");

        printf("1  - Inserir alunos\n");
        printf("2  - Exibir lista de alunos\n");
        printf("3  - Buscar aluno\n");
        printf("4  - Exibir dados do aluno\n");
        printf("5  - Alterar dados do aluno\n");
        printf("6  - Alterar notas\n");
        printf("7  - Consultar aprovados/reprovados\n");
        printf("8  - Remover aluno\n");
        printf("9  - Salvar dados\n");
        printf("10 - Carregar dados\n");
        printf("0  - Sair\n");

        printf("====================================\n");
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
                buscarAluno(turma, total);
                break;

            case 4:
            {
                int matricula;
                int posicao;

                if (total == 0)
                {
                    printf("\nNenhum aluno cadastrado.\n");
                    break;
                }

                printf("\nDigite a matricula do aluno: ");
                scanf("%d", &matricula);
                getchar();

                posicao = buscarPorMatricula(turma, total, matricula);

                if (posicao != -1)
                {
                    exibirAluno(&turma[posicao]);
                }
                else
                {
                    printf("\nAluno nao encontrado.\n");
                }

                break;
            }

            case 5:
                alterarDados(turma, total);
                break;

            case 6:
                alterarNotas(turma, total);
                break;

            case 7:
                consultarSituacao(turma, total);
                break;

            case 8:
                removerAluno(turma, &total);
                break;

            case 9:
                salvarDados(turma, total);
                break;

            case 10:
                carregarDados(turma, &total);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}