#ifndef PROJECT_2_SDIZO_HEAP_H
#define PROJECT_2_SDIZO_HEAP_H

// struktura krawedzi
struct Edge
{
    int beg; // wierzcholek poczatkowy
    int end; // wierzcholek koncowy
    int weight; // waga krawedzi
};

// klasa kolejki priorytetowej
class Heap
{

private:
    Edge *heap; // wskaznik na poczatek kolejki
    int size; // rozmiar kolejki

public:
    Heap();
    ~Heap();
    Edge getFront();
    void add_front(Edge value);
    void remove();
    int getSize();
    int getParent(int i);

};
#endif
