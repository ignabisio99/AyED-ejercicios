#include <iostream>
#define VACIO 0
/*********** CORTE DE CONTROL ****************/
using namespace std;
struct FacturaItem
{
    int nrofactura;
    int nroitem;
    float precio;
};

/*Procedimiento que carga datos de prueba, hardcodeados,
para poder verificar el correcto funcionamiento del algoritmo */
void cargaDatosPrueba(FacturaItem vec[], int tam)
{
    vec[0].nrofactura = 100;
    vec[0].nroitem = 432;
    vec[0].precio = 700;

    vec[1].nrofactura = 100;
    vec[1].nroitem = 198;
    vec[1].precio = 1200.5;

    vec[2].nrofactura = 102;
    vec[2].nroitem = 27;
    vec[2].precio = 340.75;

    vec[3].nrofactura = 101;
    vec[3].nroitem = 698;
    vec[3].precio = 120.15;

    vec[4].nrofactura = 101;
    vec[4].nroitem = 27;
    vec[4].precio = 340.75;

    vec[5].nrofactura = 101;
    vec[5].nroitem = 12;
    vec[5].precio = 563.20;

    for (int i= 6; i <tam;i++)
    {
        vec[i].nrofactura = VACIO;
    }

    return;
}
/*TotalPorFactura implementa el corte de control,
para poder utilizar este algoritmo el vector de facturas debe
estar previamente ordenada por el número de factura.
En tam debe recibir la cantidad de elementos existentes en el vector (tamaño lógico).*/
void TotalPorFactura(FacturaItem vec[], int tam)
{
    float suma;
    int i = 0;
    while (i < tam)
    {
        suma = vec[i].precio;
        i++;
        while (i < tam && vec[i].nrofactura == vec[i-1].nrofactura)
        {
            suma += vec[i].precio;
            i++;
        }
        cout << "El total de la factura nro " << vec[i-1].nrofactura << " es $" << suma << endl;
    }
    return;
}

int main()
{
    FacturaItem misfacturas[100];
    cargaDatosPrueba(misfacturas,100);
    TotalPorFactura(misfacturas,6);
    return 0;
}
