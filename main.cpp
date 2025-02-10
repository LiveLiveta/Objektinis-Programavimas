#include "pagalbines.h"

    struct studentas {
        string pavarde;
        string vardas;
        vector<int> pazymiai;
        int egzamino_pazymys;
    };

    vector<studentas> Studentai;

    void studento_duomenu_gavimas(vector<studentas> Studentai);

int main(){
    return 0;
}

void studento_duomenu_gavimas(vector<studentas> Studentai){
    studentas laikinas_studentas;
    cout << "Ivesite savo pavarde ir varda (Jei norite baigti irasyma rasykite 'n'.) :" << endl;
    cin >> laikinas_studentas.pavarde;
    if (laikinas_studentas.pavarde == "n"){
        return;
    }
    cin >> laikinas_studentas.vardas;
    cout << "Iveskite kiek pazymiu turi studentas: " <<endl;
    int pazymiu_kiekis;
    cin >> pazymiu_kiekis;
    cout << "Iveskite pazymius: "<<endl;

    for(int i = 0;  i < pazymiu_kiekis; i++){
        int pazymys;
        cin >> pazymys;
        laikinas_studentas.pazymiai.push_back(pazymys);
    }
    cout << "Iveskite egzamino pazymi: " <<endl;
    cin >> laikinas_studentas.egzamino_pazymys;
    Studentai.push_back(laikinas_studentas);
}
