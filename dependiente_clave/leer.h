#ifndef LEER_H_INCLUDED
#define LEER_H_INCLUDED

#define LIBRE -1
#define BORRADO -2
#define TAM 512


typedef struct pelicula{
    int key;
    int ano;
    int duracion;
    char titulo[100];
    char genero[50];
    int popularidad;
} pelicula;


void leerFichero(char *nombre_fichero, pelicula t_hach[], int *accesos, int *colTotal);
void iniciar(pelicula t_hash[], int tam);
void insertar(pelicula f, pelicula t_hash[], int tam, int *accesos, int *colTotal);
int buscar(int id,pelicula t_hash[],int tam, int *accesos, int *colTotal);
int eliminar(int id,pelicula t_hash[], int tam, int *accesos, int *colTotal);
float factorcarga(pelicula t_hash[], int tam);
void mostrar(pelicula t_hash[], int tam);

#endif // LEER_H_INCLUDED

