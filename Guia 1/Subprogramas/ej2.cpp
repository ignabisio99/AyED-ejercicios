#include <iostream>
 
using namespace std;
 

void calcularModulo(int &numero)
{   
    if(numero < 0){
    numero = numero * -1;
    }else
    return;
}

int main()
{   
   int numero;

   cout << "Ingrese un valor: " << endl;
   cin >> numero;
   calcularModulo(numero);
   cout << "El modulo del numero ingresado es: " << numero;


    return 0;
}
