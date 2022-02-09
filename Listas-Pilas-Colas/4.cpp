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

int contarNodos(Nodo *lista)
{
    int cont=0;
    while (lista)
    {
        cont++;
        lista = ObtenerSiguiente(lista);
    }
    return cont;
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

void ordenarLista(Nodo *&lista)
{

    Nodo *aux;
    Nodo *anterior;
    Nodo *proximo;
    bool intercambio;

    int cantidadNodos = contarNodos(lista);

    for(int i = 0;i<=cantidadNodos-2;i++)
    {
        aux = lista;
        for(int j = 0;j<=cantidadNodos-2-i;j++)
        {
            if (aux->sgte->info < aux->info)
            {
                intercambio= true;
                if (aux==lista)
                {
                    lista= aux->sgte;
                    proximo= lista->sgte;
                    lista->sgte=aux;
                    aux->sgte=proximo;
                }
                else
                {
                    anterior=buscarNodoAnterior(lista,aux);
                    proximo=aux->sgte;
                    anterior->sgte= proximo;
                    aux->sgte= proximo->sgte;
                    proximo->sgte= aux;
                }
            }
            else
                intercambio=false;
            if (!intercambio)
            {
                aux= aux->sgte;
            }
        }
    }

    return;
}



int main()
{   

    Nodo *lista1 = NULL;

    InsertarAlFinal(lista1,5);
    InsertarAlFinal(lista1,2);
    InsertarAlFinal(lista1,7);
    InsertarAlFinal(lista1,18);
    InsertarAlFinal(lista1,9);

    ordenarLista(lista1);

    cout << "La lista ordenada de menor a mayor es: " << endl;

    MostrarLista(lista1);
    



    return 0;
}
