#include <iostream>
using namespace std;

class apart {
    private:
        int et, nr, camere, mptr;
        bool locuit;
    public:
        apart(){
            et=0;
            nr=0;
            camere=0;
            mptr=0;
            locuit=false;
        }
        apart(int x, int y, int a, int b, bool f){
            et = x;
            nr = y;
            camere = a;
            mptr = b;
            locuit = f;
        }
        apart(const apart &obj){
            et = obj.et;
            nr = obj.nr;
            camere = obj.camere;
            mptr = obj.mptr;
            locuit = obj.locuit;
        }
        ~apart(){
            cout << "Apartamentul a fost sters din memorie" << endl;
        }

        void afisare(){
            cout << "Apartament: " << endl;
            cout << "Etajul: " << et << endl;
            cout << "Numarul: " << nr << endl;
            cout << "Numarul de camere: " << camere << endl;
            cout << "Metri patrati: " << mptr << endl;
            cout << "Locuit: " << (locuit ? "Da" : "Nu")<< endl;
            cout << endl;
        }
        void chetnr(){
            cout << "Introduceti etajul corect: "; cin >> et;
            cout << "Introduceti numarul corect al aprtamentului: "; cin >> nr;
            cout << endl;
        }
        void space(){
            cout << "Numarul de camere: "; cin >> camere;
            cout << "Metri patrati: "; cin >> mptr;
        }
        void loca(){
            (locuit ? locuit = false : locuit = true);
        }
};

int main(){
    apart c1;
    apart c2(6, 23, 3, 35, true);
    apart c3(c2);
    c1.chetnr();

    c1.afisare();
    c2.loca();
    c2.afisare();
    c2.loca();
    c2.afisare();
    c3.afisare();

    return 0;
}