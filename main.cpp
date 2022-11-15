#include "arbolBinario.h"

/*
AB q 
q = T 
T = null
delete q
*/
void agregarAlDiccionario(string);
void mostrarPalabraPorLetra();
void eliminarPalabra(string);
void buscarFrecuencia(string);
void imprimirRepetida();
string mayusculaAMinuscula(string);

struct estructuraDiccionario
{
    char letra;
    ABB arbolBinarioDeBusqueda;
    int cantidad=0;
} dic[27];

static string letrasDelDiccionario[27] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","ñ","o","p","q","r","s","t","u","v","w","x","y","z"};

int main()
{
    string palabraIngresadaPorTeclado;
    
    int seleccionMenu =0;
    while(true)
	{
		cout << "\n\n\t\t     -Menu-";
		
        cout << "\n\t\t----------------";
        
    	cout << "\n\t1.-Inicializar diccionario:";
    	
    	cout << "\n\t2.-Agregar una palabra en el diccionario:";
    	
   		cout << "\n\t3.-Eliminar una palabra contenida en el diccionario:";
   		
   		cout << "\n\t4.-Mostrar toda la información del diccionario:";
   		
   		cout << "\n\t5.-Buscar la información de una palabra:";
   		
   		cout << "\n\t6.-Mostrar todas las palabras repetidas:";
   		
    	cout << "\n\t7.-SALIR:";
    	
    	cout << "\n\tSeleccione una alternativa[1-7]:   ";
    	   
    	cin >> seleccionMenu;
    	cin.clear();
        cin.ignore();
    	
        switch(seleccionMenu)
        {
    	    case 1:
                cout << endl << "Por defecto se crea un diccionario vacio..." << endl;
    	    break;
    	
    	    case 2:
                cout << "\n\tingresa la palabra   :";
                cin >> palabraIngresadaPorTeclado;
                agregarAlDiccionario(mayusculaAMinuscula(palabraIngresadaPorTeclado));
    	    break;
    	
    	    case 3:
                cout << "\n\tingresa la palabra   :";
                cin >> palabraIngresadaPorTeclado;
                eliminarPalabra(mayusculaAMinuscula(palabraIngresadaPorTeclado));
    	    break;
    	
    	    case 4:
                mostrarPalabraPorLetra();
    	    break;
    	    
    	    case 5:
                cout << "\n\tingresa la palabra   :";
                cin >> palabraIngresadaPorTeclado;
                buscarFrecuencia(mayusculaAMinuscula(palabraIngresadaPorTeclado));
    	    break;
    	    
    	    case 6:
                imprimirRepetida();
    	    break;
    
    	    case 7:

    	        exit(-1);
    	    default:
    	        cout << "\t\t[Error] opción inválida"<<endl;
		}
	}
    return 0;
}

void agregarAlDiccionario(string palabras)
{
    //vector<string> letras(palabras.begin(), palabras.end());
    for(int i=0;i<27;i++)
    {
        if(palabras[0]==letrasDelDiccionario[i])
        {
            dic[i].letra=palabras[0];
            insertar(dic[i].arbolBinarioDeBusqueda, palabras);
            dic[i].cantidad++;
        }
    }
}

void mostrarPalabraPorLetra()
{
    for(int i=0;i<27;i++)
    {
        cout<<endl<<endl<<"letra:   "<<letrasDelDiccionario[i];
        cout<<endl<<"en orden:  ";
        enOrden(dic[i].arbolBinarioDeBusqueda);
        cout<<endl<<"cantidad de palabras con esa letra:    "<<dic[i].cantidad;
    }
}

void eliminarPalabra(string palabras)
{
    vector<char> letras(palabras.begin(), palabras.end());
    for(int i=0;i<27;i++)
    {
        if(letras[0]==letrasDelDiccionario[i])
        {
            eliminarABB(dic[i].arbolBinarioDeBusqueda, palabras);
            dic[i].cantidad--;
        }
    }    
}

void buscarFrecuencia(string palabras)
{
    vector<char> letras(palabras.begin(), palabras.end());
    for(int i=0;i<27;i++)
    {
        if(letras[0]==letrasDelDiccionario[i])
        {
            cout<<buscarPorPalabra(dic[i].arbolBinarioDeBusqueda, palabras);
        }
    } 
}

void imprimirRepetida()
{
    for(int i=0;i<27;i++)
    {
        imprimeRepetidas(dic[i].arbolBinarioDeBusqueda);
    }    
}

string mayusculaAMinuscula(string sl)
{
    transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
    
    return sl;
}