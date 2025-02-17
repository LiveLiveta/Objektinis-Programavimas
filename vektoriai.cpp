#include "pagalbines.h"

const int PRADINIS_DYDIS = 10;
int studentu_kiekis = 0;
vector<string> vardai = { "Mantas", "Lukas", "Dominykas", "Kajus", "Dovydas", "Rokas", "Emilis", "Tadas", "Benas", "Jokubas"};
vector<string> pavardes ={ "Kazlauskas", "Petrauskas", "Jankauskas", "Baliunas", "Vaiciulis", "Stankevicius", "Jonaitis", "Urbonas", "Zabielskas", "Paulauskas"};

struct Studentas {
    string pavarde;
    string vardas;
    vector<int> pazymiai;
    int egzamino_pazymys;
    double vidurkis;
    double  mediana;
};

vector<Studentas> studentai;

void studento_duomenu_gavimas();
void studento_duomenu_printinimas(vector<Studentas> &studentai);
void studento_duomenu_rikiavimas(vector<Studentas> &studentai);
bool rikiuoti_pagal_varda(Studentas &a, Studentas &b);
bool rikiuoti_pagal_pavarde(Studentas &a, Studentas &b);
bool rikiuoti_pagal_vidurkis(Studentas &a, Studentas &b);
bool rikiuoti_pagal_mediana(Studentas &a, Studentas &b);
bool baigiasi_su_txt(string failo_pavadinimas);

void studento_vidurkio_skaiciavimas(vector<Studentas> &studentai);
void studento_medianos_skaiciavimas(vector<Studentas> &studentai);

void studento_vardo_ir_pavardes_gavimas(Studentas &laikinas_studentas);
void studento_pazymiu_gavimas(Studentas &laikinas_studentas);
void studento_egzamino_pazymio_gavimas(Studentas &laikinas_studentas);

void studento_duomenu_skaitymas_is_failo();
void duomenu_is_failo_susirasymas(vector<Studentas> &studentai, string& failo_pavadinimas);
bool tikrinimas_ar_pavyko_atidaryti_faila(string& failo_pavadinimas);

void studento_pazymiu_ir_egzaminu_generavimas(Studentas &laikinas_studentas);
int gauk_kiek_pazimiu_sugeneruoti();
void studento_vardo_ir_pavardes_generavimas(Studentas &laikinas_studentas);

int studento_duomenu_surasymo_pasirinkimas();
void visi_duomenys_surasomi_ranka();
void surasoma_ranka_isskyrus_pazymius();
void viskas_generuojama_atsitiktinai();



int main(){
    studento_duomenu_gavimas();
    studento_duomenu_printinimas(studentai);
    return 0;
}

