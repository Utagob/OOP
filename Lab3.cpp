#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Rezervare{
    protected:
        string client;
        string data;
        string ora;
        int nrPers;
        int durRez = 2;
        int pret;
    public:
        Rezervare(){
            cout << "Rezervare adaugata." << endl;
        }
        ~Rezervare(){
            cout << "Rezervare stearsa." << endl;
        }
        void setRezervare(string a, string b, string c, int d){
            client = a;
            data = b;
            ora = c;
            nrPers = d;
        }
        string getClient(){
            return client;
        }
        string getData(){
            return data;
        }
        string getOra(){
            return ora;
        }
        int getNrPers(){
            return nrPers;
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

int main(){
    ifstream Fi("Rezervare.txt");
    string a, b, c;
    int d;
    vector<class Rezervare> R;
    Rezervare rez;
    
    if (!Fi.is_open()) {
        cout << "Error: could not open file!" << endl;
        return 1;
    }
    for(int i; i<3; i++){
        Fi >> a >> b >> c >> d;
        rez.setRezervare(a, b, c, d);
        R.push_back(rez);
    }
    cout << R[0].getClient() << endl;
    cout << R[1].getClient() << endl;
    cout << R[2].getClient() << endl;
    
    Fi.close();
    return 0;
}