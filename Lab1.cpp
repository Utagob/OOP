#include <iostream>
#include <string>
using namespace std;

class carte{
    private:
        int pagini, anEditura, imprumut, zI, lI, aI, zR, lR, aR;
        string titlu, autor, editor, calitate;
    public:
        carte(){
            pagini = 0;
            titlu = "Necunoscut";
            autor = "Necunoscut";
            editor = "Necunoscut";
            calitate = "Nou";
            anEditura = 0;
            imprumut = 0;
        }
        carte(string t, string z, string e, int a, string q, int p, int i){
            titlu = t;
            autor = z;
            editor = e;
            anEditura = a;
            calitate = q;
            pagini = p;
            imprumut = i;
        }
        carte(const carte &c){
            titlu = c.titlu;
            autor = c.autor;
            editor = c.editor;
            anEditura = c.anEditura;
            calitate = c.calitate;
            pagini = c.pagini;
            imprumut = c.imprumut;
        }
        ~carte(){
            cout << "Carte scoasa din biblioteca";
        }
        void afisareC(){
            cout << "Cartea: " << titlu << endl;
            cout << "Autor: " << autor << endl;
            cout << "Editura: " << editor << endl;
            cout << "Anul editiei: " << anEditura << endl; 
        }
        void afisareI(){
            cout << "Ultimul imprumut: " << zI << "/" << lI << "/" << aI << endl;
        }
        void imp(){
            cout << "Data imprumutului: " << endl;
            cout << "Ziua: "; cin >> zI;
            cout << "Luna: "; cin >> lI;
            cout << "Anul: "; cin >> aI;
        }
        void returnare(){
            cout << "Data returnarii: " << endl;
            cout << "Ziua: "; cin >> zR;
            cout << "Luna: "; cin >> lR;
            cout << "Anul: "; cin >> aR;
            cout << "Cartea a fost returnata" << endl;
            imprumut++;
            imprumut<10 ? calitate = "Buna" : calitate = "Neacceptabila";
        }
        void innoire(){
            cout << "Cartea a fost innoita" << endl;
            calitate = "Nou";
            imprumut = 0;
        }
};

int main(){
    carte c1("BUIabd", "ASDasd", 2008, "Nou", 215, 0);
    c1.imp();
    c1.returnare();

    return 0;
}