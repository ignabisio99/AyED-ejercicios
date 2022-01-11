#include <iostream>
 
using namespace std;
 
void sumarVectores(int vec1[],int vec2[],int vecSuma[],int tamanio){

    
    for(int i = 0; i<tamanio;i++){
        vecSuma[i] = vec1[i] + vec2[i];
    }  

    return; 
}

void multiplicacionEscalar(int vec1[],int vec2[],int &productoEscalar,int tamanio){
    
    for(int i = 0;i<tamanio;i++){
        productoEscalar = productoEscalar + (vec1[i] * vec2[i]);
    }

    return;
}


int main()
{   

    int tamanio;
   cout << "Ingrese el tamanio del vector entre 2 y 10: " << endl;
   cin >> tamanio;
   int vec1[tamanio];
   int vec2[tamanio];
   int vecSuma[tamanio];
   int productoEscalar = 0;

   for(int i = 0;i<tamanio;i++){
       cout << "Ingrese los valores del primer vector:" << endl;
       cin >> vec1[i];
   }

   for(int i = 0;i<tamanio;i++){
       cout << "Ingrese los valores del segundo vector:" << endl;
       cin >> vec2[i];
   }

   sumarVectores(vec1,vec2,vecSuma,tamanio);

   cout << "El vecto resultante de la suma es: " << endl;

    for(int i = 0;i<tamanio;i++){
        cout << vecSuma[i] << " ";
    }

    cout << endl;

    cout << "El resultado de la multiplicacion escalar es: " << endl;
    multiplicacionEscalar(vec1,vec2,productoEscalar,tamanio);
    cout << productoEscalar;
   


    return 0;
}
