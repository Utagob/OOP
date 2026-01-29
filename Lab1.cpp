#include <iostream>
#include <string>
using namespace std;

class carte{
    private:
        int pagini, anEditura, imprumut, zI, lI, aI, zR, lR, aR;
        string titlu, autor, editor, calitate;
        bool Im;
    public:
        carte(){
            titlu = "Necunoscut";
            autor = "Necunoscut";
            editor = "Necunoscut";
            anEditura = 0;
            calitate = "Nou";
            pagini = 0;
            imprumut = 0;
            Im = false;
            zI = 0; lI = 0; aI = 0;
            zR = 0; lR = 0; aR = 0;
        }
        carte(string t, string z, string e, int a, string q, int p, int i, bool u, int c, int y, int o, int C, int Y, int O){
            titlu = t;
            autor = z;
            editor = e;
            anEditura = a;
            calitate = q;
            pagini = p;
            imprumut = i;
            Im = u;
            zI = c; lI = y; aI = o;
            zR = C; lR = Y; aR = O;
        }
        carte(const carte &c){
            titlu = c.titlu;
            autor = c.autor;
            editor = c.editor;
            anEditura = c.anEditura;
            calitate = c.calitate;
            pagini = c.pagini;
            imprumut = c.imprumut;
            Im = c.Im;
        }
        ~carte(){
            cout << "Carte scoasa din biblioteca";
        }
        void afisareC(){
            cout << "Cartea: " << titlu << endl;
            cout << "Autor: " << autor << endl;
            cout << "Editura: " << editor << endl;
            cout << "Anul editiei: " << anEditura << endl;
            cout << endl;
        }
        void afisareI(){
            cout << "Informatie recenta:" << endl;
            if(Im){
                cout << "Imprumutata - " << zI << "/" << lI << "/" << aI << endl; 
            }else{
                cout << "Returnata - " << zR << "/" << lR << "/" << aR << endl;
            }
            cout << "Calitatea la imprumut: " << calitate << endl;
            cout << "Imprumutata de " << imprumut << " ori" << endl;
            cout << endl;
        }
        void imp(){
            cout << "Data imprumutului: " << endl;
            cout << "Ziua: "; cin >> zI;
            cout << "Luna: "; cin >> lI;
            cout << "Anul: "; cin >> aI;
            Im = true;
            cout << endl;
        }
        void returnare(){
            cout << "Data returnarii: " << endl;
            cout << "Ziua: "; cin >> zR;
            cout << "Luna: "; cin >> lR;
            cout << "Anul: "; cin >> aR;
            cout << "Cartea a fost returnata" << endl;
            imprumut++;
            imprumut<10 ? calitate = "Buna" : calitate = "Nesatisfacatoare";
            Im = false;
            cout << endl;
        }
        void innoire(){
            cout << "Cartea a fost innoita" << endl;
            calitate = "Nou";
            imprumut = 0;
            cout << endl;
        }
};

void menu(carte &c){
    int z;
    bool f = true;
    while(f){
        cout << "Actiuni disponibile:" << endl;
        cout << "1) Afisarea informatiei despre carte" << endl;
        cout << "2) Afisarea statusului cartii" << endl;
        cout << "3) Imprumutarea cartii" << endl;
        cout << "4) Returnarea cartii" << endl;
        cout << "5) Innoirea cartii" << endl;
        cout << "*Tastarea altei cifre va va transmite la catalogul cu carti" << endl;
        cin >> z;
        cout << endl;
        switch(z){
            case 1:{
                c.afisareC();
                break;
            }
            case 2:{
                c.afisareI();
                break;
            }
            case 3:{
                c.imp();
                break;
            }
            case 4:{
                c.returnare();
                break;
            }
            case 5:{
                c.innoire();
                break;
            }
            default:{
                f = false;
                break;
            }    
        }
    }
}

int main(){
    carte c1;
    carte c2("Albania mare", "Contel Aldon", "Drinca", 2020, "Buna", 225, 6, false, 0, 0, 0, 23, 8, 2026);
    carte c3(c2);
    int z;
    bool q = true;

    while(q){
        cout << "Selectati Cartea:" << endl;
        cout << "1 - Necunoscuta" << endl;
        cout << "2 - Albania mare" << endl;
        cout << "3 - Albania mare (copiere)" << endl;
        cout << "Apasati orice alta cifra pentru a iesi din program" << endl;
        cout << "Selectati: ";
        cin >> z;
        cout << endl;
        switch(z){
            case 1:{
                menu(c1);
                break;
            }
            case 2:{
                menu(c2);
                break;
            }
            case 3:{
                menu(c3);
                break;
            }
            default:{
                q = false;
                break;
            }
        }
    }
    

    return 0;
}