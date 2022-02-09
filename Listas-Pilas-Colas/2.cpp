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
        InsertarSiguiente(listaUnificada,lista1->info);
        lista1 = lista1->sgte;
    }

    while(lista2)
    {
        InsertarAlFinal(listaUnificada,lista2->info);
        lista2 = lista2->sgte;
    }




    return;
}


void MostrarLista(Nodo *lista)
{
    while (lista)
    {
        cout << lista->info << "   ";
        lista = lista->sgte;
    }

    return;
}



int main()
{   

    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;
    Nodo *listaUnificada = NULL;

    InsertarSiguiente(lista1,2);
    InsertarSiguiente(lista1,16);
    InsertarSiguiente(lista1,23);

    InsertarSiguiente(lista2,4);
    InsertarSiguiente(lista2,43);
    InsertarSiguiente(lista2,55);
    InsertarSiguiente(lista2,86);


    concatenarListas(lista1,lista2,listaUnificada);


    cout << "La lista unificada es: " << endl;

    MostrarLista(listaUnificada);
    



    return 0;
}
