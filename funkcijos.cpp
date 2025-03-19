#include "funkcijos.h"

void failo_su_studentais_generavimas(){

    int failo_generavimo_pasirinkimas;
    cout << "pasirinkite koki faila norite sugeneruoti: " << endl;
    cout << "1 - su 1000 studentu" << endl << "2 - su 10000 studentu" << endl << "3 - su 100000 studentu" << endl << "4 - su 1000000 studentu" << endl << "5 - su 10000000 studentu" << endl;
    cin >> failo_generavimo_pasirinkimas;

    if (!cin.fail() && failo_generavimo_pasirinkimas >= 1 && failo_generavimo_pasirinkimas <= 5){
        int pazymiu_kiekis;
        cout << "Iveskite kiek pazymiu tures studentai (nuo 1 iki 30): " << endl;
        cin >> pazymiu_kiekis;

        while (cin.fail() || pazymiu_kiekis < 1 || pazymiu_kiekis > 30){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    
            cout << "Iveskite kiek pazymiu tures studentai (nuo 1 iki 30): " << endl;
            cin >> pazymiu_kiekis;
        }
        studentu_kiekis = pasirinkimo_pavertimas_i_reiksme(failo_generavimo_pasirinkimas);
        failo_generavimas(studentu_kiekis, pazymiu_kiekis);
        return;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    
    failo_su_studentais_generavimas();
}
int pasirinkimo_pavertimas_i_reiksme(int failo_generavimo_pasirinkimas){
    if (failo_generavimo_pasirinkimas == 1){
        return 1000;
    } else if (failo_generavimo_pasirinkimas == 2){
        return 10000;
    } else if (failo_generavimo_pasirinkimas == 3){
        return 100000;
    } else if (failo_generavimo_pasirinkimas == 4){
        return 1000000;
    } else{
        return 10000000;
    }
}
void failo_generavimas(int studentu_kiekis, int pazymiu_kiekis){
    string failo_pavadinimo_pabaiga = ".txt";
    string failo_pavadinimas = "studentai" + to_string(studentu_kiekis) + failo_pavadinimo_pabaiga;

    ofstream failas (failo_pavadinimas);
    failas << setw(18) << left << ("Vardas") << setw(18) << left << ("Pavarde");

    for (int i = 1; i < pazymiu_kiekis; i++){
        failas << setw(8) << left << ("ND" + to_string(i));
    }
    failas << setw(8) << left << ("Egz.") << endl;

    for (int i = 0; i < studentu_kiekis; i++){
        failas << setw(18) << left << ("Vardas_N" + to_string(i + 1)) << setw(18) << left << ("Pavarde_N" + to_string(i + 1));
        for (int i = 0 ; i < pazymiu_kiekis; i++){
            failas << setw(8) << left << vieno_pazymio_sugeneravimas();
        }
        failas << endl;
    }

    failas.close();
}
int vieno_pazymio_sugeneravimas(){
    int pazymys = (rand()%10)+1;
    return pazymys;
}

void konteinerio_ir_strategijos_pasirinkimas(){
    string pasirinkimas_konteineris;
    string pasirinkimas_strategija;

    cout << "Pasirinkite su kokiu konteineriu norite leisti testus: " << endl;
    cout <<"v - Vector" << endl << "l - List" << endl << "d - Deque" << endl;
    cin >> pasirinkimas_konteineris;

    while (pasirinkimas_konteineris != "v" && pasirinkimas_konteineris != "V" && pasirinkimas_konteineris != "l" && pasirinkimas_konteineris != "L" && pasirinkimas_konteineris != "d" && pasirinkimas_konteineris != "D"){
        cout <<  "Pasirinkite su kokiu konteineriu norite leisti testus! :  "<< endl;
        cin >> pasirinkimas_konteineris;
    }  

    cout << "Pasirinkite strategija: " << endl;
    cout <<"1 - pirma" << endl << "2 - antra" << endl << "3 - trecia" << endl;
    cin >> pasirinkimas_strategija;

    while (pasirinkimas_strategija != "1" && pasirinkimas_strategija != "2" && pasirinkimas_strategija != "3"){
        cout <<  "Pasirinkite strategija! :  "<< endl;
        cin >> pasirinkimas_strategija;
    }
    

    if (pasirinkimas_strategija == "1"){
        if(pasirinkimas_konteineris == "v"){
            strategija_1<vector<Studentas>>();
        }else if(pasirinkimas_konteineris == "l"){
            strategija_1<list<Studentas>>();
        }if(pasirinkimas_konteineris == "d"){
            strategija_1<deque<Studentas>>();
        }
    }else if (pasirinkimas_strategija == "2"){
        if(pasirinkimas_konteineris == "v"){
            strategija_2<vector<Studentas>>();
        }else if(pasirinkimas_konteineris == "l"){
            strategija_2<list<Studentas>>();
        }if(pasirinkimas_konteineris == "d"){
            strategija_2<deque<Studentas>>();
        }
    }else if(pasirinkimas_strategija == "3"){
        if(pasirinkimas_konteineris == "v"){
            strategija_3<vector<Studentas>>();
        }else if(pasirinkimas_konteineris == "l"){
            strategija_3<list<Studentas>>();
        }if(pasirinkimas_konteineris == "d"){
            strategija_3<deque<Studentas>>();
        }
    }

}

void studento_duomenu_gavimas(vector<Studentas>& studentai){
    while(true){
        try{
            int  duomenu_surasymo_pasirinkimas = studento_duomenu_surasymo_pasirinkimas();
            if (duomenu_surasymo_pasirinkimas == 1){
                visi_duomenys_surasomi_ranka();
            } else if (duomenu_surasymo_pasirinkimas == 2){
                surasoma_ranka_isskyrus_pazymius();
            } else if (duomenu_surasymo_pasirinkimas == 3){
                viskas_generuojama_atsitiktinai();
            } else if (duomenu_surasymo_pasirinkimas == 4){
                studento_duomenu_skaitymas_is_failo(studentai);
            } else if (duomenu_surasymo_pasirinkimas == 5){
                failo_su_studentais_generavimas();
            } else if  (duomenu_surasymo_pasirinkimas == 6){
                konteinerio_ir_strategijos_pasirinkimas();
            } else if(duomenu_surasymo_pasirinkimas == 7){
                cout << "Atlikta operaciju: " << operaciju_kiekis << endl;
                cout << endl << "Operacija vidutiniskai uztruko: " << laiku_vidurkio_skaiciavimas(operaciju_laikai) << " s" << endl;
                break;
            } else {
                throw runtime_error("\nPasirinkite veiksma is meniu! \n");
            }
        }catch(exception &eroras){
            cout <<"Klaida: " <<eroras.what()<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');          
        }
   }
}
int studento_duomenu_surasymo_pasirinkimas(){
    int duomenu_surasymo_pasirinkimas;
    cout << endl << "Pasirinkite norima duomenu surasymo buda is galimu variantu: "<< endl;
    cout << "1 - ranka," <<endl << "2 - generuoti pazymius," << endl << "3 - generuoti ir pazymius ir studentu vardus, pavardes," << endl << "4 - skaityti duomenis is failo," << endl  <<"5 - generuoti faila" << endl << "6 - atlikti pasirinkto failo testus" << endl << "7 - baigti darba" << endl;
    cout << "Jusu pasirinkimas: ";
    cin >> duomenu_surasymo_pasirinkimas;
    cout << endl;
    return duomenu_surasymo_pasirinkimas;
 }
double laiku_vidurkio_skaiciavimas(vector<double> &operaciju_laikai){
   int operaciju_kiekis = operaciju_laikai.size();

    if (operaciju_kiekis == 0){
        return 0;
    }

   double visas_laikas = 0;

   for (int i = 0; i < operaciju_kiekis; i++){
       visas_laikas += operaciju_laikai[i];
   }

   double vidurkis = visas_laikas / operaciju_kiekis;
   return vidurkis;
}

void studento_duomenu_printinimas(vector<Studentas> &studentai){
    if (studentai.size() == 0){
        return;
    }
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
       for (int i = 0; i < studentai.size(); i ++){
           cout << setw(13) << left << studentai[i].vardas << setw(12) << left << studentai[i].pavarde << setw(20) << left << fixed << setprecision(2) << studentai[i].vidurkis << setw(20) << studentai[i].mediana << endl;
           }  
   }else if (irasimo_budas == "f"){
        duomenu_surasymas_i_faila(studentai, failo_pavadinimas);
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

   switch (rusiuoti_pagal){
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

   if (a.vardas.substr(0, 8) == "Vardas_N" && b.vardas.substr(0, 8) == "Vardas_N"){
       int sk1 = stoi(a.vardas.substr(8));
       int sk2 = stoi(b.vardas.substr(8));
       return sk1 < sk2;
   }
   string vardas_a = a.vardas;
   string vardas_b = b.vardas;
   transform(vardas_a.begin(), vardas_a.end(), vardas_a.begin(), tolower);
   transform(vardas_b.begin(), vardas_b.end(), vardas_b.begin(), tolower);
   return vardas_a < vardas_b;
}
bool rikiuoti_pagal_pavarde(Studentas &a, Studentas &b){
   if (a.pavarde.substr(0, 9) == "Pavarde_N" && b.pavarde.substr(0, 9) == "Pavarde_N"){
       int sk1 = stoi(a.pavarde.substr(9));
       int sk2 = stoi(b.pavarde.substr(9));
       return sk1 < sk2;
   }
   string pavarde_a = a.pavarde;
   string pavarde_b = b.pavarde;
   transform(pavarde_a.begin(), pavarde_a.end(), pavarde_a.begin(), tolower);
   transform(pavarde_b.begin(), pavarde_b.end(), pavarde_b.begin(), tolower);
   return pavarde_a < pavarde_b;
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

// void studento_vidurkio_skaiciavimas(vector<Studentas> &studentai){

//    for (int i = 0; i < studentai.size(); i++){
//        int pazymiu_suma = 0;
//        int pazymiu_kiekis = studentai[i].pazymiai.size();
   
//        if (pazymiu_kiekis == 0){
//            studentai[i].vidurkis = 0.6 * studentai[i].egzamino_pazymys;
//        } else{ 
//            for (int j = 0; j < pazymiu_kiekis; j++){
//                pazymiu_suma += studentai[i].pazymiai[j];
//            }
//            double pazymiu_vidurkis = pazymiu_suma * 1.0 / pazymiu_kiekis;
//            double vidurkis = 0.4 * pazymiu_vidurkis + 0.6 * studentai[i].egzamino_pazymys;
//            studentai[i].vidurkis = vidurkis;
//        }
//    }
// }
// void studento_medianos_skaiciavimas(vector<Studentas> &studentai){
//    for (int i = 0; i < studentai.size(); i++){
//        int pazymiu_kiekis = studentai[i].pazymiai.size();
//        if (pazymiu_kiekis == 0){
//            studentai[i].mediana =  0.6 * studentai[i].egzamino_pazymys;
//        }else{ 
//            sort(studentai[i].pazymiai.begin(), studentai[i].pazymiai.end());
//            double mediana;
//            if(pazymiu_kiekis%2 == 0){
//                mediana = (studentai[i].pazymiai[pazymiu_kiekis/2] + studentai[i].pazymiai[pazymiu_kiekis/2 -1]) / 2.0;
//            } else{
//                mediana = (studentai[i].pazymiai[pazymiu_kiekis/2]);
//            }
       
//            double vidurkis = 0.4 * mediana + 0.6 * studentai[i].egzamino_pazymys;
//            studentai[i].mediana = vidurkis;
//        }
//    }
// }

void studento_vardo_ir_pavardes_gavimas(Studentas &laikinas_studentas){
   cout << "Ivesite studento varda ir pavarde:" << endl;
   cin >> laikinas_studentas.vardas >> laikinas_studentas.pavarde;
   cout << endl;
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

// void studento_duomenu_skaitymas_is_failo(vector<Studentas>& studentai){
//    string failo_pavadinimas;
//    cout << "Iveskite norimo nuskaityti failo pavadinima: " << endl;
//    cin >> failo_pavadinimas;

// void studento_duomenu_is_failo_susirasymas(vector<Studentas> &studentai, string& failo_pavadinimas){
//    auto pradzia = std::chrono::high_resolution_clock::now();

//    ifstream failas(failo_pavadinimas);
//    string antrastine_eilute;
//    getline(failas, antrastine_eilute);

//    string eilute;

//    while(getline(failas, eilute)){
//        Studentas laikinas_studentas;
//        stringstream eil(eilute);
//        eil >> laikinas_studentas.vardas >> laikinas_studentas.pavarde;
//        int pazymys;
//        while (eil >> pazymys){
//            laikinas_studentas.pazymiai.push_back(pazymys);
//        }
//        laikinas_studentas.egzamino_pazymys = laikinas_studentas.pazymiai.back();
//        laikinas_studentas.pazymiai.pop_back();
//        studentai.push_back(laikinas_studentas);
//    }
//    operaciju_kiekis += 1;
   
//    auto pabaiga = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> trukme = pabaiga - pradzia;
//    cout << endl << "duomenu is failo nuskaitymas uztruko: " << trukme.count() << " s" << endl;
//    operaciju_laikai.push_back(trukme.count());
//    failas.close();
// }
void tikrinimas_ar_pavyko_atidaryti_faila(string& failo_pavadinimas){

    ifstream failas(failo_pavadinimas);
    if (!failas){
        throw runtime_error("Nepavyko atidaryti failo! Iveskite tinkama failo pavadinima: ");
    }
    failas.close();
}

void studento_vardo_ir_pavardes_generavimas(Studentas &laikinas_studentas){
   int vardo_indeksas = (rand()%10);
   int pavardes_indeksas = (rand()%10);

   cout << "Studento vardas pavarde: " << vardai[vardo_indeksas] <<" "<< pavardes[pavardes_indeksas] <<endl;
   
   laikinas_studentas.pavarde = pavardes[pavardes_indeksas];
   laikinas_studentas.vardas = vardai[vardo_indeksas];
}
void studento_pazymiu_ir_egzaminu_generavimas(Studentas &laikinas_studentas){
   
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