#include <iostream>
 
using namespace std;


struct Nodo
{
    int info;
    Nodo *sgte;
};


void insertarOrdenado(Nodo *&listaOrdenada,int numeroAInsertar)
{
    Nodo *paux = listaOrdenada;
    Nodo *anterior = NULL;

    while(paux && paux->info < numeroAInsertar)
    {
        anterior = paux;
        paux = paux->sgte;
    }

    if(paux != listaOrdenada)
    {
        anterior->sgte = new Nodo();
        anterior->sgte->info = numeroAInsertar;
        anterior->sgte->sgte = paux;

    }else{
        listaOrdenada = new Nodo();
        listaOrdenada->info = numeroAInsertar;
        listaOrdenada->sgte = paux;
    }

    return;
}

void MostrarLista(Nodo *listaOrdenada)
{
    while (listaOrdenada)    
    {
        cout << listaOrdenada->info << "   " << listaOrdenada <<endl;
        listaOrdenada = listaOrdenada->sgte;
        
    }

    return;
}



int main()
{   
    int cantidad;
    int numeroAInsertar;
    Nodo *listaOrdenada = NULL;

    cout << "Ingrese la cantidad de elementos a ingresar en la lista:" << endl;
    cin >> cantidad;

    for(int i = 0;i<cantidad;i++)
    {
        cout << "Ingrese un valor a guardar:" << endl;
        cin >> numeroAInsertar;
        insertarOrdenado(listaOrdenada,numeroAInsertar);

    }

    MostrarLista(listaOrdenada);



    return 0;
}
