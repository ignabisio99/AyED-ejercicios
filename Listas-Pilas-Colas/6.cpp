#include <iostream>
#include <cstring>
 
using namespace std;

struct Materia
{
    char nombre[50];
    char fechaAprobacion[50];
    int nota;
    int libro;
    int folio;

};

struct Alumno
{   
    char nombre[50];
    char apellido[50];
    char dni[50];
    int legajo;
    int codigoCarrera;
    NodoMaterias *materia;   

};

struct NodoMaterias
{
    Materia info;
    Nodo *sgte;
};

struct Nodo
{
    Alumno info;
    Nodo *sgte;
};

void insertarSiguienteAlumno (Nodo  *&lista, Alumno x)
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


void inicializarArchivo(void)
{   
    FILE* f;
    f = fopen("archivoAlumnos.data","wb");

    Alumno x;
    x.legajo = 145245;
    x.codigoCarrera = 23;
    strcpy(x.apellido,"Gonzales");
    strcpy(x.nombre,"Raul");
    strcpy(x.dni,"43.214.234");

    fwrite(&x,sizeof(Alumno),1,f);

    strcpy(x.apellido,"MAXIMILIANO");
    strcpy(x.nombre,"MENDEZ");
    strcpy(x.dni,"36432128");
    x.codigoCarrera=10;
    x.legajo=126211;
    fwrite(&x, sizeof(Alumno),1,f);

    strcpy(x.apellido,"JIMENA");
    strcpy(x.nombre,"REY");
    strcpy(x.dni,"30623943");
    x.codigoCarrera=10;
    x.legajo=190263;
    fwrite(&x, sizeof(Alumno),1,f);

    strcpy(x.apellido,"WALLACE");
    strcpy(x.nombre,"ESTHER");
    strcpy(x.dni,"12321543");
    x.codigoCarrera=10;
    x.legajo=71432;
    fwrite(&x, sizeof(Alumno),1,f);

    fclose(f);
}

Nodo *obtenerSiguiente(Nodo  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

void mostrarListaAlumnos(Nodo *listaAlumnos)
{
    while (listaAlumnos)
    {   
        cout << "DATOS DEL ALUMNO:" << endl;

        cout << "Nombre: " << listaAlumnos->info.nombre << endl;
        cout << "Apellido: " << listaAlumnos->info.apellido << endl;
        cout << "DNI: " << listaAlumnos->info.dni << endl;
        cout << "Legajo: " << listaAlumnos->info.legajo << endl;
        cout << "Codigo de Carrera: " << listaAlumnos->info.codigoCarrera<< endl; 

        cout << "--------------------------"<< endl;
        cout << endl;

        listaAlumnos = obtenerSiguiente(listaAlumnos);
    }
}


int main()
{   
    FILE *f;
    Alumno a;
    Nodo *alumnos = NULL;

    inicializarArchivo();

    f = fopen("archivoAlumnos.data","rb");

    fread(&a,sizeof(Alumno),1,f);
    while(!feof(f))
    {
        insertarSiguienteAlumno(alumnos,a);
        fread(&a,sizeof(Alumno),1,f);

    }

    fclose(f);


    cout << "Los alumnos ingresados en la lista son:" << endl;

    mostrarListaAlumnos(alumnos);


    return 0;
}
