#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class Zmogus {
protected:
    std::string vardas;
    std::string pavarde;

public:
    Zmogus(const std::string& v, const std::string& p)
        : vardas(v), pavarde(p) {}

    virtual ~Zmogus() {}

    virtual std::string getVardas() const { return vardas; }
    virtual std::string getPavarde() const { return pavarde; }

};

#endif
