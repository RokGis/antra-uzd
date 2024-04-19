#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class studentas {
// realizacija
private:
  string vardas;
  string pavarde;
  vector<int> ndrez;
  int erez;
  double gbalas;
  // interfeisas
  public:
      studentas(); // default konstruktorius
      studentas(const string& v, const string& p, const vector<int>& nd, int e, double g);

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

      void sortNdrez() {
    sort(ndrez.begin(), ndrez.end());
}
      ~studentas() { ndrez.clear(); }
      
};

class rule_of_five
{
    char* cstring; // raw pointer used as a handle to a
                   // dynamically-allocated memory block
public:
    explicit rule_of_five(const char* s = "") : cstring(nullptr)
    { 
        if (s)
        {
            std::size_t n = std::strlen(s) + 1;
            cstring = new char[n];      // allocate
            std::memcpy(cstring, s, n); // populate 
        } 
    }
 
    ~rule_of_five()
    {
        delete[] cstring; // deallocate
    }
 
    rule_of_five(const rule_of_five& other) // copy constructor
        : rule_of_five(other.cstring) {}
 
    rule_of_five(rule_of_five&& other) noexcept // move constructor
        : cstring(std::exchange(other.cstring, nullptr)) {}
 
    rule_of_five& operator=(const rule_of_five& other) // copy assignment
    {
        return *this = rule_of_five(other);
    }
 
    rule_of_five& operator=(rule_of_five&& other) noexcept // move assignment
    {
        std::swap(cstring, other.cstring);
        return *this;
    }
 
// alternatively, replace both assignment operators with 
//  rule_of_five& operator=(rule_of_five other) noexcept
//  {
//      std::swap(cstring, other.cstring);
//      return *this;
//  }
};
#endif // STUDENTAS_H
