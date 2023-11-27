#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "Telescopio.hpp"

using namespace std;


int main()
{
    srand(time(NULL));
    char opcion;
    string galaxia;
    string nombre;
    string cuerpo;
    int masa;
    int distancia;
    int n=0;
    int prob_fallo=0;

    pNodo cola1;
    cola1 = CreateQueue();

    pNodo cola2;
    cola2 = CreateQueue();

    pNodo cola3;
    cola3 = CreateQueue();

    pNodo cola4;
    cola4 = CreateQueue();


    do
    {
        cout<<"Menu del programa de deteccion de cuerpos celestes"<<endl<<endl;
        cout<<"A. Introducir manualmente un cuerpo en cualquier cola: AN,CE,VL,LE"<<endl;
        cout<<"B. Extraer el primer cuerpo de la cola de galaxia que se indique: AN,CE,VL,LE"<<endl;
        cout<<"C. Imprimir los cuerpos de la cola que se indique: AN,CE,VL,LE."<<endl;
        cout<<"D. Consultar que cuerpos estan en la cabecera y al final de la cola que se indique: AN,CE,VL,LE."<<endl;
        cout<<"E. Introducir los datos de n cuerpos que se generaran al azar, y se guardaran en las correspondientes colas de las galaxias correspondientes."<<endl;
        cout<<"F. Iniciar la simulacion."<<endl;
        cout<<"G. Salir de la aplicacion."<<endl<<endl;


        nombre.clear();


        //Obtener de forma aleatoria que tipo de cuerpo es

        do
        {
            cout<<"Elija una opcion: ";
            cin >> opcion;
            cout<<""<<endl;
        } while (opcion !='A' && opcion !='B' && opcion !='C' && opcion !='D' && opcion !='E' && opcion !='F' && opcion !='G');

        switch(opcion)
        {
            case 'A':
                do
                {
                    cout<<"Introduce la galaxia donde desees colocar el cuerpo celeste (AN, CE, VL, LE): ";
                    cin >> galaxia;
                }while(galaxia != "AN" && galaxia != "CE" && galaxia != "VL" && galaxia != "LE");

                if(galaxia == "AN")
                {
                    do{
                        cout<<"De que tipo es(S, P, M): "; cin>>cuerpo; cout<<endl;
                    }while(cuerpo != "S" && cuerpo!= "P" && cuerpo != "M");
                    do{
                        cout<<"Introduce su masa(0...20): "; cin>>masa; cout<<endl;
                    }while(masa<=0 || masa>=20);
                    do{
                        cout<<"Introduce su distancia(0...1000): "; cin>>distancia; cout<<endl;
                    }while(distancia<=0 || distancia>=1000);
                    nombre+=galaxia;
                    nombre+=numeroAleatorio();
                    nombre+=cuerpo;

                    InQueue(cola1 ,nombre, cuerpo, masa, distancia);

                }
                else if(galaxia == "CE")
                {

                    do{
                        cout<<"De que tipo es(S, P, M): "; cin>>cuerpo; cout<<endl;
                    }while(cuerpo != "S" && cuerpo!= "P" && cuerpo != "M");
                    do{
                        cout<<"Introduce su masa(0...20): "; cin>>masa; cout<<endl;
                    }while(masa<=0 || masa>=20);
                    do{
                        cout<<"Introduce su distancia(0...1000): "; cin>>distancia; cout<<endl;
                    }while(distancia<=0 || distancia>=1000);
                    nombre+=galaxia;
                    nombre+=numeroAleatorio();
                    nombre+=cuerpo;

                    InQueue(cola2 ,nombre, cuerpo, masa, distancia);

                }
                else if(galaxia == "VL")
                {
                    do{
                        cout<<"De que tipo es(S, P, M): "; cin>>cuerpo; cout<<endl;
                    }while(cuerpo != "S" && cuerpo!= "P" && cuerpo != "M");
                    do{
                        cout<<"Introduce su masa(0...20): "; cin>>masa; cout<<endl;
                    }while(masa<=0 || masa>=20);
                    do{
                        cout<<"Introduce su distancia(0...1000): "; cin>>distancia; cout<<endl;
                    }while(distancia<=0 || distancia>=1000);
                    nombre+=galaxia;
                    nombre+=numeroAleatorio();
                    nombre+=cuerpo;

                    InQueue(cola3 ,nombre, cuerpo, masa, distancia);

                }
                else if(galaxia == "LE")
                {
                    do{
                        cout<<"De que tipo es(S, P, M): "; cin>>cuerpo; cout<<endl;
                    }while(cuerpo != "S" && cuerpo!= "P" && cuerpo != "M");
                    do{
                        cout<<"Introduce su masa(0...20): "; cin>>masa; cout<<endl;
                    }while(masa<=0 || masa>=20);
                    do{
                        cout<<"Introduce su distancia(0...1000): "; cin>>distancia; cout<<endl;
                    }while(distancia<=0 || distancia>=1000);
                    nombre+=galaxia;
                    nombre+=numeroAleatorio();
                    nombre+=cuerpo;

                    InQueue(cola4 ,nombre, cuerpo, masa, distancia);
                }


                break;
            case 'B':
                do
                {
                    cout<<"Elige la cola de la que desees extrare el primer cuerpo(AN,CE,VL,LE): ";
                    cin >> galaxia;
                }while(galaxia != "AN" && galaxia != "CE" && galaxia != "VL" && galaxia != "LE");

                if(galaxia == "AN")
                {
                    elimCola(cola1);
                }
                else if(galaxia == "CE")
                {
                    elimCola(cola2);
                }
                else if(galaxia == "VL")
                {
                    elimCola(cola3);
                }
                else if(galaxia == "LE")
                {
                    elimCola(cola4);
                }

                break;

            case 'C':

                do
                {
                    cout<<"Elige la cola de la que desees imprimir los cuerpos: (AN, CE, VL, LE): ";
                    cin >> galaxia;
                }while(galaxia != "AN" && galaxia != "CE" && galaxia != "VL" && galaxia != "LE");

                if(galaxia == "AN")
                {
                    ViewQueue(cola1);
                }
                else if(galaxia == "CE")
                {
                    ViewQueue(cola2);
                }
                else if(galaxia == "VL")
                {
                    ViewQueue(cola3);
                }
                else if(galaxia == "LE")
                {
                    ViewQueue(cola4);
                }

                break;

            case 'D':

                do
                {
                    cout<<"Elige la cola de la que desees imprimir el primer y el ultimo cuerpo: (AN, CE, VL, LE): ";
                    cin >> galaxia;
                }while(galaxia != "AN" && galaxia != "CE" && galaxia != "VL" && galaxia != "LE");

                if(galaxia == "AN")
                {
                    FirstQueue(cola1);
                    LastQueue(cola1);
                }
                else if(galaxia == "CE")
                {
                    FirstQueue(cola2);
                    LastQueue(cola2);
                }
                else if(galaxia == "VL")
                {
                    FirstQueue(cola3);
                    LastQueue(cola3);
                }
                else if(galaxia == "LE")
                {
                    FirstQueue(cola4);
                    LastQueue(cola4);
                }

                break;

            case 'E':

                cout<<"Indique el numero de cuantos cuerpos desea generar al azar: ";cin>>n; cout<<endl;

                for(int i=1; i<=n;i++)
                {
                    galaxia=obtenerGalaxia();

                    if(galaxia == "AN")
                    {
                        cuerpo = obtenerCuerpo();
                        masa = obtenerMasa();
                        distancia = obtenerDistancia();
                        nombre+=galaxia;
                        nombre+=numeroAleatorio();
                        nombre+=cuerpo;

                        InQueue(cola1 ,nombre, cuerpo, masa, distancia);
                        nombre.clear();
                    }
                    else if(galaxia == "CE")
                    {
                        cuerpo = obtenerCuerpo();
                        masa = obtenerMasa();
                        distancia = obtenerDistancia();
                        nombre+=galaxia;
                        nombre+=numeroAleatorio();
                        nombre+=cuerpo;

                        InQueue(cola2 ,nombre, cuerpo, masa, distancia);
                        nombre.clear();
                    }
                    else if(galaxia == "VL")
                    {
                        cuerpo = obtenerCuerpo();
                        masa = obtenerMasa();
                        distancia = obtenerDistancia();
                        nombre+=galaxia;
                        nombre+=numeroAleatorio();
                        nombre+=cuerpo;

                        InQueue(cola3 ,nombre, cuerpo, masa, distancia);
                        nombre.clear();

                    }
                    else if(galaxia == "LE")
                    {
                        cuerpo = obtenerCuerpo();
                        masa = obtenerMasa();
                        distancia = obtenerDistancia();
                        nombre+=galaxia;
                        nombre+=numeroAleatorio();
                        nombre+=cuerpo;

                        InQueue(cola4 ,nombre, cuerpo, masa, distancia);
                        nombre.clear();

                    }
                }
                break;

            case 'F':

                cout<<"INICIANDO SIMUALCION: "<<endl;

                    cout<<"Estado actual : "<<endl;
                    imprimirEstadoColaAndromeda(cola1);
                    imprimirEstadoColaCentauro(cola2);
                    imprimirEstadoColaViaLactea(cola3);
                    imprimirEstadoColaLeo(cola4);

                for(int i=0; i<=5; i++)
                {


                    Sleep(5000);

                    cout<<endl;
                    cout<<"-----------------------------------------------------------------------"<<endl;
                    cout<<"Cuerpo detectado: "<<endl;

                    galaxia=obtenerGalaxia();

                    if(galaxia == "AN")
                    {
                        cuerpo = obtenerCuerpo();
                        masa = obtenerMasa();
                        distancia = obtenerDistancia();
                        nombre+=galaxia;
                        nombre+=numeroAleatorio();
                        nombre+=cuerpo;

                        InQueue(cola1 ,nombre, cuerpo, masa, distancia);
                        nombre.clear();
                        imprimirEventoAndromeda(cola1);
                    }
                    else if(galaxia == "CE")
                    {
                        cuerpo = obtenerCuerpo();
                        masa = obtenerMasa();
                        distancia = obtenerDistancia();
                        nombre+=galaxia;
                        nombre+=numeroAleatorio();
                        nombre+=cuerpo;

                        InQueue(cola2 ,nombre, cuerpo, masa, distancia);
                        nombre.clear();
                        imprimirEventoCentauro(cola2);
                    }
                    else if(galaxia == "VL")
                    {
                        cuerpo = obtenerCuerpo();
                        masa = obtenerMasa();
                        distancia = obtenerDistancia();
                        nombre+=galaxia;
                        nombre+=numeroAleatorio();
                        nombre+=cuerpo;

                        InQueue(cola3 ,nombre, cuerpo, masa, distancia);
                        nombre.clear();
                        imprimirEventoViaLactea(cola3);
                    }
                    else if(galaxia == "LE")
                    {
                        cuerpo = obtenerCuerpo();
                        masa = obtenerMasa();
                        distancia = obtenerDistancia();
                        nombre+=galaxia;
                        nombre+=numeroAleatorio();
                        nombre+=cuerpo;

                        InQueue(cola4 ,nombre, cuerpo, masa, distancia);
                        nombre.clear();
                        imprimirEventoLeo(cola4);
                    }

                        imprimirEstadoColaAndromeda(cola1);
                        imprimirEstadoColaCentauro(cola2);
                        imprimirEstadoColaViaLactea(cola3);
                        imprimirEstadoColaLeo(cola4);
                        cout<<endl;
                        cout<<endl;


                    cout<<"Procesando cuerpos: "<<endl;

                    Sleep(5000);

                    cout<<"-------------------------------------------------------------"<<endl;

                    galaxia=obtenerGalaxia();
                    prob_fallo = rand() % 10;

                    if(galaxia == "AN")
                    {
                        if(prob_fallo<=3)
                        {
                            imprimirProcesoKoAndromeda(cola1);
                            errorProceso(cola1);

                        }
                        else
                        {
                            imprimirProcesoOkAndromeda(cola1);
                            elimCola(cola1);
                        }

                    }
                    else if(galaxia == "CE")
                    {
                    if(prob_fallo<=3)
                        {
                            imprimirProcesoKoCentauro(cola2);
                            errorProceso(cola2);
                        }
                        else
                        {
                            imprimirProcesoOkCentauro(cola2);
                            elimCola(cola2);
                        }


                    }
                    else if(galaxia == "VL")
                    {
                    if(prob_fallo<=3)
                        {
                            imprimirProcesoKoViaLactea(cola3);
                            errorProceso(cola3);
                        }
                        else
                        {
                            imprimirProcesoOkViaLactea(cola3);
                            elimCola(cola3);
                        }
                    }
                    else if(galaxia == "LE")
                    {

                    if(prob_fallo<=3)
                        {
                            imprimirProcesoKoLeo(cola4);
                            errorProceso(cola4);
                        }
                        else
                        {
                            imprimirProcesoOkLeo(cola4);
                            elimCola(cola4);
                        }

                    }
                    imprimirEstadoColaAndromeda(cola1);
                    imprimirEstadoColaCentauro(cola2);
                    imprimirEstadoColaViaLactea(cola3);
                    imprimirEstadoColaLeo(cola4);
                    cout<<endl;
                    cout<<endl;
                }
            break;
            case 'G':
                break;
        }

    }while(opcion != 'G');
    return 0;
}
