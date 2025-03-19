# Projekto paleidimo instrukcija
1. Naudodami git, galite klonuoti si projekta su komanda `git clone https://github.com/LiveLiveta/Objektinis-Programavimas.git`
2. Sukurkite projekto .exe faila, paleisdami `make` komanda projekto direktorijoje
3. Paleiskite projekta, paleisdami `./vektoriai` komanda

# Testai

## Strategija 1

### Vector

||||||
|-|-|-|-|-|
|Studentu kiekis|Skaitymas|Rikiavimas|Skirstymas|
|1000|0.0067999 s|0.000899 s|0.0004967 s|
|10000|0.0451155 s|0.0144912 s|0.0055211 s|
|100000|0.379105 s|0.166723 s|0.0503665 s|
|1000000|3.25661 s|1.66952 s|0.473 s|
|10000000|33.9667 s|22.6545 s|6.74625 s|

### List

||||||
|-|-|-|-|-|
|Studentu kiekis|Skaitymas|Rikiavimas|Skirstymas|
|1000|0.0034584 s|0.0003085 s|0.0006098 s|
|10000|0.0362613 s|0.0045102 s|0.0055924 s|
|100000|0.394083 s|0.0845375 s|0.0645829 s|
|1000000|3.40987 s|0.957042 s|0.657971 s|
|10000000|34.4712 s|14.5161 s|8.5884 s|

### Deque

||||||
|-|-|-|-|-|
|Studentu kiekis|Skaitymas|Rikiavimas|Skirstymas|
|1000|0.0059507 s|0.0014088 s|0.0003574 s|
|10000|0.0339149 s|0.0182839 s|0.0046314 s|
|100000|0.338572 s|0.216443 s|0.0498382 s|
|1000000|3.3342 s|2.4227 s|0.44359 s|
|10000000|33.63 s|31.1429 s|6.70689 s|


## Strategija 2

### Vector

||||||
|-|-|-|-|-|
|Studentu kiekis|Skaitymas|Rikiavimas|Skirstymas|
|1000|0.0031301 s|0.000988 s|0.0003568 s|
|10000|0.0459206 s|0.0136961 s|0.0037891 s|
|100000|0.380268 s|0.173013 s|0.0339479 s|
|1000000|3.24247 s|1.83449 s|0.332318 s|
|10000000|34.2698 s|23.9199 s|5.06063 s|

### List

||||||
|-|-|-|-|-|
|Studentu kiekis|Skaitymas|Rikiavimas|Skirstymas|
|1000|0.0069925 s|0.000433 s|0.0008004 s|
|10000|0.0360031 s|0.0043048 s|0.0043097 s|
|100000|0.346095 s|0.086658 s|0.072307 s|
|1000000|3.32119 s|0.968775 s|0.708363 s|
|10000000|34.6489 s|14.5726 s|9.56166 s|

### Deque

||||||
|-|-|-|-|-|
|Studentu kiekis|Skaitymas|Rikiavimas|Skirstymas|
|1000|0.0030909 s|0.0014686 s|0.0004318 s|
|10000|0.0379952 s|0.0172257 s|0.0039548 s|
|100000|0.337375 s|0.216485 s|0.0437521 s|
|1000000|3.17983 s|2.38498 s|0.427251 s|
|10000000|33.7042 s|32.6965 s|6.71293 s|


## Strategija 3

### Vector

||||||
|-|-|-|-|-|
|Studentu kiekis|Skaitymas|Rikiavimas|Skirstymas|
|1000|0.0064402 s|0.001332 s|0.0005856 s|
|10000|0.0371594 s|0.012709 s|0.0044919 s|
|100000|0.357436 s|0.175865 s|0.0442798 s|
|1000000|3.13975 s|1.8639 s|0.437462 s|
|10000000|32.9613 s|24.1863 s|6.77008 s|

### List

||||||
|-|-|-|-|-|
|Studentu kiekis|Skaitymas|Rikiavimas|Skirstymas|
|1000|0.0031854 s|0.0004639 s|0.0010707 s|
|10000|0.0360607 s|0.0043548 s|0.0097693 s|
|100000|0.3659 s|0.0708206 s|0.094393 s|
|1000000|3.46133 s|0.979156 s|1.03381 s|
|10000000|34.2461 s|14.9582 s|12.695 s|

### Deque

||||||
|-|-|-|-|-|
|Studentu kiekis|Skaitymas|Rikiavimas|Skirstymas|
|1000|0.0068138 s|0.0016586 s|0.000408 s|
|10000|0.0394424 s|0.0174686 s|0.0055875 s|
|100000|0.329087 s|0.225474 s|0.0585586 s|
|1000000|3.09246 s|2.46338 s|0.544096 s|
|10000000|32.5397 s|31.3247 s|8.50725 s|

# Testu isvados

## Pastebejimai 
- **Skaitymo greitis** visoms duomenu strukturoms (`vector`, `list`, `deque`) yra panasus.
- **Rikiavimas**:
  - **`list` yra greiciausias**, ypac su dideliais duomenu kiekiais.
  - **`vector` yra vidutinis**.
  - **`deque` yra leciausias**, ypac su **10,000,000 studentu**.
- **Skirstymas**:
  - **`vector` yra greiciausias** del efektyvaus atminties isdestymo.
  - **`list` yra leciausias** del nuoseklios prieigos.
  - **`deque` siek tiek atsilieka nuo `vector`**, ypac su dideliais duomenu kiekiais.

## Duomenu strukturos pasirinkimas
| **Operacija**   | **Geriausia Struktūra** | **Priežastis** |
|----------------|------------------|--------------------------------------|
| **Skaitymas**  | Bet kuri         | Nedidelis skirtumas |
| **Rikiavimas** | **`list`**       | Greičiausias su dideliais duomenimis |
| **Skirstymas** | **`vector`**     | Efektyviausias dėl atminties išdėstymo |
| **Bendras pasirinkimas** | **Priklauso nuo prioritetų** | `list` geriausia rikiavimui, `vector` geriausia skirstymui |

## Rekomendacijos
- **Naudoti `list`, jei prioritetas - rikiavimo greitis**.
- **Naudoti `vector`, jei prioritetas - skirstymo našumas**.
- **Vengti `deque` rikiavimui**, nes jis leciausias.