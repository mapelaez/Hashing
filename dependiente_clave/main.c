#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"


int main(int argc, char *argv[])
{
  int accesos = 0,pos, colTotal = 0;
  char key_a[15],aux[10];
  pelicula myhash[TAM];
  pelicula pel_aux;
  int menu;
  iniciar(myhash,TAM);
  leerFichero("films.csv",myhash,&accesos, &colTotal);
  do{
      printf("\nFactor de carga: %.2f%%\n", factorcarga(myhash,TAM));
      printf("\nAccesos a la tabla HASH: %d\t\t", accesos);
      printf("Colisiones totales: %d\n\n", colTotal);
      printf("1. INSERTAR\n");
      printf("2. BUSCAR\n");
      printf("3. ELIMINAR\n");
      printf("4. SALIR\n\n");
      printf("Selecciona una opcion: ");
      scanf("%d",&menu);
      switch(menu){

        case 1:
            system("cls");
            if(factorcarga(myhash,TAM) != 100.00){
            printf("INSERTAR PELICULA\n" );
            printf("Ingrese el nombre de la pelicula:\n");
            fflush(stdin);
            scanf("%s",pel_aux.titulo);

            printf("Ingrese el anio de estreno de la pelicula:\n");
            fflush(stdin);
            scanf("%s",aux);
            strcpy(key_a,aux);
            pel_aux.ano = atoi(aux);

            printf("Ingrese la duracion en minutos de la pelicula:\n");
            fflush(stdin);
            scanf("%s",aux);
            strcat(key_a,aux);
            pel_aux.duracion = atoi(aux);

            printf("Ingrese el genero de la pelicula:\n");
            fflush(stdin);
            scanf("%s",pel_aux.genero);

            printf("Ingrese la calificacion de la pelicula:\n");
            fflush(stdin);
            scanf("%s",aux);
            strcat(key_a,aux);
            //printf("KEYains: %s\n", key_a);
            pel_aux.popularidad = atoi(aux);

            pel_aux.key = atoi(key_a);
            system("cls");
            insertar(pel_aux,myhash,TAM,&accesos,&colTotal);
            }
            else{
                printf("No hay espacio para insertar\n");
            }
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            printf("Ingrese el anio de estreno de la pelicula:\n");
            fflush(stdin);
            scanf("%s",aux);
            strcpy(key_a,aux);

            printf("Ingrese la duracion en minutos de la pelicula:\n");
            fflush(stdin);
            scanf("%s",aux);
            strcat(key_a,aux);

            printf("Ingrese la calificacion de la pelicula:\n");
            fflush(stdin);
            scanf("%s",aux);
            strcat(key_a,aux);

            pos = atoi(key_a);
            system("cls");
            pos = buscar(pos,myhash,TAM,&accesos,&colTotal); // pos toma el valor de la posición
            if(pos != -1){
                printf("\nAnio: %d\n", myhash[pos].ano);
                printf("Duracion: %d\n", myhash[pos].duracion);
                printf("Titulo: %s\n", myhash[pos].titulo);
                printf("Genero: %s\n", myhash[pos].genero);
                printf("Popularidad: %d\n", myhash[pos].popularidad);
            }
            else{
                printf("La posicion esta libre o ha sido borrada\n");
            }
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            printf("Ingrese el anio de estreno de la pelicula:\n");
            fflush(stdin);
            scanf("%s",aux);
            strcpy(key_a,aux);

            printf("Ingrese la duracion en minutos de la pelicula:\n");
            fflush(stdin);
            scanf("%s",aux);
            strcat(key_a,aux);

            printf("Ingrese la calificacion de la pelicula:\n");
            fflush(stdin);
            scanf("%s",aux);
            strcat(key_a,aux);

            pos = atoi(key_a); // pos lo uso para pasar key_a como parametro
            system("cls");
            pos = eliminar(pos, myhash, TAM,&accesos, &colTotal); // pos lo uso para ver si se ha borrado o no
            if(pos == 0){
                printf("\nPelicula borrada\n");
            }
            else{
                printf("\nPelicula no borrada/id incorrecto\n");
            }
            system("pause");
            system("cls");
            break;
        default:
            system("cls");
            printf("\nOPCION DE MENU NO DISPONIBLE\n\n");
            break;
      }
  }
  while(menu != 4);
  return 0;
}
