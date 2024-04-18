#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Ingrese el numero de filas y columnas: ");
    scanf(" %d %d", &n, &m);

    int M[n][m];

    // LLenamos la matriz con valores aleatorios
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            M[i][j] = rand() % 200;

    // Arreglo para almacenar los promedios por producto. Asumiremos promedio
    // con division entera.
    int promedio[n];

    // Calculamos los promedios por productos (filas). Esos promedios los usaremos
    // luego para decidir si dicho producto se debe ir a la matriz A o B
    for(int i=0; i < n; i++) {
        int sum = 0;
        for(int j=0; j < m; j++)
            sum += M[i][j];

        promedio[i] = sum / m;
    }

    // Numero de filas de las matrices A y B, respectivamente
    int nA = 0, nB;
    for(int i=0; i < n; i++)
        if(promedio[i] < 100) nA++;
        else nB++;

    // Ya que conocemos las dimensiones de las matrices A, B y C, las declaramos
    int A[nA][m];
    int B[nB][m];
    int C[1][m];

    for(int i=0, iA=0, iB=0; i < n; i++)
        // Matriz A
        if(promedio[i] < 100) {
            for(int j=0; j < m; j++)
                A[iA][j] = M[i][j];
            iA++;
        }
        else { // Matriz B
            for(int j=0; j < m; j++)
                B[iB][j] = M[i][j];
            iB++;
        }

    // Calculamos los promedios mensuales y los almacenamos en la matriz C
    for(int j=0; j < m; j++) {
        C[0][j] = 0;
        for(int i=0; i < n; i++)
            C[0][j] += M[i][j];
        C[0][j] /= n;
    }

    return 0;
}
