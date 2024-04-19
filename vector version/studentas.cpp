#include "studentas.h"
#include <utility>

studentas::studentas() : erez(0), gbalas(0.0) {}

studentas::studentas(const string& v, const string& p, const vector<int>& nd, int e, double g)
    : vardas(v), pavarde(p), ndrez(nd), erez(e), gbalas(g) {}

// Destructor
studentas::~Studentas() {}

// Copy constructor
studentas::Studentas(const studentas& kit)
    : zmogus(kit), ndrez(kit.ndrez), erez(kit.erez), gbalas(kit.gbalas) {}

// Copy assignment operator
studentas& studentas::operator=(const studentas& kit) {
    if (this != &kit) {
        zmogus::operator=(kit); // Call base class assignment operator
        ndrez = kit.ndrez;
        erez = kit.erez;
        gbalas = kit.gbalas;
    }
    return *this;
}

// Move constructor
studentas::studentas(studentas&& kit) noexcept
    : zmogus(std::move(kit)), ndrez(std::move(kit.ndrez)), erez(kit.erez), gbalas(kit.gbalas) {}

// Move assignment operator
studentas& studentas::operator=(studentas&& kit) noexcept {
    if (this != &kit) {
        zmogus::operator=(std::move(kit)); // Call base class move assignment operator
        ndrez = std::move(kit.ndrez);
        erez = kit.erez;
        gbalas = kit.gbalas;
    }
    return *this;
}