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
};

vector<Studentas> studentai;

void studento_duomenu_gavimas(vector<Studentas> &studentai);
void studento_duomenu_printinimas(vector<Studentas> &studentai);

double studento_vidurkio_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys);
double studento_medianos_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys);

void studento_vardo_ir_pavardes_gavimas(Studentas &laikinas_studentas);
void studento_pazymiu_gavimas(Studentas &laikinas_studentas);
void studento_egzamino_pazymio_gavimas(Studentas &laikinas_studentas);


void studento_pazymiu_ir_egzaminu_generavimas(Studentas &laikinas_studentas);
int gauk_kiek_pazimiu_sugeneruoti();
void studento_vardo_ir_pavardes_generavimas(Studentas &laikinas_studentas);

int studento_duomenu_surasymo_pasirinkimas();
void visi_duomenys_surasomi_ranka();
void surasoma_ranka_isskyrus_pazymius();
void viskas_generuojama_atsitiktinai();



int main(){
    studento_duomenu_gavimas(studentai);
    studento_duomenu_printinimas(studentai);
    return 0;
}

void studento_duomenu_gavimas(vector<Studentas> &studentai){
     while(true){
        int  duomenu_surasymo_pasirinkimas = studento_duomenu_surasymo_pasirinkimas();
        if (duomenu_surasymo_pasirinkimas == 1){
            visi_duomenys_surasomi_ranka();
        } else if (duomenu_surasymo_pasirinkimas == 2){
            surasoma_ranka_isskyrus_pazymius();
        } else if (duomenu_surasymo_pasirinkimas == 3){
            viskas_generuojama_atsitiktinai();
        } else if (duomenu_surasymo_pasirinkimas == 4){
            break;
        } else {
            cout << endl << "Pasirinkite veiksma is meniu! " << endl;
        }
}

}
void studento_duomenu_printinimas(vector<Studentas> &studentai){
    string skaiciavimo_budas;
    cout << "Norite apskaiciuoti v - Vidurki ar  m - Mediana? " << endl;
    cin >> skaiciavimo_budas;
    while(skaiciavimo_budas != "v" && skaiciavimo_budas != "m"){
        cout << "Pasirinkite ka norite apskaiciuoti. Vidurki ar Mediana?" << endl;
        cin >> skaiciavimo_budas;
    }

    cout << setw(13) << left << "Pavarde" << setw(12) << left << "Vardas"<< setw(12) << left << "Galutinis" << endl;
    cout << "----------------------------------" << endl;
    if (skaiciavimo_budas == "m"){
        for (int i = 0; i < studentu_kiekis; i ++){
        cout << setw(13) << left << studentai[i].pavarde << setw(12) << left << studentai[i].vardas << setw(12) << left << fixed << setprecision(2) << (studento_medianos_skaiciavimas(studentai[i].pazymiai, studentai[i].egzamino_pazymys)) << endl;
    } 
    }else if (skaiciavimo_budas == "v"){
        for (int i = 0; i < studentu_kiekis; i ++){
        cout << setw(13) << left << studentai[i].pavarde << setw(12) << left << studentai[i].vardas << setw(12) << left << fixed << setprecision(2) << (studento_vidurkio_skaiciavimas(studentai[i].pazymiai, studentai[i].egzamino_pazymys)) << endl;
    } 
    }
}

double studento_vidurkio_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys){
    int pazymiu_suma = 0;
    int pazymiu_kiekis = pazymiai.size();

    if (pazymiu_kiekis == 0){
        return 0.6 * egzamino_pazymys;
    }
    for (int i = 0; i < pazymiu_kiekis; i++){
        pazymiu_suma += pazymiai[i];
    }
    double pazymiu_vidurkis = pazymiu_suma * 1.0 / pazymiu_kiekis;
    double vidurkis = 0.4 * pazymiu_vidurkis + 0.6 * egzamino_pazymys;
    return vidurkis;
}
double studento_medianos_skaiciavimas(vector<int> pazymiai, int egzamino_pazymys){
    int pazymiu_kiekis = pazymiai.size();
    if (pazymiu_kiekis == 0){
        return 0.6 * egzamino_pazymys;
    }
    sort(pazymiai.begin(), pazymiai.end());
    double mediana;
    if(pazymiu_kiekis%2 == 0){
        mediana = (pazymiai[pazymiu_kiekis/2] + pazymiai[pazymiu_kiekis/2 -1]) / 2.0;
    } else{
        mediana = (pazymiai[pazymiu_kiekis/2]);
    }

    double vidurkis = 0.4 * mediana + 0.6 * egzamino_pazymys;
    return vidurkis;
}

void studento_vardo_ir_pavardes_gavimas(Studentas &laikinas_studentas){
    cout << "Ivesite studento pavarde ir varda:" << endl;
    cin >> laikinas_studentas.pavarde >> laikinas_studentas.vardas;
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

void studento_vardo_ir_pavardes_generavimas(Studentas &laikinas_studentas){
    srand(time(0));
    int vardo_indeksas = (rand()%10);
    int pavardes_indeksas = (rand()%10);

    cout << "Studento pavarde ir vardas: " << pavardes[pavardes_indeksas] <<" "<< vardai[vardo_indeksas] <<endl;
    
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
    cout << "1 - ranka," <<endl << "2 - generuoti pazymius," << endl << "3 - generuoti ir pazymius ir studentu vardus, pavardes," << endl << "4 - baigti darba" << endl;
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