void studento_duomenu_gavimas(){
     while(true){
        int  duomenu_surasymo_pasirinkimas = studento_duomenu_surasymo_pasirinkimas();
        if (duomenu_surasymo_pasirinkimas == 1){
            visi_duomenys_surasomi_ranka();
        } else if (duomenu_surasymo_pasirinkimas == 2){
            surasoma_ranka_isskyrus_pazymius();
        } else if (duomenu_surasymo_pasirinkimas == 3){
            viskas_generuojama_atsitiktinai();
        } else if (duomenu_surasymo_pasirinkimas == 4){
            studento_duomenu_skaitymas_is_failo();
        } else if (duomenu_surasymo_pasirinkimas == 5){
            break;
        } else {
            cout << endl << "Pasirinkite veiksma is meniu! " << endl;
        }
}

}
void studento_duomenu_printinimas(vector<Studentas> &studentai){
    string irasimo_budas;
    cout << "Duomenis norite matyti e - Ekrane ar  f - Faile? " << endl;
    cin >> irasimo_budas;
    while(irasimo_budas != "e" && irasimo_budas != "f"){
        cout << "Pasirinkite kur norite matyti duomenis. e - Ekrane ar  f - Faile?" << endl;
        cin >> irasimo_budas;
    }
    string failo_pavadinimas;
    if (irasimo_budas == "f"){
        cout << "Iveskite failo i kuri norite irasyti duomenis pavadinima (formatas: pavadinimas.txt): ";
        cin >> failo_pavadinimas;
        cout << endl;
        while (baigiasi_su_txt(failo_pavadinimas) != true){
            cout << "Netinkamas failo pavadinimas! Iveskite failo i kuri norite irasyti duomenis pavadinima (formatas: pavadinimas.txt): ";
            cin >> failo_pavadinimas;
        }
    }
    studento_medianos_skaiciavimas(studentai);
    studento_vidurkio_skaiciavimas(studentai);
    studento_duomenu_rikiavimas(studentai);

    if (irasimo_budas == "e"){
        cout << setw(13) << left << "Vardas" << setw(12) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" <<endl;
        cout << "--------------------------------------------------------------" << endl;
        for (int i = 0; i < studentu_kiekis; i ++){
            cout << setw(13) << left << studentai[i].vardas << setw(12) << left << studentai[i].pavarde << setw(20) << left << fixed << setprecision(2) << studentai[i].vidurkis << setw(20) << studentai[i].mediana << endl;
            }  
    }else if (irasimo_budas == "f"){
        ofstream failas(failo_pavadinimas);
        failas << setw(13) << left << "Vardas" << setw(12) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" <<endl;
        failas << "--------------------------------------------------------------" << endl;
        for (int i = 0; i < studentu_kiekis; i ++){
            failas << setw(13) << left << studentai[i].vardas << setw(12) << left << studentai[i].pavarde << setw(20) << left << fixed << setprecision(2) << studentai[i].vidurkis << setw(20) << studentai[i].mediana << endl;
            } 
    }
}
void studento_duomenu_rikiavimas(vector<Studentas> &studentai){
    int rusiuoti_pagal;
    while (true) {
    cout << "Pasirinkite rikiavimo kriteriju: " << endl;
    cout << "1 - Pagal varda" << endl;
    cout << "2 - Pagal pavarde" << endl;
    cout << "3 - Pagal galutini vidurki" << endl;
    cout << "4 - Pagal galutine mediana" << endl;
    cout << "5 - Palikti taip kaip dabar yra" << endl;
    cout << "Jusu pasirinkimas: ";
    cin >> rusiuoti_pagal; 
    cout << endl;

    if (cin.fail() || rusiuoti_pagal < 1 || rusiuoti_pagal > 5){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Neteisingas pasirinkimas!" << endl;
        continue;
    }
    break;
    }

    switch (rusiuoti_pagal)
    {
    case 1:
        sort(studentai.begin(), studentai.end(), rikiuoti_pagal_varda);
        break;
    case 2:
        sort(studentai.begin(), studentai.end(), rikiuoti_pagal_pavarde);
        break;
    case 3:
        sort(studentai.begin(), studentai.end(), rikiuoti_pagal_vidurkis);
        break;
    case 4:
        sort(studentai.begin(), studentai.end(), rikiuoti_pagal_mediana);
        break;
    default:
        
        break;
    }

}
bool rikiuoti_pagal_varda(Studentas &a, Studentas &b){

    if (a.vardas.substr(0, 6) == "Vardas" && b.vardas.substr(0, 6) == "Vardas"){
        int sk1 = stoi(a.vardas.substr(6));
        int sk2 = stoi(b.vardas.substr(6));
        return sk1 < sk2;
    }
    return a.vardas < b.vardas;
}
bool rikiuoti_pagal_pavarde(Studentas &a, Studentas &b){
    if (a.pavarde.substr(0, 7) == "Pavarde" && b.pavarde.substr(0, 7) == "Pavarde"){
        int sk1 = stoi(a.pavarde.substr(7));
        int sk2 = stoi(b.pavarde.substr(7));
        return sk1 < sk2;
    }
    return a.pavarde < b.pavarde;
}
bool rikiuoti_pagal_vidurkis(Studentas &a, Studentas &b){
    return a.vidurkis > b.vidurkis;
}
bool rikiuoti_pagal_mediana(Studentas &a, Studentas &b){
    return a.mediana > b.mediana;
}
bool baigiasi_su_txt(string failo_pavadinimas){
    if (failo_pavadinimas.size() >= 4 && failo_pavadinimas.substr((failo_pavadinimas.size() - 4)) == ".txt"){
        return true;
    }
    return false;
}

