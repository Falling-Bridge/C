#include <stdio.h>

int main() {
    // Pido al usuario que ingrese una velocidad
    float speed;
    printf("Ingrese una velocidad:\n");
    scanf("%f", &speed);

    //si la velocidad es menor a 411.111.... (412 redondeado), no llegará a tiempo
    if (speed >= 412) { 
        printf("Se logra llegar a tiempo\n");
    } else {
        printf("El permiso vencerá\n");
    }
    return 0;
}
