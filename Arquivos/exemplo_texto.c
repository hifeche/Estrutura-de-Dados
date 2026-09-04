#include <stdio.h>
#include <stdlib.h>
// ARQUIVO TEXTO
int adiciona_dados_arquivo(char filename[]) {
  FILE *arquivo;
  // Abre o arquivo para adição
  arquivo = fopen(filename, "a"); // a == preserva conteudo existente
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
  }
  // Grava uma nova linha ao final do arquivo sem apagar o que já estava lá
  fprintf(arquivo, "Nova linha adicionada.\n");
  fclose(arquivo);
  printf("Arquivo salvo!\n");
  return 0;
}
int escreve_dados_arquivo(char filename[]) {
  FILE *arquivo;
  // Abre (ou cria) o arquivo para escrita
  arquivo = fopen(filename, "w");
  // Sempre verifique se o arquivo foi aberto com sucesso
  if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo para escrita!\n");
      return 1;
  }
  // Escreve no arquivo usando fprintf
  fprintf(arquivo, "Esta é a primeira linha do arquivo.\n");
  fprintf(arquivo, "O modo 'w' apaga o conteúdo antigo se o arquivo já existir.\n");
  // É fundamental fechar o arquivo após o uso
  fclose(arquivo);
  printf("Arquivo criado!\n");
  return 0;
}

int main() {
  escreve_dados_arquivo("dados_1.txt");
  adiciona_dados_arquivo("dados_2.txt");
  return 0;
}