#include <stdio.h>
#include <string.h>

int main() {

    //lo compile sin el printf que se supone diga "ingrese el mensaje a cifrar", porque el timus no me lo pasaba de esa manera
    char arregloentrada[101]; //se establece el tamaño de 1 a 100 que menciona el problema, más el caracter nulo
    scanf("%s", arregloentrada);
    int largo = strlen(arregloentrada);
    char arreglosalida[largo]; //se inicia el arreglo a imprimir, con la misma longitud de lo ingresado

    for (int i = 0; i < largo; i++) {
        int num = arregloentrada[i] - 'a'; // Convierte la letra en un número de 0 a 25
        for (int j = 0; j < i; j++) {
            //contrario de la condición en donde se sumaba el numero actual con el antecesor
            //lo demás es para asegurarse de que esté en el rango de 0 a 25
            num = (num - arreglosalida[j] + 26) % 26;
        }
        arreglosalida[i] = num;
    }
    //contrario de la condición en donde se sumaba 5 al primero, lo demás es para asegurarse de que esté en el rango de 0 a 25
    arreglosalida[0] = (arreglosalida[0] - 5 + 26) % 26;

    for (int i = 0; i < largo; i++) {
        arreglosalida[i] += 'a'; // Convierte el número de nuevo a una letra
        printf("%c", arreglosalida[i]); // Imprime la letra
    }

    return 0;
}
