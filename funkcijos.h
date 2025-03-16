#include "pagalbines.h"
#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

struct Studentas {
    string pavarde;
    string vardas;
    vector<int> pazymiai;
    int egzamino_pazymys;
    double vidurkis;
    double  mediana;
};

extern int studentu_kiekis;
extern vector<string> vardai;
extern vector<string> pavardes;
extern vector<Studentas> studentai;
extern vector<double> operaciju_laikai;
extern int operaciju_kiekis;

void failo_su_studentais_generavimas();
int pasirinkimo_pavertimas_i_reiksme(int failo_generavimo_pasirinkimas);
void failo_generavimas(int studentu_kiekis, int pazymiu_kiekis);
int vieno_pazymio_sugeneravimas();
// void studentu_rusiavimas_i_kietus_ir_vargsus_ir_testai();

void studento_duomenu_gavimas(vector<Studentas> &studentai);
int studento_duomenu_surasymo_pasirinkimas();
double laiku_vidurkio_skaiciavimas(vector<double> &operaciju_laikai);

// void duomenu_surasymas_i_faila(vector<Studentas> studentai, string failo_pavadinimas);
void studento_duomenu_printinimas(vector<Studentas> &studentai);
void studento_duomenu_rikiavimas(vector<Studentas> &studentai);
bool rikiuoti_pagal_varda(Studentas &a, Studentas &b);
bool rikiuoti_pagal_pavarde(Studentas &a, Studentas &b);
bool rikiuoti_pagal_vidurkis(Studentas &a, Studentas &b);
bool rikiuoti_pagal_mediana(Studentas &a, Studentas &b);
bool baigiasi_su_txt(string failo_pavadinimas);

// void studento_vidurkio_skaiciavimas(vector<Studentas> &studentai);
// void studento_medianos_skaiciavimas(vector<Studentas> &studentai);

void studento_vardo_ir_pavardes_gavimas(Studentas &laikinas_studentas);
void studento_pazymiu_gavimas(Studentas &laikinas_studentas);
void studento_egzamino_pazymio_gavimas(Studentas &laikinas_studentas);

// void studento_duomenu_skaitymas_is_failo(vector<Studentas> &studentai);
// void studento_duomenu_is_failo_susirasymas(vector<Studentas> &studentai, string& failo_pavadinimas);
void tikrinimas_ar_pavyko_atidaryti_faila(string& failo_pavadinimas);

void studento_pazymiu_ir_egzaminu_generavimas(Studentas &laikinas_studentas);
int gauk_kiek_pazimiu_sugeneruoti();
void studento_vardo_ir_pavardes_generavimas(Studentas &laikinas_studentas);

void visi_duomenys_surasomi_ranka();
void surasoma_ranka_isskyrus_pazymius();
void viskas_generuojama_atsitiktinai();


template <typename konteineris>
void studento_medianos_skaiciavimas(konteineris &studentai){
    for (auto it = studentai.begin(); it != studentai.end(); ++it){
        int pazymiu_kiekis = it->pazymiai.size();

        if (pazymiu_kiekis == 0) {
            it->mediana = 0.6 * it->egzamino_pazymys;
        } else { 
            vector<int> laikini_pazymiai(it->pazymiai.begin(), it->pazymiai.end());
            sort(laikini_pazymiai.begin(), laikini_pazymiai.end());

            double mediana;
            if (pazymiu_kiekis % 2 == 0) {
                mediana = (laikini_pazymiai[pazymiu_kiekis / 2] + laikini_pazymiai[pazymiu_kiekis / 2 - 1]) / 2.0;
            } else {
                mediana = laikini_pazymiai[pazymiu_kiekis / 2];
            }

            double vidurkis = 0.4 * mediana + 0.6 * it->egzamino_pazymys;
            it->mediana = vidurkis;
        }
    }
}
template <typename konteineris>
void duomenu_surasymas_i_faila(konteineris studentai, string failo_pavadinimas){
    ofstream failas(failo_pavadinimas);
    failas << setw(18) << left << "Vardas" << setw(18) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" <<endl;
    failas << "--------------------------------------------------------------" << endl;

    for (auto iteratorius = studentai.begin(); iteratorius != studentai.end(); ++iteratorius) {
        failas << std::setw(18) << std::left << iteratorius->vardas
                << std::setw(18) << std::left << iteratorius->pavarde
                << std::setw(20) << std::left << std::fixed << std::setprecision(2) << iteratorius->vidurkis
                << std::setw(20) << iteratorius->mediana 
                << std::endl;
    }

    failas.close(); 
}

