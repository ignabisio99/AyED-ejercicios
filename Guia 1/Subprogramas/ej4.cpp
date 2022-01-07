#include <iostream>
 
using namespace std;
 
void obtenerNumeroMayor(int numero1, int numero2, int &numeroMayor)
{
    if(numero1 > numero2){
        numeroMayor = numero1;
    }else{
        numeroMayor = numero2;
    }
}


int main()
{
    int numero1;
    int numero2;
    int mayor = 0;

    cout << "Ingrese 2 numeros: " << endl;
    cin >> numero1;
    cin >> numero2;

    obtenerNumeroMayor(numero1,numero2,mayor);

    cout << "El numero mayor es: " << mayor << endl;

    return 0;
}
