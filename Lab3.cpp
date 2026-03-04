#include <iostream>
#include <string>
using namespace std;

class Rezervare{
    protected:
        string Client;
        string data;
        string ora;
        int nrPers;
        int durRez = 2;
        int pret;
    public:
        Rezervare(){
            cout << "Rezervare adaugata.";
        }
        ~Rezervare(){
            cout << "Rezervare stearsa." << endl;
        }
        void durataRez(){
            cout << "Durata rezervarii: " << durRez << "ore" << endl;
        }
        void pretCalc(){
            pret = nrPers * 30;
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};

class Zilnica : public Rezervare{
    public:
        Zilnica(){
            cout << "Tip: Zilnica." << endl;
        }
        void pretCalc(){
            pret = 50 + 20 * (nrPers - 2);
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};

class OcazieSpeciala : public Rezervare{
    public:
        OcazieSpeciala(){
            cout << "Tip: Ocazie speciala" << endl;
        }
        void pretCalc(){
            pret = 200 + 60 * (durRez - 2);
            cout << "Pretul rezarvarii: " << pret << "lei" << endl; 
        }
};

class GrupMare : public Rezervare{
    public:
        GrupMare(){
            cout << "Tip: Grup mare" << endl;
        }
        void pretCalc(){
            pret = 500 + 10 * (nrPers - 20);
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};

class VIP : public Rezervare{
    public:
        VIP(){
            cout << "Tip: VIP" << endl;
        }
        void pretCalc(){
            pret = 1000;
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};