template <typename konteineris>
void studento_vidurkio_skaiciavimas(konteineris &studentai){

    for (auto iteratorius = studentai.begin(); iteratorius != studentai.end(); ++iteratorius) { 
        int pazymiu_suma = 0;
        int pazymiu_kiekis = iteratorius->pazymiai.size();
    
        if (pazymiu_kiekis == 0){
             iteratorius->vidurkis = 0.6 * iteratorius->egzamino_pazymys;
        } else{ 
            for (int j = 0; j < pazymiu_kiekis; j++){
              pazymiu_suma += iteratorius->pazymiai[j];
            }
            double pazymiu_vidurkis = pazymiu_suma * 1.0 / pazymiu_kiekis;
            double vidurkis = 0.4 * pazymiu_vidurkis + 0.6 * iteratorius->egzamino_pazymys;
            iteratorius->vidurkis = vidurkis;
        }
    }
 }

template <typename konteineris>
void studento_duomenu_is_failo_susirasymas(konteineris&studentai, string& failo_pavadinimas){
    auto pradzia = std::chrono::high_resolution_clock::now();
 
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
        studentai.push_back(laikinas_studentas);
    }
    operaciju_kiekis += 1;
    
    auto pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> trukme = pabaiga - pradzia;
    cout << endl << "duomenu is failo nuskaitymas uztruko: " << trukme.count() << " s" << endl;
    operaciju_laikai.push_back(trukme.count());
    failas.close();
 }

template <typename konteineris>
void studento_duomenu_skaitymas_is_failo(konteineris& studentai){
    string failo_pavadinimas;
    cout << "Iveskite norimo nuskaityti failo pavadinima: " << endl;
    cin >> failo_pavadinimas;
 
     while (true){
         try{
             tikrinimas_ar_pavyko_atidaryti_faila(failo_pavadinimas);
             break;
         }catch(exception &eroras){
             cout << eroras.what() << endl;
             cin >> failo_pavadinimas;
         }
     }
    cout << "Failas atidarytas sekmingai!" << endl;
    studento_duomenu_is_failo_susirasymas(studentai, failo_pavadinimas);
 
 }

template <typename konteineris>
void strategija_1(){
    
    konteineris visi;
    konteineris vargsiukai;
    konteineris kietiakiai;

    studento_duomenu_skaitymas_is_failo(visi);
    studento_vidurkio_skaiciavimas(visi);

    auto rikiavimo_pradzia = std::chrono::high_resolution_clock::now();

    if constexpr (is_same_v<konteineris, list<Studentas>>) {
        visi.sort(rikiuoti_pagal_vidurkis);
    } else{
        sort(visi.begin(), visi.end(), rikiuoti_pagal_vidurkis);
    }

    auto rikiavimo_pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> rikiavimo_trukme = rikiavimo_pabaiga - rikiavimo_pradzia;
    cout << endl << "Duomenu rikiavimas nuo didziausio vidurkio iki maziausio uztruko: " << rikiavimo_trukme.count() << " s" << endl;

    auto isskirstymo_pradzia = std::chrono::high_resolution_clock::now();

    for (auto it = visi.begin(); it != visi.end(); ++it) {
        if (it->vidurkis >= 5) {
            kietiakiai.push_back(*it);
        } else {
            vargsiukai.push_back(*it); 
        }
    }
    
    auto isskirstymo_pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> isskirstymo_trukme = isskirstymo_pabaiga - isskirstymo_pradzia;
    cout << endl << "Duomenu isskirstymas i kietiakus ir vargsiukus uztruko: " << isskirstymo_trukme.count() << " s" << endl;


    string failo_pavadinimo_pabaiga = ".txt";
    string failo_pavadinimas_kieti = "kietiakiai" + to_string(kietiakiai.size()) + failo_pavadinimo_pabaiga;
    string failo_pavadinimas_vargsai = "vargsiukai" + to_string(vargsiukai.size()) + failo_pavadinimo_pabaiga;

    studento_vidurkio_skaiciavimas(kietiakiai);
    studento_vidurkio_skaiciavimas(vargsiukai);
    studento_medianos_skaiciavimas(kietiakiai);
    studento_medianos_skaiciavimas(vargsiukai);
    duomenu_surasymas_i_faila(kietiakiai, failo_pavadinimas_kieti);
    duomenu_surasymas_i_faila(vargsiukai, failo_pavadinimas_vargsai);   
}

