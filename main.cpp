#include "llist.h"
#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

void llenarlista(llnode<int> *A, int n);
void revisarArreglo(int *A, int n);
int diversidad(int *A, int n);
llnode<int> *crearNodo(int k);

int main()
{

    llnode<int> *amor = new llnode<int>(2);
    llist<int> lista;

    for (int i = 0; i < 5; i++)
    {
        lista.Insert(crearNodo(i));
    }

    lista.Insert(amor);
    cout << lista.Search(2)->key << endl;
    lista.Delete(amor);
    cout << lista.Search(2)->key << endl;

    lista.Insert(amor);
    // llenarlista(*amor,10);
}

void llenarlista(llnode<int> *A, int n)
{

    for (int i = 0; i < n; i++)
    {
        int num = 2; // rand() / 10;/// (124000 / (32000 - 30000));
        A->key = num;
        *(A + i);
    }
}

void revisarArreglo(int *A, int n)
{

    for (int i = 1; i < n; i++)
        if (*(A + i) < *(A + i - 1))
            cout << " ¡Falló !";
}

llnode<int> *crearNodo(int k)
{
    llnode<int> *nuevo = new llnode<int>(2);
    return nuevo;
}