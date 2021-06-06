#ifndef PROJECT_2_SDIZO_ADJACENCYMATRIX_H
#define PROJECT_2_SDIZO_ADJACENCYMATRIX_H

#include <string>


using namespace std;

// Klasa reprezentacji macierzy sasiedztwa
class AdjacencyMatrix
{

private:
    const int MAXINT = 2147483647;
    int v; // liczba wierzcholkow
    int e; // liczba krawedzi
    int** matrix; // macierz grafu

    // elementy pomocnicze
    int** resultsEdge; // krawedzie (wierzcholek poczatkowy i koncowy)
    int* weights; // wagi krawedzi
    int startV; // poczatkowy wierzcholek
    int finishV; // koncowy wierzcholek
    long long* cost; // odleglosc z startV do okreslonego wierzcholka
    int* path; // sciezka

public:
    AdjacencyMatrix();
    ~AdjacencyMatrix();
    void readFile(string file_input);
    void createDirectedMatrix();
    void createUndirectedMatrix();
    void createDirectedRandomMatrix(double d, int n);
    void createUndirectedRandomMatrix(double d, int n);
    void print();
    void printResultsMST();
    void printResults();
    void Prim(bool print);
    void Kruskal(bool print);
    void Dijkstra(bool print);
    bool BellmanFord(bool print);

};
#endif
