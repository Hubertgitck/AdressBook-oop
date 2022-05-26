#include "UzytkownikMenedzer.h"

using namespace std;

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::rejestracjaUzytkownika(){

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << '\n' << "Konto zalozono pomyslnie" << '\n' << '\n';
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika(){

    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do{
        cout << "Podaj login: ";
        uzytkownik.ustawLogin(metodyPomocnicze.wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()));

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(metodyPomocnicze.wczytajLinie());

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty())
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login){

    for (int i = 0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login){
            cout << '\n' << "Istnieje uzytkownik o takim loginie." << '\n';
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow(){

    for (int i = 0; i < uzytkownicy.size(); i++){
        cout << uzytkownicy[i].pobierzLogin() << '\n';
        cout << uzytkownicy[i].pobierzHaslo() << '\n';
    }
}

int UzytkownikMenedzer::logowanieUzytkownika(){

    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << '\n' << "Podaj login: ";
    login = metodyPomocnicze.wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()){
        if (itr -> pobierzLogin() == login){
            for (int iloscProb = 3; iloscProb > 0; iloscProb--){
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metodyPomocnicze.wczytajLinie();

                if (itr -> pobierzHaslo() == haslo){
                    cout << '\n' << "Zalogowales sie." << '\n' << '\n';
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    return idZalogowanegoUzytkownika ;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << '\n';
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << '\n' << '\n';
    system("pause");
    return 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika(){

    Uzytkownik uzytkownik;
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = metodyPomocnicze.wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++){
        if (itr -> pobierzId() == idZalogowanegoUzytkownika){
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << '\n' << '\n';
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wylogowanieUzytkownika(){
    idZalogowanegoUzytkownika = 0;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany(){
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}
