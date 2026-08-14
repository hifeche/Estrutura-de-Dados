#include <stdio.h>
typedef struct
{
  float peso;
  float altura; 
} Pessoa;

struct Aluno
{
  char nome[50];
  int  matricula;
  char nascimento[12];
  char sexo;
  char telefone[20];
};

void printPessoa(Pessoa p) 
{
  printf("Peso: %f Altura: %f\n", p.peso, p.altura);
}

int main() {
  // Inicialização
  struct Aluno a1 = {
      "Ana Maria Souza",
      20240101,
      "15/04/2002",
      'F',
      "(11) 98765-4321"
  };

  // Exibição dos dados
  printf("\n--- Dados do Aluno ---\n");
  printf("Nome: \t\t%s\n", a1.nome);
  printf("Matrícula: \t%d\n", a1.matricula);
  printf("Nascimento: \t%s\n", a1.nascimento);
  printf("Telefone: \t%s\n", a1.telefone);
  printf("Sexo: \t\t%c\n\n", a1.sexo);


  Pessoa turma[26];
  turma[0].altura = 1.76;
  turma[0].peso = 72;
  printPessoa(turma[0]);

  return 0;
}