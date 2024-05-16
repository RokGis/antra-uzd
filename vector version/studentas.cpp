#include "studentas.h"
#include "errorfinder.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <cstdlib> // Add missing header for rand() function

using namespace std;
using namespace std::chrono;

studentas::studentas() : erez(0), gbalas(0.0) {}

studentas::studentas(const string& v, const string& p, const vector<int>& nd, int e, double g)
    : vardas(v), pavarde(p), ndrez(nd), erez(e), gbalas(g) {}

// Destructor
studentas::~studentas() {
    ndrez.clear();
}

// Copy constructor
studentas::studentas(const studentas& kit) 
    : vardas(kit.vardas), pavarde(kit.pavarde), ndrez(kit.ndrez), erez(kit.erez), gbalas(kit.gbalas) {}

// Copy assignment operator
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

// Move constructor
studentas::studentas(studentas&& kit) noexcept
    : vardas(std::move(kit.vardas)), pavarde(std::move(kit.pavarde)), ndrez(std::move(kit.ndrez)), erez(kit.erez), gbalas(kit.gbalas) {}

// Move assignment operator
studentas& studentas::operator=(studentas&& kit) noexcept {
    if (this != &kit) {
        vardas = std::move(kit.vardas);
        pavarde = std::move(kit.pavarde);
        ndrez = std::move(kit.ndrez);
        erez = kit.erez;
        gbalas = kit.gbalas;
    }
    return *this;
}

void studentas::skaiciavimas(double sum, char budas)
{
    for (int grade : ndrez) {
        sum += grade;
    }

    double vid, mediana;
    double galrez = 0;
    int tempsize = ndrez.size();
    if (tempsize == 0) {
        vid = 0;
        mediana = 0;
    }
    else {
        vid = sum / tempsize;
        sort(ndrez.begin(), ndrez.end());
        if (tempsize % 2 == 0) {
            mediana = (ndrez[tempsize / 2 - 1] + ndrez[tempsize / 2]) / 2.0;
        } else {
            mediana = ndrez[tempsize / 2];
        }
    }

    if (budas == 'v') {
        galrez = 0.4 * vid + 0.6 * erez;
    }
    else if (budas == 'm') {
        galrez = 0.4 * mediana + 0.6 * erez;
    }

    gbalas = galrez;
}

void studentas::pazymiuived(int ivedbudas) {
    int sum = 0;
    vector<int> pazymysVector;
    int pazymys;
    if (ivedbudas == 1){
        cout << "Iveskite studento namu darbu rezultata arba „11“, jeigu norite uzbaigti rezultatu vedima: " << endl;
    }

    while (true) {
        if (ivedbudas == 1) {
            pazymys = pazymiopatikra();
            if (pazymys == 11) {
                break;
            }                
        }
        if (ivedbudas == 2 || ivedbudas == 3) {
            pazymys = rand() % 12;
            if (pazymys == 11) {
                break;
            }
        }
        pazymysVector.push_back(pazymys); // pridedamas elementas i gala
        sum += pazymys;
    }
    int erez;
    if (ivedbudas == 1) {
        erez = erezpatikra();
    }
    if (ivedbudas == 2 || ivedbudas == 3) {
        erez = rand() % 11;
    }
    this->erez = erez;
    this->ndrez = pazymysVector;
}

bool rikiavimasgbalas(const studentas &a, const studentas &b)
{
    return a.getGbalas() > b.getGbalas();
}

bool rikiavimasvardas(const studentas &a, const studentas &b)
{
    return a.getVardas() < b.getVardas();
}

bool rikiavimaspavarde(const studentas &a, const studentas &b)
{
    return a.getPavarde() < b.getPavarde();
}

void rikiavimas(vector<studentas>& A)
{
    char rikbudas = rikbudpatikra();
    auto start = high_resolution_clock::now(); // Start measuring time

    if (rikbudas == 'b')
    {
        sort(A.begin(), A.end(), rikiavimasgbalas);
    }
    else if (rikbudas == 'v') {
        sort(A.begin(), A.end(), rikiavimasvardas);
    }
    else if (rikbudas == 'p') {
        sort(A.begin(), A.end(), rikiavimaspavarde);
    }

    auto stop = high_resolution_clock::now(); // Stop measuring time
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Rūšiavimas (sort) truko: " << duration.count() << " miliseconds" << endl;
}

istream &operator>>(istream &in, studentas &kit)
{
    vector<std::string> vardai = {"Jonas", "Vytautas", "Tomas", "Mindaugas", "Antanas", "Darius", "Rokas", "Matas", "Lukas"};

    vector<std::string> pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "Vaigauskas", "Gilys", "Gavenas", "Gruodis"};

    kit.ndrez.clear();
    string temp;
    int sum = 0;
    int ivedbudas;
    ivedbudas = ivedbudpatikra();

    if (ivedbudas != 4)
    {
        char budas;
        budas = budaspatikra();
        char duomskait;
        if (ivedbudas == 1 || ivedbudas == 2){
            duomskait = dskaitpatikra();
        }
        char ski;
        int skistr;

        vector<studentas> A; //sudaromas vektorius
        vector<studentas> K; 
        vector<studentas> V; 

        if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'f')
        {
            try {
                ifstream in("studentai10000.txt");
                if (!in.is_open()) {
                    throw runtime_error("Nepavyko atidaryti failo.");
                }

                string eil;
                getline(in, eil); // Skip the header line

                while (getline(in, eil)) {
                    int sum = 0;
                    istringstream my_buffer(eil);

                    if (ivedbudas == 1) {
                        my_buffer >> kit.vardas >> kit.pavarde;
                        int pazymys;
                        vector<int> pazymysVector;
                        while (my_buffer >> pazymys)
                        {
                            pazymysVector.push_back(pazymys); // prisikiriamas elSementas
                            sum += pazymys;
                        }

                        kit.erez = pazymysVector.back();
                        pazymysVector.pop_back();
                        sum -= kit.erez;
                        kit.ndrez = pazymysVector;
                        kit.skaiciavimas(sum, budas);
                        //out<<kit;
                    }
                }
                in.close();
            }
            catch (const runtime_error &e) {
                cerr << e.what() << endl;
                exit(EXIT_FAILURE);
            }
        }
        else if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'r')
        {
            while (true)
            {
            cout << "Įveskite studento vardą ir pavardę: ";
            in >> temp;
            if (temp == "11"){
                break;}
            kit.vardas = temp;
            in >> kit.pavarde;
            kit.pazymiuived(ivedbudas);
            kit.skaiciavimas(sum, budas);
            //out << kit;
            }
        }
        if (ivedbudas == 3)
        {
            int m;
            cout << "Iveskite studentu skaiciu: ";
            m = studskpatikra();

            A.resize(m); // nustatyti vektoriaus dydi

            for (int i = 0; i < m; i++)
            {
                kit.vardas = vardai[rand() % vardai.size()];
                kit.pavarde = pavardes[rand() % pavardes.size()];
                kit.pazymiuived(ivedbudas);
                kit.skaiciavimas(sum, budas);
               // out << kit;
            }
        };
        return in;
    }
    return in;
}

ostream& operator<<(ostream& out, const studentas &kit) {
    out << setw(25) << left << kit.vardas << setw(25) << left << kit.pavarde << setw(25) << left << fixed << setprecision(2) << kit.gbalas << endl;
    return out;
}