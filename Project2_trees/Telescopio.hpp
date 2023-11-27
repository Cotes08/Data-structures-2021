#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#define INF 1061109567
using namespace std;

typedef struct nodoA
{
    string nombre;
    string tipo;
    int masa;
    int distancia;
    int num;
    struct nodoA *izq, *der;
} *nodoarbol;

typedef struct Tree
{
    struct nodoA *raiz;
} *arbol;

arbol CrearArbol()
{

    arbol ar = new struct Tree;

    ar->raiz = new struct nodoA;

    ar->raiz->num = -1;
    ar->raiz->izq = ar->raiz->der = NULL;

    return (ar);
}

bool ArbolVacio(arbol ar)
{

    if (ar->raiz->num == -1)
        return (true);
    else
        return (false);
}

void InArbol(arbol ar, string nombre, string tipo, int masa, int distancia, int num)
{

    struct nodoA *nodo_padre, *nodo_aux;
    nodo_padre = new struct nodoA;
    nodo_aux = new struct nodoA;

    nodo_padre = NULL;
    nodo_aux = ar->raiz;

    if (ArbolVacio(ar))
    {
        nodo_aux->nombre = nombre;
        nodo_aux->tipo = tipo;
        nodo_aux->masa = masa;
        nodo_aux->distancia = distancia;
        nodo_aux->num = num;
        return;
    }

    while ((nodo_aux != NULL) && (nodo_aux->num != num))
    {
        nodo_padre = nodo_aux;
        if (num < nodo_aux->num)
        {
            nodo_aux = nodo_aux->izq;
        }
        else
        {
            nodo_aux = nodo_aux->der;
        }
    }

    if (nodo_aux != NULL)
    {
        // cout<<valor<< "NO SE PUEDE INTRODUCIR EL CUERPO PORQUE YA EXISTE"
        return;
    }

    // En el caso de que sea NULL significa que podemos introducir ese valor, pero primeor hacemos al comprobacion de si vamos a la derecha o a la izquierda
    // Una vez hecho eso se crea el nuevo nodo, se coloca donde toca y se establece sus hijos a NULL
    if (num < nodo_padre->num)
    {
        struct nodoA *nodo;
        nodo = new struct nodoA;

        nodo_padre->izq = nodo;
        nodo->nombre = nombre;
        nodo->tipo = tipo;
        nodo->masa = masa;
        nodo->distancia = distancia;
        nodo->num = num;
        nodo->izq = nodo->der = NULL;
    }
    else
    {
        struct nodoA *nodo;
        nodo = new struct nodoA;

        nodo_padre->der = nodo;
        nodo->nombre = nombre;
        nodo->tipo = tipo;
        nodo->masa = masa;
        nodo->distancia = distancia;
        nodo->num = num;
        nodo->izq = nodo->der = NULL;
    }
}

void PreOrdenArbol(nodoarbol nodo)
{
    cout << "Nombre del cuerpo: " << nodo->nombre << endl;
    cout << "Tipo de cuerpo: " << nodo->tipo << endl;
    cout << "Masa del cuerpo(En referencia al sol de la via lactea): " << nodo->masa << endl;
    cout << "Distancia del cuerpo(En anyos luz): " << nodo->distancia << endl
         << endl;
    if (nodo->izq != NULL)
        PreOrdenArbol(nodo->izq);
    if (nodo->der != NULL)
        PreOrdenArbol(nodo->der);
}

void PostOrdenArbol(nodoarbol nodo)
{

    if (nodo->izq != NULL)
        PostOrdenArbol(nodo->izq);
    if (nodo->der != NULL)
        PostOrdenArbol(nodo->der);
    cout << "Nombre del cuerpo: " << nodo->nombre << endl;
    cout << "Tipo de cuerpo: " << nodo->tipo << endl;
    cout << "Masa del cuerpo(En referencia al sol de la via lactea): " << nodo->masa << endl;
    cout << "Distancia del cuerpo(En anyos luz): " << nodo->distancia << endl
         << endl;
}

void InOrdenArbol(nodoarbol nodo)
{

    if (nodo->izq != NULL)
    {
        InOrdenArbol(nodo->izq);
    }
    cout << "Nombre del cuerpo: " << nodo->nombre << endl;
    cout << "Tipo de cuerpo: " << nodo->tipo << endl;
    cout << "Masa del cuerpo(En referencia al sol de la via lactea): " << nodo->masa << endl;
    cout << "Distancia del cuerpo(En anyos luz): " << nodo->distancia << endl
         << endl;
    if (nodo->der != NULL)
    {
        InOrdenArbol(nodo->der);
    }
}

