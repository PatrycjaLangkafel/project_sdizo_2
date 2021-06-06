#include "AdjacencyList.h"
#include "Heap.h"
#include "QHeap.h"
#include "NodeSet.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;

// konstruktor
AdjacencyList :: AdjacencyList()
{
    v = 0;
    e = 0;
    list = nullptr;
    resultsEdge = nullptr;
    help = nullptr;
    weights = nullptr;
    startV = 0;
    finishV = 0;
    cost = nullptr;
    path = nullptr;
}

// destruktor
AdjacencyList :: ~AdjacencyList()
{
    for (int i = 0; i < e; i++)
    {
        delete[] list[i];
        delete[] resultsEdge[i];
    }

    delete[] list;
    delete[] help;
    delete[] weights;
    delete[] cost;
    delete[] path;
    delete[] resultsEdge;
}

// funkcja odczytujaca dane do grafu
void AdjacencyList :: readFile(string file_input)
{
    fstream file;

    file.open(file_input, ios::in);
    if(!file.is_open())
    {
        cout << "Podany plik nie mozna otworzyc!!"<< endl;
        return;
    }
    else
    {
        file >> e;
        file >> v;
        file >> startV;
        file >> finishV;
        resultsEdge = new int *[e];
        weights = new int [e];

        int fromV, toV, w;

        for (int i = 0; i < e; i++)
        {
            file >> fromV;
            file >> toV;
            file >> w;

            resultsEdge[i] = new int[2];
            resultsEdge[i][0] = fromV;
            resultsEdge[i][1] = toV;
            weights[i] = w;
        }
    }

    file.close();
}

// funkcja tworzaca macierz sasiedztwa dla grafu nieskierowanego
void AdjacencyList :: createUndirectedList()
{
    list = new List *[v];
    for (int i = 0; i < v; i++)
    {
        list[i] = nullptr;
    }

    for (int i = 0; i < e; i++)
    {
        help = new List;
        help->n = resultsEdge[i][1];
        help->weight = weights[i];
        help->next = list[resultsEdge[i][0]];
        list[resultsEdge[i][0]] = help;

        help = new List;
        help->n = resultsEdge[i][0];
        help->weight = weights[i];
        help->next = list[resultsEdge[i][1]];
        list[resultsEdge[i][1]] = help;
    }
}

// funkcja tworzaca macierz sasiedztwa dla grafu skierowanego
void AdjacencyList :: createDirectedList()
{
    list = new List *[v];

    for (int i = 0; i < v; i++)
    {
        list[i] = nullptr;
    }

    for (int i = 0; i < e; i++)
    {
        help = new List;
        help->n = resultsEdge[i][1];
        help->weight = weights[i];
        help->next = list[resultsEdge[i][0]];
        list[resultsEdge[i][0]] = help;
    }
}

// funkcja generujaca randomowa macierz (graf skierowany)
void AdjacencyList :: createDirectedRandomList(double d, int n)
{
    double t = (d*n*(n-1))/2;
    e = (int) t;
    v = n;
    int p, l, w;

    startV = 0;
    finishV = (rand()%v);

    while(finishV == startV)
    {
        finishV = (rand()%v);
    }

    list = new List *[v];
    for (int i = 0; i < v; i++)
    {
        list[i] = nullptr;
    }

    for (int i = 0; i < e; i++)
    {
        w = rand()%101;
        p = (rand()%v);
        l = (rand()%v);

        while (l==p)
        {
            l = (rand()%v);
        }

        help = new List;
        help->n = l;
        help->weight = w;
        help->next = list[p];

        list[p] = help;
    }
}

