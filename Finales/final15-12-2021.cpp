#include <iostream>
#include <cstring>

using namespace std;

// PUNTO 1 - Codifique la definición de los tipos de datos a utilizar 
//              (array de usuarios y lista de libros de cada usuario)

struct InfoColaUsuarios
{
    int idUsuario;
    char nombreUsuario[250+1];

};

struct NodoColaUsuarios
{
    InfoColaUsuarios info;
    NodoColaUsuarios *sgte;

};

struct Compra
{
    int idLibro;
    char nombreLibro[100+1];
    int idUsuario;
};

struct InfoUsuarios
{
    int idUsuario;
    char nombreUsuario[250+1];
    int cantTotalLibrosComprados;
    NodoLibros *librosComprados;
};

struct LibroInfo
{
    int idLibro;
    char nombreLibro[100+1];
};

struct NodoLibros
{
    LibroInfo info;
    NodoLibros *sgte;
};

// PUNTO 2 - Desarrolle el procedimiento cargarArrayUsuarios que recibe 4 parámetros: 
//              los punteros de la cola (colaFte y colaFin), el array de usuarios vacío y por último 
//               su cantidad de elementos útiles (len) que ya fue inicializada en cero previamente. 
//                Debe consumir la cola y cargar el array de usuarios con los datos obtenidos. 
//                  Dado que todavía no se están procesando los libros comprados, la cantidad total de libros 
//                     comprados debe quedar inicializada en cero y la lista de libros comprados inicializada 
//                         correctamente para estar vacía.

void cargarArrayUsuarios(NodoColaUsuarios *&colaFte,NodoColaUsuarios *&colaFin,InfoUsuarios usuario[],int len)
{
    NodoColaUsuarios *aux = colaFte;
    int cont = 0;

    while(aux != colaFin && cont < len)
    {
        usuario[cont].idUsuario = aux->info.idUsuario;
        strcpy(usuario[cont].nombreUsuario,aux->info.nombreUsuario);
        usuario[cont].cantTotalLibrosComprados = 0;
        usuario[cont].librosComprados = NULL;

        cont++;
        aux = aux->sgte;
    }
};  


// PUNTO 3 -  Desarrolle el procedimiento cargarCompras que debe cumplir con  lo siguiente:
//      Recibe 3 parámetros: el archivo de compras ya abierto, el array de usuarios y su cantidad de elementos útiles 
//          (len) asociada (ambos ya cargados en el punto anterior).
//      Se debe leer secuencialmente el archivo de compras.
//      Por cada compra, agregar el libro en la lista de libros comprados del usuario correspondiente
//          Por cada compra, contabilizar en el usuario correspondiente la cantidad de total de libros 

int busquedaBinaria(InfoUsuarios vec[], int idbuscado);
NodoLibros* agregarAlFinal(NodoLibros*& raiz, LibroInfo v);
NodoLibros* buscar(NodoLibros* raiz, LibroInfo v);

void cargarCompras(FILE *archivoCompras,InfoUsuarios usuario[],int cantElementos)
{   
    Compra compraLeida;
    LibroInfo libroLeido;

    fread(&compraLeida,sizeof(Compra),1,archivoCompras);
    while(!feof(archivoCompras))
    {
        int posUsuario = busquedaBinaria(usuario,compraLeida.idUsuario);
        if(posUsuario >= 0 && (buscar(usuario[posUsuario].librosComprados,libroLeido) == NULL))
        {
            usuario[posUsuario].cantTotalLibrosComprados +=1;
            libroLeido.idLibro = compraLeida.idLibro;
            strcpy(libroLeido.nombreLibro,compraLeida.nombreLibro);
            usuario[posUsuario].librosComprados = agregarAlFinal(usuario[posUsuario].librosComprados,libroLeido);
            
        }
        
        fread(&compraLeida,sizeof(Compra),1,archivoCompras);
    }

};

// PUNTO 4 - Desarrolle el procedimiento tieneLibro que recibe por parámetro la raíz de una lista de libros 
//  y un id de libro, y retorna true si ese libro se encuentra en la lista, false en caso contrario.


bool tieneLibro(NodoLibros *&raiz,int idLibro)
{
    NodoLibros *aux = raiz;
    
    while(aux)
    {   
        if(aux->info.idLibro == idLibro)
        {
            return true;
        }
        aux = aux->sgte;
    }

    return false;
}


int main()
{
    InfoUsuarios usuario[10000];


    return 0;
}