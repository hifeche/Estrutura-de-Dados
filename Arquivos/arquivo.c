#include <stdio.h>
typedef  struct{
  float salario;
  char nome[100];
  long id; 
  char nascimento[10];
} Funcionario;

void imprimeDadosFuncionario(Funcionario func) {
  printf("\nNome: %s  \n\t- Salario: %.2f", func.nome, func.salario);
  printf("\n\t- Data de nascimento: %s", func.nascimento);  
}
int salva_funcionario(char nome_arquivo[], Funcionario colaborador){
  FILE *arquivo;
  arquivo = fopen(nome_arquivo, "wb");
  if (arquivo == NULL){
    printf("\nNão foi possivel abrir o arquivo");
    return 1;
  }
  fwrite(
    &colaborador,
    sizeof(Funcionario),
    1,
    arquivo
  );
  fclose(arquivo);
  return 0;
}

int salva_texto(
  char nome_arquivo[], 
  char texto[]) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        return -1; 
      }
    fputs(texto, arquivo);
    fclose(arquivo);
    return 0;
}

int main(){
  // exemplo de criação de registro
  Funcionario jose = {
    1300.3, "Jose", 10, "10/10/2010"
  };
  // binario
  salva_funcionario("colaboradores.bin", jose);
  // texto
  salva_texto("texto.txt", "admin:1234abcd");

  return 0;
}