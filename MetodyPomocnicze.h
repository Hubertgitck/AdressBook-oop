#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze{


public:
    string konwerjsaIntNaString(int liczba);
    string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    char wczytajZnak();
    bool czyPlikJestPusty(fstream &plikTekstowy);
    int konwersjaStringNaInt(string liczba);
    int wczytajLiczbeCalkowita();

};

#endif // METODYPOMOCNICZE_H
