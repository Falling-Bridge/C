#include <stdio.h>

int main() {
    // Pido al usuario que ingrese un numero y declaro 'conversor' para calcular los residuos de divisiones
    int numero, conversor;
    printf("Ingrese un numero entre -255 y 255:\n");
    scanf("%d", &numero);

    int matriz[8] = {0}; // Creo un arreglo de 8 bits para la representacion binaria

    // Verificar si el numero esta dentro del rango de 8 bits
    if (numero < -255 || numero > 255) {
        printf("Numero fuera de rango\n");
        return 1;
    }

    if (numero < 0) {
        numero = -numero; // Tratamos el numero como positivo
        int carry = 1;

        // Obtener el complemento a uno del numero
        for (int i = 7; i >= 0; i--) {
            conversor = numero % 2;
            matriz[i] = conversor ^ 1;
            numero /= 2;
        }

        // Convertir el complemento a uno en complemento a dos
        for (int i = 7; i >= 0; i--) {
            int suma = matriz[i] + carry;
            matriz[i] = suma % 2;
            carry = suma / 2;
        }
    } else {
        // Obtener la representacion binaria del numero 
        for (int i = 7; i >= 0; i--) {
            conversor = numero % 2;
            matriz[i] = conversor;
            numero /= 2;
        }
    }
    
    // Imprimir la representacion binaria
    for (int k = 0; k < 8; k++) {
        printf("%d", matriz[k]);
    }
    printf("\n");

    return 0;
}
