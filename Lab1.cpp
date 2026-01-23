#include <iostream>
using namespace std;

class apart {
    private:
        int et, nr, mptr, pretmptr;
        bool locuit;
    public:
        apart(){
            et = 0;
            nr = 0;
            mptr = 0;
            pretmptr = 0;
            locuit = false;
        }
        apart(int x, int y, int a, int b, bool f){
            et = x;
            nr = y;
            mptr = a;
            pretmptr = b;
            locuit = f;
        }
        apart(const apart &obj){
            et = obj.et;
            nr = obj.nr;
            mptr = obj.mptr;
            pretmptr = obj.pretmptr;
            locuit = obj.locuit;
        }
        ~apart(){
            cout << "Apartamentul a fost sters din memorie" << endl;
        }

        void afisare(){
            cout << "Apartament: " << endl;
            cout << "Etajul: " << et << endl;
            cout << "Numarul: " << nr << endl;
            cout << "Metri patrati: " << mptr << endl;
            cout << "Pretul per metru patrat: " << pretmptr << endl;
            cout << "Locuit: " << (locuit ? "Da" : "Nu")<< endl;
            cout << endl;
        }
        void chetnr(){
            cout << "Introduceti etajul corect: "; cin >> et;
            cout << "Introduceti numarul corect al aprtamentului: "; cin >> nr;
            cout << endl;
        }
        void space(){
            cout << "Metri patrati: "; cin >> mptr;
        }
        void pret(){
            cout << "Pretul apartamentului este €" << mptr*pretmptr << endl;
        }
        void loca(){
            (locuit ? locuit = false : locuit = true);
        }
};

int main(){
    int z, k;
    bool q=true, w=true;
    apart a1;
    apart a2(5, 26, 30, 16, false);
    apart a3(a2);
    
    while(q){
        cout << "Alegeti apartamentul de vizualizat: " << endl;
        cout << "1) Apartamentul 1 (nu este dat in exploatare)" << endl;
        cout << "2) Apartamentul 2" << endl;
        cout << "3) Apartamentul 3 (identic apartamentului 2)" << endl;
        cout << "4) Iesire din program" << endl;
        cout << "Selectat: ";
        cin >> z;
        switch(z){
            case 1:{
                while(w){
                    cout << "1) Caractristica apartamentului" << endl;
                    cout << "2) Corecteaza etajul si numarul apartamentului" << endl;
                    cout << "3) Modificarea spatiului din apartament" << endl;
                    cout << "4) Afisarea pretului" << endl;
                    cout << "5) Schimbat statutul de ocupare" << endl;
                    cout << "6) Iesire in menu" << endl;
                    cout << "Selectat: ";
                    cin >> k;
                    switch(k){
                        case 1:{
                            a1.afisare();
                        }
                        case 2:{
                            a1.chetnr();
                        }
                        case 3:{
                            a1.space();
                        }
                        case 4:{
                            a1.pret();
                        }
                        case 5:{
                            a1.loca();
                        }
                        case 6:{
                            w = false;
                        }
                    }
                }
            }
            case 2:{
                while(w){
                    cout << "1) Caractristica apartamentului" << endl;
                    cout << "2) Corecteaza etajul si numarul apartamentului" << endl;
                    cout << "3) Modificarea spatiului din apartament" << endl;
                    cout << "4) Afisarea pretului" << endl;
                    cout << "5) Schimbat statutul de ocupare" << endl;
                    cout << "6) Iesire in menu" << endl;
                    cout << "Selectat: ";
                    cin >> k;
                    switch(k){
                        case 1:{
                            a2.afisare();
                        }
                        case 2:{
                            a2.chetnr();
                        }
                        case 3:{
                            a2.space();
                        }
                        case 4:{
                            a2.pret();
                        }
                        case 5:{
                            a2.loca();
                        }
                        case 6:{
                            w = false;
                        }
                    }
                }
            }
            case 3:{
                while(w){
                    cout << "1) Caractristica apartamentului" << endl;
                    cout << "2) Corecteaza etajul si numarul apartamentului" << endl;
                    cout << "3) Modificarea spatiului din apartament" << endl;
                    cout << "4) Afisarea pretului" << endl;
                    cout << "5) Schimbat statutul de ocupare" << endl;
                    cout << "6) Iesire in menu" << endl;
                    cout << "Selectat: ";
                    cin >> k;
                    switch(k){
                        case 1:{
                            a3.afisare();
                        }
                        case 2:{
                            a3.chetnr();
                        }
                        case 3:{
                            a3.space();
                        }
                        case 4:{
                            a3.pret();
                        }
                        case 5:{
                            a3.loca();
                        }
                        case 6:{
                            w = false;
                        }
                    }
                }
            }
            case 4:{
                q = false;
            }
        }
    }
    

    return 0;
}