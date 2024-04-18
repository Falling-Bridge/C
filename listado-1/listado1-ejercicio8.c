#include <stdio.h>

int main() {
   
    int n, i, m;// n para el rango, i para el bucle for, m para el modulo

    printf("Ingrese el valor de m y n:\n");// Solicitar al usuario ingresar los valores de m y n
    scanf("%d %d", &m, &n);

    int arreglo[n];

    // Llenar el arreglo y calcular el módulo
    for (i = 0; i < n; i++) {
        int aux = i + 1; // se utiliza una variable aux, para que lleve uno más que el contador i
        arreglo[i] = aux; //debido a que los elementos comienzan desde 1
        printf("%d ", arreglo[i] % m);
    }

    return 0;
}