void studento_vidurkio_skaiciavimas(vector<Studentas> &studentai){
    for (int i = 0; i < studentu_kiekis; i++){
        int pazymiu_suma = 0;
        int pazymiu_kiekis = studentai[i].pazymiai.size();
    
        if (pazymiu_kiekis == 0){
            studentai[i].vidurkis = 0.6 * studentai[i].egzamino_pazymys;
        } else{ 
            for (int j = 0; j < pazymiu_kiekis; j++){
                pazymiu_suma += studentai[i].pazymiai[j];
            }
            double pazymiu_vidurkis = pazymiu_suma * 1.0 / pazymiu_kiekis;
            double vidurkis = 0.4 * pazymiu_vidurkis + 0.6 * studentai[i].egzamino_pazymys;
            studentai[i].vidurkis = vidurkis;
        }
    }

}
void studento_medianos_skaiciavimas(vector<Studentas> &studentai){
    for (int i = 0; i < studentu_kiekis; i++){
        int pazymiu_kiekis = studentai[i].pazymiai.size();
        if (pazymiu_kiekis == 0){
            studentai[i].mediana =  0.6 * studentai[i].egzamino_pazymys;
        }else{ 
            sort(studentai[i].pazymiai.begin(), studentai[i].pazymiai.end());
            double mediana;
            if(pazymiu_kiekis%2 == 0){
                mediana = (studentai[i].pazymiai[pazymiu_kiekis/2] + studentai[i].pazymiai[pazymiu_kiekis/2 -1]) / 2.0;
            } else{
                mediana = (studentai[i].pazymiai[pazymiu_kiekis/2]);
            }
        
            double vidurkis = 0.4 * mediana + 0.6 * studentai[i].egzamino_pazymys;
            studentai[i].mediana = vidurkis;
        }
    }
}

