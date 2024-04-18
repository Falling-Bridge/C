#include <stdio.h>

int main() {
    int n;
    //elimine el printf donde pedía ingresar un numero entre 1 y 100, porque el timus no me lo aceptaba
    //se verifica que se ingrese un numero, y que el numero ingresado esté en el rango de 1 a 100
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        return 1;
    }
    int matriz[n][n];
    int numero = 1;

    //en una matriz cuadrada existen 2 * n -1 diagonales, he ahí la condición de termino
    for (int d = 0; d < 2 * n - 1; d++) {
        int inicio = (d < n) ? 0 : d - n + 1; // Marca dónde comienza la diagonal
        int final = (d < n) ? d : n - 1;      // Marca dónde termina la diagonal

        //usa los índices calculados como condiciones de inicio y termino para ubicar los números en la diagonal
        for (int i = inicio; i <= final; i++) {
            int j = d - i; // Calcula la posición que ocupa la columna en la diagonal correspondiente
            matriz[i][j] = numero;
            numero++;
        }
    }
    // Imprime la matriz reflejada espejo respecto a j
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
