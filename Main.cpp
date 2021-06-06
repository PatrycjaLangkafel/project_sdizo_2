#include <iostream>
#include <string>
#include "Test.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"


using namespace std;

int main()
{
    int menu = 333;
    int choice = 333;
    string name_file;
    Test t;
    AdjacencyList l;
    AdjacencyMatrix m;

    while(menu)
    {
        cout << "MENU: " << endl;
        cout << "1. Testy Automatyczne" << endl;
        cout << "2. Testy Struktur" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Twoj wybor: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            while(choice)
            {
                cout << "MENU dla Testow Automatycznych: " << endl;
                cout << "1. Algorytm Prima" << endl;
                cout << "2. Algorytm Kruskala" << endl;
                cout << "3. Algorytm Dijkstra" << endl;
                cout << "4. Algorytm Bellmana Forda" << endl;
                cout << "0. Wyjscie" << endl;
                cout << "Twoj wybor: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    t.testPrim();
                    break;

                case 2:
                    t.testKruskal();
                    break;

                case 3:
                    t.testDijkstra();
                    break;

                case 4:
                    t.testBellmanFord();
                    break;

                case 0:
                    return 0;
                }
            }
            break;

        case 2:
            while(choice)
            {
                cout << "MENU dla Testow Struktur: " << endl;
                cout << "1. Algorytm Prima i Kruskala" << endl;
                cout << "2. Algorytm Dijkstra i Bellmana Forda" << endl;
                cout << "0. Wyjscie" << endl;
                cout << "Twoj wybor: ";
                cin >> choice;


                switch (choice)
                {
                case 1:
                    while(choice)
                    {
                        cout << "MENU: " << endl;
                        cout << "1. Wczytanie grafu z pliku" << endl;
                        cout << "2. Wyswietlenie grafu macierzowo i listowo" << endl;
                        cout << "3. Algorytm Prima" << endl;
                        cout << "4. Algorytm Kruskala" << endl;
                        cout << "0. Wyjscie" << endl;
                        cout << "Twoj wybor: ";
                        cin >> choice;

                        switch (choice)
                        {
                        case 1:
                            cout << "Podaj nazwe pliku : ";
                            cin >> name_file;

                            m.readFile(name_file);
                            l.readFile(name_file);
                            m.createUndirectedMatrix();
                            l.createUndirectedList();
                            break;

                        case 2:
                            cout << "Wyswietlam grafy macierzowo i listowo " << endl;
                            m.print();
                            l.print();
                            break;

                        case 3:
                            cout << "Algorytm Prima : Wyniki : " << endl;
                            cout << "Macierzowo: " << endl;
                            m.Prim(true);

                            cout << "Listowo: " << endl;
                            l.Prim(true);
                            break;

                        case 4:
                            cout << "Algorytm Kruskala : Wyniki : " << endl;
                            cout << "Macierzowo: " << endl;
                            m.Kruskal(true);

                            cout << "Listowo: " << endl;
                            l.Kruskal(true);
                            break;

                        case 0:
                            return 0;
                            break;
                        default:
                            cout << "Podales/as zla liczbe. dokanaj wyboru jeszcze raz. " << endl;
                            break;
                        }
                    }
                    break;

                case 2:
                    while(choice)
                    {
                        cout << "MENU: " << endl;
                        cout << "1. Wczytanie grafu z pliku" << endl;
                        cout << "2. Wyswietlenie grafu macierzowo i listowo" << endl;
                        cout << "3. Algorytm Dijkstra" << endl;
                        cout << "4. Algorytm Bellmana Forda" << endl;
                        cout << "0. Wyjscie" << endl;
                        cout << "Twoj wybor: ";
                        cin >> choice;

                        switch (choice)
                        {
                        case 1:
                            cout << "Podaj nazwe pliku : ";
                            cin >> name_file;

                            m.readFile(name_file);
                            l.readFile(name_file);
                            m.createDirectedMatrix();
                            l.createDirectedList();
                            break;

                        case 2:
                            cout << "Wyswietlam grafy macierzowo i listowo " << endl;
                            m.print();
                            l.print();
                            break;

                        case 3:
                            cout << "Algorytm Dijkstra : Wyniki : " << endl;
                            cout << "Macierzowo: " << endl;
                            m.Dijkstra(true);

                            cout << "Listowo: " << endl;
                            l.Dijkstra(true);
                            break;

                        case 4:
                            cout << "Algorytm Bellmana Forda : Wyniki : " << endl;
                            cout << "Macierzowo: " << endl;
                            m.BellmanFord(true);

                            cout << "Listowo: " << endl;
                            l.BellmanFord(true);
                            break;

                        case 0:
                            return 0;
                            break;
                        default:
                            cout << "Podales/as zla liczbe. dokanaj wyboru jeszcze raz. " << endl;
                            break;
                        }
                    }
                    break;

                case 0:
                    return 0;
                    break;
                default:
                    cout << "Podales/as zla liczbe. dokanaj wyboru jeszcze raz. " << endl;
                    break;
                }
            }
            break;

        case 0:
            return 0;
            break;

        default:
            cout << "Podales/as zla liczbe. dokanaj wyboru jeszcze raz. " << endl;
            break;
        }
    }

    return 0;
}
