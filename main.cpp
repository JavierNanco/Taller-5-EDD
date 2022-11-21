#include "arbolBinario.h"

void agregarAlDiccionario(string);
void mostrarPalabraPorLetra();
void eliminarPalabra(string);
void buscarFrecuencia(string);
void imprimirRepetida();
string mayusculaAMinuscula(string);
void inicializarDic();

struct estructuraDiccionario
{
    string letra;
    ABB arbolBinarioDeBusqueda;
    int cantidad=0;
} dic[28];

static string letrasDelDiccionario[28] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","ñ","o","p","q","r","s","t","u","v","w","x","y","z"};

int main()
{
    string palabraIngresadaPorTeclado;
    char aux;
    int inicio=1;
    
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
                if(inicio==1)
                {
                    cout << endl << "inicializando..." << endl;
                    inicializarDic();
                    inicio=0;
                }
                else if(inicio==0)
                {
                    cout << endl << "YA INICIALIZO" << endl;
                }
    	    break;
    	
    	    case 2:
                if(inicio==0)
                {
                    cout << "\n\tingresa la palabra   :";
                    cin >> palabraIngresadaPorTeclado;
                    agregarAlDiccionario(mayusculaAMinuscula(palabraIngresadaPorTeclado));
                }
                if(inicio==1)
                {
                    cout << endl << "SE DEBE INICIALIZAR" << endl;
                }
    	    break;
    	
    	    case 3:
                if(inicio==0)
                {
                    cout << "\n\tingresa la palabra   :";
                    cin >> palabraIngresadaPorTeclado;
                    eliminarPalabra(mayusculaAMinuscula(palabraIngresadaPorTeclado));
                }
                if(inicio==1)
                {
                    cout << endl << "SE DEBE INICIALIZAR" << endl;
                }
    	    break;
    	
    	    case 4:
                if(inicio==0)
                {
                    mostrarPalabraPorLetra();
                }
                if(inicio==1)
                {
                    cout << endl << "SE DEBE INICIALIZAR" << endl;
                }
    	    break;
    	    
    	    case 5:
                if(inicio==0)
                {
                    cout << "\n\tingresa la palabra   :";
                    cin >> palabraIngresadaPorTeclado;
                    buscarFrecuencia(mayusculaAMinuscula(palabraIngresadaPorTeclado));
                }
                if(inicio==1)
                {
                    cout << endl << "SE DEBE INICIALIZAR" << endl;
                }
    	    break;
    	    
    	    case 6:
                if(inicio==0)
                {
                    imprimirRepetida();
                }
                if(inicio==1)
                {
                    cout << endl << "SE DEBE INICIALIZAR" << endl;
                }
    	    break;
    
    	    case 7:

    	        exit(-1);
    	    default:
    	        cout << "\t\t[Error] opción inválida"<<endl;
		}
	}
    return 0;
}

void inicializarDic()
{
    for(int i=0;i<27;i++)
    {
        dic[i].letra="0";
        inicializar(dic[i].arbolBinarioDeBusqueda);
        dic[i].cantidad=0;
    }
    
}

void agregarAlDiccionario(string palabras)
{
    char a = palabras[0];
    string c;
    c=a;
    for(int i=0;i<27;i++)
    {
        if(c==letrasDelDiccionario[i])
        {
            dic[i].letra=c;
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
        cout<<endl<<"palabras:  ";
        enOrden(dic[i].arbolBinarioDeBusqueda);    
        cout<<endl<<"cantidad de palabras con esa letra:    "<<dic[i].cantidad;
    }
}

void eliminarPalabra(string palabras)
{
    char a=palabras[0];
    string c;
    c=a;
    
    for(int i=0;i<27;i++)
    {
       if(c==letrasDelDiccionario[i])
        {
            eliminarABB(dic[i].arbolBinarioDeBusqueda, palabras);
            dic[i].cantidad--;
        }
    }
    
}

void buscarFrecuencia(string palabras)
{
    char a=palabras.front();
    string c;
    c=a;
    //vector<string> letras(palabras.begin(), palabras.end());
    for(int i=0;i<27;i++)
    {
        if(c==letrasDelDiccionario[i])
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
