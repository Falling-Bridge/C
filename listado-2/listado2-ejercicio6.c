#include <stdio.h>

int main() {
    int n;

    printf("\nIngrese un numero entre 0 y 255:\n");

    if (scanf("%d", &n) != 1 || n < 0 || n > 255) {
        printf("Debe ingresar un numero entero valido entre 0 y 255. Intente de nuevo.\n");
        return 1;
    }

    printf("El numero ingresado: %d\ncomo caracter: %c\ncomo unsigned int: %u\ncomo octal: %o\ncomo hexadecimal: %x\n", n, n, n, n, n);

    return 0;
}
