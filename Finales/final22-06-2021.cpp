#include <iostream>
#include <cstring>

using namespace std;

/*
DISPONE DE LAS SIG FUNCIONES:
TipoInfo Pop(Nodo*& P); 
Nodo* InsertarOrdenado(Nodo* & P, tipoInfo x); 
Nodo*InsertaSinRepetir(Nodo* &, TipoInfo x) 
*/

// PUNTO 1 - Codifique la declaración todas las estructuras de datos involucradas respetando nombres y tipos

ListaInfo Pop(NodoListaDato *& P);


struct ListaInfo
{
    int campo1;
    char campo2[20];
    float campo3;
    int campo4;
};

struct NodoListaDato
{
    ListaInfo info;
    NodoListaDato *sgte;
};

struct ListaResultante
{
    int campo1;
    char campo2[20];
    NodoSublistaResultante *sgte;
};

struct InfoSublistaResultante
{
    float campo3;
    int campo4;
};

struct NodoSublistaResultante
{
    InfoSublistaResultante info;
    NodoSublistaResultante *sgte;
};

struct NodoListaResultante
{
    ListaResultante info;
    NodoListaResultante *sgte;
};


// PUNTO 2 - Codifique o diagrame la función cargarListaDeListas. Que reciba la lista dato como parámetro 
//              y retorne un puntero a la lista resultado descripta.

//  Dado un conjunto de datos en una lista ordenada, simplemente enlazada, con repetición de datos, 
//    se pide generar una lista ordenada con los datos que se repiten en la lista principal y los 
//      complementarios en una sub lista que surge a partir de esa lista principal.

// Campo1 y Campo2 con repetición, estructura ordenada por el Campo1.



NodoListaResultante *cargarListaDeListas(NodoListaDato *&listaDato)
{   
    NodoListaResultante *listaResultante = NULL;

    NodoListaDato *aux = listaDato;
    bool esPrimerNodo = true;

    NodoListaResultante *auxResult = listaResultante;

    while(aux)
    {   
        ListaInfo datoObtenido = Pop(aux);
        
        if(esPrimerNodo)
        {   
            NodoListaResultante *nodoAInsertar = new NodoListaResultante();

            nodoAInsertar->info.campo1 = datoObtenido.campo1;
            strcpy(nodoAInsertar->info.campo2,datoObtenido.campo2);

            NodoSublistaResultante *subList = new NodoSublistaResultante();
            subList->info.campo3 = datoObtenido.campo3;
            subList->info.campo4 = datoObtenido.campo4;
            subList->sgte = NULL;

            nodoAInsertar->sgte = NULL;
            nodoAInsertar->info.sgte = subList;
            
            listaResultante = nodoAInsertar;
            

            esPrimerNodo = false;
        }
        else
        {
            NodoListaResultante *nodoAInsertar = new NodoListaResultante();

            nodoAInsertar->info.campo1 = datoObtenido.campo1;
            strcpy(nodoAInsertar->info.campo2,datoObtenido.campo2);

            NodoSublistaResultante *subList = new NodoSublistaResultante();
            subList->info.campo3 = datoObtenido.campo3;
            subList->info.campo4 = datoObtenido.campo4;
            subList->sgte = NULL;

            nodoAInsertar->sgte = NULL;
            nodoAInsertar->info.sgte = subList;

            while(auxResult->sgte)
            {
                auxResult = auxResult->sgte;
            }

            auxResult->sgte = nodoAInsertar;
            
        }

        
        
        
        
    }

    return listaResultante;
}

/*
   PUNTO 4 - Determine fortalezas y debilidades de cada alternativa según un contexto que usted plantee
   

El tema con la lista es que tengo que ir comparando una por una al ser muchos elementos y ocupan muchos elementos 
en memoria, en cambio al usar listas con sublistas se optimiza la busqueda y las iteraciones se reducen a la mitad 
Siempre que alla mucha repeticion este tipo de estrategia de resolucion me va a comvenir porque al hacer una 
sublista optimizo la búsqueda en tiempo y en dificultad





*/
int main()
{
    // PUNTO 3 - Codifique un segmento de código que represente una correcta invocación de la función desarrollada

    NodoListaResultante *listaResult = NULL;
    NodoListaDato *listaDat = NULL;

    listaResult = cargarListaDeListas(listaDat);


    return 0;
}