// funkcja generujaca randomowa macierz (graf nieskierowany)
void AdjacencyList :: createUndirectedRandomList(double d, int n)
{
    double t = (d*n*(n-1))/2;
    e = (int) t;
    v = n;
    int p, l, w;

    list = new List *[v];
    for (int i = 0; i < v; i++)
    {
        list[i] = nullptr;
    }

    for (int i = 0; i < e; i++)
    {
        w = rand()%101;
        p = (rand()%v);
        l = (rand()%v);
        while (l==p)
        {
            l = (rand()%v);
        }

        help = new List;
        help->n = l;
        help->weight = w;
        help->next = list[p];
        list[p] = help;

        help = new List;
        help->n = p;
        help->weight = w;
        help->next = list[l];
        list[l] = help;
    }
}

// funkcja wyswietlajaca liste sasiedztwa
void AdjacencyList :: print()
{
    for (int i = 0; i < v; i++)
    {
        cout << "A[" << i << "] = ";
        help = list[i];
        while (help != nullptr)
        {
            cout << help->n << "(" << help->weight << ")" << "  ";
            help = help->next;
        }
        cout << endl;
    }
}

// funkcja wyswietlajaca wyniki dla algorytmu Prima i Kruskala
void AdjacencyList :: printResultsMST()
{
    int MST = 0;
    cout << "Edge    Weight" << endl;
    for (int i = 0; i < v-1; i++)
    {
        MST += weights[i];
        cout << "(" << resultsEdge[i][0] << "," << resultsEdge[i][1] << ")   " << weights[i] << endl;
    }

    cout << "MST: " << MST << endl;
}

// funkcja pomocnicza do wyswietlania dla algorytmow Dijsktry i Bellmana-Forda
void AdjacencyList :: printResults()
{
    int* tab = new int[v];
    int s = 0;

    cout << "Start = " << startV << endl;
    cout << "End    Dist    Path" << endl;

    for (int i = 0; i < v; i++)
    {
        cout << i << " | ";
        int j = i;

        while (j > -1)
        {
            tab[s++] = j;
            j = path[j];
        }

        cout << "   | " << cost[i] << " |   ";

        while (s != 0)
        {
            s--;
            cout << tab[s] << " ";
        }
        cout << endl;
    }
    delete[] tab;
}

// funkcja algorytmu Prima
void AdjacencyList :: Prim(bool print)
{
    resultsEdge = new int*[v-1];
    weights = new int[v-1];
    bool * visitedV = new bool[v];
    int z = 0, k = 0, i = 0;
    Edge edge;
    Heap heap;

    while (i < v)
    {
        visitedV[i++] = false;
    }

    visitedV[k] = true;
    i = 0;

    while (i < v - 1)
    {
        for (help=list[k]; help!=nullptr; help=help->next)
        {
            if (help->weight != 0 && visitedV[help->n] == false)
            {
                edge.beg = k;
                edge.end = help->n;
                edge.weight = help->weight;
                heap.add_front(edge);
            }
        }

        do
        {
            edge = heap.getFront();
            heap.remove();
        }
        while (visitedV[edge.end] == true);

        resultsEdge[z] = new int[2];

        resultsEdge[z][0] = edge.beg;
        resultsEdge[z][1] = edge.end;
        weights[z] = edge.weight;
        z++;

        k = edge.end;
        visitedV[k] = true;
        i++;
    }

    if (print)
    {
        printResultsMST();
    }

    delete[] visitedV;
}

// funkcja algorytmu Kruskala
void AdjacencyList :: Kruskal(bool print)
{
    if (e < v-1)
    {
        cout << "Nie mozna wykonac algorytmu, graf nie jest spojny!!" << endl;
    }

    resultsEdge = new int*[v-1];
    weights = new int[v-1];
    Edge edge;
    Heap heap;
    NodeSet set(v);
    int z = 0, i = 0;


    for (int i = 0; i < v; i++)
    {
        for (help = list[i]; help != nullptr; help = help->next)
        {
            if (help->weight != 0)
            {
                edge.beg = i;
                edge.end = help->n;
                edge.weight = help->weight;
                heap.add_front(edge);
            }
        }
    }

    while (i < v)
    {
        set.makeSet(i++);
    }

    i = 0;

    while (i < v - 1)
    {
        do
        {
            edge = heap.getFront();
            heap.remove();
        }
        while (set.findSet(edge.beg) == set.findSet(edge.end));

        set.unionSet(edge);

        resultsEdge[z] = new int[2];

        resultsEdge[z][0] = edge.beg;
        resultsEdge[z][1] = edge.end;
        weights[z] = edge.weight;
        z++;
        i++;
    }

    if (print)
    {
        printResultsMST();
    }
}

