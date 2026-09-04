#include <stdio.h>
#include "produto.h"

// Função que remove um produto pelo ID. 
// Retorna 0 (sucesso), 1 (erro de arquivo) ou 2 (produto não encontrado)
int remover_produto(int id_alvo) {
    FILE *arquivo_original = fopen(ARQUIVO_ESTOQUE, "rb");
    if (arquivo_original == NULL) {
        printf("Erro: Arquivo '%s' nao encontrado.\n", ARQUIVO_ESTOQUE);
        return 1;
    }

    // Cria um arquivo temporário para ESCRITA ("wb")
    const char *ARQUIVO_TEMP = "temp.bin";
    FILE *arquivo_temp = fopen(ARQUIVO_TEMP, "wb");
    if (arquivo_temp == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo temporario.\n");
        fclose(arquivo_original);
        return 1;
    }
    Produto p;
    int encontrou = 0; // Flag para saber se o produto foi encontrado

    // Lê o arquivo original até o fim
    while (fread(&p, sizeof(Produto), 1, arquivo_original) == 1) {
        // Se o ID for diferente, salvar no temporário
        if (p.id != id_alvo) {
            fwrite(&p, sizeof(Produto), 1, arquivo_temp);
        } else {
            // Se for igual, ignorar (não grava) 
            encontrou = 1;
        }
    }

    // Fecha ambos os arquivos (MUITO IMPORTANTE antes de deletar/renomear)
    fclose(arquivo_original);
    fclose(arquivo_temp);

    // Substituição dos arquivos
    if (encontrou) {
        remove(ARQUIVO_ESTOQUE);  // Deleta o arquivo original antigo
        rename(ARQUIVO_TEMP, ARQUIVO_ESTOQUE); // Renomeia o temp para o nome oficial
        return 0; // Sucesso
    } else {
        remove(ARQUIVO_TEMP); // Se não encontrou, deletar o arquivo temp
        return 2; // Não encontrado
    }
}

int main() {
    int id_para_apagar;

    printf("--- EXCLUSAO DE PRODUTO ---\n");
    printf("Digite o ID do produto para remover: ");
    scanf("%d", &id_para_apagar);

    int status = remover_produto(id_para_apagar);

    if (status == 0) {
        printf("Sucesso! Produto %d removido do estoque.\n", id_para_apagar);
    } else if (status == 2) {
        printf("Aviso: Nenhum produto encontrado com ID %d.\n", id_para_apagar);
    } else {
        printf("Falha ao tentar remover o produto.\n");
    }

    return 0;
}