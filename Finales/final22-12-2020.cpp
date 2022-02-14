#include <iostream>
#include <cstring>

using namespace std;

// PUNTO 1 - DECLARACIONES Y FUNCION CARGAR

struct Paises
{
    char nombre[20];
    int cantHabitantes;
    int casos[12][3]; // ARREGLO DE ARREGLOS = MATRIZ

};

struct PaisArchivo
{
    int cantCasos;
    int mes;
    int dia;
    char tipoCaso; // H - I - R
    char nombre[20];
};


// 1A- Funcion Cargar PROTOTIPO

void cargar(FILE *f,Paises pais[]); 

// 1B- CODIFICAR LA DEFINICION DE CARGAR

void cargar(FILE *f,Paises pais[])
{
    PaisArchivo paisLeido;

    fread(&paisLeido,sizeof(paisLeido),1,f);
    while(!feof(f))
    {
        int i = 0;
        while(!strcmp(paisLeido.nombre,pais[i].nombre))
        {
            i++;
        }

        int tipoCaso;

        if(paisLeido.tipoCaso == 'H'){
            tipoCaso = 0;
        }else{
            if(paisLeido.tipoCaso == 'I'){
                tipoCaso = 1;
            }else{
                tipoCaso = 2;
            }
        }

        pais[i].casos[paisLeido.mes-1][tipoCaso] += paisLeido.cantCasos;

        fread(&paisLeido,sizeof(paisLeido),1,f);

    }

    fclose(f);

    return;
};


// PUNTO 2 - FUNCION LISTAR

// 2A- CODIFICAR PROTOTIPO DE LA FUNCION

void listar(Paises pais[],int cantidadPaises);

// 2B- CODIFICAR INVOCACION Y FUNCION

void listar(Paises pais[],int cantPaises)
{

    int i = 0;

    while(i<cantPaises)
    {
        cout << "Pais: " << pais[i].nombre << ", cantidad de habitantes: " << pais[i].cantHabitantes << endl;

        for(int j = 0;j<12;j++)
        {
            cout << "Casos en el mes: " << j << " tipo H: " << pais[i].casos[j][0] << endl;
            cout << "Casos en el mes: " << j << " tipo I: " << pais[i].casos[j][1] << endl;
            cout << "Casos en el mes: " << j << " tipo R: " << pais[i].casos[j][2] << endl;
        }


    }



    return;
}



int main()
{
    FILE* f;
    

    f = fopen("ParteDiario.DAT","rb");
    
    int cantPaises; // contiene la cantidad de paises en el arreglo
    // Paises *pais = new Paises[cantPaises];
    Paises pais[cantPaises];


    listar(pais,cantPaises);




    return 0;
}
