#include <stdio.h>
#include <ctype.h>

void imprimirMatriz(int matriz[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[9][9];

    // Llenar la matriz (el Sudoku)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int valor;
            printf("Ingrese el valor en la posicion %d,%d (debe ser un numero entre 1 y 9):\n", i + 1, j + 1);
            if (scanf("%d", &valor) != 1 || valor < 1 || valor > 9) {
                printf("Entrada invalida. Debe ingresar un numero entero entre 1 y 9. Intente de nuevo.\n\n");
                return 1;
            }
            matriz[i][j] = valor;
        }
    }

    // Imprimir la matriz ingresada
    printf("Matriz ingresada:\n");
    imprimirMatriz(matriz);
    printf("\n");

    // Comprobación de filas y columnas
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int contadorfila = 0; 
            int contadorcolumna = 0;
            
            //se itera con el valor obtenido de los 1ros for anidados, y se comparan con el valor de la fila o columna correspondiente
            for (int k = 0; k < 9; k++) { //estos for, comprueban las filas
                if (matriz[i][j] == matriz[k][j]) {
                    contadorfila++;
                    if (contadorfila > 1) {
                        printf("No es una solucion valida. Duplicado en la fila %d, columna %d.\n", i + 1, j + 1);
                        return 0;
                    }
                }
            }

            for (int l = 0; l < 9; l++) {
                if (matriz[i][j] == matriz[i][l]) {//estos for, comprueban las columnas
                    contadorcolumna++;
                    if (contadorcolumna > 1) {
                        printf("No es una solución valida. Duplicado en la fila %d, columna %d.\n", i + 1, j + 1);
                        return 0;
                    }
                }
            }
        }
    }

    // Comprobación de submatrices 3x3
    for (int a = 0; a < 9; a += 3) {
        for (int b = 0; b < 9; b += 3) {
            int submatriz[9];
            // Inicializamos un contador para llevar un registro de la posición en el array submatriz
            int contador = 0;

            for (int i = a; i < a + 3; i++) { //itera por las filas de la submatriz
                for (int j = b; j < b + 3; j++) { //itera por las columnas de la submatriz
                    // Copiamos el valor de la celda correspondiente de la matriz principal 'matriz'
                    // en la posición actual del array 'submatriz'
                    submatriz[contador] = matriz[i][j];
                    // Incrementamos el contador para avanzar a la siguiente posición en 'submatriz'
                    contador++;
                }
            }
            
            for (int i = 0; i < 9; i++) {
                for (int j = i + 1; j < 9; j++) {
                    if (submatriz[i] == submatriz[j]) { //se comprueba por cade elemento de submatriz, que no se repita
                        printf("No es una solución válida. Duplicado en la submatriz %d,%d.\n", a / 3 + 1, b / 3 + 1);
                        return 0;
                    }
                }
            }
        }
    }

    // Si no se encontraron duplicados, se considera una solución válida
    printf("Es una solución válida.\n");
    return 0;
}
