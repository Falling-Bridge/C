#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char matriz[16][13][12];
    char *meses[12] = {
        //todos los elementos de meses, tienen esos espacios para que al imprimirlos, cuadren con la matriz
        "Enero     ", "Febrero   ", "Marzo     ", "Abril     ", "Mayo      ", "Junio     ",
        "Julio     ", "Agosto    ", "Septiembre", "Octubre   ", "Noviembre ", "Diciembre "
    };
    char *regiones[16] = {
        "Region i", "Region ii", "Region iii", "Region iv", "Region v", "Region vi", "Region vii",
        "Region viii", "Region ix", "Region x", "Region xi", "Region xii", "Region xiii", "Region xiv",
        "Region xv", "Region xvi"
    };
    srand(time(NULL));
    // Copiar los nombres de los meses en la matriz
    for (int j = 0; j < 12; j++) {
        strcpy(matriz[0][j + 1], meses[j]);
    }
    // Copiar los nombres de las regiones en la matriz
    for (int i = 0; i < 16; i++) {
        strcpy(matriz[i + 1][0], regiones[i]);
    }
    // Generar valores aleatorios y calcular el promedio en la matriz
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 12; j++) {
            float suma = 0;
            for (int k = 0; k < 15; k++) {
                switch (j) { 

                    //se simulan las estaciones del año, se suman y promedian los valores de 15 años
                    //verano
                    case 11: // Diciembre
                    case 0: // Enero
                    case 1: // Febrero
                        suma += rand() % 300;
                        break;
                    //Otoño
                    case 2: // Marzo
                    case 3: // Abril
                    case 4: // Mayo
                        suma += rand() % 1200;
                        break;
                    //Invierno
                    case 5: // Junio
                    case 6: // Julio
                    case 7: // Agosto
                        suma += rand() % 800;
                        break;
                    //Primavera
                    case 8: // Septiembre
                    case 9: // Octubre
                    case 10: // Noviembre
                        suma += rand() % 500;
                        break;
                }
            }
            //se copia el obtenido y se promedia, se le establce un formato de impresión y la posición en donde irá en la matríz
            snprintf(matriz[i + 1][j + 1], sizeof(matriz[i + 1][j + 1]), "%8.2f mm", suma / 15.0);
        }
    }
    matriz[0][0][0] = '\0';
    printf("\nLos valores promedio de precipitacion de los ultimos 15 anhos por region y mes son los siguientes:\n\n");
    // Imprimir la matriz con los nombres de regiones, meses y valores
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 13; j++) {
            if (i == 0 && j >= 1) {
                printf("  %2s", matriz[i][j]);
            } else {
                printf("%-12s", matriz[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
