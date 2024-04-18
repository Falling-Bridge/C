#include <stdio.h>
#include <math.h>

int main() {
    // n para establecer el rango, i para el bucle for
    int n, i;

    printf("Ingrese el valor de n:");
    scanf("%d", &n);
    while(n<1){
        printf("el numero debe ser mayor a 1\n");
        printf("Ingrese el valor de n:");
        scanf("%d", &n);
    }

    int arreglo[n]; //declaro un arreglo para todos los numeros de 1 a n

    for (i = 1; i <= n; i++) {
        arreglo[i - 1] = i;

        if (arreglo[i - 1] > 0 && arreglo[i - 1] <= 5) { // numeros de 0 a 5 inclusivo el 5
            printf("%d, ", 2 * arreglo[i - 1]); // como no tiene decimales, es entero
        } else if (arreglo[i - 1] > 5 && arreglo[i - 1] <= 13) { //numeros de 5 a 13 inclusivo el 13
            printf("%.0f, ", pow(arreglo[i - 1], 2) - 3 * arreglo[i - 1] + 2); //como tiene una potencia, es float
        } else {
            printf("%.2lf, ", 100.0 / arreglo[i - 1] + 3); //es float con dos decimales
        }
    }

    return 0;
}
