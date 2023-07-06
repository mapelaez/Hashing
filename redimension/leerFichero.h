
#ifndef LEER_H
#define LEER_H

#include "cabecera.h"
typedef struct peliculas{
    int key;
    int ano;
    int duracion;
    char titulo[100];
    char genero[50];
    int popularidad;

}Pelicula;

Pelicula* leerFichero(char *nombre_fichero, Pelicula *f,int *accesos, int *tam, int *colTotal);

#endif // LEER
