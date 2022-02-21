#include <iostream>
#include <cstring>

using namespace std;

// PUNTO 1 - DECLARACIONES

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct InfoArchivo
{
    int dni;
    int edad;
    Fecha fecha;
    char vacuna[15];
    int dosis; // 1 - 2 -3
};

struct EstructuraInfo
{
    int edadPromedio; // edad promedio de las personas que recibieron 3 dosis sinopharm
    int cantPrimeraDosis2020; // cantidad de personas que se dieron al 1 dosis en 2020
    int mayorEdad; // mayor edad de la persona con 3 dosis
};


struct InfoPersona
{
    int dni;
    int edad;
    NodoVacuna vacunas;
};

struct InfoVacuna
{
    Fecha fecha;
    char vacuna[15];
    int dosis;
};

struct NodoVacuna
{
    InfoVacuna info;
    NodoVacuna *sgte;
};

struct NodoPersona
{
    InfoPersona persona;
    Nodo *sgte;
};



// PUNTO 2 - DESAROLLAR 
 
NodoPersona* buscar(NodoPersona* raiz, int dni); // busca en la lista de personas por dni
void agregarAlFinal(NodoPersona*& raiz, InfoPersona v);
void agregarAlFinalV2(NodoVacuna*& raiz, InfoVacuna v);

/*
    Leemos todo el archivo de vacunas y guardamos la info en una lista de personas, que cada persona tiene una lista con todas las vacunas que se dio

*/
void cargarEstructura(FILE *aplicaciones,NodoPersona *&personas) 
{
    aplicaciones = fopen("Aplicaciones.dat","rb");
    InfoArchivo infoLeida;
    NodoPersona *personaBuscada;
    InfoPersona personaLeida;
    InfoVacuna vacunaLeida;
    
    
    fread(&infoLeida,sizeof(InfoArchivo),1,aplicaciones);
    while(!feof(aplicaciones))
    {
        
        personaLeida.dni = infoLeida.dni;
        personaLeida.edad = infoLeida.edad;
        strcpy(vacunaLeida.vacuna,infoLeida.vacuna);
        vacunaLeida.dosis = infoLeida.dosis;
        vacunaLeida.fecha = infoLeida.fecha;
        
        personaBuscada = buscar(personas,infoLeida.dni);
        
       if(personaBuscada == NULL) // Si la persona leida no se encuentra ya en la lista de personas la agregamos
       {
           
           agregarAlFinal(personas,personaLeida);
           agregarAlFinalV2(NodoVacuna*& personaLeida.vacunas, vacunaLeida v);
       }else // en cambio, si ya se encuentra la persona, le agregamos la sig dosis de su vacuna
       {
           agregarAlFinalV2(NodoVacuna*& personaBuscada.vacunas, vacunaLeida v);
       }
        
    }
    
    
    return;
}


// PUNTO 3 - DESAROLLAR

void informePedido(NodoPersona *&personas)
{
    
    NodoPersona *aux = personas;
    int edadPromedio = 0 // personas con 3 dosis sinopharm
    int contPersonasEdad = 0;
    int cantPersonas = 0 // personas con la 1 dosis en 2020
    int mayorEdad = 0 // mayor edad de la persona con 3 dosis
    char vacunaQuerida[] = "Sinopharm";
    
    while(aux)
    {
        if(aux->persona.vacunas->info.fecha.anio == 2020) // Verificamos la fecha de la 1 dosis (como insertamos al final, siempre el primer nodo va a ser la 1 dosis)
        {
            cantPersonas +=1;
        }
        
        NodoVacuna auxVacuna = aux->persona.vacunas;
        
        if(strcmp(auxVacuna->info.vacuna,auxVacuna->sgte->info.vacuna)) // Verificamos q la 1 y 2 dosis sean de la misma vacuna
        {
            if(strcmp(auxVacuna->info.vacuna,auxVacuna->sgte->sgte->info.vacuna) // si se cumplio lo anterior, verificamos la 1 con la 3
               {
                   if(mayorEdad < aux->persona.edad)
                   {
                       mayorEdad = aux ->persona.edad
                   }
                   
                   if(strcmp(aux->info.vacuna,vacunaQuerida))
                   {
                       contPersonasEdad +=1;
                       edadPromedio = (edadPromedio + aux->persona.edad) / contPersonnasEdad
                   }
               }
        }
        
        
        aux = aux->sgte;
    }
    
    cout << "La edad promedio de las personas que recibieron 3 dosis Sinopharm es: " << edadPromedio << endl;
    cout << "La cantidad de personas que recibieron la 1 dosis en 2020 es: " << cantPersonas << endl;
    cout << "La edad de la persona con mayor edad y 3 dosis es: " << mayorEdad;
    
    return;
}

int main()
{
    

    return 0;
}
