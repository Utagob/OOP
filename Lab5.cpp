#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cont{
    protected:
        int ID;
        string nume;
        float sold;
        vector<string> tranzactie;

    public:
        Cont(){
            ID = 0;
            nume = " ";
            sold = 0;
            tranzactie = {};
        }
        Cont(int a, string b, float c, vector<string> d){
            ID = a; nume = b; sold = c; tranzactie = d;
        }
        ~Cont(){}

        void setId(int x){ID = x;}
        void setNume(string x){nume = x;}
        void setSold(float x){sold = x;}
        void setTranzactie(vector<string> x){tranzactie = x;}

        int getID(){return ID;}
        string getNume(){return nume;}
        float getSold(){return sold;}
        vector<string> getTranzactie(){return tranzactie;}
        string getTranzactieI(int i){return tranzactie[i];}

        void depuneBani(float suma){
            sold += suma;
            cout << "Depunerea a fost efectuata cu succes" << endl;
            cout << endl;
            string s;
            char buf[100];
            snprintf(buf, sizeof(buf), "Depunere bani -> suma: %.2f => sold: %.2f", suma, sold);
            s = buf;
            tranzactie.push_back(s);
        }

        void retrageBani(float suma){
            if(suma <= sold){
                sold -= suma;
                cout << "Extragerea a fost efectuata cu succes" << endl;
                cout << endl;
                string s;
                char buf[100];
                snprintf(buf, sizeof(buf), "Retragere bani -> suma: %.2f => sold: %.2f", suma, sold);
                s = buf;
                tranzactie.push_back(s);
            } else {
                cout << "Fonduri insuficiente" << endl << endl;
            }
        }

        void trimiteBani(int idDestinatie, vector<Cont> &C){
            for(int i=0; i<C.size(); i++){
                if(idDestinatie == C[i].getID()){
                    float suma;
                    cout << "Introduceti suma pentru transfer" << endl;
                    cout << "Suma: "; cin >> suma;
                    if(suma <= sold){
                        sold -= suma;
                        C[i].setSold(C[i].getSold() + suma);
                        cout << "Transferul a fost efectuata cu succes" << endl << endl;
                        string s;
                        char buf[100];
                        snprintf(buf, sizeof(buf), "Transfer -> persoana: %s -> suma -> %.2f", C[i].getNume().c_str(), suma);
                        s = buf;
                        tranzactie.push_back(s);
                    } else {
                        cout << "Fonduri insuficiente" << endl << endl;
                    }
                    return;
                }
            }
            cout << "ID invalid." << endl << endl;
        }

        void verificaSold(){
            cout << "Sold: " << sold << endl;
            cout << endl;
        }

        void vizualizeazaTranzactii(){
            for(int i = 0; i < tranzactie.size(); i++){
                cout << i+1 << ") " << tranzactie[i] << endl;
            }
            cout << endl;
        }

        void blocheazaCont(int a, vector<Cont> &C){
            for(int i=0; i<C.size(); i++){
                if(C[i].getID() == a){
                    C.erase(C.begin() + i);
                    cout << "Contul a fost sters" << endl;
                    cout << endl;
                    break;
                }
            }
        }
};

void citire(ifstream &Fi, vector<Cont> &C){
    int a; string b; float c; int n;
    while(Fi >> a){
        Fi >> b;
        Fi >> c;
        Fi >> n;
        Fi.ignore();
        vector<string> d;
        for(int i = 0; i < n; i++){
            string line;
            getline(Fi, line);
            d.push_back(line);
        }
        C.push_back(Cont(a, b, c, d));
    }
    Fi.close();
}

void scriere(ofstream &Fo, vector<Cont> &C){
    for(int i = 0; i < C.size(); i++){
        Fo << C[i].getID() << '\n';
        Fo << C[i].getNume() << '\n';
        Fo << C[i].getSold() << '\n';
        int n = C[i].getTranzactie().size();
        Fo << n << '\n';
        for(int j = 0; j < n; j++){
            Fo << C[i].getTranzactieI(j) << '\n';
        }
    }
    Fo.close();
}

