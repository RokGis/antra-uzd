#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#include "zmogus.h"
#include <vector>

class studentas : public zmogus {
private:
    std::vector<int> ndrez;
    int erez;
    double gbalas;

public:
    studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int e, double g)
        : zmogus(v, p), ndrez(nd), erez(e), gbalas(g) {}

    // Destructor
    virtual ~studentas();

    // Copy constructor
    studentas(const studentas& kit);

    // Copy assignment operator
    studentas& operator=(const studentas& kit);

    // Move constructor
    studentas(studentas&& kit) noexcept;

    // Move assignment operator
    studentas& operator=(studentas&& kit) noexcept;

    // Functions for getting ndrez, erez, and gbalas
    std::vector<int> getNdrez() const { return ndrez; }
    int getErez() const { return erez; }
    double getGbalas() const { return gbalas; }
      
      void setVardas(const string& v) { vardas = v; }
      void setPavarde(const string& p) { pavarde = p; }
      void setNdrez(const vector<int>& nd) { ndrez = nd; }
      void setErez(int e) { erez = e; }
      void setGbalas(double g) { gbalas = g; }                     // set'eriai

      void sortNdrez() { sort(ndrez.begin(), ndrez.end()); }
};

#endif // STUDENTAS_H
