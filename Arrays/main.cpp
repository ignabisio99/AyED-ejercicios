#include <iostream>
#define VACIO 0
#define TAMANO 10
using namespace std;


/*********** APAREO ****************/
int cantElementos(int v[],int tamfisico)
{
    int i = 0;
    while (i<tamfisico && v[i]!=VACIO)
        i++;
    return i;
}

void apareo(int v1[],int tam1, int v2[], int tam2, int vresult[])
{
    int i = 0,j = 0,k = 0;
    while (i< tam1 && j < tam2)
    {
        if ( v1[i] < v2[j] )
        {
            vresult[k] = v1[i];
            i++;
        }
        else
        {
            vresult[k] = v2[j];
            j++;
        }
        k++;
    }
    for (int cont=i; cont < tam1; cont++)
    {
            vresult[k] = v1[cont];
            k++;
    }
    for (int cont=j; cont < tam2; cont++)
    {
            vresult[k] = v2[cont];
            k++;
    }

    return;
}

int main()
{
    int vector1[TAMANO] = {23,45,78,87,98};
    int vector2[] = {12,56,57,58,71,80,89,90,92,105,109,120};
    int vresultado[50] = {0};
    apareo(vector1,cantElementos(vector1,TAMANO), vector2, cantElementos(vector2,12),vresultado);
    for (int x=0; x < cantElementos(vresultado,50);x++)
        cout << "vresultado[" << x <<"] = " << vresultado[x] << endl;
    return 0;
}