void interfata(int a, vector<Cont> &C){
    int x;
    do{
        cout << "ATM (Detinator: " << C[a].getNume() << ")" << endl;
        cout << "1 => Depunere numerar" << endl;
        cout << "2 => Extragere numerar" << endl;
        cout << "3 => Transfer numerar catre alt cont" << endl;
        cout << "4 => Afisarea soldului" << endl;
        cout << "5 => Istoria tranzactiilor" << endl;
        cout << "6 => Blocheaza contul" << endl << endl;
        cout << "0 => Iesire" << endl;
        cout << "Actiune: ";
        cin >> x;
        cout << endl;
        switch(x){
            case 0:{
                cout << endl;
                return;
            }
            case 1:{
                float y;
                cout << "Introduceti suma de depunere" << endl;
                cout << "Suma: "; cin >> y;
                C[a].depuneBani(y);
                ofstream Fo("conturi.txt");
                scriere(Fo, C);
                break;
            }
            case 2:{
                float y;
                cout << "Introduceti suma pentru extragere" << endl;
                cout << "Suma: "; cin >> y;
                C[a].retrageBani(y);
                ofstream Fo("conturi.txt");
                scriere(Fo, C);
                break;
            }
            case 3:{
                int y;
                cout << "Introduceti ID-ul contului destinat" << endl;
                cout << "ID: "; cin >> y;
                if(y == C[a].getID()){
                    cout << "ID invalid" << endl;
                    return;
                }
                C[a].trimiteBani(y, C);
                ofstream Fo("conturi.txt");
                scriere(Fo, C);
                break;
            }
            case 4:{
                C[a].verificaSold();
                break;
            }
            case 5:{
                C[a].vizualizeazaTranzactii();
                break;
            }
            case 6:{
                C[a].blocheazaCont(C[a].getID(), C);
                ofstream Fo("conturi.txt");
                scriere(Fo, C);
                return;
            }
            default: cout << "Operatie nevalida" << endl;
        }
    }while(true);
}

void inregistrare(vector<Cont> &C){
    Cont A;
    int a; string b;
    cout << "Creati un ID" << endl;
    cout << "ID: "; cin >> a;
    for(int i=0; i<C.size(); i++){
        if(a == C[i].getID()){
            cout << "Cont cu ID-ul oferit deja exista" << endl << endl;
            return;
        }
    }
    cout << "Introduceti numele dumneavoastra" << endl;
    cout << "Nume: "; cin >> b;
    A.setId(a);
    A.setNume(b);
    C.push_back(A);
    cout << endl;
    interfata(C.size()-1, C);
}

void autentificare(vector<Cont> &C){
    int id, index = -1;
    cout << "Introduceti ID-ul contului: ";
    cin >> id;
    for (int i = 0; i < C.size(); i++) 
        if (C[i].getID() == id) { index = i; break; }
    if (index != -1) interfata(index, C);
    else {
        cout << "Date gresite" << endl;
        cout << endl;
    }
}

void menu(vector<Cont> &C){
    int x;
    do{
        cout << "ATM" << endl;
        cout << "1) Inregistrare" << endl;
        cout << "2) Autentificare" << endl << endl;
        cout << "0) Iesire" << endl;
        cout << "Actiune: ";
        cin >> x;
        cout << endl;
        switch(x){
            case 0:{
                return;
            }
            case 1:{
                inregistrare(C);
                break;
            }
            case 2:{
                autentificare(C);
                break;
            }
            default: cout << "Operatie nevalida" << endl;
        }
    }while(true); 
}

int main(){
    vector<Cont> C;

    ifstream Fi("conturi.txt");
    citire(Fi, C);

    menu(C);

    ofstream Fo("conturi.txt");
    scriere(Fo, C);

    return 0;
}