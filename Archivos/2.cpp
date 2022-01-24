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

// -------- LECTURA DEL ARCHIVO ORIGINAL -----------

    cout << "Los numeros escritos en el archivo original son:" << endl;

    f = fopen("ejemplo","rb");
    
    fread(&numero,sizeof(float),1,f);

    while(!feof(f))
    {   
        
        cout << numero << " ";
        fread(&numero,sizeof(float),1,f);
    }
    fclose(f);
    cout << endl;
    cout << "---------------------------------------------" << endl;

// -------- MODIFICAR UNA POSICION ESPECIFICA ------

    int posicionModificar;
    cout << "Ingrese una posicion del archivo a modificar:" << endl;
    cin >> posicionModificar;
    cout << "Ingrese el valor deseado en esa posicion:" << endl;
    cin >> numero;

    f = fopen("ejemplo","rb+");
    fseek(f,sizeof(float)*(posicionModificar -1),SEEK_SET);
    fwrite(&numero,sizeof(float),1,f);
    fclose(f);

// -------- LECTURA DEL ARCHIVO REESCRITO -----------

    cout << "Los numeros escritos en el archivo reescrito son:" << endl;

    f = fopen("ejemplo","rb");
    
    fread(&numero,sizeof(float),1,f);

    while(!feof(f))
    {   
        
        cout << numero << " ";
        fread(&numero,sizeof(float),1,f);
    }
    fclose(f);

    return 0;
}
