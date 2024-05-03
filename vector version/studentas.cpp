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

// priskyrimo operatorius
studentas& studentas::operator=(const studentas& kit) {
    if (this != &kit) {
        vardas = kit.vardas;
        pavarde = kit.pavarde;
        ndrez = kit.ndrez;
        erez = kit.erez;
        gbalas = kit.gbalas;
    }
    return *this;
}

// move konstruktorius
studentas::studentas(studentas&& kit) noexcept
    : vardas(move(kit.vardas)), pavarde(move(kit.pavarde)), ndrez(move(kit.ndrez)), erez(kit.erez), gbalas(kit.gbalas)
    {
        kit.vardas.clear();
        kit.pavarde.clear();
        kit.ndrez.clear();
        kit.erez = 0;
        kit.gbalas = 0.0;
    }

// priskyrimo operatorius
studentas& studentas::operator=(studentas&& kit) noexcept {
    if (this != &kit) {
        vardas = move(kit.vardas);
        pavarde = move(kit.pavarde);
        ndrez = move(kit.ndrez);
        erez = kit.erez;
        gbalas = kit.gbalas;
        kit.vardas.clear();
        kit.pavarde.clear();
        kit.ndrez.clear();
        kit.erez = 0;
        kit.gbalas = 0.0;
    }
    return *this;
}