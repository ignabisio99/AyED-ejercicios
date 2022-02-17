#include <iostream>
#include <cstring>

using namespace std;

// PUNTO 1

// 1A - Describir en C++ la definición de una cola que contenga un registro con un campo de caracteres 
//          y un campo numérico. Declarar las variables necesarias para poder operar con la cola descripta

struct ColaInfo
{
    int campoNumerico;
    int campoCaracteres[50];
};

struct NodoCola
{
    ColaInfo info;
    NodoCola *sgte;
};

int unqueue(NodoCola *&cola);
void queue(NodoCola *&cola, int elemento);


// PUNTO 1B - Describir en C++ la definición de una pila que contenga un campo de caracteres.
//               Declarar las variables necesarias para poder operar con la pila descripta

struct NodoPila
{
    char campoCaracteres [50];
    NodoPila *sgte;
};

// PUNTO 2 

// 2A - Revisar la función “retirarPalabras”. Describir con unas pocas palabras qué proceso realiza 
//          dicha función e indicar cuál es el resultado si se la ejecuta con los siguientes datos:


// Lista =   Hoy -> es -> jueves -> y -> rendimos -> final -> de -> algoritmos -> .   
//              El -> jueves -> pasado ->  también -> de -> algortimos

// Pila = algoritmos->jueves->parcial

void retirarPalabras(tListaTexto *&listaTexto,tPilaPal *&pilaPal,tColaRepetFte *&colaFte,tColaRepFdo *&colaFdo)
{
    inicializarColaRep(colaFte,colaFdo);
    string palabra1;
    tRegCola r;  // debe contener palabra y cantidad de veces que se repite
    tListaTexto *q;

    while(pilaPal != NULL)
    {
        palabra1 = pop(pilaPal);
        cant = 0;
        q = buscarListaPal(listaTexto,palabra1);
        while(q != NULL)
        {
            q = eliminarLista(listaTexto,palabra1);
            cant++;
            q = buscarListaPal(listaTexto,palabra1);
        }
        if(cant >0)
        {
            r.palabra = palabra1;
            r.cant = cant;
            encolar(colaFte,colaFdo,r);
        }
    }

    return;
};


/* El proceso que realiza la funcion "retirarPalabras" es primero va desapilando mediante el metodo
    LIFO (last in, firts out) que es el que utilizan las pilas, en el que el ultimo dato que entra es el primero que 
    sale, en este caso el primero en salir es "parcial", a medida que se va desapilando la pila mientras que esta
    no este vacia, se busca en la lista de palabras si esta contiene la palabra desapilada, y si esta se 
    encuentra en la lista, se va a eliminar todas las veces en la que se encuentre en la lista, aumentando 
    el contado de cantidad.
    Luego, si la palabra si se encontraba en la lista, el contador tiene que haber crecido, por lo tanto es
    mayor a 0, se agrega esa palabra con su cantidad de veces de aparicion en la cola.


    El resultado de la ejecucion con esos datos seria:

    Parcial no se encuentra en la lista, por lo tanto no se va a encolar y se pasa a la sig palabra
    Jueves si se encuentar en la lista, cant toma el valor de 2, y este pasa a la cola
    algoritmos tambien se encuentra en la lista, cant toma el valor de 2 y se agrega a la cola

    Por lo tanto queda:

    Cola: algoritmos, 2 -> Jueves,2


*/

// PUNTO 2B- En el algoritmo propuesto realizar las modificaciones necesarias para poder mostrar 
//              en pantalla las palabras que están en la pila, pero no están en la lista.  

void retirarPalabrasV2(tListaTexto *&listaTexto,tPilaPal *&pilaPal,tColaRepetFte *&colaFte,tColaRepFdo *&colaFdo)
{
    inicializarColaRep(colaFte,colaFdo);
    string palabra1;
    tRegCola r;  // debe contener palabra y cantidad de veces que se repite
    tListaTexto *q;

    while(pilaPal != NULL)
    {
        palabra1 = pop(pilaPal);
        cant = 0;
        q = buscarListaPal(listaTexto,palabra1);
        while(q != NULL)
        {
            q = eliminarLista(listaTexto,palabra1);
            cant++;
            q = buscarListaPal(listaTexto,palabra1);
        }
        if(cant == 0)
        {
            r.palabra = palabra1;
            r.cant = cant;
            cout << palabra1 << cant;
            encolar(colaFte,colaFdo,r);
        }
    }

    return;
};

int main()
{
    NodoCola *colaInicio = NULL;
    NodoCola *colaFin = NULL;

    NodoPila* pila = NULL;



    return 0;
}