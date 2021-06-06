#ifndef PROJECT_2_SDIZO_ADJACENCYLIST_H
#define PROJECT_2_SDIZO_ADJACENCYLIST_H

#include <string>


using namespace std;

// struktura listy
struct List
{
    List* next; // wskaznik na nastepny element
    int n; // numer wezla docelowego
    int weight; // waga elementu
};

// Klasa reprezentacji listy sasiedztwa
class AdjacencyList
{

private:
    const int MAXINT = 2147483647;
    int v; // liczba wierzcholkow
    int e; // liczba krawedzi
    List** list; // lista sasiedztwa

    // elementy pomocnicze
    List* help; // lista pomocnicza
    int** resultsEdge; // krawedzie (wierzcholek poczatkowy i koncowy)
    int* weights; // wagi krawedzi
    int startV; // poczatkowy wierzcholek
    int finishV; // wierzcholek koncowy
    long long* cost; // odleglosc z startV do okreslonego wierzcholka
    int* path; // sciezka jako sekwencja wierzcholkow

public:
    AdjacencyList();
    ~AdjacencyList();
    void createDirectedList();
    void createUndirectedList();
    void createDirectedRandomList(double d, int n);
    void createUndirectedRandomList(double d, int n);
    void readFile(string file_input);
    void print();
    void printResultsMST();
    void printResults();
    void Prim(bool print);
    void Kruskal(bool print);
    void Dijkstra(bool print);
    bool BellmanFord(bool print);

};
#endif
