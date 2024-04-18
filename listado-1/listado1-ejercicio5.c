#include <stdio.h>

int main() {
    int tamaño;
    printf("Ingrese las dimensiones de la figura:\n");
    scanf("%d", &tamaño);

    for (int i = 0; i < tamaño; i++) {
        char caracter;
        if (i % 2 == 0) { // Si la fila es par, imprime "#"
            caracter = '#';
        } else { // Si es impar imprime "*"
            caracter = '+';
        }
        for (int j = 0; j < tamaño; j++) {//por cada iteración, mueve la columna un espacio
            if (j >= i) {
                printf("%c", caracter);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
