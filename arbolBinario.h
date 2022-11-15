#include <fstream>  //relacionada al manejo de archivos
#include <iostream> //utilizada para la entrada y salida de datos
#include <limits>   //relacionada a los límites de valores
#include <sstream>  //relacionada a string stream
#include <vector>   //relacionada al manejo de vectores dinámicos
#include <string>
#include <locale.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct nodo
{
    string palabra;
    int frecuencia = 1;
    struct nodo *izq, *der;
};

typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */

ABB crearNodo(string palabrasDelDiccionario)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->palabra = palabrasDelDiccionario;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, string palabrasDelDiccionario)
{
    if(arbol==NULL)
    {
        arbol = crearNodo(palabrasDelDiccionario);
    }
    else if(palabrasDelDiccionario < arbol->palabra)
    {
        insertar(arbol->izq, palabrasDelDiccionario);
    }
    else if(palabrasDelDiccionario > arbol->palabra)
    {
        insertar(arbol->der, palabrasDelDiccionario);
    }
    else if(palabrasDelDiccionario == arbol->palabra)
    {
        arbol->frecuencia++;
    }
}

void recorrido(ABB arbol)
{
    if(arbol!=NULL)
    {
        recorrido(arbol->izq);
        recorrido(arbol->der);
    }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->palabra << " ";
          cout << arbol->frecuencia<<" ";
          enOrden(arbol->der);
     }
}

void Mayor(ABB &S, ABB &p)
{
    if(S->der != NULL)
         return Mayor(S->der,p);
    else{
         p = S;
         S = S->izq;
    }
}

void eliminarABB(ABB &arbol, string palabraQueEntra)
{
    ABB q;
    if (arbol != NULL)
    {
        if (palabraQueEntra == arbol->palabra && arbol->frecuencia==1)
        {
            q = arbol;
            if(arbol->der == NULL)
            {
                arbol = arbol->izq;
            }
            else
            {
                if (arbol->izq == NULL)
                {
                    arbol = arbol->der;
                }
                else
                {
                 Mayor(arbol->izq, q);
                 arbol->palabra = q->palabra;
                }
                delete q;
            }
        }
        else if(palabraQueEntra == arbol->palabra && arbol->frecuencia>1)
        {
            arbol->frecuencia--;    
        }
        else
        {
            if (palabraQueEntra < arbol->palabra)
            {
                eliminarABB(arbol->izq,palabraQueEntra);
            }
            else
            {
                if (palabraQueEntra > arbol->palabra)
                {
                    eliminarABB(arbol->der,palabraQueEntra);
                }
            }
        }
    }
}

string buscarPorPalabra(ABB arbol, string palabraQueEntra)
{
    string aux="EXISTE Y ES";
    string contador="NO EXISTE";
    if(arbol!=NULL)
    {
        buscarPorPalabra(arbol->izq, palabraQueEntra);
        if(palabraQueEntra==arbol->palabra)
        {
            cout << endl << "\t\tla palabra " << arbol->palabra;
            cout << " se repite " << arbol->frecuencia << " veces" << endl;
            return aux;
        }
        buscarPorPalabra(arbol->der, palabraQueEntra);
    }
    return contador;
}

//contador de palabras repetidas
void imprimeRepetidas(ABB arbol)
{
    if(arbol!=NULL)
    {
        imprimeRepetidas(arbol->izq);
        if(arbol->frecuencia>1)        
        {
            cout << endl << "\t\tla palabra " << arbol->palabra;
            cout << " se repite " << arbol->frecuencia << " veces" << endl;
            
        }
        imprimeRepetidas(arbol->der);
    }        
}
