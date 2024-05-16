#include "functions.h"
#include "errorfinder.h"
#include"filegenerator.h"
#include "studentas.h"

int main()
{
    // vector<std::string> vardai = {"Jonas", "Vytautas", "Tomas", "Mindaugas", "Antanas", "Darius", "Rokas", "Matas", "Lukas"};

    // vector<std::string> pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "Vaigauskas", "Gilys", "Gavenas", "Gruodis"};

    // srand(time(nullptr));

    // string vardas;
    // string pavarde;
    // failugeneravimas();
    // int ivedbudas;
    // ivedbudas = ivedbudpatikra();
    
    // if (ivedbudas != 4)
    // {
    //     char budas;
    //     budas = budaspatikra();
    //     char duomskait;
    //     if (ivedbudas == 1 || ivedbudas == 2){
    //         duomskait = dskaitpatikra();
    //     }
    //     char ski;
    //     int skistr;


    //     if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'f')
    //     {
    //         skaitymasisfailo(A, budas, ivedbudas);
    //         rikiavimas(A);
    //         ski = skirstymopatikra();
    //         if (ski == 't')
    //         {
    //             skistr = skirststratpat();
    //             if (skistr == 1) {skirstymas1(A, K, V);}
    //             if (skistr == 2) {skirstymas2(A, V);}
    //             if (skistr == 3) {skirstymas3(A, K, V);}
    //             irasymasifailaK(A, K, V, budas, skistr);
    //         }
    //         else if (ski == 'n')
    //         {
    //             isvedimas(A, budas);
    //         }
            
    //     }

    //     else if ((ivedbudas == 1 || ivedbudas == 2) && duomskait == 'r')
    //     {
    //         while (true)
    //         {
    //             studentas new_studentas;
    //             cout << "Iveskite studento varda ir pavarde arba „11“, jeigu norite uzbaigti studentu vedima: ";
    //             cin >> vardas;
    //             if (vardas == "11"){
    //                 break;}
    //             new_studentas.setVardas(vardas);
    //             cin >> pavarde;
    //             new_studentas.setPavarde(pavarde);
    //             pazymiuived(new_studentas, budas, ivedbudas);
    //             A.push_back(new_studentas); // pridedamas elementas i gala 
    //         }
    //         rikiavimas(A);
    //         ski = skirstymopatikra();
    //         if (ski == 't')
    //         {
    //             skistr = skirststratpat();
    //             if (skistr == 1) {skirstymas1(A, K, V);}
    //             if (skistr == 2) {skirstymas2(A, V);}
    //             if (skistr == 3) {skirstymas3(A, K, V);}
    //             irasymasifailaK(A, K, V, budas, skistr);
    //         }
    //         else if (ski == 'n')
    //         {
    //             isvedimas(A, budas);
    //         }
    //     }
        
    //     if (ivedbudas == 3)
    //     {
    //         int m;
    //         cout << "Iveskite studentu skaiciu: ";
    //         m = studskpatikra();

    //         A.resize(m); // nustatyti vektoriaus dydi

    //         for (int i = 0; i < m; i++)
    //         {
    //             studentas new_studentas;
    //             new_studentas.setVardas(vardai[rand() % vardai.size()]);
    //             new_studentas.setPavarde(pavardes[rand() % pavardes.size()]);
    //             pazymiuived(new_studentas, budas, ivedbudas);
    //             A[i] = new_studentas;
    //         }
    //         rikiavimas(A);
    //         ski = skirstymopatikra();
    //         if (ski == 't')
    //         {
    //             skistr = skirststratpat();
    //             if (skistr == 1) {skirstymas1(A, K, V);}
    //             if (skistr == 2) {skirstymas2(A, V);}
    //             if (skistr == 3) {skirstymas3(A, K, V);}
    //             irasymasifailaK(A, K, V, budas, skistr);
    //         }
    //         else if (ski == 'n')
    //         {
    //             isvedimas(A, budas);
    //         }
    //     }
    // }
    // else {return 0;}
    // return 0;
            vector<studentas> A; //sudaromas vektorius
            vector<studentas> K; 
            vector<studentas> V;
            char budas = 'v';
            studentas D;
            cin >> D;
            A.push_back(D); // save studentas data in vector A

            for (int i = 0; i < A.size(); i++)
            {
                cout << setw(25) << left << A[i].getVardas() << setw(25) << left << A[i].getPavarde() << setw(25) << left << fixed << setprecision(2) << A[i].getGbalas() << endl;
            }
}