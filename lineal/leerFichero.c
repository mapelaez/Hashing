#include "cabecera.h"

void leerFichero(char *nombre_fichero, Pelicula *f,int *accesos, int *colTotal) {

    char linea[500]; // Para guardar la linea de cada fichero
    char *token;     // Para cada token de cada linea
    Pelicula aux;
    //Abrimos el fichero
    FILE *fp = fopen(nombre_fichero,"r");

    ///Una vez abierto el fichero se procede a medir el tiempo que tarda en insertar los ficheros
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    ///Codigo a medir

    *accesos = 0;
    // Comprobar que no hay error al abrir
    if(fp == NULL){
            printf(ERR "Error de lectura del archivo\n" RESET);

    }

    // Recorremos cada linea del fichero
    while(fgets(linea,500,fp)!=NULL){
            char *key = (char *) malloc(sizeof(char) * 15);
            strcpy(key,"");
            token = strtok(linea,";");
            aux.ano = atoi(token);
            strcpy(key, token);//Empieza la concatenacion de la clave por cada elemento

            token = strtok(NULL, ";");
            aux.duracion = atoi(token);
            strcat(key, token);//Segundo elemento concatenado para la clave

            token = strtok(NULL, ";");
            strcpy(aux.titulo, token);

            token = strtok(NULL, ";");
            strcpy(aux.genero, token);

            token = strtok(NULL, ";");
            aux.popularidad = atoi(token);
            strcat(key, token);//Ultimo elemento concatenado para la clave

            aux.key = atoi(key); //convertimos la variable key de string a int

            insertar(aux,f,accesos,colTotal);//Insertamos el elemento actual
            free(key);//limpia la memoria

    }

    fclose(fp);
     ///Finaliza la cuenta del tiempo una vez insertados todos los elementos de la tabla hahs
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Intervalo de ejecucion inicial: "TITLE"%.20f\n"RESET, interval);//Imprime el tiempo de ejecución
}


