#include <iostream>
 
using namespace std;
 
int sumarNumeros(int numero1,int numero2)
{
    return numero1+numero2;
}

int restarNumeros(int numero1, int numero2)
{
    return numero1-numero2;
}

int multiplicarNumeros(int numero1, int numero2)
{
    return numero1*numero2;
}

int dividirNumeros(int numero1, int numero2)
{   
    
    if(numero2 == 0){
        return 0;
    }

    return numero1/numero2;

}

int main()
{ 
    int numero1;
    int numero2;
    char opcion;

    cout << "Ingrese 2 numeros: " << endl;
    cin >> numero1;
    cin >> numero2;

    cout << "Seleccione una operacion a realizar ingresando el caracter correspondiente: "<< endl;
    cout << "a - Sumar" << endl;
    cout << "b - Restar" << endl;
    cout << "c - Multiplicar" << endl;
    cout << "d - Dividir" << endl;
    cout << "e - Salir" << endl;

    cin >> opcion;

    switch(opcion){
        case 'a':
        case 'A':
            cout << "La suma de los numeros es: " << sumarNumeros(numero1,numero2) << endl;
            break;
        case 'b':
        case 'B':
            cout << "La resta de los numeros es: " << restarNumeros(numero1,numero2) << endl;
            break;
        case 'c':
        case 'C':
            cout << "La multiplicacion de los numeros es: " << multiplicarNumeros(numero1,numero2) << endl;
            break;
        case 'd':
        case 'D':
            cout << "La division de los numeros es: " << dividirNumeros(numero1, numero2) << endl;
            break;
        case 'e':
        case 'E':
            exit(-1);
            break;
   }
     

    return 0;
}
