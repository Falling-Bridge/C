#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//se crea la función "contarenarchivo"para contar las diferentes estadísticas que pide el problema como:
//Cantidad total de caracteres del archivo; Cantidad de dígitos en el archivo; Cantidad de letras minúsculas o mayúsculas en el archivo
//Cantidad de símbolos que no son dígitos o letras; Cantidad total de palabras (definimos palabras como substrings separados por espacios)

void contarenarchivo(const char *path, FILE *creado) {
    FILE * archivo = fopen(path, "r");

    //se declaran las variables necesarias
    int contadorCaracteres = 0; 
    int contadorNumeros = 0;
    int contadorLetras = 0;
    int contadorSimbolos = 0;
    int contadorPalabras = 0;
    char caracter;
    bool letra;
    
    if (archivo != NULL) {
        while ((caracter = fgetc(archivo)) != EOF) {

            contadorCaracteres++; //se cuentan los caracteres
            
            if (isalpha(caracter)) {// se usa isalpha y se comprueba que pertenezca al alfabeto
                contadorLetras++;
                letra = true;
            } else if (isdigit(caracter)) { //se usa isdigit y se comprueba que sea un numero
                contadorNumeros++;
            } else if (!isalnum(caracter)) { //si no es un caracter alfanumérico, se considera como un simbolo
                contadorSimbolos++;
                letra = false;             
            }
            
            //en este if no me dejó compilar cuando estaban '¡';'¿' o '?', por eso no están en el if
            if (caracter == ' ' || caracter == '.' || caracter == '!' || caracter == '-' || caracter == '"' || caracter == '(' || caracter == ')' || caracter == '\t' 
                || caracter == '\n' || caracter == ',' && letra == true) { 
                contadorPalabras++; //comprueba que sea una palabra con todas las combinaciones posibles (o que se me ocurrieron)
            }
 
            }
    }
            
    else {
    fprintf(creado, "No se pudo abrir el archivo.\n"); // si aparece este mensaje, se debe a que no se ingreso bien 
                                                       // el nombre o la extensión del archivo o el archivo no está en
                                                       // la misma dirección que el código
    }

    fprintf(creado, "El archivo contiene %d caracteres.\n", contadorCaracteres);
    fprintf(creado, "El archivo contiene %d numeros.\n", contadorNumeros);
    fprintf(creado, "El archivo contiene %d letras.\n", contadorLetras);
    fprintf(creado, "El archivo contiene %d simbolos.\n", contadorSimbolos);
    fprintf(creado, "El archivo contiene %d palabras.\n", contadorPalabras);
    fclose(archivo);

}

int main() {

    char nombre[100]; //se pregunta por el archivo de entrada
    printf("Ingrese el nombre de su archivo, con la extension del mismo:\n");
    scanf("%s", nombre);

    FILE *archivo = fopen(nombre, "r"); //se ocupa *archivo para llamar al archivo
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo ingresado.\n");
        return 1;
    }

    char archivocreado[200]; //esto se hace para que el archivo de salida, quede de la forma "estadísticas-archivo.formato" y sea más fácil de ubicar
    sprintf(archivocreado, "estadisticas-%s", nombre);

    FILE *creado = fopen(archivocreado, "w"); //se ocupa *creado para llamar al espacio donde se creará el archivo
    if (creado == NULL) {
        printf("No se pudo crear el archivo de estadisticas.\n");
        return 1;
    }

    fprintf(creado, "Estadisticas de \"%s\":\n", nombre); //establezco que el espacio *creado, se llame como "Estadisticas de 'archivo.formato' "
    contarenarchivo(nombre, creado); //se llama a la función para que lea el archivo y lo guarde en creado

    fclose(creado);
    printf("Las estadisticas se han guardado en el archivo \"%s\".\n", archivocreado);
    return 0;

}