#include <iostream>
#include <string>
#include <fstream>
#include "Test.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "Time.h"


using namespace std;

// konstruktor
Test :: Test()
{
    D = 0;
    h = 0;
}

// destruktor
Test :: ~Test() {}

// funkcja testow algorytmu Prima
void Test :: testPrim()
{
    long long resultTimeM = 0;
    long long resultTimeL = 0;
    double D;
    int h;
    AdjacencyMatrix m;
    AdjacencyList l;
    Time t;
    fstream file_output;

    file_output.open("wyniki.txt", ios::out | ios::app);


    if (!file_output.is_open())
    {
        cout<< "Nie otworzono pliku zapisowego. Zakonczenie testow"<<endl;
        return;
    }

    for (int i = 0; i<5; i++)
    {
        h = tabV[i];
        for (int j = 0; j<4; j++)
        {
            D = tabD[j];
            for (int k = 0; k<100; k++)
            {
                m.createUndirectedRandomMatrix(D, h);
                t.start_time();
                m.Prim(false);
                t.stop_time();
                resultTimeM += t.time();

                l.createUndirectedRandomList(D, h);
                t.start_time();
                l.Prim(false);
                t.stop_time();
                resultTimeL += t.time();
            }
            cout<<"Koniec testow v = "<<h<<endl;
            file_output<<"Prim Matrix : "<<D<<" "<<h<<" "<<resultTimeM/100;
            file_output<<endl;
            resultTimeM = 0;

            file_output<<"Prim List : "<<D<<" "<<h<<" "<<resultTimeL/100;
            file_output<<endl;
            resultTimeL = 0;
        }
    }

    file_output.close();
    return;
}

// funkcja testow algorytmu Kruskala
void Test :: testKruskal()
{
    long long resultTimeM = 0;
    long long resultTimeL = 0;
    double D;
    int h;
    AdjacencyMatrix m;
    AdjacencyList l;
    Time t;
    fstream file_output;

    file_output.open("wyniki.txt", ios::out | ios::app);


    if (!file_output.is_open())
    {
        cout<< "Nie otworzono pliku zapisowego. Zakonczenie testow"<<endl;
        return;
    }

    for (int i = 0; i<5; i++)
    {
        h = tabV[i];
        for (int j = 0; j<4; j++)
        {
            D = tabD[j];
            for (int k = 0; k<100; k++)
            {
                m.createUndirectedRandomMatrix(D, h);
                t.start_time();
                m.Kruskal(false);
                t.stop_time();
                resultTimeM += t.time();

                l.createUndirectedRandomList(D, h);
                t.start_time();
                l.Kruskal(false);
                t.stop_time();
                resultTimeL += t.time();
            }
            cout<<"Koniec testow v = "<<h<<endl;
            file_output<<"Kruskal Matrix : "<<D<<" "<<h<<" "<<resultTimeM/100;
            file_output<<endl;
            resultTimeM = 0;

            file_output<<"Kruskal List : "<<D<<" "<<h<<" "<<resultTimeL/100;
            file_output<<endl;
            resultTimeL = 0;
        }
    }

    file_output.close();
    return;
}

// funkcja testow algorytmu Dijkstra
void Test :: testDijkstra()
{
    long long resultTimeM = 0;
    long long resultTimeL = 0;
    double D;
    int h;
    AdjacencyMatrix m;
    AdjacencyList l;
    Time t;
    fstream file_output;

    file_output.open("wyniki.txt", ios::out | ios::app);


    if (!file_output.is_open())
    {
        cout<< "Nie otworzono pliku zapisowego. Zakonczenie testow"<<endl;
        return;
    }

    for (int i = 0; i<5; i++)
    {
        h = tabV[i];
        for (int j = 0; j<4; j++)
        {
            D = tabD[j];
            for (int k = 0; k<100; k++)
            {
                m.createDirectedRandomMatrix(D, h);
                t.start_time();
                m.Dijkstra(false);
                t.stop_time();
                resultTimeM += t.time();

                l.createDirectedRandomList(D, h);
                t.start_time();
                l.Dijkstra(false);
                t.stop_time();
                resultTimeL += t.time();
            }
            cout<<"Koniec testow v = "<<h<<endl;
            file_output<<"Dijkstra Matrix : "<<D<<" "<<h<<" "<<resultTimeM/100;
            file_output<<endl;
            resultTimeM = 0;

            file_output<<"Dijkstra List : "<<D<<" "<<h<<" "<<resultTimeL/100;
            file_output<<endl;
            resultTimeL = 0;
        }
    }

    file_output.close();
    return;
}

// funkcja testow algorytmu Bellmana Forda
void Test :: testBellmanFord()
{
    long long resultTimeM = 0;
    long long resultTimeL = 0;
    double D;
    int h;
    AdjacencyMatrix m;
    AdjacencyList l;
    Time t;
    fstream file_output;

    file_output.open("wyniki.txt", ios::out | ios::app);


    if (!file_output.is_open())
    {
        cout<< "Nie otworzono pliku zapisowego. Zakonczenie testow"<<endl;
        return;
    }

    for (int i = 0; i<5; i++)
    {
        h = tabV[i];
        for (int j = 0; j<4; j++)
        {
            D = tabD[j];
            for (int k = 0; k<100; k++)
            {
                m.createDirectedRandomMatrix(D, h);
                t.start_time();
                m.BellmanFord(false);
                t.stop_time();
                resultTimeM += t.time();

                l.createDirectedRandomList(D, h);
                t.start_time();
                l.BellmanFord(false);
                t.stop_time();
                resultTimeL += t.time();
            }
            cout<<"Koniec testow v = "<<h<<endl;
            file_output<<"Bellman Ford Matrix : "<<D<<" "<<h<<" "<<resultTimeM/100;
            file_output<<endl;
            resultTimeM = 0;

            file_output<<"Bellman Ford List : "<<D<<" "<<h<<" "<<resultTimeL/100;
            file_output<<endl;
            resultTimeL = 0;
        }
    }

    file_output.close();
    return;
}
