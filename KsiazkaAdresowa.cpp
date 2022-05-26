#include "KsiazkaAdresowa.h"

void  KsiazkaAdresowa::rejestracjaUzytkownika(){

    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){

    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){

    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){

    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::dodajAdresata(){

    adresatMenedzer -> dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){

    adresatMenedzer -> wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){

    adresatMenedzer -> wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){

    adresatMenedzer -> wyszukajAdresatowPoNazwisku();
}

void KsiazkaAdresowa::edytujAdresata(){

    adresatMenedzer -> edytujAdresata();
}

void KsiazkaAdresowa::usunAdresata(){

    adresatMenedzer -> usunAdresata();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego(){

    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << '\n';
    cout << "---------------------------" << '\n';
    cout << "1. Rejestracja" << '\n';
    cout << "2. Logowanie" << '\n';
    cout << "9. Koniec programu" << '\n';
    cout << "---------------------------" << '\n';
    cout << "Twoj wybor: ";

    wybor = metodyPomocnicze.wczytajZnak();
    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika(){
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << '\n';
    cout << "---------------------------" << '\n';
    cout << "1. Dodaj adresata" << '\n';
    cout << "2. Wyszukaj po imieniu" << '\n';
    cout << "3. Wyszukaj po nazwisku" << '\n';
    cout << "4. Wyswietl adresatow" << '\n';
    cout << "5. Usun adresata" << '\n';
    cout << "6. Edytuj adresata" << '\n';
    cout << "---------------------------" << '\n';
    cout << "7. Zmien haslo" << '\n';
    cout << "8. Wyloguj sie" << '\n';
    cout << "---------------------------" << '\n';
    cout << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany(){

    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        return true;
    else
        return false;
}





