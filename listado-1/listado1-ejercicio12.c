#include <stdio.h>

int main() {
    int n, suma = 0; //n para el numero, suma para la suma

    scanf("%d", &n);

    while (n < -10000 || n > 10000) {//establezco que debe estar entre -10000 y 10000
        scanf("%d", &n);
    }

    if (n >= 1) { // si n es positivo, uso la formula para la suma de los primeros n naturales
        suma = (n * (n + 1)) / 2;
    } else if (n < 1) {
        for (int i = 1; i >= n; i--) {// si n es negativo, sumo término a término
            suma += i;
        }
    }

    printf("%d", suma);

    return 0;
}
