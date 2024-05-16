#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

// Forward declaration of studentas class
class studentas;

extern int tlaikas;

void skaitymasisfailo(std::vector<studentas> &A, char budas, char ivedbudas);
void isvedimas(std::vector<studentas> &A, char budas);
void pazymiuived(studentas &new_studentas, char budas, int ivedbudas);
void skaiciavimas(studentas &new_studentas, int sum, char budas);
void irasymasifaila(std::vector<studentas> &A, char budas);
bool rikiavimasgbalas(const studentas &a, const studentas &b);
bool rikiavimasvardas(const studentas &a, const studentas &b);
bool rikiavimaspavarde(const studentas &a, const studentas &b);
void rikiavimas(std::vector<studentas> &A);
void skirstymas1(std::vector<studentas> &A, std::vector<studentas> &K, std::vector<studentas> &V);
void skirstymas2(std::vector<studentas> &A, std::vector<studentas> &V);
void skirstymas3(std::vector<studentas> &A, std::vector<studentas> &K, std::vector<studentas> &V);
void irasymasifailaK(std::vector<studentas> &A, std::vector<studentas> &K, std::vector<studentas> &V, char budas, int skistr);

#endif // FUNCTIONS_H