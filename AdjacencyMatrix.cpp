#include "AdjacencyMatrix.h"
#include "Heap.h"
#include "QHeap.h"
#include "NodeSet.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>


using namespace std;

// konstruktor
AdjacencyMatrix :: AdjacencyMatrix()
{
    v = 0;
    e = 0;
    matrix = nullptr;
    resultsEdge = nullptr;
    weights = nullptr;
    startV = 0;
    finishV = 0;
    cost = nullptr;
    path = nullptr;
}

// destruktor
AdjacencyMatrix :: ~AdjacencyMatrix()
{
    for (int i = 0; i < e; i++)
    {
        delete[] resultsEdge[i];
    }

    for (int i = 0; i < v; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
    delete[] weights;
    delete[] cost;
    delete[] path;
    delete[] resultsEdge;
}

// funkcja odczytujaca dane do grafu
void AdjacencyMatrix :: readFile(string file_input)
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
void AdjacencyMatrix :: createUndirectedMatrix()
{
    matrix = new int *[v];

    for (int i = 0; i < v; i++)
    {
        matrix[i] = new int[v];

        for (int j = 0; j < v; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        matrix[resultsEdge[i][0]][resultsEdge[i][1]] = weights[i];
        matrix[resultsEdge[i][1]][resultsEdge[i][0]] = weights[i];
    }

    for (int i = 0; i < e; i++)
    {
        delete[] resultsEdge[i];
    }
    delete[] resultsEdge;
    delete[] weights;
}

// funkcja tworzaca macierz sasiedztwa dla grafu skierowanego
void AdjacencyMatrix :: createDirectedMatrix()
{
    matrix = new int *[v];

    for (int i = 0; i < v; i++)
    {
        matrix[i] = new int[v];

        for (int j = 0; j < v; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        matrix[resultsEdge[i][0]][resultsEdge[i][1]] = weights[i];
    }

    for (int i = 0; i < e; i++)
    {
        delete[] resultsEdge[i];
    }
    delete[] resultsEdge;
    delete[] weights;
}

// funkcja generujaca randomowa macierz (graf skierowany)
void AdjacencyMatrix :: createDirectedRandomMatrix(double d, int n)
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

    matrix = new int *[v];

    for (int i = 0; i < v; i++)
    {
        matrix[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            matrix[i][j] = 0;
        }
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

        while (matrix[p][l] != 0)
        {
            p = (rand()%v);
            l = (rand()%v);
            while (l==p)
            {
                l = (rand()%v);
            }
        }
        matrix[p][l] = w;
    }
}


// funkcja generujaca randomowa macierz (graf nieskierowany)
void AdjacencyMatrix :: createUndirectedRandomMatrix(double d, int n)
{
    double t = (d*n*(n-1))/2;
    e = (int) t;
    v = n;
    int p, l, w;

    matrix = new int *[v];

    for (int i = 0; i < v; i++)
    {
        matrix[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            matrix[i][j] = 0;
        }
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

        while (matrix[p][l] != 0 && matrix[l][p] != 0)
        {
            p = (rand()%v);
            l = (rand()%v);
            while (l==p)
            {
                l = (rand()%v);
            }
        }
        matrix[p][l] = w;
        matrix[l][p] = w;
    }
}


// funkcja wyswietlajaca macierz sasiedztwa
void AdjacencyMatrix :: print()
{
    cout << "     ";
    for (int j = 0; j < v; j++)
    {
        cout << j << "     ";
    }
    cout << endl;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if(j==0)
            {
                cout << i << "     ";
            }
            cout << matrix[i][j] << "     ";
        }
        cout << endl;
    }
}

// funkcja wyswietlajaca wyniki dla algorytmu Prima i Kruskala
void AdjacencyMatrix:: printResultsMST()
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
void AdjacencyMatrix :: printResults()
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
            cout << tab[--s] << " ";
        }
        cout << endl;
    }
    delete[] tab;
}

