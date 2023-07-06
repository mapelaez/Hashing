#include "leer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

void leerFichero(char *nombre_fichero, pelicula t_hash[],int *accesos, int *colTotal) {

    char linea[500]; // Para guardar la linea de cada fichero
    char *token;     // Para cada token de cada linea


    pelicula aux;

    //Abrimos el fichero
    FILE *fp = fopen(nombre_fichero,"r");

    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    *accesos = 0;
    // Comprobar que no hay error al abrir
    if(fp == NULL){
            printf("Error de lectura del archivo");
            return;
    }

    // Recorremos cada linea del fichero
    while(fgets(linea,500,fp)!= NULL){
            char key[15];
            token = strtok(linea,";"); // Separamos cada linea por ","
            aux.ano = atoi(token);
            strcpy(key, token);

            token = strtok(NULL, ";");
            aux.duracion = atoi(token);
            strcat(key, token);

            token = strtok(NULL, ";");
            strcpy(aux.titulo, token);

            token = strtok(NULL, ";");
            strcpy(aux.genero, token);

            token = strtok(NULL, ";");
            aux.popularidad = atoi(token);
            strcat(key, token);

            aux.key = atoi(key);

            insertar(aux,t_hash,TAM,accesos,colTotal);

    }
           fclose(fp);

            QueryPerformanceCounter(&end);
            interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

            printf("Intervalo de ejecucion inicial: %.20f\n", interval);//Imprime el tiempo de ejecución
           //system("PAUSE");
}

