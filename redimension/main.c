#include "cabecera.h"

int main()
{
    system("cls");//limpiar pantalla inicial para que los colores de texto se muestren correctamente al inicio
    int pos = 0, accesos = 0, key, tam = 32, colTotal = 0;//contadores y variables auxiliares
    char *key_s = (char *) malloc(sizeof(char) * 15);//Puntero para concatenar los elementos que forman el key
    char *aux = (char *) malloc(sizeof(char) * 5);//Puntero auxiliar para leer los elementos como string y poder concatenarlos

    Pelicula *peliculas = (Pelicula *)malloc(sizeof(Pelicula)*tam);//Se crea la tabla hash con un tamaño inicial de 32
    iniciar(peliculas,&tam);//se inicia la tabla hash con todas sus posiciones a -1

    Pelicula pel_aux;//pelicula auxiliar para la opcion de menu insertar

    peliculas = leerFichero("films.csv", peliculas,&accesos,&tam,&colTotal);//cargar las peliculas del fichero al programa

    for (;;)
    {
       //Menú de selección
        char menu;// variable que comprueba la opción de menu ingresada
        printf("\nFactor de carga: "SUCCESS"%.2f%%\n"RESET, factorcarga(peliculas,&tam));//imprimir el factor de carga actualizado
        printf("\nAccesos a la tabla HASH: "MSSG"%d\t"RESET"Colisiones totales: "ERR"%d\n"RESET, accesos,colTotal);//Imprime el número de accesos a la tabla hash que van hasta el momento
        //Imprimir menú
        printf(TITLE "\n**MENU DE OPCIONES**\n\n" RESET);
        printf("1.- INSERTAR PELICULA \n");
        printf("2.- BUSCAR PELICULA \n");
        printf("3.- ELIMINAR PELICULA \n");

        printf(ERR "0.- SALIR\n" RESET);
        fflush(stdin);
        //Leer opcion seleccionada por teclado
        printf("\nOPCION: ");scanf("%c", &menu);//solicita al usuario una opción del menú

        switch (menu)
        {
            case '1'://Para insertar un nuevo valor a la tabla hahs
                if(factorcarga(peliculas,&tam) != 100.00){ //Antes de insertar compara si la tabla se encuentra llena y ya no se pueden insertar mas datos
                    system("cls");
                    printf(TITLE "INSERTAR PELICULA\n" RESET);
                    printf("Ingrese el nombre de la pelicula:\n");
                    fflush(stdin);
                    scanf("%s",pel_aux.titulo);//Lee el titulo de la pelicula

                    printf("Ingrese el anio de estreno de la pelicula:\n");
                    fflush(stdin);
                    scanf("%s",aux);//Lee el año de la pelicula
                    strcpy(key_s,aux);//copia el año a la key aux para concatenar el key final
                    pel_aux.ano = atoi(aux);//almacena el año como entero

                    printf("Ingrese la duracion en minutos de la pelicula:\n");
                    fflush(stdin);
                    scanf("%s",aux);//Lee la duracion de la pelicula
                    strcat(key_s,aux);//concatena la duracion al valor ya guardado dentro del key_s
                    pel_aux.duracion = atoi(aux);//guarda la duracion como entero

                    printf("Ingrese el genero de la pelicula:\n");
                    fflush(stdin);
                    scanf("%s",pel_aux.genero);//Lee el genero de la pelicula

                    printf("Ingrese la calificacion de la pelicula:\n");
                    fflush(stdin);
                    scanf("%s",aux);//Lee la calificacion de la pelicula
                    strcat(key_s,aux);//concatena la calificacion para tener la key final
                    pel_aux.popularidad = atoi(aux);

                    pel_aux.key = atoi(key_s);//guarda el key concatenado como entero dentro de la estructura

                    insertar(pel_aux,peliculas,&tam,&accesos,&colTotal);//Llama a a funcion insertar

                    system("cls");
                    printf(SUCCESS"LA PELICULA SE HA REGISTRADO CORRECTAMENTE\n\n"RESET);//mensaje de registro correcto
                    if(factorcarga(peliculas,&tam)>=50.00)//comprueba si el factor de carga ya ha alcanzado el 50%
                        peliculas = redimensionar(peliculas, &tam, &accesos,&colTotal);//Redimensiona la tabla al doble

                }else{
                    system("cls");
                    printf(ERR"\nYA NO SE PUEDEN INGRESAR MAS VALORES A LA TABLA\n\n"RESET);//mensaje de tabla llena
                }

                break;

            case '2':

                system("cls");
                printf(TITLE "BUSCANDO PELICULA\n" RESET);

                printf("Ingrese el anio de estreno de la pelicula:\n");
                fflush(stdin);
                scanf("%s",aux);//Lee el año de la pelicula
                strcpy(key_s,aux);//copia el año a la key aux para concatenar el key final

                printf("Ingrese la duracion en minutos de la pelicula:\n");
                fflush(stdin);
                scanf("%s",aux);//Lee la duracion de la pelicula
                strcat(key_s,aux);//concatena la duracion al valor ya guardado dentro del key_s

                printf("Ingrese la calificacion de la pelicula:\n");
                fflush(stdin);
                scanf("%s",aux);//Lee la calificacion de la pelicula
                strcat(key_s,aux);//concatena la calificacion para generar la clave final

                key = atoi(key_s);//convierte el key_s a entero para guardar en key que se utiliza para la busqueda

                pos = buscar(key,peliculas,&tam,&accesos,&colTotal);//s ellama a la funcion buscar con la key obtenida
                system("cls");
                if(pos < 0){
                    printf(ERR"\nLOS VALORES INGRESADOS NO CONCUERDAN CON NINGUNA PELICULA\n\n"RESET);

                }else{
                    printf(SUCCESS"LA PELICULA QUE BUSCA HA SIDO ENCONTRADA\n\n"RESET);
                    //Imprime los datos obtenidos de la pelicula
                    printf(MSSG"Titulo: "RESET"%s\n", peliculas[pos].titulo);
                    printf(MSSG"Anio de estreno: "RESET"%d\n", peliculas[pos].ano);
                    printf(MSSG"Duracion: "RESET"%d\n", peliculas[pos].duracion);
                    printf(MSSG"Genero: "RESET"%s\n", peliculas[pos].genero);
                    printf(MSSG"Calificacion: "RESET"%d\n\n", peliculas[pos].popularidad);
                }
                system("PAUSE");
                system("cls");
                break;
            case '3':

                system("cls");
                printf(TITLE "ELIMINAR PELICULA\n" RESET);

                printf("Ingrese el anio de estreno de la pelicula:\n");
                fflush(stdin);
                scanf("%s",aux);//Lee el año de la pelicula
                strcpy(key_s,aux);//copia el año a la key aux para concatenar el key final

                printf("Ingrese la duracion en minutos de la pelicula:\n");
                fflush(stdin);
                scanf("%s",aux);//Lee la duracion de la pelicula
                strcat(key_s,aux);//concatena la duracion al valor ya guardado dentro del key_s

                printf("Ingrese la calificacion de la pelicula:\n");
                fflush(stdin);
                scanf("%s",aux);//Lee la calificacion de la pelicula
                strcat(key_s,aux);//concatena la calificacion para generar la clave final

                key = atoi(key_s);//convertimos la clave concatenada a entero

                pos = eliminar(key,peliculas,&tam,&accesos,&colTotal);//llama a la funcion eliminar para borrar la pelicula de la tabla hash
                system("cls");//limpia pantalla
                if(pos < 0){//comprueba si se ha eliminado correctamente
                    printf(ERR"\nLOS VALORES INGRESADOS NO CONCUERDAN CON NINGUNA PELICULA\n\n"RESET);//si la pelicula que se trató de eliminar no esta en la tabla hash se indica
                }else{
                    printf(SUCCESS"\nLA PELICULA SE HA ELIMINADO CORRECTAMENTE\n\n"RESET);//La pelicula se encontró y se borró
                }
                system("PAUSE");//Espera
                system("cls");//limpiar pantalla
                break;
            case '0'://SALIR
                system("cls");
                free(key_s);
                free(aux);
                return 0;//finaliza el programa
                break;
            default://OTRO
                system("cls");
                //la opcion ingresada o se encuentra disponible en el menú
                printf(ERR"\nOPCION DE MENU NO DISPONIBLE\n"RESET);
                break;

        }
    }
    free(key_s);
    free(aux);
    return 0;// finaliza el programa
}
