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

    cout << "Los numeros ingresados en el vector son:" << endl;

    for(int i = 0;i<5;i++)
    {
        cout << *(puntero+i) << " ";
    }



    return 0;
}
