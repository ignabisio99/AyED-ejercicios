#include <iostream>
 
using namespace std;


struct Alumno{

    string nombreYApellido;
    string tipoDocumento;
    int numeroDocumento;
    int legajo;
    int nota;
};

void inicializarVector(Alumno alumnos[])
{
    for(int i =0;i<50;i++)
    {
        alumnos[i].legajo = 0;
    }

    return;
}

int alumnosCantidadLogica(Alumno alumnos[])
{   
    int cont = 0;

    while(cont < 50 && alumnos[cont].legajo != 0)
    {
        cont++;
    }

    return cont;
}

int sumatoriaDeNotas(Alumno alumnos[],int cantidadLogica)
{
    int acum = 0;

    for(int i = 0;i<cantidadLogica;i++)
    {
        acum = acum + alumnos[i].nota;
    }

    return acum;
}


int main()
{  
    Alumno alumnos[50];

    inicializarVector(alumnos);
    int cont = 0;

    while(cont < 50 && alumnos[cont-1].nombreYApellido != "Wolf Roberto")
    {
        cout << "Ingrese el nombre y apellido:" << endl;
        cin >> alumnos[cont].nombreYApellido;

        cout << "Ingrese el tipo de documento: " << endl;
        cin >> alumnos[cont].tipoDocumento;

        cout << "Ingrese el numero de documento:" << endl;
        cin >> alumnos[cont].numeroDocumento;

        cout << "Ingrese el legajo:" << endl;
        cin >> alumnos[cont].legajo;

        cout << "Ingrese la nota" << endl;
        cin >> alumnos[cont].nota;

        cont++;
    }

    int cantidadAlumnos = alumnosCantidadLogica(alumnos);
    int sumatoriaNotas = sumatoriaDeNotas(alumnos,cantidadAlumnos);
    cout << "El promedio de las notas obtenidas por los alumnos es:" << sumatoriaNotas/cantidadAlumnos << endl;



    return 0;
}
