#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "Telescopio.hpp"

int main()
{
    srand(time(NULL));
    char opcion;
    string galaxia;
    string nombre;
    string cuerpo;
    string orden;
    string nombusq;
    int numbusq;
    int num;
    int masa;
    int distancia;
    int n = 0;

    // Grafos
    char estrellas[30], *pre;
    int v, np, j, N;
    N = 0;
    j = 0;
    int **valores;
    int **ruta;
    int const c = 1023;
    char **estr;
    int o = 0;
    int dir = 0;
    char *origen;
    origen = new char;

    arbol arbol1;
    arbol1 = CrearArbol();

    arbol arbol2;
    arbol2 = CrearArbol();

    arbol arbol3;
    arbol3 = CrearArbol();

    arbol arbol4;
    arbol4 = CrearArbol();

    do
    {
        cout << "Menu del programa de deteccion de cuerpos celestes" << endl
             << endl;
        cout << "A. Introducir manualmente un cuerpo en cualquier ABB: AN,CE,VL,LE" << endl;
        cout << "B. Buscar cualquier cuerpo celeste en el ABB que se indique y mostrar sus datos." << endl;
        cout << "C. Imprimir los cuerpos de la cola que se indique: AN,CE,VL,LE.Imprimir los cuerpos de cualquier ABB recorridos de cualquier forma: anchura, profundidad (PRE, IN, POST ORDEN)." << endl;
        cout << "D. Borrar un cuerpo celeste, introducido por teclado, si existe en el correspondiente ABB." << endl;
        cout << "E. Introducir un numero y crear dicha cantidad de cuerpos celestes de cualquier galaxia, que se generaran al azar y se guardaran en el correspondiente ABB." << endl;
        cout << "F. Introducir un numero y generar al azar dicha cantidad de cuerpos de cualquier galaxia y borrarlos, si existen, de los correspondientes ABB." << endl;
        cout << "G. Iniciar la simulacion." << endl;
        cout << "H. Determinar si existe un camino minimo entre un par de estrellas introducidas por el usuario y mostrar sus etapas, conforme a la tabla que aparece abajo." << endl;
        cout << "I. Salir de la aplicacion." << endl;

        nombre.clear();

        // Obtener de forma aleatoria que tipo de cuerpo es

        do
        {
            cout << "Elija una opcion: ";
            cin >> opcion;
            cout << "" << endl;
        } while (opcion != 'A' && opcion != 'B' && opcion != 'C' && opcion != 'D' && opcion != 'E' && opcion != 'F' && opcion != 'G' && opcion != 'H' && opcion != 'I');

        switch (opcion)
        {
        case 'A':
            do
            {
                cout << "Introduce la galaxia donde desees colocar el cuerpo celeste (AN, CE, VL, LE): ";
                cin >> galaxia;
            } while (galaxia != "AN" && galaxia != "CE" && galaxia != "VL" && galaxia != "LE");

            if (galaxia == "AN")
            {
                do
                {
                    cout << "De que tipo es(S, P, M): ";
                    cin >> cuerpo;
                    cout << endl;
                } while (cuerpo != "S" && cuerpo != "P" && cuerpo != "M");
                do
                {
                    cout << "Introduce su masa(0...20): ";
                    cin >> masa;
                    cout << endl;
                } while (masa <= -1 || masa >= 21);
                do
                {
                    cout << "Introduce su distancia(0...1000): ";
                    cin >> distancia;
                    cout << endl;
                } while (distancia <= -1 || distancia >= 1001);
                num = numeroAleatorio();
                nombre += galaxia;
                nombre += IntaString(num);
                nombre += cuerpo;

                InArbol(arbol1, nombre, cuerpo, masa, distancia, num);
            }
            else if (galaxia == "CE")
            {

                do
                {
                    cout << "De que tipo es(S, P, M): ";
                    cin >> cuerpo;
                    cout << endl;
                } while (cuerpo != "S" && cuerpo != "P" && cuerpo != "M");
                do
                {
                    cout << "Introduce su masa(0...20): ";
                    cin >> masa;
                    cout << endl;
                } while (masa <= -1 || masa >= 21);
                do
                {
                    cout << "Introduce su distancia(0...1000): ";
                    cin >> distancia;
                    cout << endl;
                } while (distancia <= -1 || distancia >= 1001);
                num = numeroAleatorio();
                nombre += galaxia;
                nombre += IntaString(num);
                nombre += cuerpo;

                InArbol(arbol2, nombre, cuerpo, masa, distancia, num);
            }
            else if (galaxia == "VL")
            {
                do
                {
                    cout << "De que tipo es(S, P, M): ";
                    cin >> cuerpo;
                    cout << endl;
                } while (cuerpo != "S" && cuerpo != "P" && cuerpo != "M");
                do
                {
                    cout << "Introduce su masa(0...20): ";
                    cin >> masa;
                    cout << endl;
                } while (masa <= -1 || masa >= 21);
                do
                {
                    cout << "Introduce su distancia(0...1000): ";
                    cin >> distancia;
                    cout << endl;
                } while (distancia <= -1 || distancia >= 1001);
                num = numeroAleatorio();
                nombre += galaxia;
                nombre += IntaString(num);
                nombre += cuerpo;

                InArbol(arbol3, nombre, cuerpo, masa, distancia, num);
            }
            else if (galaxia == "LE")
            {
                do
                {
                    cout << "De que tipo es(S, P, M): ";
                    cin >> cuerpo;
                    cout << endl;
                } while (cuerpo != "S" && cuerpo != "P" && cuerpo != "M");
                do
                {
                    cout << "Introduce su masa(0...20): ";
                    cin >> masa;
                    cout << endl;
                } while (masa <= -1 || masa >= 21);
                do
                {
                    cout << "Introduce su distancia(0...1000): ";
                    cin >> distancia;
                    cout << endl;
                } while (distancia <= -1 || distancia >= 1001);
                num = numeroAleatorio();
                nombre += galaxia;
                nombre += IntaString(num);
                nombre += cuerpo;

                InArbol(arbol4, nombre, cuerpo, masa, distancia, num);
            }

            break;
        case 'B':
            do
            {
                cout << "Elige el arbol donde desees buscar (AN,CE,VL,LE): ";
                cin >> galaxia;
            } while (galaxia != "AN" && galaxia != "CE" && galaxia != "VL" && galaxia != "LE");

            cout << "Introduce el numero del cuerpo que desees buscar: (0..999): ";
            cin >> numbusq;
            if (galaxia == "AN")
            {
                cout << "Introduce el nombre del cuerpo que desees buscar: (AN..LE 0..999 P..M): ";
                cin >> nombusq;
                BusquedaValorArbol(arbol1->raiz, numbusq, nombusq);
                cout << endl
                     << endl;
            }
            else if (galaxia == "CE")
            {
                cout << "Introduce el nombre del cuerpo que desees buscar: (AN..LE, 0..999, P..M): ";
                cin >> nombusq;
                BusquedaValorArbol(arbol2->raiz, numbusq, nombusq);
                cout << endl
                     << endl;
            }
            else if (galaxia == "VL")
            {
                cout << "Introduce el nombre del cuerpo que desees buscar: (AN..LE, 0..999, P..M): ";
                cin >> nombusq;
                BusquedaValorArbol(arbol3->raiz, numbusq, nombusq);
                cout << endl
                     << endl;
            }
            else if (galaxia == "LE")
            {
                cout << "Introduce el nombre del cuerpo que desees buscar: (AN..LE, 0..999, P..M): ";
                cin >> nombusq;
                BusquedaValorArbol(arbol4->raiz, numbusq, nombusq);
                cout << endl
                     << endl;
            }
            break;

        case 'C':
            do
            {
                cout << "Introduce la galaxia de la que deeses imprimir los cuerpos (AN, CE, VL, LE): ";
                cin >> galaxia;
            } while (galaxia != "AN" && galaxia != "CE" && galaxia != "VL" && galaxia != "LE");
            do
            {
                cout << endl
                     << "Elige la forma de impresion PRE, IN, POST ORDEN(PRE, IN, POST): ";
                cin >> orden;
            } while (orden != "PRE" && orden != "IN" && orden != "POST");

            if (galaxia == "AN")
            {
                if (orden == "PRE")
                    PreOrdenArbol(arbol1->raiz);
                else if (orden == "IN")
                    InOrdenArbol(arbol1->raiz);
                else if (orden == "POST")
                    PostOrdenArbol(arbol1->raiz);
                cout << endl
                     << endl;
            }
            else if (galaxia == "CE")
            {
                if (orden == "PRE")
                    PreOrdenArbol(arbol2->raiz);
                else if (orden == "IN")
                    InOrdenArbol(arbol2->raiz);
                else if (orden == "POST")
                    PostOrdenArbol(arbol2->raiz);
                cout << endl
                     << endl;
            }
            else if (galaxia == "VL")
            {
                if (orden == "PRE")
                    PreOrdenArbol(arbol3->raiz);
                else if (orden == "IN")
                    InOrdenArbol(arbol3->raiz);
                else if (orden == "POST")
                    PostOrdenArbol(arbol3->raiz);
                cout << endl
                     << endl;
            }
            else if (galaxia == "LE")
            {
                if (orden == "PRE")
                    PreOrdenArbol(arbol4->raiz);
                else if (orden == "IN")
                    InOrdenArbol(arbol4->raiz);
                else if (orden == "POST")
                    PostOrdenArbol(arbol4->raiz);
                cout << endl
                     << endl;
            }

            break;

        case 'D':

            do
            {
                cout << "Elige el arbol donde desees buscar (AN,CE,VL,LE): ";
                cin >> galaxia;
            } while (galaxia != "AN" && galaxia != "CE" && galaxia != "VL" && galaxia != "LE");
            /*
                cout<<"Introduce el numero del cuerpo que desees buscar: (0..999): ";
                cin>>numbusq;
                */
            if (galaxia == "AN")
            {
                cout << "Introduce el nombre del cuerpo que desees buscar: (AN..LE 0..999 P..M): ";
                cin >> nombusq;
                Borrar(arbol1, nombusq);
                cout << endl
                     << endl;
            }
            else if (galaxia == "CE")
            {
                cout << "Introduce el nombre del cuerpo que desees buscar: (AN..LE, 0..999, P..M): ";
                cin >> nombusq;

                Borrar(arbol2, nombusq);
                cout << endl
                     << endl;
            }
            else if (galaxia == "VL")
            {
                cout << "Introduce el nombre del cuerpo que desees buscar: (AN..LE, 0..999, P..M): ";
                cin >> nombusq;

                Borrar(arbol3, nombusq);
                cout << endl
                     << endl;
            }
            else if (galaxia == "LE")
            {
                cout << "Introduce el nombre del cuerpo que desees buscar: (AN..LE, 0..999, P..M): ";
                cin >> nombusq;

                Borrar(arbol4, nombusq);
                cout << endl
                     << endl;
            }

            break;

            break;
        case 'E':
            cout << "Indique el numero de cuantos cuerpos desea generar al azar: ";
            cin >> n;
            cout << endl;

            for (int i = 1; i <= n; i++)
            {

                galaxia = obtenerGalaxia();

                if (galaxia == "AN")
                {
                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    InArbol(arbol1, nombre, cuerpo, masa, distancia, num);
                }

                else if (galaxia == "CE")
                {
                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    InArbol(arbol2, nombre, cuerpo, masa, distancia, num);
                }
                else if (galaxia == "VL")
                {

                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    InArbol(arbol3, nombre, cuerpo, masa, distancia, num);
                }
                else if (galaxia == "LE")
                {

                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    InArbol(arbol4, nombre, cuerpo, masa, distancia, num);
                }
                nombre.clear();
            }

            break;

        case 'F':
            cout << "Indique el numero de cuantos cuerpos desea generar al azar y si existe borrarlo: ";
            cin >> n;
            cout << endl;

            for (int i = 1; i <= n; i++)
            {

                galaxia = obtenerGalaxia();

                if (galaxia == "AN")
                {
                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    if (Existecuerpo(arbol1->raiz, num, nombre))
                        Borrar(arbol1, nombre);
                    else
                        InArbol(arbol1, nombre, cuerpo, masa, distancia, num);
                }

                else if (galaxia == "CE")
                {
                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    if (Existecuerpo(arbol2->raiz, num, nombre))
                        Borrar(arbol2, nombre);
                    else
                        InArbol(arbol2, nombre, cuerpo, masa, distancia, num);
                }
                else if (galaxia == "VL")
                {

                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    if (Existecuerpo(arbol3->raiz, num, nombre))
                        Borrar(arbol3, nombre);
                    else
                        InArbol(arbol3, nombre, cuerpo, masa, distancia, num);
                }
                else if (galaxia == "LE")
                {

                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    if (Existecuerpo(arbol4->raiz, num, nombre))
                        Borrar(arbol4, nombre);
                    else
                        InArbol(arbol4, nombre, cuerpo, masa, distancia, num);
                }
                nombre.clear();
            }

            break;

        case 'G':
            cout << "INICIANDO SIMUALCION: " << endl;

            cout << "Estado actual : " << endl;
            imprimirEstadoArbolAndromeda(arbol1->raiz);
            imprimirEstadoArbolCentauro(arbol2->raiz);
            imprimirEstadoArbolViaLactea(arbol3->raiz);
            imprimirEstadoArbolLeo(arbol4->raiz);
            for (int i = 0; i <= 5; i++)
            {

                Sleep(5000);

                cout << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                cout << "Cuerpo detectado: " << endl;

                galaxia = obtenerGalaxia();

                if (galaxia == "AN")
                {
                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    imprimirEventoAndromeda(arbol1, nombre, cuerpo, masa, distancia, num);
                    nombre.clear();
                }

                else if (galaxia == "CE")
                {
                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    imprimirEventoCentauro(arbol2, nombre, cuerpo, masa, distancia, num);
                    nombre.clear();
                }
                else if (galaxia == "VL")
                {

                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    imprimirEventoViaLactea(arbol3, nombre, cuerpo, masa, distancia, num);
                    nombre.clear();
                }
                else if (galaxia == "LE")
                {

                    cuerpo = obtenerCuerpo();
                    masa = obtenerMasa();
                    distancia = obtenerDistancia();
                    num = numeroAleatorio();
                    nombre += galaxia;
                    nombre += IntaString(num);
                    nombre += cuerpo;

                    imprimirEventoLeo(arbol4, nombre, cuerpo, masa, distancia, num);
                    nombre.clear();
                }

                imprimirEstadoArbolAndromeda(arbol1->raiz);
                imprimirEstadoArbolCentauro(arbol2->raiz);
                imprimirEstadoArbolViaLactea(arbol3->raiz);
                imprimirEstadoArbolLeo(arbol4->raiz);
                cout << endl;
                cout << endl;

                cout << "Procesando cuerpos: " << endl;

                Sleep(5000);

                cout << "-------------------------------------------------------------" << endl;

                galaxia = obtenerGalaxia();

                if (galaxia == "AN")
                {
                    imprimirProcesoAndromeda(arbol1, arbol1->raiz);
                }
                else if (galaxia == "CE")
                {
                    imprimirProcesoCentauro(arbol2, arbol2->raiz);
                }
                else if (galaxia == "VL")
                {
                    imprimirProcesoViaLactea(arbol3, arbol3->raiz);
                }
                else if (galaxia == "LE")
                {
                    imprimirProcesoLeo(arbol4, arbol4->raiz);
                }
                imprimirEstadoArbolAndromeda(arbol1->raiz);
                imprimirEstadoArbolCentauro(arbol2->raiz);
                imprimirEstadoArbolViaLactea(arbol3->raiz);
                imprimirEstadoArbolLeo(arbol4->raiz);
                cout << endl;
                cout << endl;
            }

            break;

        case 'H':

            FILE *datos;
            datos = fopen("Estrellas.txt", "r");
            if (!datos)
            {
                cout << "No se ha encontrado el fichero indicado.\n";
                break;
            }
            fgets(estrellas, 30, datos);
            np = atoi(estrellas);
            N = np;
            estr = new char *[N];
            for (int i = 0; i < N; i++)
            {
                estr[i] = new char[c];
            }
            valores = new int *[N];

            for (int i = 0; i < N; i++)
            {
                valores[i] = new int[N];
            }

            for (int i = 0; i < N; i++)
            {
                fgets(estrellas, 30, datos);
                sscanf(estrellas, "%s", estr[i]);
            }

            for (int i = 0; i < N; i++)
            {
                fgets(estrellas, 50, datos);
                pre = strtok(estrellas, " ");
                j = 0;
                v = atoi(pre);
                valores[i][j] = v;
                for (j = 1; j < N; j++)
                {
                    pre = strtok(NULL, " ");
                    v = atoi(pre);
                    valores[i][j] = v;
                }
            }
            fclose(datos);
            ruta = new int *[N];

            for (int i = 0; i < N; i++)
            {
                ruta[i] = new int[N];
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    ruta[i][j] = 30;
                }
            }

            FloyW(valores, N, ruta);

            cout << "Estrellas disponibles: ";
            for (int i = 0; i < N; i++)
            {
                cout << estr[i] << " ";
            }
            cout << "\nIntroduce la estrella de origen: ";
            cin >> origen;
            for (int i = 0; i < N; i++)
            {
                if (strcmp(estr[i], origen) == 0)
                {
                    o = i;
                    break;
                }
            }
            cout << "Destino\t\tDistancia\t\t\tRuta\n-------\t\t------\t\t\t----";
            for (int i = 0; i < N; i++)
            {
                if (i != o)
                {
                    cout << endl
                         << estr[i] << "\t\t" << valores[o][i] << "\t\t\t" << estr[o] << "->";
                    dir = ruta[o][i];
                    if (ruta[o][i] == 30)
                    {
                        cout << estr[i];
                    }
                    else
                    {

                        for (int j = 0; j < N; j++)
                        {
                            cout << estr[dir] << "->";
                            dir = ruta[dir][i];
                            if (dir == 30)
                            {
                                break;
                            }
                        }
                        cout << estr[i];
                    }
                }
            }

            cout << endl
                 << endl;
            break;

        case 'I':
            break;
        }

    } while (opcion != 'I');
    return 0;
}
