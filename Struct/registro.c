#include <stdio.h>
typedef  struct{
  float salario; // 5340.50
  char nome[100];
  long id; 
  char nascimento[10];
} Funcionario;
/*
struct Funcionario {
  float salario;
  char nome[100];
  long id; 
  char nascimento[10];
};
*/
// gcc -g registro.c -o registro.app && ./registro.app
void imprimeDadosFuncionario(Funcionario func) {
  printf("\nNome: %s  \n\t- Salario: %.2f", func.nome, func.salario);
  printf("\n\t- Data de nascimento: %s", func.nascimento);  
}
int main(){
  Funcionario jose = {
    1300.3,
    "Jose",
    10,
    "10/10/2010"
  };
  // lê o campo através do operador .
  imprimeDadosFuncionario(jose);
  // atribuir valor ao campo salario
  jose.salario += 200;
  imprimeDadosFuncionario(jose);
  jose.salario += 300;
  imprimeDadosFuncionario(jose);

  // array
  //Funcionario funcionarios[3];
  //funcionarios[0] = jose;
  // adicionar mais dois funcionarios e imprimir os dados de 
  // todos os funcionarios da empresa

  return 0;
}