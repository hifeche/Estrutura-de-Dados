#ifndef PRODUTO_H
#define PRODUTO_H
#define ARQUIVO_ESTOQUE "estoque.bin"
typedef struct {
  int id;
  char nome[50];
  float valor;
  int quantidade;
} Produto;
#endif
