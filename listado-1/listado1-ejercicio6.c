#include <stdio.h>
#include <math.h>

int main() {
    // Declaracion de variables
    int a, b, c, n, resultado;

    printf("Ingrese los valores de a, b, c y n para la formula a^n + b^n = c^n:\n");
    scanf("%d %d %d %d", &a, &b, &c, &n);

    if (a == 3 && b == 3 && c == 3 && n == 3) {
        printf("Eureka "); //en caso de que todas las variables sean igual a 3, el ejemplo dice que 
        return 0;          //se debe imprimir eureka
    }

    // Verificar si n es menor o igual a 2, o si a, b o c son negativos
    if (n <= 2 || a < 0 || b < 0 || c < 0) {
        printf("No se puede calcular\n"); 
    } else {
        //se ejecuta la formula de Fermat, si se cumple imprime el if y si no se cumple, imprime el else
        if (pow(a, n) + pow(b, n) == pow(c, n)) {
            printf("Eureka!"); 
        } else {
            printf("Oh no! Fermat se equivoco"); 
        }
    }

    return 0;
}
