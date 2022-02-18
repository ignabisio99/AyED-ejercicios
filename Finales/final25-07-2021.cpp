#include <iostream>
#include <cstring>

using namespace std;

// PUNTO 1 - Declarar todas las estructuras de datos involucradas en la aplicación que se propone


struct CobroAutomatico
{   
    char nombreCabina[15];
    int horaDeRegistro;
    char patente[7];
    int tipoVehiculo;

};

struct CobroManual
{
    char nombreCabina[15];
    int horaDeRegistro;
    char patente[7];
    int tipoVehiculo;
};

struct CobroMixto
{
    char nombreCabina[15];
    int horaDeRegistro;
    char patente[7];
    int tipoVehiculo;
    char modalidadDePago; // M (manual), P (automatico)

};

struct InfoArchivo
{
    int horaDeRegistro;
    char patente[7];
    int tipoVehiculo;
    char modalidadDePago;
};

// PUNTO 3 - Codificar o diagramar la función void aparearArchivos(lista de parametros) que recibe por parámetro 
//              los archivos dato asi como el que resultara del apareo de los mismos. (5 puntos)

void aparearArchivos(FILE *telePase1,FILE *telePase2,FILE *coborManual1,FILE *cobroManual2, FILE *pagoMixto1, FILE *pagoMixto2,FILE *archivoResultante)
{
    CobroManual datoManualLeido;
    CobroAutomatico datoAutomaticoLeido;
    CobroMixto datoMixtoLeido;
    InfoArchivo datoAInsertar;

    // TOMO COMO SI TODOS LOS ARCHIVOS YA FUERON ABIERTOS

    fread(&datoManualLeido,sizeof(CobroManual),1,telePase1);
    while(!feof(telePase1))
    {
        datoAInsertar.horaDeRegistro = datoManualLeido.horaDeRegistro;
        datoAInsertar.modalidadDePago = 'M';
        strcpy(datoAInsertar.patente,datoManualLeido.patente);
        datoAInsertar.tipoVehiculo = datoManualLeido.tipoVehiculo;

        fwrite(&datoAInsertar,sizeof(InfoArchivo),1,archivoResultante); 

        fread(&datoManualLeido,sizeof(CobroManual),1,telePase1);
    }

    // SE REPETIRIA ESTO POR CADA ARCHIVO


    return;
};


int main()
{
    // PUNTO 2 - Declare y ponga a disposición los flujos de datos involucrados
    
    FILE *telePase1; // Archivos por cada uno de las cabinas, cada vez que pasa un auto el archivo se va cargando
    FILE *telePase2;
    FILE *cobroManual1;
    FILE *cobroManual2;
    FILE *pagoMixto1;
    FILE *pagoMixto2;

    FILE *archivoResultante;


    return 0;
}
