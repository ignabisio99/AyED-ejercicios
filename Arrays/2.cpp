#include <iostream>
 
using namespace std;
 

void calcularPromedio(int vec[],float &promedio){

    int acum = 0;

    for(int i = 0;i<15;i++){
        acum += vec[i];
    }

    promedio = acum / 15;
    
    return;
}

int main()
{
    int vec[15];

    for(int i = 0; i<15;i++){
        cout << "Ingrese un valor:" << endl;
        cin >> vec[i];
    }

    int numeroMayor = vec[0];
    int numeroMenor = vec[0];
    float promedio;
    int masCercaPromedio = vec[0];

    for(int i = 1; i<15;i++){
        if(vec[i] > numeroMayor){
            numeroMayor = vec[i];
        }
        if(vec[i] < numeroMenor){
            numeroMenor = vec[i];
        }
    }

    calcularPromedio(vec,promedio);

    cout << "El numero mayor es: " << numeroMayor << endl;
    cout << "El numero menor es: " << numeroMenor << endl;
    cout << "El promedio es: " << promedio << endl;
    return 0;
}
