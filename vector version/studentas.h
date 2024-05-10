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

      ~studentas(); // destruktorius

      studentas(const studentas& kit); // copy konstruktorius

      studentas& operator=(const studentas& kit); // priskyrimo operatorius

      studentas(studentas&& kit) noexcept; // move konstruktorius

      studentas& operator=(studentas&& kit) noexcept;

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

      // Overloaded << operator
      friend ostream& operator<<(ostream& out, const studentas &kit) {
          out << setw(25) << left << kit.vardas << setw(25) << left << kit.pavarde << setw(25) << left << fixed << setprecision(2) << kit.gbalas << endl;
          return out;
      }

      // Overloaded >> operator
      friend istream& operator>>(istream& in, studentas &kit) {
      cout << "Enter student's name: ";
      in >> kit.vardas;
      cout << "Enter student's surname: ";
      in >> kit.pavarde;

      // Read and store student's homework grades
      cout << "Enter student's homework grades (enter '11' to finish): ";
      int grade;
      while (in >> grade && grade != 11) {
          kit.ndrez.push_back(grade);
      }

      // Read and store student's exam grade
      cout << "Enter student's exam grade: ";
      in >> kit.erez;

      return in;
  }
      };

#endif // STUDENTAS_H
