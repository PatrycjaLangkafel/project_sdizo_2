#include "Heap.h"
#include <iostream>

using namespace std;

// konstruktor
Heap :: Heap()
{
    size = 0;
    heap = new Edge[size];
}

// destruktor
Heap :: ~Heap()
{
    delete[] heap;
    heap = nullptr;
}

// funkcja dodajaca do kolejki krawedz value
// w zaleznosci od weight
void Heap :: add_front(Edge value)
{
    Edge* e = new Edge[size+1];

    if(size == 0)
    {
        size++;
        e[0] = value;
        heap = e;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            e[i] = heap[i];
        }

        delete[] heap;
        heap = e;


        int l = size++;
        int parent = getParent(l);


        while (l > 0 && heap[parent].weight > value.weight)
        {
            heap[l] = heap[parent];
            l = parent;
            parent = getParent(l);
        }

        heap[l] = value;
    }
}

// funkcja ususwajaca z poczatku kolejki element
void Heap :: remove()
{
    if (size == 0)
    {
        cout << "Kolejka jest pusta!!" << endl;
        return;
    }

        Edge e;
        e = heap[--size];
        int l = 0;

        for (int p = 1; p < size; p = 2 * l + 1)
        {
            if (heap[p + 1].weight < heap[p].weight && p + 1 < size)
            {
                p++;
            }

            if (e.weight <= heap[p].weight)
            {
                break;
            }

            heap[l] = heap[p];
            l = p;
        }

        heap[l] = e;


        Edge* ed = new Edge[size];
        for (int i = 0; i < size; i++)
        {
            ed[i] = heap[i];
        }

        delete[] heap;
        heap = ed;

}

// funkcja zwracajaca wartosc z poczatku kopca
Edge Heap :: getFront()
{
    return heap[0];
}

// funkcja zwracajaca rozmiar kopca
int Heap :: getSize()
{
    return size;
}

// funkcja zwracajaca indeks rodzica
int Heap :: getParent(int i)
{
    return (i-1)/2;
}


