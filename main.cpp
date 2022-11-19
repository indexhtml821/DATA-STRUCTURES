#include "llist.h"
#include "bstree.h"
#include "rbtree.h"
#include "chasht.h"
#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

#define TIMING

#ifdef TIMING
#define INIT_TIMER auto start = std::chrono::high_resolution_clock::now();
#define START_TIMER start = std::chrono::high_resolution_clock::now();
#define STOP_TIMER(name) std::cout << "RUNTIME of " << name << ": " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start).count() << " s " << std::endl;
#else
#define INIT_TIMER
#define START_TIMER
#define STOP_TIMER(name)
#endif

void llenarlista(llnode<int> *A, int n);
void revisarArreglo(int *A, int n);
int diversidad(int *A, int n);
llnode<int> *crearNodo(int k);
bstnode<int> *crearNodoBst(int k);
rbtnode<int> *crearNodoRbt(int k);

int main()
{

    INIT_TIMER;
    /*
    llist<int> *lista1 = new llist<int>();
    for (int i = 0; i < 1000000; i++)
    {
        int num = rand() % 1000000;
        lista1->Insert(crearNodo(num));
    }


    int i = 0;
    START_TIMER;
    for (i = 0; i < 4000; i++)
    {
        int num = rand() % 100000;

        lista1->Search(num)->key;
    }
    STOP_TIMER("busquedas aleatorias")
    cout << endl;
    cout << endl;
    llist<int> *lista = new llist<int>();
    START_TIMER;
    for (int i = 0; i < 1000000; i++)
    {
        lista->Insert(crearNodo(i + 1));
    }

    //  lista.print();
    cout << endl;
    cout << endl;
     i = 0;
    START_TIMER;
    for (i = 0; i < 2390; i++)
    {
        int num = rand() % 100;

        lista->Search(num)->key;
    }
    STOP_TIMER("busquedas aleatorias")
    cout << i << endl;

    delete lista;
    // llenarlista(*amor,10);
    /*
      cout << endl;
        cout << endl;
         i = 0;
        START_TIMER;
        for ( i = 0; i < 2390; i++)
        {

            lista->Search(i)->key;

        }
        STOP_TIMER("busquedas en orden")
    */

    /*
        bstnode<int> *nodo = new bstnode<int>(25);
        bstnode<int> *nodo1 = new bstnode<int>(50);
        bstnode<int> *nodo2 = new bstnode<int>(15);
        bstnode<int> *nodo3 = new bstnode<int>(-1);
        bstnode<int> *nodo4 = new bstnode<int>(0);
        bstree<int> arbol;
        arbol.Insert(nodo);
        arbol.Insert(nodo1);
        arbol.Insert(nodo2);
        arbol.Insert(nodo3);
        arbol.Insert(nodo4);
        arbol.InorderWalk(nodo);
        cout << arbol.Search(nodo, 0)->key << endl;
        cout << arbol.IterativeSearch(nodo, 0)->key << endl;
        arbol.Delete(nodo4);
        cout << endl;
        arbol.InorderWalk(nodo);
        cout << endl;
        arbol.Delete(nodo);
        cout << endl;
        arbol.InorderWalk(nodo);
        cout << endl;
        cout << arbol.Successor(nodo)->key << endl;
        cout << arbol.Minimum(nodo)->key << endl;
        cout << arbol.Maximum(nodo)->key << endl;
        */

    // bstree<int> *arbol2 = new bstree<int>;

    /*

    BTREE-TIME COMPLEXITY
    bstree<int> *arbol1 = new bstree<int>;

       int i = 0;
       for (int i = 0; i < 1000000; i++)
       {
           arbol1->InsertGreaters(crearNodoBst(i + 1));
       }

       i = 0;
       START_TIMER;
       for (i = 0; i < 100000; i++)
       {
           int num = rand() % 100000;
           arbol1->IterativeSearch(arbol1->root, num);
       }
       STOP_TIMER("busquedas en orden")
       delete arbol1;
   */
    /*  int i = 0;
      for (int i = 0; i < 100000; i++)
      {
          arbol2->Insert(crearNodoBst(i + 1));
      }
      cout << endl;
      i = 0;
      START_TIMER;
      for (i = 0; i < 5000; i++)
      {
          int num = rand() % 99000;
          arbol2->IterativeSearch(arbol2->root, num);
      }
      STOP_TIMER("busquedas en orden")
      delete arbol2;
      */
    /*
    RBTREE Methods test
        rbtnode<int> *nodo = new rbtnode<int>(13);
        rbtnode<int> *nodo1 = new rbtnode<int>(8);
        rbtnode<int> *nodo2 = new rbtnode<int>(17);
        rbtnode<int> *nodo3 = new rbtnode<int>(1);
        rbtnode<int> *nodo4 = new rbtnode<int>(11);
        rbtnode<int> *nodo5 = new rbtnode<int>(6);
        rbtnode<int> *nodo6 = new rbtnode<int>(15);
        rbtnode<int> *nodo7 = new rbtnode<int>(25);
        rbtnode<int> *nodo8 = new rbtnode<int>(22);
        rbtnode<int> *nodo9 = new rbtnode<int>(27);
        rbtree<int> *arbol = new rbtree<int>();
        arbol->Insert(nodo);
        arbol->Insert(nodo1);
        arbol->Insert(nodo2);
        arbol->Insert(nodo3);
        arbol->Insert(nodo4);
        arbol->Insert(nodo5);
        arbol->Insert(nodo6);
        arbol->Insert(nodo7);
        arbol->Insert(nodo8);
        arbol->Insert(nodo9);
        arbol->InorderWalk(nodo);
        cout << arbol->IterativeSearch(nodo, 3) << endl; // error se devuelve nullptr
        cout << arbol->Search(nodo, 3) << endl;          // error se devuelve nullptr
        cout << arbol->IterativeSearch(nodo, 27)->key << endl;
        cout << arbol->Search(nodo, 6)->key << endl;

        cout << "Max:  " << arbol->Maximum(nodo)->key << endl;
        cout << "Min:  " << arbol->Minimum(nodo)->key << endl;
        cout << "Succesor:  " << arbol->Successor(nodo)->key << endl;
        delete arbol;
        */

    // RBTREE-Testing time complexity

    /*  rbtree<int> *arbol1 = new rbtree<int>;

      int i = 0;
      for (i = 0; i < 1000000; i++)
      {
          int num = rand() % 999000;
          arbol1->Insert(crearNodoRbt(num));
      }
      cout << endl;
      i = 0;
      START_TIMER;
      for (i = 0; i < 10500000; i++)
      {
          int num = rand() % 999000;
          arbol1->IterativeSearch(arbol1->root, num);
      }
      STOP_TIMER("busquedas en orden")
      delete arbol1;
  */
    // ordered nmbrs
    /*
        rbtree<int> *arbol2 = new rbtree<int>;

        int i = 0;
        for (i = 0; i < 1000000; i++)
        {

            arbol2->Insert(crearNodoRbt(i));
        }
        cout << endl;
        i = 0;
        rbtnode<int> *nodo = arbol2->root;

        START_TIMER;
        for (i = 0; i < 8000000; i++)
        {
            int num = rand() % 999000;
            arbol2->IterativeSearch(arbol2->root, num);
        }
        STOP_TIMER("busquedas en orden")
        delete arbol2;
        */

    // TESTING HASH FUNCTION METHODS
        chtable<int> tabla(3);
        tabla.Insert(2);
        int *ptr = tabla.Search(2);
        cout << tabla.Search(2) << endl;
        
}

void llenarlista(llnode<int> *A, int n)
{

    for (int i = 0; i < n; i++)
    {
        int num = rand() / 124000 / (2 * 1000000);
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
    int num = rand() / 124000 / (2 * 1000000);
    llnode<int> *nuevo = new llnode<int>(k);
    return nuevo;
}

bstnode<int> *crearNodoBst(int k)
{
    int num = rand() % 100;
    bstnode<int> *nuevo = new bstnode<int>(k);
    return nuevo;
}

rbtnode<int> *crearNodoRbt(int k)
{
    int num = rand() % 100;
    rbtnode<int> *nuevo = new rbtnode<int>(k);
    return nuevo;
}

