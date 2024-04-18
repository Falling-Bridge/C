#include <stdio.h>
int main() {
    int tamaño;
    printf("Ingrese la dimension de la figura:\n");
    scanf("%d", &tamaño);

    /*establecí un tamaño de 5, porque desde ese número se empieza a apreciar el patrón que se
    forma, esa es la única razón de este if*/
    if(tamaño < 5){ 
        printf("debe ser un numero mayor o igual a 4");
        return 1;
    }
    //se crea una matriz de x * y, con x e y siendo la variable tamaño
    char matriz[tamaño][tamaño];
    
    // Se crea una matriz con asteriscos
    for (int fila = 0; fila < tamaño; fila++) {
        for (int columna = 0; columna < tamaño; columna++) {
            matriz[fila][columna] = '*';
        }
    }
    
    int c = 1;
    for (int fila = 0; fila < tamaño - 1; fila++) {// indica que se cambiará cada c espacios
        if (fila == tamaño / 2) {                  // un '*' por un ' '
            c += 1;
        }
        for (int columna = 0; columna <= tamaño + 1; columna++) {
            if (columna == c || columna == tamaño + 1 - c) { // indica que se hace en la parte  
                matriz[fila][columna] = ' ';                 //izquierda y derecha de matriz
            }
        }
        c += 1; //aumenta cada cuanto se hace el cambio, en un espacio
    }
        
    // Se imprime la matriz
    for (int fila = 0; fila < tamaño - 1; fila++) {
        for (int columna = 0; columna < tamaño + 2; columna++) {
            printf("%c", matriz[fila][columna]);
        }
        printf("\n");
    }
    return 0;
}