// funkcja algorytmu Prima
void AdjacencyMatrix :: Prim(bool print)
{
    resultsEdge = new int *[v - 1];
    weights = new int [v-1];
    bool *visitedV = new bool[v];
    int k = 0, z = 0, i = 0;
    Edge edge;
    Heap heap;

    while (i < v)
    {
        visitedV[i++] = false;
    }

    visitedV[k] = true;
    i = 0;

    while (i < v-1)
    {
            for (int j = 0; j < v; j++)
            {
                if (visitedV[j] == false && matrix[k][j] != 0)
                {
                    edge.beg = k;
                    edge.end = j;
                    edge.weight = matrix[k][j];
                    heap.add_front(edge);
                }

            }

        do
        {
            edge = heap.getFront();
            heap.remove();
        }
        while (visitedV[edge.end] == true);

        k = edge.end;
        visitedV[k] = true;

        resultsEdge[z] = new int[2];

        resultsEdge[z][0] = edge.beg;
        resultsEdge[z][1] = edge.end;

        weights[z] = edge.weight;
        z++; i++;
    }

    if (print)
    {
        printResultsMST();
    }

    delete[] visitedV;
}

// funkcja dla algorytmu Kruskala
void AdjacencyMatrix :: Kruskal(bool print)
{
    if (e < v-1)
    {
        cout << "Nie mozna wykonac algorytmu, graf nie jest spojny!!" << endl;
    }

    resultsEdge = new int *[v-1];
    weights = new int [v-1];
    Edge edge;
    Heap heap;
    NodeSet set(v);
    int z = 0, i = 0;


    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (matrix[i][j] != 0)
            {
                edge.beg = i;
                edge.end = j;
                edge.weight = matrix[i][j];
                heap.add_front(edge);

            }
        }
    }

    while (i < v)
    {
        set.makeSet(i++);
    }

    for (int i = 0; i < v-1; i++)
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
        z++; //i++;
    }

    if (print)
    {
        printResultsMST();
    }
}

// funkcja dla algorytmu Dijkstra
void AdjacencyMatrix :: Dijkstra(bool print)
{
    bool m = false;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j<v; j++)
            if (matrix[i][j]<0)
            {
                cout << "Ujemne wagi algorytmu. Moze nie zadzialac poprawnie!" << endl;;
                m = true;
                break;
            }
        if (m)
        {
            break;
        }
    }

    if (finishV < 0 || finishV > v)
    {
        cout << "Wierzcholek koncowy jest poza zakresem!!" << endl;
    }

    QHeap q (v, startV);
    bool* Q = new bool[v];
    cost = new long long[v];
    path = new int [v];
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
        Q[i++] = false;
    }


    for (int i = 0; i < v; i++)
    {
        Verticle vr = q.pop();
        Q[vr.nr] = true;
        int n = 0;
        Verticle* addN = new Verticle[n];

        if (vr.nr != startV && path[vr.nr] == -1)
        {
            break;
        }

        for (int j = 0; j < v; j++)
        {
            if (matrix[vr.nr][j] != 0)
            {
                Verticle* buf = new Verticle[n + 1];
                for (int w = 0; w < n+1; w++)
                {
                    buf[w] = addN[w];
                }
                buf[n].nr = j;
                buf[n].cost = matrix[vr.nr][j];

                n++;
                delete[] addN;
                addN = buf;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (Q[addN[j].nr])
                continue;

            if (cost[addN[j].nr] > addN[j].cost + cost[vr.nr])
            {
                path[addN[j].nr] = vr.nr;
                cost[addN[j].nr] = addN[j].cost + cost[vr.nr];
            }

            q.change_cost(addN[j].nr, cost[addN[j].nr]);
        }
    }

    if (print)
    {
        printResults();
    }

    delete[] Q;
    delete[] cost;
    delete[] path;
}

// funkcja algorytmu Bellmana Forda
bool AdjacencyMatrix :: BellmanFord(bool print)
{
    cost = new long long[v];
    path = new int [v];
    int i = 0;
    bool test;

    while (i < v)
    {
        cost[i] = MAXINT;
        path[i] = -1;
        i++;
    }
    cost[startV] = 0;

    for (int k = 0; k < v-1; k++)
    {
        test = true;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (cost[j] > cost[i] + matrix[i][j])
                    {
                        test = false;
                        cost[j] = cost[i] + matrix[i][j];
                        path[j] = i;
                    }
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

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if ((cost[j] > cost[i] + matrix[i][j]) && matrix[i][j] != 0)
            {
                cout << " Ujemny cykl!!!" << endl;
                return false;
            }
        }
    }

    if (print)
    {
        printResults();
    }

    delete[] cost;
    delete[] path;

    return true;
}


