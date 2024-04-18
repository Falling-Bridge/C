#include <stdio.h>
#include <string.h>

int main(){
    int n, m;
    
    printf("Ingrese la cantidad de frases:\n");
      if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Debe ingresar un número entero positivo. Intente de nuevo.\n");
        return 1;
    }
    printf("Ingrese la cantidad de caracteres a obtener de la frase:\n");
      if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Debe ingresar un número entero positivo. Intente de nuevo.\n");
        return 1;
    }

    char frase[m+1]; // el + 1 es para el caracter nulo '\0'
    char cadenafinal[n*m + 1]; //uso este rango porque, si son n frases, con una longitud de m el rango necesario para guardar todo es
                               // n*m +1, el + 1 para el caracter nulo
    cadenafinal[0] = '\0'; //esto es para que la función strncar no se maree, así sabe donde comenzar a guardar 

    for(int i = 0; i < n; i++){
        printf("Ingrese la frase numero %d:\n", i+1);
        scanf(" %[^\n]s", frase); //" %[^\n]s", está expresión lee hasta un salto de línea o se ingresa enter
        while(strlen(frase) < m){ //verificación de al menos largo m
            printf("la frase debe tener al menos %d caracteres, ingrese nuevamente:\n", m);
            scanf(" %[^\n]s", frase);
        }
        strncat(cadenafinal, frase, m); //guarda en cadenafinal, una cantidad 'm' de caracteres obtenidos de 'frase'
        
    }

    printf("%s", cadenafinal);

    return 0;
}