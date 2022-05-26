#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba){
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba){
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}


string MetodyPomocnicze::wczytajLinie(){
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

bool MetodyPomocnicze::czyPlikJestPusty(fstream &plikTekstowy){
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst){
    if (!tekst.empty()){
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int MetodyPomocnicze::wczytajLiczbeCalkowita(){

    string wejscie = "";
    int liczba = 0;

    while (true){
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << '\n';
    }
    return liczba;
}

char MetodyPomocnicze::wczytajZnak(){

    string wejscie = "";
    char znak  = {0};

    while (true){
        getline(cin, wejscie);

        if (wejscie.length() == 1){
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << '\n';
    }
    return znak;
}
