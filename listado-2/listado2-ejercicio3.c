#include <stdio.h>

int main() {
    int n; 
    printf("\nIngrese un numero entero negativo entre -2.147.483.648 y -1:\n");

    //se verifica que sea un numero, y que sea un numero negativo
    if (scanf("%d", &n) != 1 || n >= 0) {
        printf("Debe ingresar un numero entero negativo. Intente de nuevo.\n\n");
        return 1;
    }
    
    printf("\n");

    // Posición de los bits
    printf("Posicion de los bits:\n");
    for(int i = 31; i >= 0; i--){
        printf("%3d", i);
    }
    printf("\n\n");

    // Representación en binario usando operaciones a nivel de bits
    printf("La representacion binaria de %d\n", n);
    for(int i = 31; i >= 0; i--){
        int bit = (n >> i) & 1; // Obtiene el bit en la posición i de n y aplica AND con 1
        printf("%3d", bit);
    }

    printf("\n\n");

    return 0;
}
