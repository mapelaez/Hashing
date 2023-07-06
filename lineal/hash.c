#include "hash.h"
//FUNCION INICIAR
void iniciar(Pelicula t_hash[], int tam){//Inicializa la tabla hash con todos los valores a -1(LIBRE)
    int i;
    for(i = 0; i < tam; i++){ // for para recorer la tabla hash completa
        t_hash[i].key = LIBRE; //Indica como libre todos los datos de la tabla
    }

}
//FUNCION HASH
//Funcion para encontrar la posicion insicial dentro de la tabla hash
int H(int key, int tam){ //funcion hash
    int pos;
    pos = key % tam;//Formula hash implementada para este ejercicio
    return pos;
}
//FUNCION INSERTAR
//insertar nuevos campos dentro de la tabla hash
void insertar(Pelicula f, Pelicula *t_hash, int *accesos, int *colTotal){ //Pasa como parametros la pelicula a ingresar, la tabla hash el tamaño de la tabla y el numero de accesos a la tabla actual
    int pos;
    (*accesos)++;//incrementa los accesos cada vez que intenta ingresar a la tabla hash, haya colision o no
    pos = H(f.key,TAM); //Se implementa la funcion de hash para encontrar la posicion en que se debe insertar
    if(t_hash[pos].key == LIBRE || t_hash[pos].key == BORRADO){
        t_hash[pos] = f;//Si la posicion en la tabla esta libre o borrada se puede ingresar el valor deseado
    }
    else{//Si no se procede a llamar a la funcion G para que encuentre la nueva posicion
        (*colTotal)++;//Incrementa el numero de colisiones totales del programa
        pos = G(pos, 1, t_hash, accesos, colTotal);//la funcion G devuelve la posicion correcta para ingresar los datos en la tabla
        t_hash[pos] = f;//Se ingresa el dato en la posicion de de la tabla que esta disponible
    }
}
//FUNCION G
//G busca una nueva posicion donde insertar cuando hay colision
int G(int h, int colisiones, Pelicula *t_hash, int *accesos, int *colTotal){
    int pos;
    pos = (h + colisiones) % TAM;//Formula g para encontrar la siguiente posicion en la tabla hash
    (*accesos)++;
    if(t_hash[pos].key == LIBRE || t_hash[pos].key == BORRADO){
        return pos;//returna la posicion si encuentra un espacion libre o borrado dentro de la tabla
    }
    else{
        (*colTotal)++;//Incrementa el numero de colisiones totales del programa
        colisiones++;//incrementa el nuemro de colision que van hasta el momento
        return G(h, colisiones,t_hash,accesos,colTotal);//aplica recursividad hasta encontrar una posicion dipsonible para poder insertar

    }
}
//FUNCION BUSCAR
//Para encontrar un valor en la tablas hash segun la clave con la que se busca, devuelve la posicion de la tabla si encuentra la clave
//sino devuelve un -1 para indicar que no se encuentra la clave registrada en la tabla
int buscar(int id, Pelicula *t_hash,int *accesos, int *colTotal){
    int pos;
    pos = H(id,TAM);
    (*accesos)++;//Se le suma 1 al numeor de accesos actual de la tabla hash
    if(t_hash[pos].key == LIBRE)//si la posisiion esta libre deja de buscar dentro de la tabala
       return -1;
    else if(t_hash[pos].key == id)//si el valor se encuentra devuelve la posicion donde se encuentra
        return pos;//posision de la tabla encontrada
    else{
        (*colTotal)++;//Incrementa el numero de colisiones totales del programa
        pos = Gbuscar(pos, 1, t_hash, id,accesos, colTotal);//si hay una clave diferente o esta borrado esta posicion llama a la funcion Gbuscar
        return pos;//devuelve la nueva clave para mostrar la busqueda al usuario
    }
}

//FUNCION GBUSCAR
//Funciona similar a la funcion g con unas pequeñas variaciones que hay entre la busqueda y lainsercion de los datos
int Gbuscar(int h, int colisiones, Pelicula *t_hash, int id,int *accesos, int *colTotal){
    int pos;
    pos = (h + colisiones) % TAM; //Formula G de hashing donde h es la posision dada por la funcion H
    (*accesos)++;
    if(t_hash[pos].key == LIBRE || colisiones == TAM){
        return -1; // Si encuentra una casilla libre entonces returna -1, ya que no se encontrara el valor en la lista
                    //Si el numero de colisiones alcanza el valor de la tabla hash entonces la tabla no tiene un espacio libre donde guardar el valor
    }else if(t_hash[pos].key == id){
        return pos; // Si encuentra el id correcto retorna la posicion
    }else{
        colisiones++; //aumenta el numeor de colisiones para una busqueda unicamenta
        (*colTotal)++;//Incrementa el numero de colisiones totales del programa
        pos = Gbuscar(h,colisiones, t_hash, id,accesos,colTotal); //Llamada recursiva si hay colision en la busqueda
        return pos; // retorna la posision de la pelicula encontrada si se encuentra en la tabla cuando se aplica la recursividad

    }
}

//FUNCION ELIMINAR
//Se auxilia de la función buscar para encontrar el valor dentro de la tabla hash y poder eliminarlo.
int eliminar(int id, Pelicula *t_hash,int *accesos, int *colTotal){
    int pos;
    pos = buscar(id, t_hash,accesos,colTotal);//se auxilia de funcion buscar para encontrar si la clave esta en la tabla hash y saber su posicion
    if(pos != -1){//si la posicion no esta marcada como libre se marca como borrado
        t_hash[pos].key = BORRADO;//marca el key como borrado
        return 0;
    }else
        return -1;//devuelve -1 cuando no encuentra la clave para poder eliminarla
}

//FUNCION FACTOR DE CARGA
float factorcarga(Pelicula *t_hash){//Calcular el factor de carga
    int n_elemen_oc = 0;//Contador para el numero de elementos ocupados
    int i;//i para recorrer un for
    for(i = 0; i < TAM; i++){//for para recorrer la tabla hash
        if ((t_hash[i].key != LIBRE) && (t_hash[i].key != BORRADO))//si no esta libre ni borrado la posicion esta siendo ocupada
            n_elemen_oc++;//se suma el número de elementos por 1
    }
    return ((float)n_elemen_oc/TAM) * 100;//returna el porcentaje del numero de elementos que estan siendo ocupados
}
