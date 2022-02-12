#include <iostream>
#include <cstring>


 
using namespace std;

// PUNTO 1 - DECLARACION DE LA LISTA PRINCIPAL LISTAQ

struct Tipo1
{
    char dato1[3];
};

struct NodoListaTipo1
{
    Tipo1 info;
    NodoListaTipo1 *sgte;
    NodoListaTipo2 *sublista;
};

struct Tipo2
{
    char dato2[3];
    char dato1[3];
};

struct NodoListaTipo2
{
    Tipo2 info;
    NodoListaTipo2 *sgte;
    NodoListaTipo2 *ant;
};

void ListaDEborrarLista(NodoListaTipo2 *&lista)
{
    NodoListaTipo2 *anterior;
    NodoListaTipo2 *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}



// PUNTO 3 - Subprograma que reciba por parámetros una lista principal, una cadena de caracteres 
//              y busque el nodo de la lista principal cuyo valor de dato1 coincida con la cadena parámetro


bool buscarNodo(NodoListaTipo1 *listaPrincipal,char dato1[3])
{
    while(listaPrincipal)
    {
        if(strcmp(dato1,listaPrincipal->info.dato1))
        {
            return true;
        }
        listaPrincipal = listaPrincipal->sgte;
    }

    return false;
}


int main()
{   
    // PUNTO 1 - DECLARACION LISTAQ

    NodoListaTipo1 *listaQ = NULL;

    // PUNTO 2A - Agregar un nodo

    NodoListaTipo2 *nuevoNodoTipo2 = new NodoListaTipo2();
    strcpy(nuevoNodoTipo2->info.dato1,"N1");
    strcpy(nuevoNodoTipo2->info.dato2,"S8");

    NodoListaTipo2 *aux = listaQ->sublista;
    aux = aux->sgte;

    nuevoNodoTipo2->sgte = aux->sgte; // ACOMODAMOS APUNTADO AL ANTERIOR Y SIGUIENTE DEL NUEVO NODO;
    nuevoNodoTipo2->ant = aux;

    aux->sgte->ant = nuevoNodoTipo2; // ACOMODAMOS EL SIG NODO

    aux->sgte = nuevoNodoTipo2; // ACOMODAMOS EL NODO ANTERIOR


    // PUNTO 2B - Eliminar nodo con dato1="N3"

    NodoListaTipo1 *auxNodoAnterior = listaQ;
    NodoListaTipo1 *nodoABorrar = NULL;
    NodoListaTipo2 *auxSublista = NULL;

    while(strcmp("N3",auxNodoAnterior->sgte->info.dato1) != 0)
    {   
        auxNodoAnterior = auxNodoAnterior->sgte;

    }

    nodoABorrar = auxNodoAnterior->sgte;
    auxSublista = nodoABorrar->sublista;

    ListaDEborrarLista(auxSublista); // BORRAMOS LA SUBLISTA DE DEL NODO

    auxNodoAnterior->sgte = nodoABorrar->sgte; // ASIGANMOS LOS PUNTEROS Y BORRAMOS EL NODO DE LA LISTA PRINCIPAL
    delete(nodoABorrar);
    


    return 0;
}
