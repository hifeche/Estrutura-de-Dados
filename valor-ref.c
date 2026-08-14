#include <stdio.h>
void altera(int x){ // copia
    x = 99; 
}
void altera_mesmo(int *x){ // ponteiro (hack)
    // acesso ao endereço de memória
    *x = 99;
}
int main() {
   int num = 10;
   printf("%i\n", num); // 10
   altera(num);  // passagem por valor (copia)
   printf("%i\n", num); // 10

   altera_mesmo(&num); // passagem por referencia
   printf("%i\n",num); // 99
   return 0;
}
