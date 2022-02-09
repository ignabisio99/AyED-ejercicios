#include <iostream>
 
using namespace std;


struct Nodo
{
    int info;
    Nodo *sgte;
};

void InsertarSiguiente (Nodo  *&lista, int x)
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

Nodo *ObtenerUltimo(Nodo *p)
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

void InsertarAlFinal(Nodo *&lista, int x)
{
    Nodo *aux;
    aux=ObtenerUltimo(lista);
    if (aux)
    {
        InsertarSiguiente(aux,x);
    }
    else
    {
        InsertarSiguiente(lista,x);
    }
    return;
}



void concatenarListas(Nodo *lista1, Nodo *lista2, Nodo *&listaUnificada)
{
    Nodo *paux = lista1;

    while(lista1)
    {
        InsertarAlFinal(listaUnificada,lista1->info);
        lista1 = lista1->sgte;
    }

    while(lista2)
    {
        InsertarAlFinal(listaUnificada,lista2->info);
        lista2 = lista2->sgte;
    }

    return;
}


Nodo *ObtenerSiguiente(Nodo  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

void MostrarLista(Nodo *milista)
{
    while (milista)
    {
        cout << milista->info << "   ";
        milista = ObtenerSiguiente(milista);
    }
}



int main()
{   

    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;
    Nodo *listaUnificada = NULL;

    InsertarAlFinal(lista1,2);
    InsertarAlFinal(lista1,16);
    InsertarAlFinal(lista1,23);

    cout << "La primera lista es:" << endl;
    MostrarLista(lista1);
    cout << endl;

    InsertarAlFinal(lista2,4);
    InsertarAlFinal(lista2,43);
    InsertarAlFinal(lista2,55);
    InsertarAlFinal(lista2,86);

    cout << "La segunda lista es:" << endl;
    MostrarLista(lista2); 
    cout << endl;


    concatenarListas(lista1,lista2,listaUnificada);


    cout << "La lista unificada es: " << endl;

    MostrarLista(listaUnificada);
    



    return 0;
}