template <typename konteineris>
void strategija_2(){
    
    konteineris visi;
    konteineris vargsiukai;

    studento_duomenu_skaitymas_is_failo(visi);
    studento_vidurkio_skaiciavimas(visi);

    auto rikiavimo_pradzia = std::chrono::high_resolution_clock::now();

    if constexpr (is_same_v<konteineris, list<Studentas>>) {
        visi.sort(rikiuoti_pagal_vidurkis);
    } else{
        sort(visi.begin(), visi.end(), rikiuoti_pagal_vidurkis);
    }

    auto rikiavimo_pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> rikiavimo_trukme = rikiavimo_pabaiga - rikiavimo_pradzia;
    cout << endl << "Duomenu rikiavimas nuo didziausio vidurkio iki maziausio uztruko: " << rikiavimo_trukme.count() << " s" << endl;

    auto isskirstymo_pradzia = std::chrono::high_resolution_clock::now();

    for (auto it = visi.begin(); it != visi.end();) {
        if (it->vidurkis < 5) {
            vargsiukai.push_back(*it);
            it = visi.erase(it);
        }else{
            ++it;
        }
    }
    
    auto isskirstymo_pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> isskirstymo_trukme = isskirstymo_pabaiga - isskirstymo_pradzia;
    cout << endl << "Duomenu isskirstymas i kietiakus ir vargsiukus uztruko: " << isskirstymo_trukme.count() << " s" << endl;


    string failo_pavadinimo_pabaiga = ".txt";
    string failo_pavadinimas_kieti = "kietiakiai" + to_string(visi.size()) + failo_pavadinimo_pabaiga;
    string failo_pavadinimas_vargsai = "vargsiukai" + to_string(vargsiukai.size()) + failo_pavadinimo_pabaiga;

    studento_vidurkio_skaiciavimas(visi);
    studento_vidurkio_skaiciavimas(vargsiukai);
    studento_medianos_skaiciavimas(visi);
    studento_medianos_skaiciavimas(vargsiukai);
    duomenu_surasymas_i_faila(visi, failo_pavadinimas_kieti);
    duomenu_surasymas_i_faila(vargsiukai, failo_pavadinimas_vargsai);   
}

template <typename konteineris>
void strategija_3(){
    
    konteineris visi;
    studento_duomenu_skaitymas_is_failo(visi);
    studento_vidurkio_skaiciavimas(visi);

    auto rikiavimo_pradzia = std::chrono::high_resolution_clock::now();
    if constexpr (is_same_v<konteineris, list<Studentas>>) {
        visi.sort(rikiuoti_pagal_vidurkis);
    } else {
        sort(visi.begin(), visi.end(), rikiuoti_pagal_vidurkis);
    }
    auto rikiavimo_pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> rikiavimo_trukme = rikiavimo_pabaiga - rikiavimo_pradzia;
    cout << "\nDuomenu rikiavimas nuo didziausio vidurkio iki maziausio uztruko: " << rikiavimo_trukme.count() << " s" << endl;

    auto isskirstymo_pradzia = std::chrono::high_resolution_clock::now();
    
    // Partitioning students into two groups using stable_partition
    auto it = stable_partition(visi.begin(), visi.end(), [](const Studentas& s) {
        return s.vidurkis >= 5;
    });
    
    konteineris kietiakiai(visi.begin(), it);
    konteineris vargsiukai(it, visi.end());

    auto isskirstymo_pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> isskirstymo_trukme = isskirstymo_pabaiga - isskirstymo_pradzia;
    cout << "\nDuomenu isskirstymas i kietiakus ir vargsiukus uztruko: " << isskirstymo_trukme.count() << " s" << endl;

    string failo_pavadinimo_pabaiga = ".txt";
    string failo_pavadinimas_kieti = "kietiakiai" + to_string(kietiakiai.size()) + failo_pavadinimo_pabaiga;
    string failo_pavadinimas_vargsai = "vargsiukai" + to_string(vargsiukai.size()) + failo_pavadinimo_pabaiga;

    studento_vidurkio_skaiciavimas(kietiakiai);
    studento_vidurkio_skaiciavimas(vargsiukai);
    studento_medianos_skaiciavimas(kietiakiai);
    studento_medianos_skaiciavimas(vargsiukai);
    duomenu_surasymas_i_faila(kietiakiai, failo_pavadinimas_kieti);
    duomenu_surasymas_i_faila(vargsiukai, failo_pavadinimas_vargsai);
}

#endif