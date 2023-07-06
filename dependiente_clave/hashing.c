#include "leer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void iniciar(pelicula t_hash[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        t_hash[i].key = LIBRE;
    }
}

int H(int key, int tam){
    int pos;
    pos = key % tam;
    return pos;
}

int G(int key, int pos, int tam, int cont_col){
int d;
d = key/tam;
if(d % 2 == 0){
    d = d + 1;
    pos = pos + (d*cont_col);
}
else{
    pos = pos + (d*cont_col);
}
return pos%tam;
}

void insertar(pelicula f, pelicula t_hash[], int tam, int *accesos, int *colTotal){
    int pos,cont_col = 0;
    int pos_orig;
    (*accesos)++;
    pos = H(f.key,tam);
    pos_orig = pos;
    if(t_hash[pos].key == LIBRE || t_hash[pos].key == BORRADO){
            t_hash[pos] = f;
             return;
        }
    else{
        while((t_hash[pos].key != LIBRE) && (t_hash[pos].key != BORRADO)){
            (*accesos)++;
            pos = G(f.key,pos_orig,tam,cont_col);
            cont_col++;
            (*colTotal)++;
        }
        t_hash[pos] = f;
        return;
    }
}

int buscar(int id,pelicula t_hash[],int tam, int *accesos, int *colTotal){
    int pos,pos_orig,cont_col = 0;
    (*accesos)++;
    pos = H(id,tam);
    pos_orig = pos;
    do{
        if(t_hash[pos].key == LIBRE  || cont_col == 511)
            return -1;
        else if(t_hash[pos].key == id)
            return pos;
        else{
            (*accesos)++;
            pos = G(id,pos_orig,tam,cont_col);
            cont_col++;
            (*colTotal)++;
            if(t_hash[pos].key == id) return pos;
        }
    }
    while((t_hash[pos].key != id) && (cont_col < TAM));
    return -1;
}

int eliminar(int id, pelicula t_hash[], int tam, int *accesos, int *colTotal){
    int pos;
    pos = buscar(id, t_hash, tam,accesos, colTotal);
    if(pos != -1){
        t_hash[pos].key = BORRADO;
        return 0;
    }else
        return -1;
}

float factorcarga(pelicula t_hash[], int tam){
    int n_elemen_oc = 0;
    int i;
    for(i = 0; i < tam; i++){
        if ((t_hash[i].key != LIBRE) && (t_hash[i].key != BORRADO))
            n_elemen_oc++;
    }
    return ((float)n_elemen_oc/tam) * 100;
}


