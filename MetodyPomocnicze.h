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
    bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int konwersjaStringNaInt(string liczba);

};

#endif // METODYPOMOCNICZE_H