void studento_vardo_ir_pavardes_gavimas(Studentas &laikinas_studentas){
    cout << "Ivesite studento varda ir pavarde:" << endl;
    cin >> laikinas_studentas.vardas >> laikinas_studentas.pavarde;
    cout << endl;
    studentu_kiekis += 1;
}
void studento_pazymiu_gavimas(Studentas &laikinas_studentas){
    cout << "Iveskite pazymius (jei surasete visus pazymius iveskite -2): "<<endl;
        int pazymys = 0; //tam kad patekti i while cikla.

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

void studento_duomenu_skaitymas_is_failo(){

    string failo_pavadinimas;
    cout << "Iveskite norimo nuskaityti failo pavadinima: " << endl;
    cin >> failo_pavadinimas;

    while (tikrinimas_ar_pavyko_atidaryti_faila(failo_pavadinimas) == false){
        cout << "Nepavyko atidaryti failo! Iveskite tinkama failo pavadinima: " << endl;
        cin >> failo_pavadinimas;
    }
    cout << "Failas atidarytas sekmingai!" << endl;
    duomenu_is_failo_susirasymas(studentai, failo_pavadinimas);

}
void duomenu_is_failo_susirasymas(vector<Studentas> &studentai, string& failo_pavadinimas){

    ifstream failas(failo_pavadinimas);
    string antrastine_eilute;
    getline(failas, antrastine_eilute);

    string eilute;

    while(getline(failas, eilute)){
        Studentas laikinas_studentas;
        stringstream eil(eilute);
        eil >> laikinas_studentas.vardas >> laikinas_studentas.pavarde;
        int pazymys;
        while (eil >> pazymys){
            laikinas_studentas.pazymiai.push_back(pazymys);
        }
        laikinas_studentas.egzamino_pazymys = laikinas_studentas.pazymiai.back();
        laikinas_studentas.pazymiai.pop_back();
        studentu_kiekis += 1;
        studentai.push_back(laikinas_studentas);
    }
    cout << "Duomenys nuskaityti sekmingai!" << endl;

}
bool tikrinimas_ar_pavyko_atidaryti_faila(string& failo_pavadinimas){
    ifstream failas(failo_pavadinimas);
    if (!failas){
        return false;
    }
    return true;
}

void studento_vardo_ir_pavardes_generavimas(Studentas &laikinas_studentas){
    srand(time(0));
    int vardo_indeksas = (rand()%10);
    int pavardes_indeksas = (rand()%10);

    cout << "Studento vardas pavarde: " << vardai[vardo_indeksas] <<" "<< pavardes[pavardes_indeksas] <<endl;
    
    laikinas_studentas.pavarde = pavardes[pavardes_indeksas];
    laikinas_studentas.vardas = vardai[vardo_indeksas];

    studentu_kiekis += 1;
}
void studento_pazymiu_ir_egzaminu_generavimas(Studentas &laikinas_studentas){
    
    srand(time(0));
    int pazymiu_kiekis = gauk_kiek_pazimiu_sugeneruoti();

    for (int i = 0; i < pazymiu_kiekis; i++){
        int pazymys = (rand()%10)+1;
        cout <<"pazymys: " << pazymys << endl;
        laikinas_studentas.pazymiai.push_back(pazymys);
    }
    int egzamino_rezultatas = (rand()%10)+1 ;
    cout << "egzamino rezultatas: "<< egzamino_rezultatas << endl;

    laikinas_studentas.egzamino_pazymys = egzamino_rezultatas;
}
int gauk_kiek_pazimiu_sugeneruoti(){

    int pazymiu_kiekis;
    cout << "Kiek pazymiu sugeneruoti?" <<endl;
    cout << "pazymiu kiekis: ";
    cin >> pazymiu_kiekis;

    while (pazymiu_kiekis < 0 || cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite skaiciu kiek pazymiu norite sugeneruoti!" << endl;
        cout << "pazymiu kiekis: ";
        cin >> pazymiu_kiekis; 
    }
    cout << endl;
    return pazymiu_kiekis;
}


int studento_duomenu_surasymo_pasirinkimas(){
    int duomenu_surasymo_pasirinkimas;
    cout << endl << "Pasirinkite norima duomenu surasymo buda is galimu variantu: "<< endl;
    cout << "1 - ranka," <<endl << "2 - generuoti pazymius," << endl << "3 - generuoti ir pazymius ir studentu vardus, pavardes," << endl << "4 - skaityti duomenis is failo," << endl << "5 - baigti darba" << endl;
    cout << "Jusu pasirinkimas: ";
    cin >> duomenu_surasymo_pasirinkimas;
    cout << endl;
    return duomenu_surasymo_pasirinkimas;
}
void visi_duomenys_surasomi_ranka(){

    Studentas laikinas_studentas;
    
    studento_vardo_ir_pavardes_gavimas(laikinas_studentas);
    studento_pazymiu_gavimas(laikinas_studentas);
    studento_egzamino_pazymio_gavimas(laikinas_studentas);

    studentai.push_back(laikinas_studentas);
    }
void surasoma_ranka_isskyrus_pazymius(){
    Studentas laikinas_studentas;
    
    studento_vardo_ir_pavardes_gavimas(laikinas_studentas); 
    studento_pazymiu_ir_egzaminu_generavimas(laikinas_studentas);
  
    studentai.push_back(laikinas_studentas);
}
void viskas_generuojama_atsitiktinai(){
    Studentas laikinas_studentas;
    
    studento_vardo_ir_pavardes_generavimas(laikinas_studentas); 
    studento_pazymiu_ir_egzaminu_generavimas(laikinas_studentas);

    studentai.push_back(laikinas_studentas);
}