#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define weigth 100
#define size 40
#define PI 3.14159265358979323846

//se ocupa SDL_Rect* particulas que tiene los campos: particulas.x particulas.y 
                                                   // particulas.h particulas.w 
                                                   // particulas.d particulas.p

// se copian enteros sin signo y se copian a los atributos particula.x, particula.y, particula.d, particula.p
SDL_Rect* leercsv(FILE* archivo, int* contadorparticulas, SDL_Rect* particulas) {
    while (fscanf(archivo, "%u,%u,%u,%u,", &particulas[*contadorparticulas].x, &particulas[*contadorparticulas].y,
                                           &particulas[*contadorparticulas].d, &particulas[*contadorparticulas].p) == 4) {
        (*contadorparticulas)++;
        if (feof(archivo)) {
            break;
        }
        particulas = realloc(particulas, sizeof(SDL_Rect) * ((*contadorparticulas) + 1));
    }
    return particulas;
}

// se copia un grupo de 32 'caracteres' de solo 1's y 0's que se tratan como numeros en base2 y se pasan a base10 ocupando los campos:
//particula.x, particula.y, particula.d, particula.p
SDL_Rect* leerbinario(FILE* archivo, int* contadorparticulas, SDL_Rect* particulas) {
    char grupo[32];
    int cuenta = 0;

    while (fscanf(archivo, "%32s", grupo) == 1) {
        int decimal = 0;
        for (int i = 0; i < 32; i++) {
            if (grupo[i] != '1' && grupo[i] != '0') {
                printf("No tiene el formato especificado\n");
                break;
            }
            else if (grupo[i] == '1') {
                decimal += 1 << (31 - i);
            }
        }
        switch (cuenta) {
            case 0:
                particulas[*contadorparticulas].x = decimal;
                break;
            case 1:
                particulas[*contadorparticulas].y = decimal;
                break;
            case 2:
                particulas[*contadorparticulas].d = decimal;
                break;
            case 3:
                particulas[*contadorparticulas].p = decimal;
                break;
        }

        if (feof(archivo)) {
            break;
        }

        cuenta++;
        if (cuenta == 4) {
            cuenta = 0;
            (*contadorparticulas)++;
            particulas = realloc(particulas, sizeof(SDL_Rect) * ((*contadorparticulas) + 1));
        }
    }

    return particulas;
}

//se busca un parentesis con 4 enteros sin signo separados por coma y se copia en los campos
//particula.x, particula.y, particula.d, particula.p
SDL_Rect* leertxt(FILE* archivo, int* contadorparticulas, SDL_Rect* particulas) {
    while (fgetc(archivo) != '(' && !feof(archivo)) {
        while (fscanf(archivo, "(%u,%u,%u,%u)", &particulas[*contadorparticulas].x, &particulas[*contadorparticulas].y,
                                             &particulas[*contadorparticulas].d, &particulas[*contadorparticulas].p) == 4) {
            (*contadorparticulas)++;
            if (feof(archivo)) {
                break;
            }
            particulas = realloc(particulas, sizeof(SDL_Rect) * ((*contadorparticulas) + 1));
        }
    }

    return particulas;
}

//se muestra en la esquina superior izquierda la cantidad de partículas, cantidad de colisiones, la variable speed y la variable delay
void Estadisticas(SDL_Renderer* renderer, TTF_Font* font, int contadorcolisiones, int *speed, int *contadorparticulas, int *delay) {
    char texto[50];
    SDL_Color colortexto = {255, 255, 255}; //se establece un color determinado para la muestra de las estadísticas
    sprintf(texto, "Colisiones: %d Cantidad de particulas: %d speed: %d Delay: %d", contadorcolisiones, *contadorparticulas, *speed, *delay);
    SDL_Surface* surface = TTF_RenderText_Solid(font, texto, colortexto); //se crea toda la 'plantilla de texto'
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // se 'mete' la plantilla al texto
    SDL_Rect dstRect = {10, 10, surface->w, surface->h}; //se coloca en la esquina superior izquierda
    SDL_RenderCopy(renderer, texture, NULL, &dstRect); // hace que el texto se muestre en pantalla
    //una vez que ya  está en el renderer, no es necesario que las otras funciones se sigan ejecutando
    SDL_FreeSurface(surface); 
    SDL_DestroyTexture(texture);
}

