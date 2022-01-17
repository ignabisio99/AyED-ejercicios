#include <iostream>
 
using namespace std;
 

void mostrarTabla(int const tabla[][5],int tamanio1,int tamanio2)
{
    for(int i = 0;i<tamanio1;i++){
        for(int j = 0;j<tamanio2;j++){
            cout << tabla[i][j] << "\t\t";
        }
        cout << endl << endl;
    }

    return;
}

void convertirTablaVector(int tabla[][5],int vec[],int tamanioVector)
{   
    int cont = 0;
    for(int i = 0;i<3;i++){
        for(int j=0;j<5;j++)
        {
            vec[cont] = tabla[i][j];
            cont++;
        }
    }

    return;
}

int tamanioLogicoVector(int vec[],int tamanioFisico)
{   
    int tamanioLogico = 0;

    while(tamanioLogico<tamanioFisico && vec[tamanioLogico]!=0)
    {
        tamanioLogico++;
    }

    return tamanioLogico;
}


void ordenarVector(int vec[],int tamanio)
{
    int aux;
    int cont = 0;
    int i = 0;

    while(cont<tamanio){

        while(i<tamanio -1 - cont){
            if(vec[i] < vec[i+1]){
                aux = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = aux;
            }
            i++;
        }
        cont++;
        i =0;
    }

    return;
}


void mostrarVector(int vec[],int tamanio)
{   
    int cont = 0;
    while(cont < tamanio && vec[cont]!=0){

        cout << vec[cont] << " ";
        cont++;
    }

    cout << endl;

    return;
}

int main()
{   
    int tabla [3][5]{ 22,32,4,12,11,
                      3,13,16,18,19,
                      33,1,66,77,88 };


    mostrarTabla(tabla,3,5);
    int vec[50];
    convertirTablaVector(tabla,vec,50);


    int tam = tamanioLogicoVector(vec,50);
    mostrarVector(vec,tam);

    ordenarVector(vec,tam);

    cout <<"La tabla transformada en vector y ordenada es: " << endl;

     mostrarVector(vec,tam);


    return 0;
}
