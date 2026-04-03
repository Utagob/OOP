#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class IRezervare{
    public:
        virtual int durataRezervarii(){return 0;}
        virtual int pretCalc(){return 0;}
        virtual ~IRezervare(){}
};

class Rezervare : public IRezervare{
    protected:
        string tipRezervare, client, data;
        int oraIntrare, minuteIntrare, oraIesire, minuteIesire, nrPers;
    public:
        Rezervare(string z, string a, string b, int c, int d, int e, int f, int g){
            tipRezervare = z;
            client = a;
            data = b; 
            oraIntrare = c; 
            minuteIntrare = d;
            oraIesire = e; 
            minuteIesire = f; 
            nrPers = g;
            cout << "Rezervare adaugata." << endl;
        }
        virtual ~Rezervare(){}
        string getTipRezervare(){return tipRezervare;}
        string getClient(){return client;}
        string getData(){return data;}
        int getOraIntrare(){return oraIntrare;}
        int getMinuteIntrare(){return minuteIntrare;}
        int getOraIesire(){return oraIesire;}
        int getMinuteIesire(){return minuteIesire;}
        int getNrPers(){return nrPers;}

        virtual void afiseazaInfo(){
            cout << endl;
            cout << "=====================================================" << endl;
            cout << "Tip rezervare: " << getTipRezervare() << endl;
            cout << "   Nume: " << getClient() << endl;
            cout << "   Data: " << getData() << endl;
            cout << "   Ora: " << getOraIntrare() << ":" << getMinuteIntrare() << " -> "
                << getOraIesire() << ":" << getMinuteIesire() << endl;
            cout << "   Rezervat pentru: " << durataRezervarii() << " ore" << endl;
            cout << "   Numarul de persoane: " << getNrPers() << endl;
            cout << "   Pretul rezervarii: " << pretCalc() << "lei" << endl;
            cout << "=====================================================" << endl;
        }

        int pretCalc() override{
            int pret = nrPers * 30;
            return pret;
        }

        int durataRezervarii() override{
            int intrare, iesire, durata;
            intrare = oraIntrare*3600 + minuteIntrare*60;
            iesire = oraIesire*3600 + minuteIesire*60;
            durata = (iesire-intrare)/60;
            if(durata % 60 != 0)durata = durata/60+1;
            else durata /= 60;
            return durata;
        }
};

class RezervareZilnica : public Rezervare{
    public:
        RezervareZilnica(string z, string a, string b, int c, int d, int e, int f, int g) 
            : Rezervare(z, a, b, c, d, e, f, g){cout << "Tip: Zilnica." << endl;}
        int pretCalc() override{
            int pret;
            if(nrPers > 2) pret = 50 + 20 * (nrPers - 2);
            else pret = 50;
            return pret;
        }
};

class RezervareOcazieSpeciala : public Rezervare{
    public:
        RezervareOcazieSpeciala(string z, string a, string b, int c, int d, int e, int f, int g) 
            : Rezervare(z, a, b, c, d, e, f, g){cout << "Tip: Ocazie speciala" << endl;}
        int pretCalc() override{
            int pret;
            if(durataRezervarii()>2) pret = 200 + 60 * (durataRezervarii() - 2);
            else pret = 200;
            return pret;
        }
};

class RezervareGrupMare : public Rezervare{
    public:
        RezervareGrupMare(string z, string a, string b, int c, int d, int e, int f, int g) 
            : Rezervare(z, a, b, c, d, e, f, g){cout << "Tip: Grup mare" << endl;}
        int pretCalc() override{
            int pret;
            if(nrPers>20) pret = 500 + 10 * (nrPers - 20);
            else pret = 500;
            if(nrPers>30) pret *=0.85; 
            return pret;
        }
};

class RezervareVIP : public Rezervare{
    public:
        RezervareVIP(string z, string a, string b, int c, int d, int e, int f, int g)
            : Rezervare(z, a, b, c, d, e, f, g){cout << "Tip: VIP." << endl;}
        int pretCalc() override{
            int pret;
            if(nrPers>5) pret = 1000 + 200*(nrPers-5);
            else pret = 1000;
            pret *= durataRezervarii();
            return pret;
        }
};

void afiseaza(vector<Rezervare*> R){
    for(int i=0; i<R.size(); i++){
        R.at(i)->afiseazaInfo();
        delete R.at(i);
    }
}

int main(){
    ifstream Fi("Rezervare.txt");
    if(!Fi){
        cout << "Eroare: fisierul nu a fost gasit!" << endl;
        return 1;
    }

    vector<Rezervare*> R;    
    string z, a, b, c, d;
    int e;
    
    while(Fi >> z >> a >> b >> c >> d >> e){
        if(z == "RezervareZilnica"){
            R.push_back(new RezervareZilnica(z, a, b, stoi(c.substr(0, 2)), stoi(c.substr(3, 2)), stoi(d.substr(0, 2)), stoi(d.substr(3, 2)), e));
        } else if(z == "RezervareOcazieSpeciala"){
            R.push_back(new RezervareOcazieSpeciala(z, a, b, stoi(c.substr(0, 2)), stoi(c.substr(3, 2)), stoi(d.substr(0, 2)), stoi(d.substr(3, 2)), e));
        } else if(z == "RezervareGrupMare"){
            R.push_back(new RezervareGrupMare(z, a, b, stoi(c.substr(0, 2)), stoi(c.substr(3, 2)), stoi(d.substr(0, 2)), stoi(d.substr(3, 2)), e));
        } else if(z == "RezervareVIP"){
            R.push_back(new RezervareVIP(z, a, b, stoi(c.substr(0, 2)), stoi(c.substr(3, 2)), stoi(d.substr(0, 2)), stoi(d.substr(3, 2)), e));
        }  
    }
    afiseaza(R);

    Fi.close();
    return 0;
}
