#ifndef PROJECT_2_SDIZO_TEST_H
#define PROJECT_2_SDIZO_TEST_H

// klasa testu
class Test
{

public:
    int D; // pomocnicza wartosc gestosci
    int h; // pomocnicza wartosc wierzcholkow
    double tabD[4] = {0.25, 0.50, 0.75, 0.99}; // pomocnicza tablica gestosci
    int tabV[5] = {50, 100, 150, 300, 400}; // pomocnicza tablica wierzcholkow

    Test();
    ~Test();
    void testPrim();
    void testKruskal();
    void testDijkstra();
    void testBellmanFord();
};
#endif