//aquí se controla la dirección de movimiento, el cambio de direccion de movimiento, y el cambio de direccion (y de peso) causado por particulas que colisionan
SDL_Rect* movimiento(int **contadorparticulas, SDL_Rect* particulas, int ancho, int largo, int* speed, int *contadorcolisiones) {
    for (int i = 0; i < **contadorparticulas; i++) {
        if (particulas[i].p == 0) {
            particulas[i] = particulas[**contadorparticulas - 1];
            (**contadorparticulas)--;
            particulas = realloc(particulas, sizeof(SDL_Rect) * (**contadorparticulas));
            i--;
        }

        // Como se mueve
        double angulo = particulas[i].d * (PI / 180);
        particulas[i].x += (*speed) * cos(angulo);
        particulas[i].y += (*speed) * sin(angulo);

        // Manejar rebotes en los bordes
        if (particulas[i].y < 0 || particulas[i].y >= largo) {
            particulas[i].y = fmax(0, fmin(largo - 1, particulas[i].y));
            particulas[i].d = 360 - particulas[i].d;
        }

        if (particulas[i].x < 0 || particulas[i].x >= ancho) {
            particulas[i].x = fmax(0, fmin(ancho - 1, particulas[i].x));
            particulas[i].d = 180 - particulas[i].d;
        }

        // Manejar rebotes entre partículas
        for (int j = 0; j < **contadorparticulas; j++) {
            if (i != j) {
                int dx = particulas[j].x - particulas[i].x;
                int dy = particulas[j].y - particulas[i].y;
                int distancia = sqrt(dx * dx + dy * dy);

                if (distancia < size) { // Si hay colisión
                    double anguloColision = atan2(dy, dx);
                    double nuevoAnguloI = 2 * anguloColision - particulas[i].d;
                    double nuevoAnguloJ = 2 * anguloColision - particulas[j].d;

                    particulas[i].d = nuevoAnguloI;
                    particulas[j].d = nuevoAnguloJ;

                    (*contadorcolisiones)++;
                    particulas[i].p -= 1;
                    particulas[j].p -= 1;
                }
            }
        }
    }
    return particulas;
}

int visualizar(int* contadorparticulas, SDL_Renderer* renderer, SDL_Rect* particulas, SDL_Window* ventana, TTF_Font* font, int largo, int ancho) {
    SDL_Event event;
    int corriendo = 1;
    int r = 255, g = 255, b = 255;
    int speed = 5;
    int contadorcolisiones = 0;
    int estadísticas = 0;
    int delay = 50;
    while (corriendo) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // se establece el color del fonfo
        SDL_RenderClear(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_q) { //quit everything
                    corriendo = 0;
                } else if (event.key.keysym.sym == SDLK_1) { // cambiar el color de partículas y del fondo
                    r = rand() % 256;
                    g = rand() % 256;
                    b = rand() % 256;
                    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
                    SDL_RenderClear(renderer);
                } else if (event.key.keysym.sym == SDLK_PLUS) { // agregar partículas
                    (*contadorparticulas)++;
                    particulas = realloc(particulas, sizeof(SDL_Rect) * ((*contadorparticulas) + 1));
                    particulas[*contadorparticulas - 1].x = rand() % ancho;
                    particulas[*contadorparticulas - 1].y = rand() % largo;
                    particulas[*contadorparticulas - 1].d = rand() % 360;
                    particulas[*contadorparticulas - 1].h = size;
                    particulas[*contadorparticulas - 1].w = size;
                    particulas[*contadorparticulas - 1].p = rand() % weigth + 1;
                } else if (event.key.keysym.sym == SDLK_MINUS && *contadorparticulas > 0) { // quitar partículas
                    (*contadorparticulas)--;
                    particulas = realloc(particulas, sizeof(SDL_Rect) * ((*contadorparticulas) + 1));
                } else if (event.key.keysym.sym == SDLK_2) { //elimina todas las partículas en pantalla
                    free(particulas);
                    *contadorparticulas = 0;
                    particulas = (SDL_Rect*)malloc(sizeof(SDL_Rect));
                } else if (event.key.keysym.sym == SDLK_3) { //aumenta la variable velocidad en una cantidad de entre 0 a 14
                    speed += rand() % 15;
                } else if (event.key.keysym.sym == SDLK_4) { //disminuye la variable velocidad en una cantidad de entre 0 a 14
                    speed -= rand() % 15;
                } else if (event.key.keysym.sym == SDLK_s) { //guarda la posición actual de la particulas en el archivo de nombre particuladedios en la carpeta Colisionador de Adrones

                    FILE* name = fopen("particuladedios.txt", "w");
                    if (name == NULL) {
                        perror("Error al abrir el archivo");
                        return -1;
                    }

                    fprintf(name, "c\n");
                    for (int i = 0; i < *contadorparticulas; i++) {
                        fprintf(name, "%d,%d,%d,%d\n", particulas[i].x, particulas[i].y, particulas[i].d, particulas[i].p);
                    }
                    corriendo = 0;
                    printf("las particulas se han guardado en el archivo 'particuladedios.txt'\n");
                } else if (event.key.keysym.sym == SDLK_5) { //muestra las estádistcas, sea cantidad de particulas, cantidad de colisiones, speed, delay
                    estadísticas = 1;
                } else if (event.key.keysym.sym == SDLK_6) { //oculta las estádisticas
                    estadísticas = 0;
                } else if (event.key.keysym.sym == SDLK_7) { //se le agrega una unidad a delay
                    delay++;
                } else if (event.key.keysym.sym == SDLK_8 && delay > 1) { //se le quita una unidad a delay mientras sea mayor a uno
                    delay--;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 255 - r, 255 - g, 255 - b, 255); // se establece el color de las partículas
        SDL_RenderClear(renderer);
        particulas = movimiento(&contadorparticulas, particulas, ancho, largo, &speed, &contadorcolisiones);

        for (int i = 0; i < *contadorparticulas; i++) {
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderFillRect(renderer, &particulas[i]);
        }

        if (estadísticas) { // si se acciona el comando, se muestra estadísticas
            Estadisticas(renderer, font, contadorcolisiones, &speed, contadorparticulas, &delay);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(delay);
    }
    //si corriendo llega a 0 se termina el programa 
    free(particulas);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}

