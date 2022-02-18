#include <iostream>
#include <cstring>

using namespace std;


/*Nodo* buscar(Nodo* &, TipoDeDato);
Nodo* insertarOrdenado(Nodo* &, tipoDeDato);

*/

// PUNTO 1 - Declarar todas las estructuras de datos involucradas en la aplicación que se propone

struct InfoLista
{
    char patente[7];
    int horaRegistro;
};

struct Nodo
{
    InfoLista info;
    Nodo *sgte;
};

struct DatosVehiculoSospechado
{
    char patente[7];
    char delitoSospechado[50+1];
    int hora;
};

struct datosVector
{
    int numeroZona;
    char denominacionLugar[30+1];
    Nodo *puntero;

};


/*  PUNTO 2 - Codificar el prototipo la función struct VehiculoSospechoso recorrido(lista de parámetros) 
que reciba las estructuras de datos con los vehículos registrados, la patente del vehículo sospechoso, 
el ilícito y retorna una struct  con la patente del vehículo, el ilícito del que se sospecha pudo haber participado 
y un puntero a una lista con el recorrido del mismo y la siguiente información: la denominación de la zona 
y la hora de registro, ordenado por esto y solo en caso de que la hora de registro sea posterior a la hora 
del ilícito, caso contrario decida un valor de para ese campo y justifique la elección.

*/

struct VehiculoSospechoso
{
    char patente[7];
    char ilicitoSospechado[50+1];
    NodoVehiculo *listaRecorrido;
};

struct InfoRecorrido
{
    char denominacionZona[30];
    int hora;
};

struct NodoVehiculo
{
    InfoRecorrido info;
    NodoVehiculo *sgte;
};

struct VehiculoSospechoso recorrido(datosVector vectorDeZonas[],char patenteSospechoso[],char ilicito[]);


// PUNTO 3 - Codificar o diagramar la función descripta en (2)

/*retorna una struct  con la patente del vehículo, el ilícito del que se sospecha pudo haber participado 
y un puntero a una lista con el recorrido del mismo y la siguiente información: la denominación de la zona 
y la hora de registro, ordenado por esto y solo en caso de que la hora de registro sea posterior a la hora 
del ilícito, caso contrario decida un valor de para ese campo y justifique la elección.


Nodo* insertarOrdenado(Nodo* &, tipoDeDato);
*/

NodoVehiculo* insertarOrdenado(NodoVehiculo *vehiculo, InfoRecorrido recorrido);

struct VehiculoSospechoso recorrido(datosVector vectorDeZonas[],char patenteSospechoso[],char ilicito[])
{
    VehiculoSospechoso vehiculo;
    int contZonas = 0;
    Nodo *aux;
    InfoRecorrido recorrido;

    while(contZonas < 10)
    {
        aux = vectorDeZonas[contZonas].puntero;
        while(aux)
        {
            if(!(strcmp(aux->info.patente,patenteSospechoso)))
            {
                strcpy(vehiculo.patente,patenteSospechoso);
                strcpy(vehiculo.ilicitoSospechado,ilicito);
                strcpy(recorrido.denominacionZona,vectorDeZonas[contZonas].denominacionLugar);
                if(vectorDeZonas[contZonas].puntero->info.horaRegistro)
                recorrido.hora = vectorDeZonas[contZonas].puntero->info.horaRegistro;

            }

            aux = aux->sgte;
        }

        contZonas++;
    }
    




    return vehiculo;
}

int main()
{
    datosVector vectorDeZonas[10];


    return 0;
}