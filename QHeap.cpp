#include "QHeap.h"
#include "Heap.h"


using namespace std;

// konstruktor
QHeap :: QHeap(int len, int start)
{
    size = len;
    queue = new Verticle[size];

    for (int i = 0; i < size; i++)
    {
        queue[i].cost = MAXINT;
        queue[i].nr = i;
    }

    change_cost(start, 0);
}

// destruktor
QHeap :: ~QHeap()
{
    delete[] queue;
}

// funkcja usuwajaca pierwszy element i zwracajaca go
Verticle QHeap :: pop()
{
    Verticle v = queue[0];
    size--;
    Verticle* vr = new Verticle[size];

    for (int i = 0; i < size; i++)
    {
        vr[i] = queue[i+1];
    }

    delete[] queue;
    queue = vr;

    heap_fix_down();

    return v;
}

// funkcja naprawiajaca kopiec w dol
void QHeap :: heap_fix_down()
{
    int l = 0;
    Verticle vr;

    for (int p = 1; p < size; p = 2 * l + 1)
    {
        if (queue[p].cost > queue[p + 1].cost && p + 1 < size)
        {
            p++;
        }

        if (queue[l].cost <= queue[p].cost)
        {
            return;
        }

        vr = queue[p];
        queue[p] = queue[l];
        queue[l] = vr;

        l = p;
    }
}

// funkcja naprawiajaca kopiec w gore
void QHeap :: heap_fix_up(int index)
{
    Heap h;
    Verticle vr;
    int child = index;
    int parent = h.getParent(child);

    while (queue[parent].cost > queue[child].cost && child != 0)
    {
        vr = queue[child];
        queue[child] = queue[parent];
        queue[parent] = vr;

        child = parent;
        parent = h.getParent(child);
    }
}

// funkcja zmieniajaca koszt dotarcia do wierzcholka
void QHeap :: change_cost(int nr, int cost)
{
    int in, i = 0;
    while (i < size)
    {
        if (queue[i].nr == nr)
        {
            queue[i].cost = cost;
            in = i;
            break;
        }
        i++;
    }

    heap_fix_up(in);
}
