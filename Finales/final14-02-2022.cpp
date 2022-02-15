#include <iostream>
#include <cstring>

using namespace std;

// FUNCIONES PARA UTILIZAR SIN DESAROLLAR

/* ARRAYS 
void agregar(TipoDeDatoElemento arr[], int& len, TipoDeDatoElemento v)
int insertarOrdenado(TipoDeDatoElemento arr[], int& len, TipoDeDatoElemento v)
int buscar(TipoDeDatoElemento arr[], int len, TipoDeLaClaveDeBusqueda v)
int busquedaBinaria(TipoDeDatoElemento arr[], int len, TipoDeLaClaveDeBusqueda v, bool& enc)
int buscaEInsertaOrdenado(TipoDeDatoElemento arr[], int& len, TipoDeDatoElemento v, bool& enc)
void ordenar(TipoDeDatoElemento arr[], int len)
void eliminar(TipoDeDatoElemento arr[], int& len, int pos)*/


/* Listas simplemente enlazadas
void insertaPrimero(TipoNodo*& raiz, TipoInfo v)
TipoNodo* agregarAlFinal(TipoNodo*& raiz, TipoInfo v)
TipoNodo* insertarOrdenado(TipoNodo*& raiz, TipoInfo v)
TipoNodo* buscar(TipoNodo* raiz, TipoDeLaClaveDeBusqueda v)
TipoNodo* buscaEInsertaOrdenado(TipoNodo*& raiz, TipoInfo v, bool& enc)
void ordenar(TipoNodo*& raiz)
TipoInfo suprimePrimero(TipoNodo*& raiz)
void eliminar(TipoNodo*& raiz, TipoDeLaClaveDeBusqueda v)
void liberar(TipoNodo*& raiz) */


// PUNTO 1: DEFINICION DE TIPOS DE DATOS

struct Electrodomestico
{
    char codigoElectrodomestico[6+1];
    char nombreElectrodomestico[250+1];
    float precioUnitario;

};

struct Venta // Registro del archivo ventas.dat
{
    char codigoElectrodomestico[6+1];
    int diaDelMes; //1 al 31
    int cantidadVendida;
    int dniCliente;
    char nombreCliente[100+1];


};

struct clienteInfo
{
    int dniCliente;
    char nombreCliente[100+1];
};

struct NodoCliente
{
    clienteInfo info;
    NodoCliente *sgte;
};

struct infoMatriz
{
    int cantidadVendida;
    NodoCliente *cliente;
};

// Punto 2 - DESAROLLAR

// PUNTO 2A - DESAROLLAR int obtenerPosFilaEnMatriz(int diaDelMes);

int obtenerPosFilaEnMatriz(int diaDelMes)
{
   
    return diaDelMes-1;
};

// PUNTO 2B - int obtenerPosColumnaEnMatriz(Electrodomestico electrodomesticos[], char codigoElectrodomestico[6 + 1])

int buscar(Electrodomestico arr[], int len, char v[]);

int obtenerPosColumnaEnMatriz(Electrodomestico electrodomesticos[], char codigoElectrodomestico[6 + 1])
{
    int posColumna = buscar(electrodomesticos,2500,codigoElectrodomestico);

    return posColumna;
};

// PUNTO 3 - DESAROLLAR CARGAR MATRIZ

NodoCliente* agregarAlFinal(NodoCliente*& raiz, clienteInfo v);

void cargarMatriz(FILE *archivoVentas,Electrodomestico electrodomestico[],infoMatriz matrizDatos[][2500])
{
    //El archivo ya se encuentra abierto, array y matriz ya estan inicializadas (cant = 0 y listaCliente = NULL)

    Venta ventaLeida;

    fread(&ventaLeida,sizeof(Venta),1,archivoVentas);

    while(!feof(archivoVentas))
    {
        int posFila = obtenerPosFilaEnMatriz(ventaLeida.diaDelMes);
        int posColumna = obtenerPosColumnaEnMatriz(electrodomestico,ventaLeida.codigoElectrodomestico);

        matrizDatos[posFila][posColumna].cantidadVendida += ventaLeida.cantidadVendida; 

        // Agregamos la info del cliente en la lista de infoMatriz
        clienteInfo clienteLeido;
        clienteLeido.dniCliente = ventaLeida.dniCliente;
        strcpy(clienteLeido.nombreCliente,ventaLeida.nombreCliente);

        agregarAlFinal(matrizDatos[posFila][posColumna].cliente,clienteLeido);

        fread(&ventaLeida,sizeof(Venta),1,archivoVentas);
    }

    fclose(archivoVentas);
    return;
};

// PUNTO 4 - MOSTRAR CLIENTES

void mostrarClientes(infoMatriz matrizDatos[][2500],int numeroFila,int numeroColumna)
{
    NodoCliente *aux;

    cout << "La cantidad de ventas realizadas para el producto es: ";
    cout << matrizDatos[numeroFila][numeroColumna].cantidadVendida << endl;
    cout << "Y los DNIs de las personas que realizaron la compra de ese producto son: " << endl;

    aux = matrizDatos[numeroFila][numeroColumna].cliente;

    while(aux)
    {
        cout << aux->info.dniCliente << ", ";
        aux = aux->sgte; 
    }



    return;
}

/*  
    BONUS) (1 punto) Qué estructura de datos hubiese utilizado en el caso de no conocer 
                la cantidad total de electrodoméstico que vende el comercio (cantidad de electrodomésticos variable)? 
                El punto se obtiene si se define y justifica correctamente y 
                sin ambigüedades la estructura a utilizar.

    En caso de no conocer el total de electrodomesticos que se venden en el comercio, no seria posible utilizar
    un array (vector), ya que estos son una estructura estatica, en ese caso habría que utilizar una lista de
    electrodomesticos, con esto se lograria que el tamaño sea variable y en caso de que se agreguen más
    electrodomesticos, no habria problema



*/

int main()
{
    Electrodomestico electrodomesticos[2500];   // Ordenado por codigoElectrodomestico ascendente (0-1-2...)

    infoMatriz matrizDatos[31][2500]; // matriz de datos, donde: filas = dias del mes (31) y columnas son los electrodomesticos (2500)
    NodoCliente *clienteInfo = new NodoCliente();



    return 0;
}