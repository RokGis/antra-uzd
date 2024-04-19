#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class zmogus {
protected:
    std::string vardas;
    std::string pavarde;

public:
    zmogus(const std::string& v, const std::string& p)
        : vardas(v), pavarde(p) {}

    virtual ~zmogus() {}

    virtual std::string getVardas() const { return vardas; }
    virtual std::string getPavarde() const { return pavarde; }

};

#endif
