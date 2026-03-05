#include <iostream>
#include <fstream>
#include <string>
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
        Rezervare(){cout << "Rezervare adaugata." << endl;}
        virtual ~Rezervare(){cout << "Rezervare stearsa." << endl;}
        void setClient(string x){client = x;}
        void setData(string x){data = x;}
        void setOra(string x){ora = x;}
        void setNrPers(int x){nrPers = x;}
        string getClient(){return client;}
        string getData(){return data;}
        string getOra(){return ora;}
        int getNrPers(){return nrPers;}
        virtual void afiseazaInfo(){
            cout << "   Nume: " << getClient() << endl;
            cout << "   Data: " << getData() << endl;
            cout << "   Ora: " << getOra() << endl;
            cout << "   Numarul de persoane: " << getNrPers() << endl;
            cout << endl;
        }
        virtual void durataRez(){
            cout << "Durata rezervarii: " << durRez << "ore" << endl;
        }
        virtual void pretCalc(){
            pret = nrPers * 30;
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};

class RezervareZilnica : public Rezervare{
    public:
        RezervareZilnica(){
            cout << "Tip: Zilnica." << endl;
        }
        void afiseaza(){
            cout << "Informatia rezervarii:" << endl;
            cout << "   Tip: Zilnic" << endl;
        }
        void pretCalc(){
            pret = 50 + 20 * (nrPers - 2);
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};

class RezervareOcazieSpeciala : public Rezervare{
    public:
        RezervareOcazieSpeciala(){
            cout << "Tip: Ocazie speciala" << endl;
        }
        void afiseaza(){
            cout << "Informatia rezervarii:" << endl;
            cout << "   Tip: Ocazie speciala" << endl;
        }
        void pretCalc(){
            pret = 200 + 60 * (durRez - 2);
            cout << "Pretul rezarvarii: " << pret << "lei" << endl; 
        }
};

class RezervareGrupMare : public Rezervare{
    public:
        RezervareGrupMare(){
            cout << "Tip: Grup mare" << endl;
        }
        void afiseaza(){
            cout << "Informatia rezervarii:" << endl;
            cout << "   Tip: Grup mare" << endl;
        }
        void pretCalc(){
            pret = 500 + 10 * (nrPers - 20);
            cout << "Pretul rezarvarii: " << pret << "lei" << endl;
        }
};

class RezervareVIP : public Rezervare{
    public:
        RezervareVIP(){
            cout << "Tip: VIP" << endl;
        }
        void afiseaza(){
            cout << "Informatia rezervarii:" << endl;
            cout << "   Tip: VIP" << endl;
        }
        void pretCalc(){
            pret = 1000;
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
    node *newNode = new node; //allocate a dynamic memory in the heap
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

int main(){
    ifstream Fi("Rezervare.txt");
    if(!Fi){
        cout << "Eroare: fisierul nu a fost gasit!" << endl;
        return 1;
    }
    
    string a, b, c;
    int d;
    while(Fi >> a >> b >> c >> d){
        Rezervare* R = new Rezervare();
        R->setClient(a);
        R->setData(b);
        R->setOra(c);
        R->setNrPers(d);
        InsertAtHead(R);
    }

    if(head) cout << head->R->getClient() << endl;

    node* curr = head;
    while(curr){
        node* next = curr->next;
        delete curr->R;
        delete curr;
        curr = next;
    }
    Fi.close();
    return 0;
}