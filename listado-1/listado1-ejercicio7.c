#include <stdio.h>

int main() {
    // Declaración de variables
    int n;
    
    printf("Ingrese un numero:\n");//se solicita ingresar un número
    scanf("%d", &n);

    if (n >= 0) {
        // Imprimir la configuración zig-zag si n es no negativo
        printf("Su configuracion zig-zag es:\n%d\n", 2 * n);
    } else {
        // Imprimir la configuración zig-zag si n es negativo
        printf("Su configuracion zig-zag es:\n%d\n", -(2 * n + 1));
    }

    return 0;
}
