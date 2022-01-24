#include <iostream>
 
using namespace std;



int main()
{   

    int cantidad;  
    cout << "Ingrese la cantidad de valores a escribir en el archivo:" << endl;
    cin >> cantidad;

    float numero;
    FILE* f;

// ---------  ESCRITURA DEL ARCHIVO ---------

    f = fopen("ejemplo","wb");

    for(int i = 0;i<cantidad;i++){

        cout << "Ingrese un numero a escribir en el archivo:" << endl;
        cin >> numero;

        fwrite(&numero,sizeof(float),1,f);
        
    }
    fclose(f);

// -------- LECTURA DEL ARCHIVO ESCRITO -----------

    cout << "Los numeros escritos en el archivo son:" << endl;

    f = fopen("ejemplo","rb");
    
    fread(&numero,sizeof(float),1,f);

    while(!feof(f))
    {   
        
        cout << numero << " ";
        fread(&numero,sizeof(float),1,f);
    }

    return 0;
}
