#ifndef PROJECT_2_SDIZO_NODESET_H
#define PROJECT_2_SDIZO_NODESET_H

#include "Heap.h"

// struktura zbiorow rozlacznych
struct Node
{
    int up; // zbior elementu
    int rank; // ranga obiektu
};

// klasa obiektu struktury zbiorow rozlacznych
class NodeSet
{

private:
    Node* set; // obiekt

public:
    NodeSet(int n);
    ~NodeSet();
    void makeSet(int value);
    int findSet(int value);
    void unionSet(Edge e);

};
#endif
