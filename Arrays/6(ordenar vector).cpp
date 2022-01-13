#include <iostream>
 
using namespace std;
 

void mostrarVector(int vec[],int tamanio)
{
    for(int i = 0;i<tamanio;i++){
        cout << vec[i] << " ";
    }

    cout << endl;

    return;
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


int main()
{   
    int tamanio;

    cout << "Ingrese el tamanio del vector: " << endl;
    cin >> tamanio;

    int vec[tamanio];

    for(int i = 0;i<tamanio;i++)
    {
        cout <<"Ingrese un valor: " << endl;
        cin >> vec[i];
    }

    
    cout << "El vector ingresado es: ";
    mostrarVector(vec,tamanio);


    cout << "El vector ordenado descendentemente es: ";
    ordenarVector(vec,tamanio);
    mostrarVector(vec,tamanio);


    return 0;
}