// funkcja algorytmu Dijkstra
void AdjacencyList :: Dijkstra(bool print)
{
    bool m = false;

    for (int i = 0; i < v-1; i++)
    {
        for (help = list[i]; help != nullptr; help = help->next)
        {
            if (help->weight < 0)
            {
                cout << "Ujemne wagi algorytmu. Moze nie zadzialac poprawnie!" << endl;;
                m = true;
                break;
            }
        }

        if(m)
        {
            break;
        }
    }

    if (finishV < 0 || finishV > v)
    {
        cout << "Wierzcholek koncowy jest poza zakresem!!" << endl;
    }

    QHeap q(v, startV);
    cost = new long long[v];
    path = new int[v];
    bool* visitedV = new bool[v];
    int i = 0;

    while (i < v)
    {
        if (i == startV)
        {
            cost[i] = 0;
        }
        else
        {
            cost[i] = MAXINT;
        }
        path[i] = -1;
        visitedV[i++] = false;
    }

    for (int i = 0; i < v; i++)
    {
        Verticle vr = q.pop();
        visitedV[vr.nr] = true;

        int n = 0;
        Verticle* ad = new Verticle[n];

        if (vr.nr != startV && path[vr.nr] == -1)
            break;

        List* l = list[vr.nr];
        while (l != nullptr)
        {
            Verticle* buf = new Verticle[n + 1];

            for (int w = 0; w < n; w++)
            {
                buf[w] = ad[w];
            }
            buf[n].nr = l->n;
            buf[n].cost = l->weight;

            l = l->next;

            delete[] ad;
            ad = buf;
            n++;
        }

        for (int j = 0; j < n; j++)
        {
            if (visitedV[ad[j].nr])
                continue;

            if (cost[ad[j].nr] > ad[j].cost + cost[vr.nr])
            {
                cost[ad[j].nr] = ad[j].cost + cost[vr.nr];
                path[ad[j].nr] = vr.nr;
            }

            q.change_cost(ad[j].nr, cost[ad[j].nr]);
        }
    }

    if (print)
    {
        printResults();
    }

    delete[] cost;
    delete[] path;
}

// funkcja algorytmu Bellmana Forda
bool AdjacencyList :: BellmanFord(bool print)
{
    cost = new long long[v];
    path = new int[v];
    int i = 0;
    bool test;

    while (i < v)
    {
        cost[i] = MAXINT;
        path[i++] = -1;
    }
    cost[startV] = 0;


    for (int i = 0; i < v-1; i++)
    {
        test = true;
        for (int z = 0; z < v; z++)
        {
            for (help = list[z]; help!=nullptr; help = help->next)
            {
                if (cost[help->n] > cost[z] + help->weight)
                {
                    test = false;
                    cost[help->n] = cost[z] + help->weight;
                    path[help->n] = z;
                }
            }
        }
        if(test)
        {
            if (print)
            {
                printResults();
            }
            return true;
        }
    }

    i = 0;
    while (i < v)
    {
        for (help = list[i]; help!=nullptr; help = help->next)
        {
            if (cost[help->n] > cost[i] + help->weight)
            {
                cout << " Ujemny cykl !!!" << endl;
                return false;
            }
        }
        i++;
    }

    if (print)
    {
        printResults();
    }

    delete[] cost;
    delete[] path;
    return true;
}

