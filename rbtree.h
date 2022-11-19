//
//  rbtree.h
//

#ifndef rbtree_h
#define rbtree_h

#include <iostream>

enum colors
{
    RED,
    BLACK
};

// Nodos del arbol:
template <typename T>
class rbtnode
{
public:
    // Esta clase es usada por la clase rbtree. Por eficiencia se hacen los atributos publicos.
    T key;
    rbtnode<T> *p, *left, *right;
    enum colors color;

    // Constructor por omision.
    rbtnode(){};

    // Inicializacion de datos miembro.
    rbtnode(const T &k, rbtnode<T> *w = nullptr, rbtnode<T> *y = nullptr, rbtnode<T> *z = nullptr, enum colors c = RED) : key(k), p(w), left(y), right(z), color(c){};

    ~rbtnode()
    {

        delete left;
        delete right;
    };
};

// Arbol rojinegro:
template <typename T>
class rbtree
{
public:
    rbtnode<T> *root = nullptr; // raiz del arbol
    rbtnode<T> *nil = nullptr;  // nodo nil (hoja) del arbol

    rbtree(){
        // Constructor (crea un arbol vacio)

    };

    ~rbtree()
    {
        // Destructor (borra el arbol)
        delete root;
    };

    void Insert(rbtnode<T> *z)
    {
        // Inserta el nodo z en la posicion que le corresponde en el arbol.
        rbtnode<T> *y = nil;
        rbtnode<T> *x = root;

        while (x != nil)
        {
            y = x;
            if (z->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        z->p = y;

        if (y == nil)
            this->root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;

        z->left = nil;
        z->right = nil;
        z->color = RED;
        RB_INSERT_FIXUP(z);
    };

    void RB_INSERT_FIXUP(rbtnode<T> *z)
    {
        rbtnode<T> *y;

        while (z != root && z->p->color == RED)
        {
            if (z->p == z->p->p->left)
            {
                y = z->p->p->right;
                if (y != nullptr && y->color == RED)
                {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                }
                else
                {
                    if (z == z->p->right)
                    {
                        z = z->p;
                        this->RotateLeft(z);
                    }

                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    this->RotateRight(z->p->p);
                }
            }
            else
            {
                y = z->p->p->left;
                if (y != nullptr && y->color == RED)
                {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                }
                else
                {
                    if (z == z->p->left)
                    {
                        z = z->p;
                        this->RotateRight(z);
                    }

                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    this->RotateLeft(z->p->p);
                }
            }
        }

        this->root->color = BLACK;
    };

    void InorderWalk(rbtnode<T> *x)
    {
        // Recorre en orden el sub�arbol con raiz x, imprimiendo la llave de cada nodo en en una nueva linea de la salida estandar despu�s de recorrido el subarbol izquierdo y antes de recorrer el subarbol derecho.
        if (x != nil)
        {
            InorderWalk(x->left);
            cout << x->key << endl;
            InorderWalk(x->right);
        }
    };

    rbtnode<T> *Search(rbtnode<T> *x, const T &k)
    {
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve nil.
        if (x == nil || k == x->key)
        {
            return x;
        }
        if (k < x->key)
        {
            return Search(x->left, k);
        }
        else
        {
            return Search(x->right, k);
        }
    };

    rbtnode<T> *IterativeSearch(rbtnode<T> *x, const T &k)
    {
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve nil.
        while (x != nil && k != x->key)
        {
            if (k < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        return x;
    };

    rbtnode<T> *Minimum(rbtnode<T> *x)
    {
        // Devuelve el nodo que tiene la llave menor. Si el arbol esta� vacio, devuelve nil.
        while (x->left != nullptr)
        {
            x = x->left;
        }
        return x;
    };

    rbtnode<T> *Maximum(rbtnode<T> *x)
    {
        // Devuelve el nodo que tiene la llave mayor. Si el arbol esta vacio devuelve nil.

        while (x->right != nullptr)
        {
            x = x->right;
        }
        return x;
    };

    rbtnode<T> *Successor(rbtnode<T> *x)
    {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve nil.
        rbtnode<T> *y;
        if (x->right != nullptr)
        {
            return Minimum(x->right);
        }
        y = x->p;
        while (y != nullptr && x == y->right)
        {
            x = y;
            y = y->p;
        }

        return y;
    };

    void RotateLeft(rbtnode<T> *x)
    {

        rbtnode<T> *y = x->right;

        x->right = y->left;

        if (y->left != nullptr)
            y->left->p = x;

        y->p = x->p;

        if (x->p == nullptr)
            root = y;
        else if (x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;

        y->left = x;
        x->p = y;
    }

    void RotateRight(rbtnode<T> *x)
    {
        rbtnode<T> *y = x->left;

        x->left = y->right;

        if (y->right != nullptr)
            y->right->p = x;

        y->p = x->p;

        if (x->p == nullptr)
            root = y;
        else if (x == x->p->right)
            x->p->right = y;
        else
            x->p->left = y;

        y->right = x;
        x->p = y;
    }
};

#endif /* rbtree_h */
