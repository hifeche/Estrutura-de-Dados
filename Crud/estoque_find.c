#include <stdio.h>
#include <string.h>
#include "produto.h"

// ---------------------------------------------------------
// Localiza um produto pelo id
// Retorna 1 se encontrar (e preenche o ponteiro p), 
// ou 0 se não achar
// ---------------------------------------------------------
int find_produto(int id_alvo, Produto *p) {

    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "rb");
    if (arquivo == NULL) {
        return 0; // Arquivo não encontrado
    }

    // Lê bloco por bloco
    while (fread(p, sizeof(Produto), 1, arquivo) == 1) {
        if (p->id == id_alvo) {
            // Encontrou! 
            // A variável 'p' já foi inicializada em fread
            fclose(arquivo);
            return 1; 
        }
    }

    fclose(arquivo);
    return 0; // Chegou ao fim do arquivo e não encontrou
}

// TODO: 
// - find_produto_nome()
// - find_produto_quantidade(0)

// int main() {
//     int id_produto;
//     Produto produto;

//     printf("--- BUSCA PRODUTO ---\n");
//     printf("Digite o ID do produto: ");
//     scanf("%d", &id_produto);

//     // Busca o produto
//     if (find_produto(id_produto, &produto)) {
//         printf("\nProduto encontrado!\n");
//         printf("ID: %-4d | %-20s | Qtd: %-4d | Preco: R$ %.2f\n", 
//                produto.id, produto.nome, produto.quantidade, produto.valor);
//     } else {
//         printf("\nProduto ID %d nao encontrado.\n", id_produto);
//     }
//     return 0;
// }