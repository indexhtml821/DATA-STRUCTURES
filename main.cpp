#include "Ordenador.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

#define TIMING

#ifdef TIMING
#define INIT_TIMER auto start = std::chrono::high_resolution_clock::now();
#define START_TIMER start = std::chrono::high_resolution_clock::now();
#define STOP_TIMER(name) std::cout << "RUNTIME of " << name << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << " ms " << std::endl;
#else
#define INIT_TIMER
#define START_TIMER
#define STOP_TIMER(name)
#endif

void llenarArreglo(int *A, int n);

int main()
{
    Ordenador *ordenar = new Ordenador();
    int tam = 50000;
    int tam1 = 100000;
    int tam2 = 150000;
    int tam3 = 200000;
    INIT_TIMER;
    /*
        // ORDENAMIENTO POR SELECCIÓN

        cout << INT16_MAX << endl;

        int array[tam];
        int *dir;
        dir = array;
        llenarArreglo(dir, tam);

        START_TIMER;
        ordenar->seleccion(dir, tam);
        STOP_TIMER("array tam")


        int array1[tam1];
        int *dir1;
        dir1 = array1;
        llenarArreglo(dir1, tam1);
        START_TIMER;
        ordenar->seleccion(dir1, tam1);
        STOP_TIMER("array tam1")


        int array2[tam2];
        int *dir2;
        dir2 = array2;
        llenarArreglo(dir2, tam2);
        START_TIMER;
        ordenar->seleccion(dir2, tam2);
        STOP_TIMER("array tam2")

        int array3[tam3];
        int *dir3;
        dir3 = array3;
        llenarArreglo(dir3, tam3);
        START_TIMER;
        ordenar->seleccion(dir3, tam3);
        STOP_TIMER("array tam3")
    */

    // ORDENAMIENTO INSERCIÓN;
    cout << "___________________________________" << endl;
    cout << endl;
    cout << "Ordenamiento por insercion" << endl;
    int array4[tam];
    int *dir4;
    dir4 = array4;
    llenarArreglo(dir4, tam);
    START_TIMER;
    ordenar->insercion(dir4, tam);
    STOP_TIMER("array tam")

    int array5[tam1];
    int *dir5;
    dir5 = array5;
    llenarArreglo(dir5, tam1);
    START_TIMER;
    ordenar->seleccion(dir5, tam1);
    STOP_TIMER("array tam1")

    int array6[tam2];
    int *dir6;
    dir6 = array6;
    llenarArreglo(dir6, tam2);
    START_TIMER;
    ordenar->seleccion(dir6, tam2);
    STOP_TIMER("array tam2")

    int array7[tam3];
    int *dir7;
    dir7 = array7;
    llenarArreglo(dir7, tam3);
    START_TIMER;
    ordenar->seleccion(dir7, tam3);
    STOP_TIMER("array tam3")
}

void llenarArreglo(int *A, int n)
{

    for (int i = 0; i < n; i++)
    {
        // int num = rand()/(64000/(32000-30000));
        int num = rand() % 50;
        *A = num;
        *(A++);
    }
}