#ifndef PROJECT_2_SDIZO_QHEAP_H
#define PROJECT_2_SDIZO_QHEAP_H

// struktura wierzcholka
struct Verticle
{
    int nr; // numer wierzcholak, z ktorym jest polaczony
    int cost; // koszt dotarcia do wierzcholka
};

// klasa struktury dla algorytmu Dijkstra
class QHeap
{

public:
    const int MAXINT = 2147483647;
    Verticle* queue; // wskaznik  na poczatek struktury
    int size; // rozmiar struktury

    QHeap(int len, int start);
    ~QHeap();
    void heap_fix_down();
    void heap_fix_up(int index);
    void change_cost(int nr, int cost);
    Verticle pop();

};
#endif
