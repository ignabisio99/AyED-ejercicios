#include <iostream>
 
using namespace std;


void ordenarVector(int *numeros,int cantidad)
{
    

    for(int i = 0;i<cantidad;i++)
    {   
        for(int j = i+1;j<cantidad;j++)
        {
            if(*(numeros+j) < *(numeros+i))
            {
                int temp = *(numeros+j);
                *(numeros+j) = *(numeros+i);
                *(numeros+i) = temp;
            }
        }
    }


    return;
}


void mostrarVector(int *numeros,int cantidad)
{
    for(int i = 0;i<cantidad;i++)
    {
        cout << *(numeros + i) << " ";
    }

    return;
}


int main()
{   
    int cantidad;
    
    cout << "Ingrese la cantidad de elementos: " << endl;
    cin >> cantidad;

    int *numeros = new int[cantidad];

    for(int i = 0;i<cantidad;i++)
    {
        cout << "Ingrese un numero:" << endl;
        cin >> *(numeros+i);
    }

    ordenarVector(numeros,cantidad);

    cout << "El vector ordenado de menor a mayor es:" << endl;

    mostrarVector(numeros,cantidad);

   
    return 0;
}
