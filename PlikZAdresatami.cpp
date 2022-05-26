#include "PlikZAdresatami.h"

using namespace std;

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat){

    fstream plikTekstowy;
    string liniaZDanymiAdresata = "";
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good()){
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (metodyPomocnicze.czyPlikJestPusty(plikTekstowy)){
            plikTekstowy << liniaZDanymiAdresata;
        }
        else{
            plikTekstowy << '\n' << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat){

    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += metodyPomocnicze.konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += metodyPomocnicze.konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika){

    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    vector <Adresat> adresaci;
    plikTekstowy.open("Adresaci.txt", ios::in);

    if (plikTekstowy.good()){
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)){
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)){
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << '\n';

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != ""){
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    else
        return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami){

    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = metodyPomocnicze.konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami){

    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++){
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|'){
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else{
            switch(numerPojedynczejDanejAdresata){
                case 1:
                    adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                    break;
                case 2:
                    adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                    break;
                case 3:
                    adresat.ustawImie(pojedynczaDanaAdresata);
                    break;
                case 4:
                    adresat.ustawNazwisko(pojedynczaDanaAdresata);
                    break;
                case 5:
                    adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                    break;
                case 6:
                    adresat.ustawEmail(pojedynczaDanaAdresata);
                    break;
                case 7:
                    adresat.ustawAdres(pojedynczaDanaAdresata);
                    break;
                }
        pojedynczaDanaAdresata = "";
        numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami){

    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = metodyPomocnicze.konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku){

    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true){
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata(){

    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunWybranaLinieWPliku(int idUsuwanegoAdresata){

    int idAdresataPobraneZPlikuInt,idKolejnegoAdresataPobraneZPlikuInt, idPrzedostatniegoAdresata;
    string liniaRobocza,kolejnaLinia;

    ifstream plikTekstowy;
    plikTekstowy.open("Adresaci.txt");

    ofstream plikTymczasowy;
    plikTymczasowy.open("temp.txt",ios::out|ios::app);

    getline(plikTekstowy,liniaRobocza);
    idAdresataPobraneZPlikuInt = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaRobocza);

    while (getline(plikTekstowy, kolejnaLinia)){

        idKolejnegoAdresataPobraneZPlikuInt = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(kolejnaLinia);

        if (idAdresataPobraneZPlikuInt != idUsuwanegoAdresata){
            if (idKolejnegoAdresataPobraneZPlikuInt == idOstatniegoAdresata && idKolejnegoAdresataPobraneZPlikuInt == idUsuwanegoAdresata){
                plikTymczasowy << liniaRobocza;
            }
            else{
                plikTymczasowy << liniaRobocza << '\n' ;
            }
        }
        idPrzedostatniegoAdresata = idAdresataPobraneZPlikuInt;
        liniaRobocza = kolejnaLinia;
        idAdresataPobraneZPlikuInt = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaRobocza);
    }
    if (idAdresataPobraneZPlikuInt != idUsuwanegoAdresata){
        plikTymczasowy << liniaRobocza;
        idOstatniegoAdresata = idAdresataPobraneZPlikuInt;
    }
    else{
        idOstatniegoAdresata = idPrzedostatniegoAdresata;
    }
    plikTekstowy.close();
    plikTymczasowy.close();

    remove("Adresaci.txt");
    rename("temp.txt", "Adresaci.txt");
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata (Adresat adresat, int idEdytowanegoAdresata){

    int idAdresataPobraneZPlikuInt = 0, idUzytkownikaPobraneZPlikuInt = 0;
    string liniaRobocza = "", idUzytkownikaPobraneZPliku = "";

    ifstream plikTekstowy("Adresaci.txt");
    ofstream plikTymczasowy;
    plikTymczasowy.open("temp.txt",ios::out|ios::app);

    while(getline(plikTekstowy,liniaRobocza, '\n')) {

        idAdresataPobraneZPlikuInt = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaRobocza);

        if (idAdresataPobraneZPlikuInt == idEdytowanegoAdresata){
            plikTymczasowy << idEdytowanegoAdresata << '|' << adresat.pobierzIdUzytkownika() << '|';
            plikTymczasowy << adresat.pobierzImie()  << '|' << adresat.pobierzNazwisko() << '|' << adresat.pobierzEmail() << '|'
            << adresat.pobierzNumerTelefonu() << '|' << adresat.pobierzAdres()<< '|';
        }
        else
            plikTymczasowy << liniaRobocza;

        if (idAdresataPobraneZPlikuInt != idOstatniegoAdresata)
            plikTymczasowy << '\n';
    }
    plikTekstowy.close();
    plikTymczasowy.close();

    remove("Adresaci.txt");
    rename("temp.txt", "Adresaci.txt");
}
