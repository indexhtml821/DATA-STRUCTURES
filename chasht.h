//
//  chtable.h
//

#ifndef chtable_h
#define chtable_h

#include <list>
#include <vector>

using namespace std;
template <typename T>

// Tabla de dispersi�n con encadenamiento
class chtable
{
public:
    std::list<T> tab;
    // Constructor que especifica el tama�o de la tabla
    chtable(int sz)
    {
        this->size = sz;
        this->table.resize(sz);
    };

    // Destructor (borrra la tabla)
    ~chtable()
    {
        table.clear();
    };

    // Inserta el elemento en la tabla
    void Insert(const T &k)
    {
        if (k <= this->size)
        {
            /*
            auto lista = table[k % this->size];

            lista.push_back(k);
            */

            table[hashFunction(k)].push_back(k);
        }
    };

    // Retorna un puntero a la llave o nullptr si no se encuentra
    T *Search(const T &k)
    {
        int index = hashFunction(k);
        list<T> lista = table[hashFunction(k)];
        auto iter = lista.begin();

        T *ptr = &*iter;

        return ptr;
    };

    int hashFunction(const T &k)
    {
        return (k % this->size);
    }

private:
    // N�mero de entradas en la tabla
    int size;

    // La tabla es un vector de listas de STL
    std::vector<std::list<T>> table;
};

#endif /* chtable_h */
