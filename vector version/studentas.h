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
    Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int e, double g)
        : Zmogus(v, p), ndrez(nd), erez(e), gbalas(g) {}

    // Destructor
    virtual ~Studentas();

    // Copy constructor
    Studentas(const Studentas& other);

    // Copy assignment operator
    Studentas& operator=(const Studentas& other);

    // Move constructor
    Studentas(Studentas&& other) noexcept;

    // Move assignment operator
    Studentas& operator=(Studentas&& other) noexcept;

      string getVardas() const { return vardas; }                   // get'eriai
      string getPavarde() const { return pavarde; }                 // get'eriai
      vector<int> getNdrez() const { return ndrez; }
      int getErez() const { return erez; }
      double getGbalas() const { return gbalas; } // get'eriai
      
      void setVardas(const string& v) { vardas = v; }
      void setPavarde(const string& p) { pavarde = p; }
      void setNdrez(const vector<int>& nd) { ndrez = nd; }
      void setErez(int e) { erez = e; }
      void setGbalas(double g) { gbalas = g; }                     // set'eriai

    void sortNdrez() { sort(ndrez.begin(), ndrez.end()); }

  
};

#endif // STUDENTAS_H