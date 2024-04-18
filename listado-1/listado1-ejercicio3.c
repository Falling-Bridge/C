#include <stdio.h>

int main() {
    int n, i, m; // n para la cantidad de numeros, i para bucles for, m para comparacion
    
    // Ingresar la cantidad de numeros (n) y el valor de comparacion (m)
    printf("Ingrese la cantidad de numeros (n) y el valor de comparacion (m):\n");
    scanf("%d %d", &n, &m);

    int arreglo[n]; // Declarar un arreglo de tamano n para almacenar los numeros

    // Ingresar n numeros y guardarlos en el arreglo
    for (i = 0; i < n; i++) {
        printf("Ingrese un numero a comparar:\n");
        scanf("%d", &arreglo[i]);
    }

    printf("Los numeros mayores a m son: ");

    // Comparar cada numero en el arreglo con m y mostrar los mayores
    for (i = 0; i < n; i++) {
        if (arreglo[i] > m) {
            printf("%d ", arreglo[i]);
        }
    }

    return 0;
}
