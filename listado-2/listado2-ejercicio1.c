#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int n, m;
    char input[256];

    //se verifica que sea un numero y que esté en el rango que tiene sentido, que son los enteros positvos
    printf("\nIngrese la cantidad de numeros n:\n");
    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }
    //la misma verificación que con n, pero m puede ser negativo o positivo
    printf("Ingrese la condicion de comparación de numeros m:\n");
    if (scanf("%d", &m) != 1) {
        return 1;
    }

    // arreglo de tamaño n
    int arregloA[n];

    // Se llena el arregloA
    for (int i = 0; i < n; i++) {
    printf("Ingrese el valor numero %d para el arreglo principal:\n", i + 1);
    if (scanf("%d", &arregloA[i]) != 1) {
        printf("Debe ingresar un numero entero valido. Intente de nuevo.\n");
        return 1;
    }
}

    
    // Se asigna memoria dinámica para el arreglo B y C
    int* arregloB = (int *)malloc(n * sizeof(int));
    int* arregloC = (int *)malloc(n * sizeof(int));

    if (arregloB == NULL || arregloC == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria dinámica.\n");
        return 1;
    }
    //indices para el arregloB y arregloC
    int j = 0; 
    int k = 0;

    // Ciclo para llenar B y C con las condiciones correspondientes
    for (int i = 0; i < n; i++) {
        
        if (arregloA[i] < m) {
            arregloB[j] = arregloA[i];
            j++;
        } else {
            arregloC[k] = arregloA[i];
            k++;
        }
    }
    printf("\n");
    // Se imprimen los arreglos

    printf("El arregloA tiene %d elementos: ", n);
    for(int i = 0; i < n; i ++){
        printf("%d ", arregloA[i]);
    }
    printf("\n");

    printf("El arregloB tiene %d elementos: ", j);
    for (int i = 0; i < j; i++) {
        printf("%d ", arregloB[i]);
    }
    printf("\n");

    printf("El arregloC tiene %d elementos: ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", arregloC[i]);
    }
    printf("\n");

    // Se libera la memoria asignada a B y C
    free(arregloB);
    free(arregloC);

    return 0;
}
