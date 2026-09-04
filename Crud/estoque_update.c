#include <stdio.h>
#include <string.h>
#include "produto.h"
#include "estoque_find.c"

// ---------------------------------------------------------
// U - UPDATE (Atualizar um produto existente)
// Retorna 1 se atualizar com sucesso, ou 0 se falhar/não achar
// ---------------------------------------------------------
int update_produto(const Produto *produto_atualizado) {
    // Modo "r+b": Abre para leitura E escrita simultânea (não apaga o arquivo)
    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "r+b");
    if (arquivo == NULL) {
        return 0;
    }
    Produto p_temp;

    while (fread(&p_temp, sizeof(Produto), 1, arquivo) == 1) {
        // Verifica se o ID do produto no arquivo é igual ao ID do produto atualizado
        if (p_temp.id == produto_atualizado->id) {
            
            // Volta o cursor do arquivo exatamente 1 bloco para trás
            // SEEK_CUR significa "a partir da posição atual do cursor"
            fseek(arquivo, -sizeof(Produto), SEEK_CUR);
            
            // Sobrescreve aquele espaço com os novos dados
            fwrite(produto_atualizado, sizeof(Produto), 1, arquivo);
            
            fclose(arquivo);
            return 1; // Sucesso!
        }
    }

    fclose(arquivo);
    return 0; // Produto não encontrado
}

// ---------------------------------------------------------
// Exemplo de uso
// ---------------------------------------------------------
int main() {
    int id_produto;
    Produto produto; // variavel armazena o produto lido do arquivo

    printf("--- BUSCA E ATUALIZA PRODUTO ---\n");
    printf("Digite o ID do produto que deseja alterar: ");
    scanf("%d", &id_produto);

    // Buscar o produto
    if (find_produto(id_produto, &produto)) {
        printf("\nProduto encontrado!\n");
        printf("Nome atual: %s\n", produto.nome);
        printf("Valor atual: R$ %.2f\n", produto.valor);

        // Modifica os dados na memória RAM
        printf("\nDigite o novo valor: ");
        scanf("%f", &produto.valor);
        
        printf("Digite a nova quantidade: ");
        scanf("%d", &produto.quantidade);

        // Salva o produto modificado no arquivo
        if (update_produto(&produto)) {
            printf("\nSucesso! Produto atualizado.\n");
        } else {
            printf("\nErro ao tentar salvar a atualizacao.\n");
        }

    } else {
        printf("\nProduto com ID %d nao encontrado no estoque.\n", id_produto);
    }

    return 0;
}