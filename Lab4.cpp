#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class IRezervare{
    public:
        virtual void afiseazaInfo() = 0;
        virtual void pretCalc() = 0;
        virtual ~IRezervare(){};
};

class Rezervare : public IRezervare{
    protected:
        string tipRezervare, client, data;
        int oraIntrare, minuteIntrare, oraIesire, minuteIesire, nrPers, pret;
    public:
        Rezervare(){cout << "Rezervare adaugata." << endl;}
        virtual ~Rezervare(){cout << "Rezervare stearsa." << endl;}
        void setTipRezervare(string x){tipRezervare = x;}
        void setClient(string x){client = x;}
        void setData(string x){data = x;}
        void setOraIntrare(int x){oraIntrare = x;}
        void setMinuteIntrare(int x){minuteIntrare = x;}
        void setOraIesire(int x){oraIesire = x;}
        void setMinuteIesire(int x){minuteIesire = x;}
        void setNrPers(int x){nrPers = x;}
        string getTipRezervare(){return tipRezervare;}
        string getClient(){return client;}
        string getData(){return data;}
        int getOraIntrare(){return oraIntrare;}
        int getMinuteIntrare(){return minuteIntrare;}
        int getOraIesire(){return oraIesire;}
        int getMinuteIesire(){return minuteIesire;}
        int getNrPers(){return nrPers;}

        virtual void afiseazaInfo(){
            cout << "Tip rezervare: " << getTipRezervare() << endl;
            cout << "   Nume: " << getClient() << endl;
            cout << "   Data: " << getData() << endl;
            cout << "   Ora: " << getOraIntrare() << ":" << getMinuteIntrare() << " -> "
                << getOraIesire() << ":" << getMinuteIesire() << endl;
            cout << "   Durata rezervarii: ";
                if (durataOra() > 0)
                    cout << durataOra() << " ore ";
                if (durataMinute() > 0)
                    cout << durataMinute() << " minute";
                cout << endl;
            cout << "   Numarul de persoane: " << getNrPers() << endl;
            pretCalc();
            cout << endl;
        }

        virtual void citire(string z, string a, string b, int c, int d, int e, int f, int g){
            setTipRezervare(z);
            setClient(a);
            setData(b);
            setOraIntrare(c);
            setMinuteIntrare(d);
            setOraIesire(e);
            setMinuteIesire(f);
            setNrPers(g);
        }

        virtual void pretCalc(){
            pret = nrPers * 30;
            cout << "   Pretul rezarvarii: " << pret << "lei" << endl;
        }

        int durataRezervarii(){
            int intrare, iesire, durata;
            intrare = oraIntrare*3600 + minuteIntrare*60;
            iesire = oraIesire*3600 + minuteIesire*60;
            durata = iesire-intrare;
            return durata;
        }
        int durataOra(){
            int durata = durataRezervarii()/3600;
            return durata;
        }
        int durataMinute(){
            int durata = durataRezervarii()/60-durataOra()*60;
            return durata;
        }
};

class RezervareZilnica : public Rezervare{
    public:
        RezervareZilnica(){
            cout << "Tip: Zilnica." << endl;
        }
        void pretCalc() override{
            if(nrPers > 2) pret = 50 + 20 * (nrPers - 2);
            else pret = 50;
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};

class RezervareOcazieSpeciala : public Rezervare{
    public:
        RezervareOcazieSpeciala(){
            cout << "Tip: Ocazie speciala" << endl;
        }
        void pretCalc(){
            if(durataOra()>2) pret = 200 + 60 * (durataOra() - 2);
            else pret = 200;
            cout << "Pretul rezarvarii: " << pret << "lei" << endl; 
        }
};

class RezervareGrupMare : public Rezervare{
    public:
        RezervareGrupMare(){
            cout << "Tip: Grup mare" << endl;
        }
        void pretCalc(){
            if(nrPers>20) pret = 500 + 10 * (nrPers - 20);
            else pret = 500;
            if(nrPers>30) pret *=0.85; 
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};

class RezervareVIP : public Rezervare{
    public:
        RezervareVIP(){
            cout << "Tip: VIP" << endl;
        }
        void pretCalc(){
            if(nrPers>5) pret = 1000 + 200*(nrPers-5);
            else pret = 1000;
            pret *= durataOra() + float(durataMinute()/60);
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};

struct node {
    Rezervare *R; 
    node *prev;
    node *next;
};
node *head = NULL;

node* getNewNode(Rezervare *x){
    node *newNode = new node;
    newNode->R = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(Rezervare *x){
    node *newNode = getNewNode(x);
    if (head == NULL){
        head =  newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;    
}

void Interfata(node* head){
    int y;
    do{
        cout << endl;
        cout << "1) Datele rezervarii" << endl;
        cout << "2) Rezervarea urmatoare" << endl;
        cout << "3) Rezervarea precedenta" << endl;
        cout << "4) Iesire din program" << endl;
        cout << "   Selectati una dintre optiuni: ";
        cin >> y;
        cout << endl;
        switch(y){
            case 1:{
                head->R->afiseazaInfo();
                break;
            }
            case 2:{
                if(head->next != NULL) head = head->next;
                else cout << "Nu mai sunt rezervari" << endl;
                break;
            }
            case 3:{
                if(head->prev != NULL) head = head->prev;
                else cout << "Ati ajuns la inceput de lista" << endl;
                break;
            }
            case 4:{
                node* curr = head;
                while(curr){
                    node* next = curr->next;
                    delete curr->R;
                    delete curr;
                    curr = next;
                }
                break;
            }
            default: {cout << "Functie ne-existenta" << endl;}
        }
    }while(y!=4);
}

int main(){
    ifstream Fi("Rezervare1.txt");
    if(!Fi){
        cout << "Eroare: fisierul nu a fost gasit!" << endl;
        return 1;
    }
    
    string a, b, c, d, z;
    int e;
    while(Fi >> z >> a >> b >> c >> d >> e){
        if(z == "RezervareZilnica"){
            Rezervare* R = new RezervareZilnica();
            R->citire(z, a, b, stoi(c.substr(0, 2)), stoi(c.substr(3, 2)), stoi(d.substr(0, 2)), stoi(d.substr(3, 2)), e);
            InsertAtHead(R);
        } else if(z == "RezervareOcazieSpeciala"){
            Rezervare* R = new RezervareOcazieSpeciala();
            R->citire(z, a, b, stoi(c.substr(0, 2)), stoi(c.substr(3, 2)), stoi(d.substr(0, 2)), stoi(d.substr(3, 2)), e);
            InsertAtHead(R);
        } else if(z == "RezervareGrupMare"){
            Rezervare* R = new RezervareGrupMare();
            R->citire(z, a, b, stoi(c.substr(0, 2)), stoi(c.substr(3, 2)), stoi(d.substr(0, 2)), stoi(d.substr(3, 2)), e);
            InsertAtHead(R);
        } else if(z == "RezervareVIP"){
            Rezervare* R = new RezervareVIP();
            R->citire(z, a, b, stoi(c.substr(0, 2)), stoi(c.substr(3, 2)), stoi(d.substr(0, 2)), stoi(d.substr(3, 2)), e);
            InsertAtHead(R);
        }  
    }
    Interfata(head);

    Fi.close();
    return 0;
}