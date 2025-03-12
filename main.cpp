#include "pagalbines.h"

vector<string> vardai = { "Mantas", "Lukas", "Dominykas", "Kajus", "Dovydas", "Rokas", "Emilis", "Tadas", "Benas", "Jokubas"};
vector<string> pavardes ={ "Kazlauskas", "Petrauskas", "Jankauskas", "Baliunas", "Vaiciulis", "Stankevicius", "Jonaitis", "Urbonas", "Zabielskas", "Paulauskas"};


    struct Studentas {
        string pavarde;
        string vardas;
        vector<int> pazymiai;
        int egzamino_pazymys;
    };

    vector<Studentas> studentai;
    srand(time(nullptr));

    void studento_duomenu_gavimas(vector<Studentas> &studentai);
    void studento_duomenu_printinimas(vector<Studentas> studentai);
    double studento_vidurkio_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys);
    double studento_medianos_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys);
    void studento_pazymiu_surasymas(Studentas &laikinas_studentas);
    void studento_egzamino_pazymio_gavimas(Studentas &laikinas_studentas);

int main(){
    studento_duomenu_gavimas(studentai);
    studento_duomenu_printinimas(studentai);
    return 0;
}

void studento_duomenu_gavimas(vector<Studentas> &studentai){
    while(true){
    Studentas laikinas_studentas;
    cout << "Ivesite studento pavarde ir varda (Jei norite baigti irasyma rasykite 'n'.) :" << endl;
    cin >> laikinas_studentas.pavarde;
    if (laikinas_studentas.pavarde == "n"){
        return;
    } else{
    cin >> laikinas_studentas.vardas;

    studento_pazymiu_surasymas(laikinas_studentas);
    studento_egzamino_pazymio_gavimas(laikinas_studentas);

    studentai.push_back(laikinas_studentas);
    }
    }
}
void studento_duomenu_printinimas(vector<Studentas> studentai){
    string skaiciavimo_budas;
    cout << "Norite apskaiciuoti Vidurki ar Mediana?" << endl;
    cin >> skaiciavimo_budas;

    cout << setw(13) << left << "Pavarde" << setw(12) << left << "Vardas"<< setw(12) << left << "Galutinis" << endl;
    cout << "----------------------------------" << endl;
    if (skaiciavimo_budas == "Mediana"){
        for (int i = 0; i < studentai.size(); i ++){
        cout << setw(13) << left << studentai[i].pavarde << setw(12) << left << studentai[i].vardas << setw(12) << left << fixed << setprecision(2) << (studento_medianos_skaiciavimas(studentai[i].pazymiai, studentai[i].egzamino_pazymys)) << endl;
    } 
    }else if (skaiciavimo_budas == "Vidurki"){
        for (int i = 0; i < studentai.size(); i ++){
        cout << setw(13) << left << studentai[i].pavarde << setw(12) << left << studentai[i].vardas << setw(12) << left << fixed << setprecision(2) << (studento_vidurkio_skaiciavimas(studentai[i].pazymiai, studentai[i].egzamino_pazymys)) << endl;
    } 
    }
}
double studento_vidurkio_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys){
    int pazymiu_suma = 0;
    int pazymiu_kiekis = pazymiai.size();

    for (int i = 0; i < pazymiu_kiekis; i++){
        pazymiu_suma += pazymiai[i];
    }
    double pazymiu_vidurkis = pazymiu_suma * 1.0 / pazymiu_kiekis;
    double vidurkis = 0.4 * pazymiu_vidurkis + 0.6 * egzamino_pazymys;
    return vidurkis;
}
double studento_medianos_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys){
    int pazymiu_kiekis = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());
    double mediana;
    if(pazymiu_kiekis%2 == 0){
        mediana = (pazymiai[pazymiu_kiekis/2] + pazymiai[pazymiu_kiekis/2 -1]) / 2.0;
    } else{
        mediana = mediana = (pazymiai[pazymiu_kiekis/2]);
    }

    double vidurkis = 0.4 * mediana + 0.6 * egzamino_pazymys;
    return vidurkis;
}
void studento_pazymiu_surasymas(Studentas &laikinas_studentas){
    cout << "Iveskite pazymius (jei surasete visus pazymius iveskite -2): "<<endl;
        int pazymys = 0;
        while (pazymys != -2){
            cout << "Pazymys: ";
            cin >> pazymys;
            if (pazymys == -2){
                break;
            }
            while (pazymys <= 0 || pazymys > 10 || cin.fail()){
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Iveskite skaiciu nuo 1 iki 10! (jei surasete visus pazymius iveskite -2)" << endl;
                cout << "Pazymys: ";
                cin >> pazymys;
                if (pazymys == -2){
                    break;
                }
            }
            laikinas_studentas.pazymiai.push_back(pazymys);
        }
}
void studento_egzamino_pazymio_gavimas(Studentas &laikinas_studentas){
    cout << "Iveskite egzamino pazymi: " <<endl;
    int egzamino_pazymys;
    cout << "Egzamino pazymys: ";
    cin >> egzamino_pazymys;
     while (egzamino_pazymys <= 0 || egzamino_pazymys > 10 || cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite skaiciu nuo 1 iki 10!" << endl;
        cout << "Egzamino pazymys: ";
        cin >> egzamino_pazymys; 
            }
    laikinas_studentas.egzamino_pazymys = egzamino_pazymys;
}