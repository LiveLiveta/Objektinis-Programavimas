#include "pagalbines.h"
#ifndef functions_h
#define functions_h

struct Studentas {
    string pavarde;
    string vardas;
    vector<int> pazymiai;
    int egzamino_pazymys;
    double vidurkis;
    double  mediana;
};

extern const int PRADINIS_DYDIS;
extern int studentu_kiekis;
extern vector<string> vardai;
extern vector<string> pavardes;
extern vector<Studentas> studentai;
extern vector<double> operaciju_laikai;
extern int operaciju_kiekis;

void studento_duomenu_gavimas();
int studento_duomenu_surasymo_pasirinkimas();
double laiku_vidurkio_skaiciavimas(vector<double> &operaciju_laikai);

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
void tikrinimas_ar_pavyko_atidaryti_faila(string& failo_pavadinimas);

void studento_pazymiu_ir_egzaminu_generavimas(Studentas &laikinas_studentas);
int gauk_kiek_pazimiu_sugeneruoti();
void studento_vardo_ir_pavardes_generavimas(Studentas &laikinas_studentas);

void visi_duomenys_surasomi_ranka();
void surasoma_ranka_isskyrus_pazymius();
void viskas_generuojama_atsitiktinai();

#endif