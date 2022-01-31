#include <iostream>
 
using namespace std;


int main()
{   
    int vec[5];
    
    int *puntero = vec;

    for(int i=0;i<5;i++)
    {
        cout << "Ingrese un numero a guardar en el vector:" << endl;
        cin >> *(puntero+i);
    }

    cout << "Los numeros ingresados en el vector de forma inversa son:" << endl;

    int cantidad = 4;

    while(cantidad>=0)
    {
        cout << vec[cantidad] << " ";
        cantidad = cantidad-1;
    }


    return 0;
}
