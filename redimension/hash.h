#ifndef HASH_H
#define HASH_H

    #include "cabecera.h"
    #define LIBRE -1
    #define BORRADO -2
    //DECLARACION DE FUNCIONES HASH
    int H(int key, int *tam);
    int G(int h,int k, int colisiones, Pelicula *t_hash, int *tam,int *accesos, int *colTotal);
    int D(int k, int *tam);

    Pelicula *redimensionar(Pelicula *t_hash,int *tam, int *accesos, int *colTotal);
    void iniciar(Pelicula *t_hash, int *tam);
    void insertar(Pelicula f, Pelicula *t_hash, int *tam, int *accesos, int *colTotal);

    int buscar(int id, Pelicula *t_hash,int *tam,int *accesos, int *colTotal);
    int Gbuscar(int h,int k, int colisiones, Pelicula *t_hash, int *tam, int id,int *accesos, int *colTotal);

    int eliminar(int id, Pelicula *t_hash,int *tam,int *accesos, int *colTotal);
    float factorcarga(Pelicula *t_hash, int *tam);


#endif // HASH_H
