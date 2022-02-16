#include <iostream>
#include <cstring>

using namespace std;

// PUNTO 1 - DESARROLLAR

// PUNTO 1A - Una función que retorne una lista ordenada a partir de la Unión de una pila y una cola.

struct Nodo
{
    int info;
    Nodo *sgte;
};
void push(Nodo *&pila, int elemento);
int pop(Nodo *&pila);
void queue(Nodo *&cola, int elemento);
int unqueue(Nodo *&cola);
void insertarOrdenado(Nodo *&lista, int ainsertar);
Nodo* buscarNodo(Nodo *p, int infoBuscada);
int buscar(int arr[], int len, int v);


Nodo *listaOrdenada(Nodo *&pila,Nodo *&cola,Nodo *&listaResultante)
{
    Nodo *auxPila = pila;
    Nodo *auxCola = cola;
    

    while(auxPila)
    {
        insertarOrdenado(listaResultante,pop(auxPila));
    }

    while(auxCola)
    {   
        if(buscarNodo(listaResultante,unqueue(auxCola)))
        {
        insertarOrdenado(listaResultante,unqueue(auxCola));
        }
    }


    return listaResultante;
}

// PUNTO 1B - Un procedimiento que genere una lista ordenada a partir de la INTERSECCION de 1 Lista 
//              y un vector de 50 posiciones. Defina usted las estructuras de los nodos de la manera 
//              que considere más conveniente y detallar.


void listaOrdenadaV2(Nodo *&lista,int vec[],Nodo *&listaResultante) // PREGUNTAR! sobre si tomar como un vector de ints
{

    Nodo *aux = lista;
    int numeroBuscado;

    while(aux)
    {   
        numeroBuscado = aux->info;
        if(buscar(vec,50,numeroBuscado)>=0)
        {
            insertarOrdenado(listaResultante,numeroBuscado);
        }

        aux = aux->sgte;
    }

    return;
}


// PUNTO 2

struct VentaArchivo
{
    int idEmpleado;
    int ventasAnuales;
    char sector; // C P S

};


struct NodoVenta
{
    VentaArchivo info;
    NodoVenta *sgte;
};

void insertarOrdenadoV2(NodoVenta *&lista,VentaArchivo ventaLeida); // Inserta ordenado por ventas anuales


// 2A - Armar y mostrar una lista ordenada por Ventas Anuales sólo para el caso que el empleado 
//        pertenece al sector de consultoría.



int main()
{
    NodoVenta *listaVentasAnuales = NULL;
    FILE *f;

    VentaArchivo ventaLeida;

    f = fopen("ventas.dat","rb");

    fread(&ventaLeida,sizeof(VentaArchivo),1,f);

    while(!feof(f))
    {
        if(ventaLeida.sector == 'C')
        {
            insertarOrdenadoV2(listaVentasAnuales,ventaLeida);
        }

        fread(&ventaLeida,sizeof(VentaArchivo),1,f);
    }

    fclose(f);

    NodoVenta *aux = listaVentasAnuales;

    while(aux)
    {
        cout << "Venta del empleado: " << aux->info.idEmpleado << endl;
        cout << "Ventas realizadas: " << aux->info.ventasAnuales << endl;  
        aux = aux->sgte;
    }


    



    return 0;
}