void BusquedaValorArbol(nodoarbol nodo, int num, string nombre)
{
    bool fin = false;

    while (not(fin))
    {
        if (nodo == NULL)
        {
            fin = true;
            cout << endl
                 << endl;
            cout << "Cuerpo NO encontrado" << endl;
        }
        else
        {
            if (nodo->nombre == nombre)
            {
                fin = true;

                cout << "Cuerpo encontrado" << endl;
                cout << "El nombre del cuerpo es: " << nodo->nombre << endl;
                cout << "Tipo de cuerpo: " << nodo->tipo << endl;
                cout << "El peso del cuerpo es: " << nodo->masa << endl;
                cout << "La distancia del cuerpo en anyos luz es: " << nodo->distancia << endl;
            }
            else
            {
                if (nodo->num < num)
                {
                    nodo = nodo->der;
                }
                else
                {
                    nodo = nodo->izq;
                }
            }
        }
    }
}

bool Existecuerpo(nodoarbol nodo, int num, string nombre)
{
    bool fin = false;
    bool encontrado = false;

    while (not(fin))
    {
        if (nodo == NULL)
        {
            encontrado = false;
            fin = true;
        }
        else
        {
            if (nodo->nombre == nombre)
            {
                encontrado = true;
                fin = true;
            }
            else
            {
                if (nodo->num < num)
                {
                    nodo = nodo->der;
                }
                else
                {
                    nodo = nodo->izq;
                }
            }
        }
    }
    return (encontrado);
}

int EsHoja(nodoarbol nodo)
{
    return !nodo->der && !nodo->izq;
}

void Borrar(arbol ar, string nombre)
{
    struct nodoA *nodo_padre, *nodo_aux, *nodo;
    nodo_padre = new struct nodoA;
    nodo_aux = new struct nodoA;
    nodo = new struct nodoA;

    nodo_padre = NULL;
    nodo_aux = ar->raiz;
    string aux;

    while (nodo_aux != NULL)
    {
        if (nombre == nodo_aux->nombre)
        {
            if (EsHoja(nodo_aux))
            {
                if (nodo_padre)
                {
                    if (nodo_padre->der == nodo_aux)
                        nodo_padre->der = NULL;
                }
                else if (nodo_padre->izq == nodo_aux)
                    nodo_padre->izq = NULL;
                free(nodo_aux);
                nodo_aux = NULL;
                return;
            }
            else
            {
                nodo_padre = nodo_aux;
                if (nodo_aux->der)
                {
                    nodo = nodo_aux->der;
                    while (nodo->izq)
                    {
                        nodo_padre = nodo;
                        nodo = nodo->izq;
                    }
                }
                else
                {
                    nodo = nodo_aux->izq;
                    while (nodo->der)
                    {
                        nodo_padre = nodo;
                        nodo = nodo->der;
                    }
                }

                aux = nodo_aux->nombre;
                nodo_aux->nombre = nodo->nombre;
                nodo->nombre = aux;
                nodo_aux = nodo;
            }
        }
        else
        {
            nodo_padre = nodo_aux;
            if (nombre > nodo_aux->nombre)
                nodo_aux = nodo_aux->der;
            else if (nombre < nodo_aux->nombre)
                nodo_aux = nodo_aux->izq;
        }
    }
    cout << "El cuerpo NO ha sido borrado.";
}
void imprimir(nodoarbol nodo)
{
    if (nodo->izq != NULL)
    {
        imprimir(nodo->izq);
    }
    cout << nodo->nombre << " ";
    if (nodo->der != NULL)
    {
        imprimir(nodo->der);
    }
}

void imprimirEstadoArbolAndromeda(nodoarbol nodo)
{
    cout << "Andromeda:      ";
    imprimir(nodo);

    cout << endl;
}

void imprimirEstadoArbolCentauro(nodoarbol nodo)
{
    cout << "Centauro:       ";
    imprimir(nodo);

    cout << endl;
}

void imprimirEstadoArbolViaLactea(nodoarbol nodo)
{
    cout << "Via Lactea:     ";
    imprimir(nodo);

    cout << endl;
}

void imprimirEstadoArbolLeo(nodoarbol nodo)
{
    cout << "Leo:            ";
    imprimir(nodo);

    cout << endl;
}

void imprimirEventoAndromeda(arbol ar, string nombre, string tipo, int masa, int distancia, int num)
{

    InArbol(ar, nombre, tipo, masa, distancia, num);

    cout << "EVENTO:         ";

    cout << "Llegada " << nombre << " arbol Andromeda" << endl;
}

void imprimirEventoCentauro(arbol ar, string nombre, string tipo, int masa, int distancia, int num)
{

    InArbol(ar, nombre, tipo, masa, distancia, num);

    cout << "EVENTO:         ";

    cout << "Llegada " << nombre << " arbol Centauro" << endl;
}

