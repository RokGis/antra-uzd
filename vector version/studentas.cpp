#include "studentas.h"
#include <utility>

studentas::studentas() : erez(0), gbalas(0.0) {}

studentas::studentas(const string& v, const string& p, const vector<int>& nd, int e, double g)
    : vardas(v), pavarde(p), ndrez(nd), erez(e), gbalas(g) {}

// destruktorius
studentas::~studentas() {
ndrez.clear();}

// copy konstruktorius
studentas::studentas(const studentas& kit) 
    : vardas(kit.vardas), pavarde(kit.pavarde), ndrez(kit.ndrez), erez(kit.erez), gbalas(kit.gbalas) {}
