#include <iostream>
 
using namespace std;
 

int calcularTamanio(int vec[],int tamanio)
{
    int tamanioLogico = 0;

    while(tamanioLogico < tamanio && vec[tamanioLogico]!=0){
        tamanioLogico++;
    }

    return tamanioLogico;
}

void aparearVectores(int vec1[],int tamanio1, int vec2[],int tamanio2, int vec3[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while(i<tamanio1 && j < tamanio2){
        if(vec1[i]<vec2[j]){
            vec3[k] = vec1[i];
            i++;
        }else{
            vec3[k] = vec2[j];
            j++;
        }
        k++;
    }

    for(int cont = i;cont <tamanio1;cont++){
        vec3[k] = vec1[cont];
        k++;
    }

    for(int cont = j;cont<tamanio2;cont++)
    {
        vec3[k] = vec2[cont];
        k++;
    }

    return;
}

void mostrarVector(int vec[],int tamanio)
{

    for(int i = 0; i<tamanio;i++){
        cout << vec[i] <<  " ";
    }

    return;

}

int main()
{   
    int vec1[10]={2,3,4,22,32};
    int vec2[7]={5,10,15,20,33,34,60};
    int vec3[50] = {0};

    int tamanioLogico1 = calcularTamanio(vec1,10);
    int tamanioLogico2 = calcularTamanio(vec2,7);

    aparearVectores(vec1,tamanioLogico1,vec2,tamanioLogico2,vec3);

    int tamanioLogico3 = calcularTamanio(vec3,50);
    cout << "El vector apareado es: " << endl;
    mostrarVector(vec3,tamanioLogico3);

    return 0;
}