void imprimirEventoViaLactea(arbol ar, string nombre, string tipo, int masa, int distancia, int num)
{

    InArbol(ar, nombre, tipo, masa, distancia, num);

    cout << "EVENTO:         ";

    cout << "Llegada " << nombre << " arbol Via Lactea" << endl;
}

void imprimirEventoLeo(arbol ar, string nombre, string tipo, int masa, int distancia, int num)
{

    InArbol(ar, nombre, tipo, masa, distancia, num);

    cout << "EVENTO:         ";

    cout << "Llegada " << nombre << " arbol Leo" << endl;
}

int AlturaArbol(nodoarbol nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }
    else
    {
        int izq = 1 + AlturaArbol(nodo->izq);
        int der = 1 + AlturaArbol(nodo->der);
        if (izq > der)
            return (izq);
        else
            return (der);
    }
}

void nodoAleatorio(nodoarbol nodo)
{

    int numAl = 0;
    int derOizq = 0;

    numAl = rand() % AlturaArbol(nodo) + 1;

    for (int i = 0; i <= numAl; i++)
    {
        derOizq = rand() % 2;
        if (derOizq == 0)
        {
            if (nodo->der != NULL)
            {
                nodo = nodo->der;
            }
            else if (nodo->izq != NULL)
            {
                nodo = nodo->izq;
            }
        }
        else if (derOizq == 1)
        {
            if (nodo->izq != NULL)
            {
                nodo = nodo->izq;
            }
            else if (nodo->der != NULL)
            {
                nodo = nodo->der;
            }
        }
    }
}

void imprimirProcesoAndromeda(arbol ar, nodoarbol nodo)
{
    nodoAleatorio(nodo);
    cout << "EVENTO:         ";
    cout << "Procesamiento del cuerpo " << nodo->nombre << " en el arbol Andromeda" << endl;
    Borrar(ar, nodo->nombre);
}

void imprimirProcesoCentauro(arbol ar, nodoarbol nodo)
{
    nodoAleatorio(nodo);
    cout << "EVENTO:         ";
    cout << "Procesamiento del cuerpo " << nodo->nombre << " en el arbol Centauro" << endl;
    Borrar(ar, nodo->nombre);
}

void imprimirProcesoViaLactea(arbol ar, nodoarbol nodo)
{
    nodoAleatorio(nodo);
    cout << "EVENTO:         ";
    cout << "Procesamiento del cuerpo " << nodo->nombre << " en el arbol Via Lactea" << endl;
    Borrar(ar, nodo->nombre);
}

void imprimirProcesoLeo(arbol ar, nodoarbol nodo)
{
    nodoAleatorio(nodo);
    cout << "EVENTO:         ";
    cout << "Procesamiento del cuerpo " << nodo->nombre << " en el arbol Leo" << endl;
    Borrar(ar, nodo->nombre);
}

// Funcion para crear un numero aleatorio
int numeroAleatorio()
{
    int num = 0;
    num = rand() % 1001;
    return (num);
}

// Funcion para obtener un cuerpo aleatorio
string obtenerCuerpo()
{
    int tipo = 0;
    string cuerpo;

    tipo = rand() % 3;

    if (tipo == 0)
    {
        cuerpo = "S";
    }
    else if (tipo == 1)
    {
        cuerpo = "P";
    }
    else if (tipo == 2)
    {
        cuerpo = "M";
    }

    return (cuerpo);
}

string obtenerGalaxia()
{
    int n = 0;
    string galaxia;

    n = rand() % 4;

    if (n == 0)
    {
        galaxia = "AN";
    }
    else if (n == 1)
    {
        galaxia = "CE";
    }
    else if (n == 2)
    {
        galaxia = "VL";
    }
    else if (n == 3)
    {
        galaxia = "LE";
    }

    return (galaxia);
}
// Funcion para obtener la masa de forma aleatoria
int obtenerMasa()
{
    int masa = 0;

    masa = rand() % 21;

    return (masa);
}
// Funcion para obtener la distancia de forma aleatoria
int obtenerDistancia()
{
    int distancia = 0;

    distancia = rand() % 1001;

    return (distancia);
}

string IntaString(int numero)
{
    stringstream ss;
    string numString;
    ss << numero;
    numString = ss.str();

    return (numString);
}

/////////////////////////////////////////////////////////////////
// grafos
////////////////////////////////////////////////////////////////

void FloyW(int **valores, int n, int **ruta)
{

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((valores[k][j] == 0) && (k != j))
                {
                    valores[k][j] = 10000;
                }
                int dt = valores[i][k] + valores[k][j];
                if (valores[i][j] > dt)
                {
                    valores[i][j] = dt;
                    ruta[i][j] = k;
                }
            }
        }
    }
}
