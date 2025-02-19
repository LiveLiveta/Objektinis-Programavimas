#include "pagalbines.h"
#include "funkcijos.h"

int studentu_kiekis = 0;
vector<string> vardai = { "Mantas", "Lukas", "Dominykas", "Kajus", "Dovydas", "Rokas", "Emilis", "Tadas", "Benas", "Jokubas"};
vector<string> pavardes ={ "Kazlauskas", "Petrauskas", "Jankauskas", "Baliunas", "Vaiciulis", "Stankevicius", "Jonaitis", "Urbonas", "Zabielskas", "Paulauskas"};
vector<Studentas> studentai;
vector<double> operaciju_laikai;
int operaciju_kiekis = 0;

int main(){
    studento_duomenu_gavimas();
    studento_duomenu_printinimas(studentai);
    return 0;
}
