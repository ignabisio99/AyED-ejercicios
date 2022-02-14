#include <iostream>
#include <cstring>

using namespace std;

// RECURSOS, ESTRUCTURAS Y FUNCIONES

struct Fecha
{
    int dia;
    int mes;

};

struct Hora
{
    int hora;
};

struct Obra
{
    int idObra;
    char titu[100];
    Fecha fEstreno;
    int idTeatro;
    int cantidadRechazados;

};

struct Teatro
{
    int idTeatro;
    char nom[50];
    int capacidad;
    int sectores;

};

struct Funcion
{
    int idFuncion;
    int diaSemana;
    Hora hora;

};

struct Reserva
{
    int idCli;
    int idObra;
    int dia;
    int sector;
    int cant;

};

// Punto 1 - Codificar estructura del Nodo

struct Nodo
{
    Funcion info;
    Nodo *sgte;

};

Obra getObra(int idObra); // Retorna los datos de una obra
Teatro getTeatro(int idTeatro); // Retorna los datos de un teatro
Reserva leerReserva(); // Lee una reserva ingresada por el sitio
bool continuarOperando(); // Determina si finaliza la operatoria del sitio
Nodo *getFuncionesObra(int idObra); // Retorna un puntero a un nodo de lista enlasada con los datos de una funcion
int capacidadSector(int idTeatro,int sector); // Retorna la disponibilidad del sector del teatro idTeatro
void notificarRechazo(int idCli,bool acept); // Notifica al cliente acerca del rechazo o aceptacion de su reserva



/* Operaciones y acotaciones

    - Las reservas seran aceptadas siempre y cuando haya funcion y disponibilidad suficiente para cubrir
    la totalidad de ubicaciones requeridas por el cliente en el sector pedido. De lo contrario se rechazaran.

    - Las obras no seran mas de 1000, numeradas del 1 al 1000

    - Solo se programa una funcion dia de la semana,pudiendo no haber funciones todos los dias

    - A lo sumo, los teatros tienen 10 sectores los cuales siempre se numeraran a partir de 1


*/
int main()
{
    // PUNTO 2 - NOTIFICAR SOBRE ACEPTACION O RECHAZO
    
    Reserva reservaLeida = leerReserva();
    while(continuarOperando())
    {
       Nodo *funcionAReservar =  getFuncionesObra(reservaLeida.idObra);
       Obra obraAReservar = getObra(reservaLeida.idObra);
       int idTeatroAReservar = obraAReservar.idTeatro;
       Teatro teatroRequerido = getTeatro(idTeatroAReservar);
        
       int capacidadRestante = capacidadSector(idTeatroAReservar,reservaLeida.sector);

       if(reservaLeida.cant < capacidadRestante) // Verifico que haya capacidad en el sector requerido
       {    
           if(reservaLeida.dia == funcionAReservar->info.diaSemana && obraAReservar.fEstreno.dia == funcionAReservar->info.diaSemana ); // Verfico que haya una obra en la fecha requerida
           notificarRechazo(reservaLeida.idCli,1); // ¿Tomo 1 como que se acepta y 0 como que se rechaza?
       }else
       {
           notificarRechazo(reservaLeida.idCli,0);
           obraAReservar.cantidadRechazados += 1;
       }

    }

    // PUNTO 3 - LISTADO DE RECHAZADOS

    Obra obra[999];

    for(int i = 0;i<999;i++)
    {
        cout << "La cantidad de rechazados de la obra: " << obra[i+1].titu << " es:" << obra[i].cantidadRechazados << endl;
        cout << "--------------------------------" << endl;
    }

    return 0;
}
