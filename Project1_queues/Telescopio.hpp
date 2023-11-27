#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
using namespace std;

// Creamos la estructura para los nodos
typedef struct nodoC
{
    string nombre;
    string tipo;
    int masa;
    int distancia;

    struct nodoC *sig;
} *cuerpoCeleste;

// Aqui declaramos las estructuras de las colas que vamos a utilizar
typedef struct Cola
{
    struct nodoC *primero;
    struct nodoC *ultimo;
} *pNodo;

// Creamos una funcion para crear cada una de las colas

pNodo CreateQueue()
{
    pNodo coA;
    coA = new struct Cola;

    coA->primero = new struct nodoC;
    coA->ultimo = new struct nodoC;

    coA->primero->sig = NULL;
    coA->ultimo = NULL;

    return (coA);
}

// Creamos funciones para comprobar si cada una de las colas esta vacia o no
bool EmptyQueue(pNodo cola)
{
    if (cola->ultimo == NULL)
        return (true);
    else
        return (false);
}

// Creamos una fucnion para introducir en cada cola los nodos con sus datos
void InQueue(pNodo cola, string nombre, string tipo, int masa, int distancia)
{
    struct nodoC *nodo_aux;

    nodo_aux = new struct nodoC;

    nodo_aux->nombre = nombre;
    nodo_aux->tipo = tipo;
    nodo_aux->masa = masa;
    nodo_aux->distancia = distancia;

    if (EmptyQueue(cola))
    {
        cola->primero->sig = nodo_aux;
        nodo_aux->sig = NULL;
        cola->ultimo = nodo_aux;
    }
    else
    {
        cola->ultimo->sig = nodo_aux;
        cola->ultimo = nodo_aux;
        cola->ultimo->sig = NULL;
    }
}

// Funcion que utilizaremos para ver los elementos de la cola
void ViewQueue(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;

    cout << "___________________________________" << endl;

    nodo_aux = cola->primero->sig;

    while (nodo_aux != NULL)
    {
        cout << "Nombre del cuerpo: " << nodo_aux->nombre << endl;
        cout << "Tipo de cuerpo: " << nodo_aux->tipo << endl;
        cout << "Masa del cuerpo(En referencia al sol de la via lactea): " << nodo_aux->masa << endl;
        cout << "Distancia del cuerpo(En anyos luz): " << nodo_aux->distancia << endl
             << endl;

        nodo_aux = nodo_aux->sig;
    }
}

// Esta funcione sirve para extraer el primer elemento de la cola
void elimCola(pNodo cola)
{
    cuerpoCeleste nodo;

    if (cola->primero->sig == NULL)
    {
        free(cola->primero);
        cola->primero = cola->ultimo = NULL;
    }
    else
    {
        nodo = cola->primero;
        cola->primero = nodo->sig;
        free(nodo);
    }
}

// Esta funcion sirve para mostrar el primer y ultimo elemento de la cola.

void FirstQueue(pNodo cola)
{
    if (EmptyQueue(cola))
    {
        cout << "La cola esta vacia " << endl;
    }
    else
    {
        struct nodoC *nodo_aux;
        nodo_aux = new struct nodoC;
        nodo_aux = cola->primero->sig;
        cout << "________________________" << endl;
        cout << "El primer elemento de la cola es: " << endl;
        cout << "Nombre del cuerpo: " << nodo_aux->nombre << endl;
        cout << "Tipo de cuerpo: " << nodo_aux->tipo << endl;
        cout << "Masa del cuerpo(En referencia al sol de la via lactea): " << nodo_aux->masa << endl;
        cout << "Distancia del cuerpo(En anyos luz): " << nodo_aux->distancia << endl
             << endl;
    }
}

void LastQueue(pNodo cola)
{
    if (EmptyQueue(cola))
    {
        cout << "La cola esta vacia " << endl;
    }
    else
    {
        struct nodoC *nodo_aux;
        nodo_aux = new struct nodoC;
        nodo_aux = cola->ultimo;
        cout << "________________________" << endl;
        cout << "El ultimo elemento de la cola es: " << endl;
        cout << "Nombre del cuerpo: " << nodo_aux->nombre << endl;
        cout << "Tipo de cuerpo: " << nodo_aux->tipo << endl;
        cout << "Masa del cuerpo(En referencia al sol de la via lactea): " << nodo_aux->masa << endl;
        cout << "Distancia del cuerpo(En anyos luz): " << nodo_aux->distancia << endl
             << endl;
    }
}

