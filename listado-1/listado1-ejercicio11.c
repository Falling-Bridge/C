#include <stdio.h>

int main() {
    int examenes, i, notas = 0; //examenes para la cantidad de notas, i para los bucles, notas para las notas
    float average; //average para promediar

    scanf("%d", &examenes);

    while (examenes < 1 || examenes > 10) { //debe haber entre 1 y 10 examenes
        scanf("%d", &examenes);
    }

    int arreglo[examenes]; //defino el arreglo para guardar las notas(marks)
    int tres = 0; //para contabilizar si existe alguna nota 3

    for (i = 0; i < examenes; i++) {
        do {
            scanf("%d", &arreglo[i]);
        } while (arreglo[i] < 3 || arreglo[i] > 5);// la nota debe estar entre 3 y 5
        notas += arreglo[i]; //sumo a notas, el puntaje de la nota
        if (arreglo[i] == 3) { //si tiene al menos una nota igual a 3, se "activa" la variable tres
            tres = 1;
        }
    }

    average = (float)notas / examenes; //se usa float, porque pueden aparecer decimales

    if (tres == 1) { // si tuvo una nota 3, no obtiene beca
        printf("None");
        return 0;
    }

    if (average == 5) { // si tuvo solo notas 5, obtiene una beca named
        printf("Named");
        return 0;
    }

    if (average >= 4.5) { // si su puntaje es mayor a 4.5, obtiene high
        printf("High");
        return 0;
    } else {
        printf("Common");// si no obtuve 3, pero su promedio es menor a 4.5 obtiene una beca common
    }

    return 0;
}
