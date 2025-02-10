#include "pagalbines.h"

    struct studentas {
        string pavarde;
        string vardas;
        vector<int> pazymiai;
        int egzamino_pazymys;
    };

    vector<studentas> Studentai;

    void studento_duomenu_gavimas(vector<studentas> &Studentai);
    void studento_duomenu_printinimas(vector<studentas> Studentai);
    double studento_vidurkio_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys);
    double studento_medianos_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys);

int main(){
    studento_duomenu_gavimas(Studentai);
    studento_duomenu_printinimas(Studentai);
    return 0;
}

void studento_duomenu_gavimas(vector<studentas> &Studentai){
    while(true){
    studentas laikinas_studentas;
    cout << "Ivesite savo pavarde ir varda (Jei norite baigti irasyma rasykite 'n'.) :" << endl;
    cin >> laikinas_studentas.pavarde;
    if (laikinas_studentas.pavarde == "n"){
        return;
    } else{
    cin >> laikinas_studentas.vardas;
    cout << "Iveskite kiek pazymiu turi studentas: " <<endl;
    int pazymiu_kiekis;
    cin >> pazymiu_kiekis;
    cout << "Iveskite pazymius: "<<endl;

    for(int i = 0;  i < pazymiu_kiekis; i++){
        int pazymys;
        cin >> pazymys;
            while (pazymys <= 0 || pazymys > 10 || cin.fail()){
                cout << "Iveskite skaiciu nuo 1 iki 10!" << endl;
                cin >> pazymys;
                cin.clear(); 
                cin.ignore();
            }
        laikinas_studentas.pazymiai.push_back(pazymys);
    }
    cout << "Iveskite egzamino pazymi: " <<endl;
    int egzamino_pazymys;
    cin >> egzamino_pazymys;
     while (egzamino_pazymys <= 0 || egzamino_pazymys > 10 || cin.fail()){
                cout << "Iveskite skaiciu nuo 1 iki 10!" << endl;
                cin >> egzamino_pazymys; 
                cin.clear();
                cin.ignore();
            }
    laikinas_studentas.egzamino_pazymys = egzamino_pazymys;

    Studentai.push_back(laikinas_studentas);
    }
    }
}
void studento_duomenu_printinimas(vector<studentas> Studentai){
    string skaiciavimo_budas;
    cout << "Norite apskaiciuoti Vidurki ar Mediana?" << endl;
    cin >> skaiciavimo_budas;

    cout << setw(13) << left << "Pavarde" << setw(12) << left << "Vardas"<< setw(12) << left << "Galutinis" << endl;
    cout << "----------------------------------" << endl;
    if (skaiciavimo_budas == "Mediana"){
        for (int i = 0; i < Studentai.size(); i ++){
        cout << setw(13) << left << Studentai[i].pavarde << setw(12) << left << Studentai[i].vardas << setw(12) << left << fixed << setprecision(2) << (studento_medianos_skaiciavimas(Studentai[i].pazymiai, Studentai[i].egzamino_pazymys)) << endl;
    } 
    }else if (skaiciavimo_budas == "Vidurki"){
        for (int i = 0; i < Studentai.size(); i ++){
        cout << setw(13) << left << Studentai[i].pavarde << setw(12) << left << Studentai[i].vardas << setw(12) << left << fixed << setprecision(2) << (studento_vidurkio_skaiciavimas(Studentai[i].pazymiai, Studentai[i].egzamino_pazymys)) << endl;
    } 
    }
}
double studento_vidurkio_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys){
    int pazymiu_suma = 0;
    int pazymiu_kiekis = pazymiai.size();

    for (int i = 0; i < pazymiu_kiekis; i++){
        pazymiu_suma += pazymiai[i];
    }
    double pazymiu_vidurkis = pazymiu_suma / pazymiu_kiekis;
    double vidurkis = 0.4 * pazymiu_vidurkis + 0.6 * egzamino_pazymys;
    return vidurkis;
}
double studento_medianos_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys){
    int pazymiu_kiekis = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());
    double mediana;
    if(pazymiu_kiekis%2 == 0){
        mediana = (pazymiai[pazymiu_kiekis/2] + pazymiai[pazymiu_kiekis/2 -1]) / 2;
    } else{
        mediana = mediana = (pazymiai[pazymiu_kiekis/2]);
    }

    double vidurkis = 0.4 * mediana + 0.6 * egzamino_pazymys;
    return vidurkis;
}
