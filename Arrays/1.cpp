#include <iostream>
 
using namespace std;
 



int main()
{
    int vec[10];

    for(int i = 0; i < 10; i++){
    cout << "Ingrese un valor numerico: ";
        cin >> vec[i];
    }

    cout << "El orden inverso de los valores ingresado es:" << endl;

    int cont = 10;

    while(cont >= 0){
        cout << vec[cont - 1] << " ";
        cont = cont - 1;
    }


    return 0;
}
