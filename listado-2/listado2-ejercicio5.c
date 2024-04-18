#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char pos[3]; // Para almacenar la posición en notación de ajedrez, dice 3 para el caracter nulo
    int x, y;
    printf("\nIngrese la posicion del alfil en notacion de ajedrez (por ejemplo, 'e4'):\n");
    scanf("%s", pos);

    // Convierte la letra a minúscula
    pos[0] = tolower(pos[0]);

    // Verifica si la entrada es válida con sus valores ASCII
    if (pos[0] < 'a' || pos[0] > 'h' || pos[1] < '1' || pos[1] > '8' || pos[2] != '\0') {
        printf("Posicion invalida. Debe ingresar una posicion valida en notacion de ajedrez.\n");
        return 1;
    }

    /* Calcula las coordenadas x e y a partir de la notación de ajedrez:
    se calculan de esta manera, para que al momento de localizarlo en el tablero se puedan usar como como enteros 
    para ubicar la posición*/
    x = pos[0] - 'a' + 1;
    y = '8' - pos[1];

    printf("\nVision del alfil en la posicion %s:\n\n", pos);
    
    char matriz[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ((i == 8 && j == 0)) { //la esquina inferior izquierda la pone con un espacio
                matriz[i][j] = ' '; 
            } 
            else if (i == 8) { //llena la fila inferior con letras de 'a' a 'h'
                matriz[i][j] = 'a' + j - 1;
            } 
            else if (j == 0) {
                matriz[i][j] = '0' + 8 - i; // ubicar los numeros en orden decreciente, a medida que se imprime la matriz
            } 
            else if (abs(i - y) == abs(j - x)) {//se usa la función 'abs' en caso de que me un valor negativo, me da el valor absoluto
                                                //y se usa el '==' para que vaya formando una diagonal
                matriz[i][j] = 'X';
            } 
            else {
                matriz[i][j] = ' '; // si no es la visión del alfil, es 'vacío'
            }
        }
    }

    matriz[y][x] = 'A'; //después de haber calculado las posiciones que ocupara la visión del alfil, ingresa la coordenada del alfil
    
    //se imprime la matriz 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}