void imprimirEstadoColaAndromeda(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;

    nodo_aux = cola->primero->sig;

    cout << "Andromeda:      ";

    while (nodo_aux != NULL)
    {
        cout << nodo_aux->nombre << ", ";

        nodo_aux = nodo_aux->sig;
    }
    cout << endl;
}

void imprimirEstadoColaCentauro(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;

    nodo_aux = cola->primero->sig;

    cout << "Centauro:       ";

    while (nodo_aux != NULL)
    {
        cout << nodo_aux->nombre << ", ";

        nodo_aux = nodo_aux->sig;
    }
    cout << endl;
}

void imprimirEstadoColaViaLactea(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;

    nodo_aux = cola->primero->sig;

    cout << "Via Lactea:     ";

    while (nodo_aux != NULL)
    {
        cout << nodo_aux->nombre << ", ";

        nodo_aux = nodo_aux->sig;
    }
    cout << endl;
}

void imprimirEstadoColaLeo(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;

    nodo_aux = cola->primero->sig;

    cout << "Leo:            ";

    while (nodo_aux != NULL)
    {
        cout << nodo_aux->nombre << ", ";

        nodo_aux = nodo_aux->sig;
    }
    cout << endl;
}

void imprimirEventoAndromeda(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->ultimo;

    cout << "EVENTO:         ";

    cout << "LLegada " << nodo_aux->nombre << " cola Andromeda" << endl;
}

void imprimirEventoCentauro(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->ultimo;

    cout << "EVENTO:         ";

    cout << "Llegada " << nodo_aux->nombre << " cola Centauro" << endl;
}

void imprimirEventoViaLactea(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->ultimo;

    cout << "EVENTO:         ";

    cout << "Llegada " << nodo_aux->nombre << " cola Via Lactea" << endl;
}

void imprimirEventoLeo(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->ultimo;

    cout << "EVENTO:         ";

    cout << "Llegada " << nodo_aux->nombre << " cola Leo" << endl;
}

void errorProceso(pNodo cola)
{
    string nom_aux;
    string tip_aux;
    int mas_aux;
    int dist_aux;

    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;

    nodo_aux = cola->primero->sig;

    elimCola(cola);

    nom_aux = nodo_aux->nombre;
    tip_aux = nodo_aux->tipo;
    mas_aux = nodo_aux->masa;
    dist_aux = nodo_aux->distancia;

    InQueue(cola, nom_aux, tip_aux, mas_aux, dist_aux);
}

void imprimirProcesoOkAndromeda(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->primero->sig;
    cout << "EVENTO:         ";
    cout << "Procesamiento OK " << nodo_aux->nombre << " cola Andromeda" << endl;
}

void imprimirProcesoOkCentauro(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->primero->sig;
    cout << "EVENTO:         ";
    cout << "Procesamiento OK " << nodo_aux->nombre << " cola Centauro" << endl;
}

void imprimirProcesoOkViaLactea(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->primero->sig;
    cout << "EVENTO:         ";
    cout << "Procesamiento OK " << nodo_aux->nombre << " cola ViaLactea" << endl;
}

void imprimirProcesoOkLeo(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->primero->sig;
    cout << "EVENTO:         ";
    cout << "Procesamiento OK " << nodo_aux->nombre << " cola Leo" << endl;
}

void imprimirProcesoKoAndromeda(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->primero->sig;
    cout << "EVENTO:         ";
    cout << "Procesamiento KO " << nodo_aux->nombre << " cola Andromeda" << endl;
}

void imprimirProcesoKoCentauro(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->primero->sig;
    cout << "EVENTO:         ";
    cout << "Procesamiento KO " << nodo_aux->nombre << " cola Centauro" << endl;
}

void imprimirProcesoKoViaLactea(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->primero->sig;
    cout << "EVENTO:         ";
    cout << "Procesamiento KO " << nodo_aux->nombre << " cola Via Lactea" << endl;
}

void imprimirProcesoKoLeo(pNodo cola)
{
    struct nodoC *nodo_aux;
    nodo_aux = new struct nodoC;
    nodo_aux = cola->primero->sig;
    cout << "EVENTO:         ";
    cout << "Procesamiento KO " << nodo_aux->nombre << " cola Leo" << endl;
}

// Funcion para crear un numero aleatorio
string numeroAleatorio()
{

    int num = 0;
    stringstream ss;
    string numString;
    num = rand() % 1001;
    ss << num;
    numString = ss.str();

    return (numString);
}

// Fucnion para obtener un cuerpo aleatorio
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
