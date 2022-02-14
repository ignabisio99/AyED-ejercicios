#include <iostream>
#include <cstring>

using namespace std;


struct Nodo
{
    int info;
    Nodo *sgte;
};

int pop(Nodo *&pila);
void insertarAlFinal(Nodo*&lista, int x);
Nodo *obtenerSiguiente(Nodo  *n);
Nodo* buscarNodo(Nodo *p, int infoBuscada);
void insertarOrdenado(Nodo *&lista, int ainsertar);

// PUNTO 1 - DESAROLLAR LOS SIG SUBPROGRAMAS

// PUNTO 1A - Una función que retorne una lista sin orden a partir de la Unión de una pila y una lista.

Nodo *unionPilaLista(Nodo *&pila,Nodo *&lista,Nodo *&listaUnificadora)
{
    Nodo *listaUnificadora = NULL;
    int datoAGuardar;

    while(pila)
    {
        datoAGuardar = pop(pila);
        insertarAlFinal(listaUnificadora,datoAGuardar);
    }

    Nodo *aux = lista;
    Nodo *auxListaUnificada = listaUnificadora;

    while(aux)
    {   
        datoAGuardar = aux->info;
        if(buscarNodo(auxListaUnificada,datoAGuardar) != NULL)
        {
            insertarAlFinal(listaUnificadora,datoAGuardar);
        }

        obtenerSiguiente(aux);
    }


    return listaUnificadora;
};

// PUNTO 1B- Un procedimiento que genere una lista ordenada a partir de la INTERSECCION de 2 listas. 


void listaOrdenada(Nodo *lista1,Nodo *lista2,Nodo *&listaUnificada)
{
    while(lista1)
    {
        if(buscarNodo(lista2,lista1->info) != NULL)
        {
            insertarOrdenado(listaUnificada,lista1->info);
        }
        lista1 = lista1->sgte;
    }


    return;
};

// PUNTO 2


struct Reservas
{
    int codigoHotel;
    int cantidadHabitaciones;
    int cantidadDiasDisponibles;
};

struct HotelLista
{
    int codigoHotel;
    int cantidadDias;
};

struct NodoReservas
{
    HotelLista info;
    NodoReservas *sgte;
};



int busquedaBinaria(Reservas reserva[], int idbuscado)
{
  bool encontrado = false;
  int Iarriba = 100-1;
  int Iabajo = 0;
  int Icentro;
  int result = -1;
  while (Iabajo <= Iarriba && !encontrado)
  {
      Icentro = (Iarriba + Iabajo)/2;
      if (reserva[Icentro].codigoHotel == idbuscado)
      {
          result= Icentro;
          encontrado= true;
      }
      else
      {
        if (idbuscado < reserva[Icentro].codigoHotel)
            Iarriba=Icentro-1;
        else
            Iabajo=Icentro+1;
      }
  }
  return result; // si no encontrado devuelve -1
}



int main()
{   
    Reservas reserva[100];

    NodoReservas *reservasRealiazdas = new NodoReservas();

    NodoReservas *aux = reservasRealiazdas;

    while(aux)
    {
        int posReserva = busquedaBinaria(reserva,aux->info.codigoHotel);
        if(posReserva>=0)
        {
            reserva[posReserva].cantidadDiasDisponibles -= aux->info.cantidadDias;
        }
        aux = aux->sgte;
    }



    return 0;
}