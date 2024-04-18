#include <stdio.h>

int main() {
    // numero para el numero, i para el bucle for, suma para guardar los resultados de las sumas
    int numero, i; 
    float suma = 0.0;

    printf("Ingrese un numero entero mayor a uno: ");
    scanf("%d", &numero);

    for (i = 1; i <= numero; i++) {
        suma += 1.0 / i;
    }

    printf("%.10f", suma); //se imprime el resultado con hasta 10 decimales

    return 0;
}
