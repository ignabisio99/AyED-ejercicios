/* LISTAS SE */

#include <iostream>
#include <conio.h>
using namespace std;


struct Nodo
{
    int info;             // Datos de el nodo
    Nodo   *sgte;  // Puntero al siguiente nodo

};



Nodo *obtenerSiguiente(Nodo  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

void mostrarLista(Nodo *lista)
{
    while (lista)
    {
        cout << lista->info << " ";
        lista = obtenerSiguiente(lista);
    }
}

void insertarSiguiente (Nodo  *&lista, int x)
{
    Nodo *nuevo= new Nodo();
    nuevo->info=x;
    if (lista)
    {
        nuevo->sgte= lista->sgte;
        lista->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= lista;
        lista= nuevo;
    }
    return;
}

void borrarSiguiente(Nodo  *lista)
{
    Nodo  *aborrar = lista->sgte;
    Nodo  *sgteaborrar;
    if (aborrar)
        sgteaborrar= aborrar->sgte;
    else
        sgteaborrar = NULL;
    lista->sgte = sgteaborrar;
    delete aborrar;
    return;
}

Nodo *obtenerUltimo(Nodo *p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;

}

Nodo* buscarNodo(Nodo *p, int infoBuscada)
{
    while (p && (p->info != infoBuscada))
    {
        p = p->sgte;
    }
    return p;
}


Nodo* buscarNodoAnterior(Nodo *raiz, Nodo *anterior_a)
{
    Nodo *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sgte!= anterior_a) )
        {
            p = p->sgte;
        }
        return p;
    }
    else
        return NULL;
}

/*
BorrarNodo: recibe por parámetro lista y el puntero a borrar
*/
void borrarNodo(Nodo *&raiz, Nodo *aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar==raiz)
        {
            raiz = raiz->sgte;
            delete aborrar;
        }
        else
        {
            Nodo *x = buscarNodoAnterior(raiz,aborrar);
            borrarSiguiente(x);
        }
    }
    return;
}


void InsertarAlFinal(Nodo*&lista, int x)
{
    Nodo *aux;
    aux=obtenerUltimo(lista);
    if (aux)
    {
        insertarSiguiente(aux,x);
    }
    else
    {
        insertarSiguiente(lista,x);
    }
    return;
}

void borrarLista(Nodo *&lista)
{
    Nodo *anterior;
    Nodo *paux;
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
int main()
{
    cout << "Estas son las primitivas para Nodos SE" << endl;

    return 0;
}
