#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct studentas
{
    string vardas;
    string pavarde;
    list<int> ndrez; //sudaromas vektorius
    int erez;
    double gbalas;
};

extern int tlaikas;

void skaitymasisfailo(list<studentas> &A, char budas, char ivedbudas);
void isvedimas(list<studentas> &A, char budas);
void pazymiuived(studentas &new_studentas, char budas, int ivedbudas);
void skaiciavimas(studentas &new_studentas, int sum, char budas);
void irasymasifaila(list<studentas> &A, char budas);
bool rikiavimasgbalas(const studentas &a, const studentas &b);
bool rikiavimasvardas(const studentas &a, const studentas &b);
bool rikiavimaspavarde(const studentas &a, const studentas &b);
void rikiavimas(list<studentas> &A);
void skirstymas1(list<studentas> &A, list<studentas> &K, list<studentas> &V);
void skirstymas2(list<studentas> &A, list<studentas> &V);
void skirstymas3(list<studentas> &A, list<studentas> &K, list<studentas> &V);
void irasymasifailaK(list<studentas> &A, list<studentas> &K, list<studentas> &V, char budas, int skistr);