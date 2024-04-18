#include <stdio.h>
#include <math.h>

int main() {
    float suma = 0;
    int n;

    printf("\nIngrese la cantidad de numeros a sumar:\n");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Debe ingresar un número entero positivo. Intente de nuevo.\n");
        return 1;
    }

    // Suma de los números
    for (int i = 0; i < n; i++) {
        float numero;
        printf("Ingrese el numero %d (utilice '.' como separador decimal):\n", i + 1);
        if (scanf("%f", &numero) != 1) {
            printf("Debe ingresar un número válido. Intente de nuevo.\n");
            return 1;
        }
        suma += numero;
    }

    printf("Numero resultante: %f\n", suma);
    float parte_entera = floor(suma); // la función sirve para redondear hacia abajo, para obtener la parte entera del numero
    float parte_decimal = suma - parte_entera; // se puede restar la parte y obtener la decimal, dado que el dato es de tipo float
    printf("Parte entera: %.0f\n", parte_entera);
    printf("Parte decimal: %f\n", parte_decimal);

    return 0;
}
