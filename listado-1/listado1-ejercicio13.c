#include <stdio.h>

int main() {
    int c, v; //c para cantidad de candidatos, v para cantidad de votos
    scanf("%d %d", &c, &v);
    int votos[c];

    for (int i = 0; i < c; i++) { //declaro el arreglo con un cero en cada posición
        votos[i] = 0;
    }

    for (int i = 0; i < v; i++) {//se utiliza la variable voto como identificación para cada candidato
        int voto;                //de 1 a c
        scanf("%d", &voto); 

        if (voto >= 1 && voto <= c) {//verifica si la identificación del candidato, existe en el arreglo
            votos[voto - 1]++;       //si lo hace, le suma un voto
        }
    }

    for (int i = 0; i < c; i++) {
        double porcentaje = (double)votos[i] * 100 / v;
        printf("%.2lf%%\n", porcentaje);
    }

    return 0;
}
