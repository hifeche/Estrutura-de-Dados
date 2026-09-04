#include <stdio.h>
#include <string.h>
#include "produto.h"
#include <time.h>
// ---------------------------------------------------------
// - Função auxiliar para cria o arquivo estoque.bin caso
//   este não exista. 
// - Inicializa o arquivo com dois produtos de exemplo
// ---------------------------------------------------------
int gerar_id() { return (int)time(NULL); }

void gera_arquivo_estoque() {
    // Abre para leitura
    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "rb");
    
    if (arquivo != NULL) {
        // Se o arquivo abriu, ele já existe. 
        // Não fazer nada nesse caso.
        fclose(arquivo);
        return; 
    }
    
    printf(">> Criando novo arquivo \n");
    
    // Abre no modo "wb" para CRIAR o arquivo
    arquivo = fopen(ARQUIVO_ESTOQUE, "wb");
    if (arquivo == NULL) {
        printf("Erro fatal: Sem permissao de acesso para '%s'.\n", ARQUIVO_ESTOQUE);
        return;
    }
    // Cria dois produtos:
    Produto p1 = {11, "Martelo", 15, 45.90};
    Produto p2 = {gerar_id(), "Prego de Aco (Caixa)", 50, 22.50};

    // Escreve produto 1 no arquivo
    fwrite(&p1, sizeof(Produto), 1, arquivo);
    // Escreve produto 2 no arquivo
    fwrite(&p2, sizeof(Produto), 1, arquivo);

    fclose(arquivo);
    printf(">> Arquivo salvo! \n\n");
}

// int main() {
//     printf("Inicialização do estoque\n");
//     gera_arquivo_estoque();
//     return 0;
// }