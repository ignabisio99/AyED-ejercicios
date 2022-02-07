#include <iostream>
 
using namespace std;

int *encontrarMax(int numeros[],int cantidad)
{   
    int *maximo = numeros;

    for(int i = 1;i<cantidad;i++)
    {
        if(*maximo < *(maximo+i))
        {
            *maximo = *(maximo+i);
        }
    }

    return maximo;
}


int main()
{   
   int cantidad;

   cout << "Ingrese la cantidad de enteros a guardar:" << endl;
   cin >> cantidad;

   int *numeros = new int[cantidad];

   for(int i =0;i<cantidad;i++)
   {
       cout << "Ingrese un numero:" << endl;
       cin >> numeros[i];
   }

   int *numeroMax = encontrarMax(numeros,cantidad);

    cout << "El numero mayor de los ingresados es: " << *numeroMax << endl; 


    return 0;
}