int main(int argc, char* argv[]) {
    char archivo[100];
    printf("\nIngrese el nombre de su archivo:\n");
    scanf("%s", archivo); //se ingresa el nombre del archivo
    srand(time(NULL));

    FILE* lectura = fopen(archivo, "r"); //se comprueba que el archivo se abra
    if (lectura == NULL) {
        perror("Error al abrir el archivo");
        return -1;
    }

    char caracter = getc(lectura); // se lee el primer del archivo y si cumple la condición ocurre el llamado a las funciones
    if (caracter == 'c' || caracter == 'b' || caracter == 't') {
        SDL_Rect* particulas = (SDL_Rect*)malloc(sizeof(SDL_Rect));
        if (particulas == NULL) {
            perror("Error al asignar memoria");
            return -1;
        }
        int contadorparticulas = 0;

        if (caracter == 'c') {
            particulas = leercsv(lectura, &contadorparticulas, particulas);
        } else if (caracter == 'b') {
            particulas = leerbinario(lectura, &contadorparticulas, particulas);
        } else if (caracter == 't') {
            particulas = leertxt(lectura, &contadorparticulas, particulas);
        }

        fclose(lectura);

        SDL_Window* ventana = NULL;
        SDL_Renderer* renderer = NULL;

        //se crea una ventana del tamaño del equipo del usuario
        ventana = SDL_CreateWindow("HOLA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (ventana == NULL) {
            printf("%s\n", SDL_GetError());
            SDL_Quit();
            return -1;
        }

        renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL) {
            printf("%s\n", SDL_GetError());
            SDL_DestroyWindow(ventana);
            SDL_Quit();
            return -1;
        }

        //se inicia ttf o la función que controla la tipografía
        if (TTF_Init() == -1) {
            printf("%s\n", TTF_GetError());
            SDL_Quit();
            return -1;
        }
        
        //se crea un puntero a la tipografía
        TTF_Font* font = TTF_OpenFont("assets\\Roboto-Black.ttf", 24);
        if (font == NULL) {
            printf("%s\n", TTF_GetError());
            return -1;
        }

        int ancho, largo;
        SDL_GetWindowSize(ventana, &ancho, &largo);

        for (int i = 0; i < contadorparticulas; i++) { //regulacion de los parametros de la partícula
            particulas[i].x %= ancho;
            particulas[i].y %= largo;
            particulas[i].h = size;
            particulas[i].w = size;
            particulas[i].d %= 360;
            particulas[i].p %= weigth + 1;
        }

        //finalmente se llama a visualizar
        visualizar(&contadorparticulas, renderer, particulas, ventana, font, largo, ancho);

        return 0;
    } else {
        printf("Archivo no tiene el formato especificado\n");
        return -1;
    }
}
