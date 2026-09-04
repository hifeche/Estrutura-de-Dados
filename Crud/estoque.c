#include <stdio.h>
#include "produto.h" // header

// Incluindo as funções CRUD externas
#include "estoque_init.c"
#include "estoque_find.c"
// #include "estoque_remove.c"
// #include "estoque_read.c"

int main() {
  int opcao = -1; 
  int id_produto;
  Produto produto;

  // Loop do menu
  while (opcao != 5) {
    printf("\n==================================\n");
    printf("       SISTEMA DE ESTOQUE\n");
    printf("==================================\n");
    printf(" 1. Inicializar estoque \n");
    printf(" 2. Buscar produto \n");
    printf(" 5. Sair\n");
    printf("----------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    // Avalia a escolha do usuário
    switch (opcao) {
      case 1:
        // Inicializa arquivo que armazena produtos
        printf("inicializando arquivo de estoque");
        gera_arquivo_estoque(); // => localizado em estoque_init.c
        break;
      case 2:
        printf("Digite o ID do produto: ");
        scanf("%d", &id_produto);
        if (find_produto(id_produto, &produto)) {
          printf("\nProduto encontrado!\n");
          printf("ID: %-4d | %-20s | Qtd: %-4d | Preco: R$ %.2f\n", 
                produto.id, produto.nome, produto.quantidade, produto.valor);
        } else {
          printf("\nProduto ID %d nao encontrado.\n", id_produto);
        }
        break;
      case 5:
        printf("\nEncerrando o sistema.!\n");
        break;
      default:
        printf("\n[ ERRO ] Opcao invalida!\n");
        break;
    }
  }
  return 0;
}