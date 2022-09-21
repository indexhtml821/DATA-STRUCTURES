#ifndef Ordenador_h
#define Ordenador_h

class Ordenador
{
private:
    // Defina aquí los métodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos métodos quiera.

public:
    Ordenador(){};
    ~Ordenador(){};
    // Si no implementa algunos de los métodos de ordenamiento no lo borre;
    // déjelo con el cuerpo vacío para evitar errores de compilación, ya
    // que se va a ejecutar el mismo «main» para todas las tareas.
    // Implemente los algoritmos en este archivo, no en un CPP.
    void seleccion(int *A, int n)
    {
        int min, i, j, aux;
        for (i = 0; i < n; i++)
        {
            min = i;
            for (j = i + 1; j < n; j++)
            {
                int comparador = *(A + j);
                if (*(A + j) < *(A + min))
                {
                    min = j;
                }
            }
            aux = *(A + i);
            *(A + i) = *(A + min);
            *(A + min) = aux;
        }
    }
    void insercion(int *A, int n)
    {
        for (int j = 1; j < n; j++)
        {
            int key = *(A + j);
            int i = j - 1;
            while (i > -1 && *(A + i) > key)
            {
                *(A + i + 1) = *(A + i);
                i = i - 1;
            }
            *(A + i + 1) = key;
        }
    }
    void mergesort(int *A, int n)
    {
        int begin = 0;
        int end = n - 1;
        mergeSort1(A, begin, end);
    }
    void heapsort(int *A, int n);
    void quicksort(int *A, int n);
    void radixsort(int *A, int n);

    void mergeSort1(int *A, int begin, int end)
    {

        if (begin >= end)
            return; // Returns recursively

        auto mid = begin + (end - begin) / 2;
        mergeSort1(A, begin, mid);
        mergeSort1(A, mid + 1, end);
        merge(A, begin, mid, end);
    }

    void merge(int *A, int left, int mid, int right)
    {

        auto const subArrayOne = mid - left + 1;
        auto const subArrayTwo = right - mid;

        // Create temp arrays
        auto *leftArray = new int[subArrayOne],
             *rightArray = new int[subArrayTwo];

        // Copy data to temp arrays leftArray[] and rightArray[]
        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = *(A+left+i);
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = *(A+mid+1+j);

        auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
            indexOfSubArrayTwo = 0;    // Initial index of second sub-array
        int indexOfMergedArray = left; // Initial index of merged array

        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
        {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
            {
                *(A+ indexOfMergedArray) = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                *(A+indexOfMergedArray) = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        // Copy the remaining elements of
        // left[], if there are any
        while (indexOfSubArrayOne < subArrayOne)
        {
            *(A+indexOfMergedArray) = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        // Copy the remaining elements of
        // right[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo)
        {
            *(A+indexOfMergedArray) = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }
    
};
#endif
