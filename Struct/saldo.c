#include <stdio.h>
#include <stdbool.h>
typedef struct {
  char nome[50];
  float saldo;
  char chave[50];
} Cliente;
void extrato(Cliente cliente){
  printf("\n[extrato] %s (saldo=R$ %.2f)",cliente.nome, cliente.saldo);
}
bool transfere(){
  /*
  if(VALIDAR){
    printf("\n\t[pix] saldo insuficiente para realizar o pix R$ %.2f", valor);
    return false;
  } 
  // atualizar saldos
  printf("\n\t[pix] valor de R$ %.2f enviado", valor);
  */
  return true;
}
int main() {
  Cliente maria = {"Maria", 1200};
  Cliente joao = {"João", 800};
  float valor = 300;
  extrato(maria); // 1200
  extrato(joao);  // 800
  //transfere();
  extrato(maria); // 1500
  extrato(joao);  // 500
  valor = 600;
  //transfere();
  extrato(maria); // 1500
  extrato(joao);  // 500
  valor = 500;
  //transfere();
  extrato(maria); // ?
  extrato(joao);  // ?
}
