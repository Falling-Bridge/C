#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    // la forma en que los bucles se forman, sigue la siguiente lógica: el primer elemento es la posición que ocupa
    // el segundo elemento, es el valor asociado a la posición, después toma el valor asociado y va a esa posicón 
    //hasta que vuelve al valor de la posición inicial 
    int n;
    printf("\nIngrese la cantidad de elementos del arreglo:\n");
    if (scanf("%d", &n) != 1 || n <= 0 || n > RAND_MAX) {
        printf("Debe ingresar un numero entero positivo valido. Intente de nuevo.\n");
        return 1;
    }

    int arreglo[n];
    int marcas[n]; // Usaremos este conjunto para rastrear valores únicos

    // Inicializa la semilla del generador de números aleatorios
    srand(time(NULL));

    // Llena el conjunto con valores únicos
    for (int i = 0; i < n; i++) {
        marcas[i] = i;
    }

    // Llena el arreglo con números aleatorios sin repetirlos
    for (int i = 0; i < n; i++) {
        int indice = rand() % (n - i);
        arreglo[i] = marcas[indice];
        marcas[indice] = marcas[n - i - 1];
    }

    // Determinar la cantidad máxima de dígitos requeridos para el formato apropiado de impresión
    int maxDigits = snprintf(NULL, 0, "%d", n);

    // Se imprime el formato dependiendo de la cantidad de dígitos
    // 1 dígito = x, 2 dígitos = xy, 3 dígitos = xyz y así
    printf("Posicion:\n");
    for (int i = 0; i < n; i++) {
        printf("%0*d", maxDigits, i);
        if (i < n - 1) {
            printf(" "); // pone un espacio, para que se pueda leer mejor
        }
    }

    // Se imprime el arreglo llenado con la función rand 
    // siguiendo el formato antes obtenido
    printf("\n\n");
    printf("Valor asociado al arreglo generado:\n");

    for (int i = 0; i < n; i++) {
        printf("%0*d", maxDigits, arreglo[i]);
        if (i < n - 1) {
            printf(" "); // pone un espacio, para que se pueda leer mejor
        }
    }

    printf("\n\n");

    // Crear bucles
    int cantidadBucles = 0; // Inicialmente no hay bucles creados
    int** bucles = (int **)malloc(n * sizeof(int *)); //generador de arreglos
    int* tamanhobucles = (int *)malloc(n * sizeof(int)); //capacidad de todos los arreglos 
    int comprobacion[n]; //para ver si un elemento ya ha sido puesto en un bucle

    for (int i = 0; i < n; i++) {
        bucles[i] = NULL; // Inicializamos todos los punteros a NULL
        comprobacion[i] = 0; // Inicializamos el arreglo de comprobación
    }

    for (int i = 0; i < n; i++) {
        if (comprobacion[i] == 0) {
            // Crear un nuevo bucle
            int indiceInicial = i; //;Almacena el índice inicial del nuevo bucle
            int indice = i;       // Inicializa un indice, para saber en que bucle se está trabajando
            int bucleSize = 0;    //tamaño del bucle actual 

            do {
                bucleSize++; // Incrementa el tamaño del bucle
                indice = arreglo[indice]; // Mueve al siguiente elemento en el bucle
                comprobacion[indice] = 1; // Marca el elemento como utilizado
            } while (indice != indiceInicial); // Continúa hasta que se complete el bucle

            // Asigna memoria para almacenar los elementos del nuevo bucle
            bucles[cantidadBucles] = (int *)malloc(bucleSize * sizeof(int));

            if (bucles[cantidadBucles] == NULL) {
                printf("No se pudo asignar memoria al bucle %d.\n", cantidadBucles + 1);
                return 1;
            }

            tamanhobucles[cantidadBucles] = bucleSize; //almacena el tamaño del bucle iterado
                                                       //en el índice actual 

            indice = indiceInicial;
            int k = 0;

            do {
                bucles[cantidadBucles][k] = indice; // Almacena el elemento en el bucle
                k++;
                indice = arreglo[indice]; // Mueve al siguiente elemento en el bucle
            } while (indice != indiceInicial); // Continúa hasta que se complete el bucle

            cantidadBucles++; // Incrementa la cantidad de bucles creados
        }
    }

    // Encontrar el bucle más largo
    int bucleMasLargo = 0;
    for (int i = 1; i < cantidadBucles; i++) {
        if (tamanhobucles[i] > tamanhobucles[bucleMasLargo]) {
            bucleMasLargo = i; // Encuentra el índice del bucle más largo
        }
    }

    // Imprimir los bucles
    for (int i = 0; i < cantidadBucles; i++) {
        printf("Bucle%d (elementos = %d):\n", i + 1, tamanhobucles[i]);
        for (int k = 0; k < tamanhobucles[i]; k++) {
            printf("%0*d", maxDigits, bucles[i][k]);
            if (k < tamanhobucles[i] - 1) {
                printf(" "); // pone un espacio, para que se pueda leer mejor
            }
        }
        printf("\n\n");
        free(bucles[i]); // liberar la memoria dinámica
    }

    // Imprimir el bucle más largo
        printf("El bucle mas largo, es el Bucle%d con %d elementos.\n", bucleMasLargo + 1, tamanhobucles[bucleMasLargo]);
        printf("\n\n");

        free(bucles); // Liberar el arreglo de punteros
        free(tamanhobucles); // Liberar el arreglo de tamaños
        return 0;
}

