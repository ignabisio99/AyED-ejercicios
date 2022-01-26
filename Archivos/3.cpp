#include <iostream>
 
using namespace std;



int main()
{   

    FILE* f1;
    FILE* f2;
    int v1[] = {33,2,14};
    int v2[] = {1,88,62,12,9};
    int numero;

    f1 = fopen("archivo1","wb");
    fwrite(v1,sizeof(int),3,f1);
    fclose(f1);

    f2 = fopen("archivo2","wb");
    fwrite(v2,sizeof(int),5,f2);
    fclose(f2);

    FILE* f3;

    f1 = fopen("archivo1","rb");
    f2 = fopen("archivo2","rb");
    f3 = fopen("archivo3","wb");

    int numero1,numero2;
    
    while(fread(&numero1,sizeof(int),1,f1) && fread(&numero2,sizeof(int),1,f2))
    {
        fwrite(&numero1,sizeof(int),1,f3);
        fwrite(&numero2,sizeof(int),1,f3);

    }

    fread(&numero1,sizeof(int),1,f1);
    
    while(!feof(f1))
    {   
        fwrite(&numero1,sizeof(int),1,f3);
        fread(&numero1,sizeof(int),1,f1);
    }

    fread(&numero2,sizeof(int),1,f2);

    while(!feof(f2))
    {   
        
        fwrite(&numero2,sizeof(int),1,f3);
        fread(&numero2,sizeof(int),1,f2);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);


    cout << "El archivo unificado es: " << endl;

    f3 = fopen("archivo3","rb");

    while(fread(&numero,sizeof(int),1,f3))
    {   
        cout << numero << " ";
    }

    fclose(f3);

 
    return 0;
}
