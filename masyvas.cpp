#include "pagalbines.h"
const int PRADINIS_DYDIS = 10;
int studentu_indeksai = -1;
int studentu_kiekis = 0;
int studentu_masyvo_dydis = PRADINIS_DYDIS;

struct Studentas {
    string pavarde;
    string vardas;
    int* pazymiai = new int[PRADINIS_DYDIS];
    int pazymiu_kiekis = 0;
    int pazymiu_masyvo_dydis = PRADINIS_DYDIS;
    int egzamino_pazymys;
};

Studentas* studentai = new Studentas[studentu_masyvo_dydis];

void studento_duomenu_gavimas(Studentas *studentai);
void studento_duomenu_printinimas(Studentas *studentai);
double studento_vidurkio_skaiciavimas(int* pazymiai, int pazymiu_kiekis, int egzamino_pazymys);
double studento_medianos_skaiciavimas(int* pazymiai, int pazymiu_kiekis, int egzamino_pazymys);
int* praplesk_masyvas(int* dabartinis_masyvas, int& masyvo_dydis);
Studentas* praplesk_masyvas(Studentas* dabartinis_masyvas, int& masyvo_dydis);

int main(){
    studento_duomenu_gavimas(studentai);
    studento_duomenu_printinimas(studentai);
    return 0;
}

void studento_duomenu_gavimas(Studentas *studentai){
    while(true){
    Studentas laikinas_studentas;
    cout << "Ivesite studento pavarde ir varda (Jei norite baigti irasyma rasykite 'n'.) :" << endl;
    cin >> laikinas_studentas.pavarde;
    if (laikinas_studentas.pavarde == "n"){
        return;
    } 
    studentu_indeksai += 1;
    studentu_kiekis += 1;
    cin >> laikinas_studentas.vardas;

    cout << "Iveskite pazymius (jei surasete visus pazymius iveskite -2): "<<endl;
        int pazymys = 0; //tam kad patekti i while cikla.
        int pazymio_indeksas = -1;

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
            pazymio_indeksas += 1;
            laikinas_studentas.pazymiu_kiekis += 1;

            if(laikinas_studentas.pazymiu_kiekis == laikinas_studentas.pazymiu_masyvo_dydis){
                laikinas_studentas.pazymiai = praplesk_masyvas(laikinas_studentas.pazymiai, laikinas_studentas.pazymiu_masyvo_dydis);
            }

            laikinas_studentas.pazymiai[pazymio_indeksas] = pazymys;
        }
        
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
    laikinas_studentas.pazymiu_kiekis = laikinas_studentas.pazymiu_kiekis;

    if (studentu_kiekis == studentu_masyvo_dydis){
        studentai = praplesk_masyvas(studentai, studentu_masyvo_dydis);
    }
    studentai[studentu_indeksai] = laikinas_studentas;
    }

}
void studento_duomenu_printinimas(Studentas *studentai){
    string skaiciavimo_budas;
    cout << "Norite apskaiciuoti Vidurki ar Mediana?" << endl;
    cin >> skaiciavimo_budas;

    cout << setw(13) << left << "Pavarde" << setw(12) << left << "Vardas"<< setw(12) << left << "Galutinis" << endl;
    cout << "----------------------------------" << endl;
    if (skaiciavimo_budas == "Mediana"){
        for (int i = 0; i < studentu_kiekis; i ++){
        cout << setw(13) << left << studentai[i].pavarde << setw(12) << left << studentai[i].vardas << setw(12) << left << fixed << setprecision(2) << (studento_medianos_skaiciavimas(studentai[i].pazymiai, studentai[i].pazymiu_kiekis, studentai[i].egzamino_pazymys)) << endl;
    } 
    }else if (skaiciavimo_budas == "Vidurki"){
        for (int i = 0; i < studentu_kiekis; i ++){
        cout << setw(13) << left << studentai[i].pavarde << setw(12) << left << studentai[i].vardas << setw(12) << left << fixed << setprecision(2) << (studento_vidurkio_skaiciavimas(studentai[i].pazymiai, studentai[i].pazymiu_kiekis, studentai[i].egzamino_pazymys)) << endl;
    } 
    }
}
double studento_vidurkio_skaiciavimas(int* pazymiai, int pazymiu_kiekis, int egzamino_pazymys){
    int pazymiu_suma = 0;

    for (int i = 0; i < pazymiu_kiekis; i++){
        pazymiu_suma += pazymiai[i];
    }

    double pazymiu_vidurkis;

    if (pazymiu_kiekis == 0){
        pazymiu_vidurkis = 0;
    }else{
        pazymiu_vidurkis = pazymiu_suma / pazymiu_kiekis;
    }

    double vidurkis = 0.4 * pazymiu_vidurkis + 0.6 * egzamino_pazymys;
    return vidurkis;
}
double studento_medianos_skaiciavimas(int* pazymiai, int pazymiu_kiekis, int egzamino_pazymys){

    sort(pazymiai, pazymiai+pazymiu_kiekis);
    double mediana;
    if(pazymiu_kiekis%2 == 0 && pazymiu_kiekis != 0){
        mediana = (pazymiai[pazymiu_kiekis/2] + pazymiai[pazymiu_kiekis/2 -1]) / 2;
    } else{
        mediana = mediana = (pazymiai[pazymiu_kiekis/2]);
    }

    double vidurkis = 0.4 * mediana + 0.6 * egzamino_pazymys;
    return vidurkis;
}
int* praplesk_masyvas(int* dabartinis_masyvas, int& masyvo_dydis){
    masyvo_dydis *= 2;
    int* praplestas_masyvas = new int[masyvo_dydis];
    for (int i = 0; i < masyvo_dydis; i++){
        praplestas_masyvas[i] = dabartinis_masyvas[i];
    }

    delete[] dabartinis_masyvas;
    return praplestas_masyvas;
}
Studentas* praplesk_masyvas(Studentas* dabartinis_masyvas, int& masyvo_dydis){ //& kad galeciau keisti kintamaji globaliai (masyvo_dydi). tada tiesiog ziuri i tapati adresa
    masyvo_dydis *= 2;
    Studentas* praplestas_masyvas = new Studentas[masyvo_dydis];
    for (int i = 0; i < masyvo_dydis; i++){
        praplestas_masyvas[i] = dabartinis_masyvas[i];
    }

    delete[] dabartinis_masyvas;
    return praplestas_masyvas;
}