#include <stdio.h>
#include "produto.h"
#include <time.h>
// Função utilitária para gerar ID automático
int gerar_id()
{
  // time(NULL) retorna os segundos desde 1970 (timestamp).
  // cast para converter o formato time_t par int.
  return (int)time(NULL);
}
// TODO: implementar o update_produto()

int salvar_produto(const Produto *produto, const char *filename)
{
  FILE *arquivo = fopen(filename, "ab");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return 1;
  }
  fwrite(produto, sizeof(Produto), 1, arquivo);
  fclose(arquivo);
  printf("arquivo salvo");
  return 0;
}

int main()
{
  // estoque_write.c
  // gcc -g estoque_write.c -o estoque_write.app
  // Obter os dados do produto do usuário

  int id = gerar_id();
  Produto p;
  printf("--- CADASTRO DE PRODUTO ---\n\n");

  // Gerar o ID
  p.id = gerar_id();
  printf("ID gerado: %d\n", p.id);

  // Lê o Nome
  printf("Digite o nome do produto: ");
  fgets(p.nome, sizeof(p.nome), stdin);
  p.nome[strcspn(p.nome, "\n")] = '\0'; // Remove o Enter
  // REMOVENDO O '\n': O fgets salva o Enter na string.

  // strcspn procura onde está o '\n' e troca por '\0' (fim de string).
  p.nome[strcspn(p.nome, "\n")] = '\0';

  // Quantidade
  printf("Digite a quantidade em estoque: ");
  scanf("%d", &p.quantidade);

  // Valor
  printf("Digite o valor (ex: 35.90): ");
  scanf("%f", &p.valor);

  printf("\nDados coletados:\n");
  printf("- ID: %d\n", p.id);
  printf("- Nome: '%s' \n", p.nome);
  printf("- Qtd: %d\n", p.quantidade);
  printf("- Valor: R$ %.2f\n", p.valor);

  printf("\nSalvando dados em %s\n", ARQUIVO_ESTOQUE);
  if (salvar_produto(&p, ARQUIVO_ESTOQUE) == 0)
  {
    printf("Sucesso!\n");
  }
  return 0;
}
