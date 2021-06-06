#include <iostream>
#include "NodeSet.h"

// konstruktor
NodeSet :: NodeSet(int n)
{
    set = new Node[n];
}

// destruktor
NodeSet :: ~NodeSet()
{
    delete[] set;
}

// funkcja tworzaca wpis w tablicy obiektow
void NodeSet :: makeSet(int value)
{
    set[value].rank = 0;
    set[value].up = value;
}

// funkcja zwracajaca indeks reprezentanta zbioru,
// w ktorym jest wierzcholek value
int NodeSet :: findSet(int value)
{
    if (set[value].up != value)
    {
        set[value].up = findSet(set[value].up);
    }

    return set[value].up;
}

// funkcja laczaca dwa zbiory
void NodeSet :: unionSet(Edge e)
{
    int u = findSet(e.beg);
    int v = findSet(e.end);

    if (u != v)
    {
        if (set[u].rank > set[v].rank)
        {
            set[v].up = u;
        }
        else
        {
            set[u].up = v;

            if(set[u].rank == set[v].rank)
            {
                set[v].rank++;
            }
        }
    }
}
