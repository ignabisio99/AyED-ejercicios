#include <iostream>
 
using namespace std;



int main()
{   

    FILE* f1;
    FILE* f2;
    int v1[] = {2,15,30,33};
    int v2[] = {1,5,10,18,28};
    int numero;

    f1 = fopen("archivo1","wb");
    fwrite(v1,sizeof(int),4,f1);
    fclose(f1);

    f2 = fopen("archivo2","wb");
    fwrite(v2,sizeof(int),5,f2);
    fclose(f2);

    FILE* f3;

    f1 = fopen("archivo1","rb");
    f2 = fopen("archivo2","rb");
    f3 = fopen("archivo3","wb");

    int numero1,numero2;

    fread(&numero1,sizeof(int),1,f1);
    fread(&numero2,sizeof(int),1,f2);
    
    while(!feof(f1) && !feof(f2))
    {   

        if(numero1 > numero2)
        {
            fwrite(&numero2,sizeof(int),1,f3);
            fread(&numero2,sizeof(int),1,f2);
        }

        if(numero1 < numero2)
        {
            fwrite(&numero1,sizeof(int),1,f3);
            fread(&numero1,sizeof(int),1,f1);
        }
    }

    while(!feof(f1))
    {   
        fwrite(&numero1,sizeof(int),1,f3);
        fread(&numero1,sizeof(int),1,f1);
      
    }

    while(!feof(f2))
    {   
        fwrite(&numero2,sizeof(int),1,f3);
        fread(&numero2,sizeof(int),1,f2);
        
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    f3 = fopen("archivo3","rb");

    cout << "El archivo unificado ordenado es: " << endl;

    while(fread(&numero,sizeof(int),1,f3))
    {
        cout << numero << " ";
    }



    return 0;
}
