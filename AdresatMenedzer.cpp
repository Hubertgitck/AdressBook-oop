#include "AdresatMenedzer.h"


using namespace std;


void AdresatMenedzer::dodajAdresata(){
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << '\n' << '\n';
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany" << '\n';
    else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << '\n';
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(){

    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(metodyPomocnicze.wczytajLinie());
    adresat.ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(metodyPomocnicze.wczytajLinie());
    adresat.ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(metodyPomocnicze.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metodyPomocnicze.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(metodyPomocnicze.wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow(){

    system("cls");
    Adresat adresat;
    if (!adresaci.empty()){
        cout << "             >>> ADRESACI <<<" << '\n';
        cout << "-----------------------------------------------" << '\n';
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
            wyswietlDaneAdresata(*itr);
        }
        cout << '\n';
    }
    else{
        cout << '\n' << "Ksiazka adresowa jest pusta." << '\n' << '\n';
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat){

    cout << '\n' << "Id:                 " << adresat.pobierzId() << '\n';
    cout << "Imie:               " << adresat.pobierzImie() << '\n';
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << '\n';
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << '\n';
    cout << "Email:              " << adresat.pobierzEmail() << '\n';
    cout << "Adres:              " << adresat.pobierzAdres() << '\n';
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu(){

    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()){
        cout << ">>> WYSZUKIWANIE ADRESATOW PO IMIENIU <<<" << '\n' << '\n';
        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        imiePoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++){
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata){
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else{
        cout << '\n' << "Ksiazka adresowa jest pusta" << '\n' << '\n';
    }
    cout << '\n';
    system("pause");
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow){

    if (iloscAdresatow == 0)
        cout << '\n' << "W ksiazce adresowej nie ma adresatow z tymi danymi." << '\n';
    else
        cout << '\n' << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << '\n' << '\n';
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku(){

    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()){
        cout << ">>> WYSZUKIWANIE ADRESATOW PO NAZWISKU <<<" << '\n' << '\n';
        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata){
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else{
        cout << '\n' << "Ksiazka adresowa jest pusta." << '\n' << '\n';
    }
    cout << '\n';
    system("pause");
}

void AdresatMenedzer::usunAdresata(){

    int idUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << '\n' << '\n';
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
        if (itr -> pobierzId() == idUsuwanegoAdresata){
            czyIstniejeAdresat = true;
            cout << '\n' << "Potwierdz naciskajac klawisz 't' lub 'n' jesli chcesz anulowac ";
            znak = metodyPomocnicze.wczytajZnak();
            if (znak == 't'){
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << '\n' << '\n' << "Szukany adresat ZOSTAL usuniety" << '\n' << '\n';
                system("pause");
                return;
            }
            else{
                cout << '\n' << '\n' << "Wybrany adresat NIE zostal usuniety" << '\n' << '\n';
                system("pause");
                return;
            }
        }
    }
    if (!czyIstniejeAdresat){
        cout << '\n' << "Nie ma adresata o podanym ID("<< idUsuwanegoAdresata<< ") w twojej ksiazce adresowej" << '\n' << '\n';
        system("pause");
    }
}

int AdresatMenedzer::podajIdWybranegoAdresata(){

    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = metodyPomocnicze.wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenedzer::edytujAdresata(){

    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << '\n' << '\n';
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    auto [czyIstniejeAdresat,indeksAdresata] = sprawdzCzyIstniejeAdresat(idEdytowanegoAdresata);

    char wybor;

    if (czyIstniejeAdresat){

        wybor = wybierzOpcjeZMenuEdycja();

        switch (wybor)
        {
        case '1':
            cout << "Podaj nowe imie: ";
            adresaci[indeksAdresata].ustawImie(metodyPomocnicze.wczytajLinie()) ;
            adresaci[indeksAdresata].ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[indeksAdresata].pobierzImie())) ;
            plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[indeksAdresata], idEdytowanegoAdresata);
            break;
        case '2':
            cout << "Podaj nowe nazwisko: ";
            adresaci[indeksAdresata].ustawNazwisko(metodyPomocnicze.wczytajLinie()) ;
            adresaci[indeksAdresata].ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[indeksAdresata].pobierzNazwisko()));
            plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[indeksAdresata], idEdytowanegoAdresata);
            break;
        case '3':
            cout << "Podaj nowy numer telefonu: ";
            adresaci[indeksAdresata].ustawNumerTelefonu(metodyPomocnicze.wczytajLinie()) ;
            plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[indeksAdresata], idEdytowanegoAdresata);
            break;
        case '4':
            cout << "Podaj nowy email: ";
            adresaci[indeksAdresata].ustawEmail(metodyPomocnicze.wczytajLinie()) ;
            plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[indeksAdresata], idEdytowanegoAdresata);
            break;
        case '5':
            cout << "Podaj nowy adres zamieszkania: ";
            adresaci[indeksAdresata].ustawAdres(metodyPomocnicze.wczytajLinie()) ;
            plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[indeksAdresata], idEdytowanegoAdresata);
            break;
        case '6':
            cout << '\n' << "Powrot do menu uzytkownika" << '\n' << '\n';
            break;
        default:
            cout << '\n' << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << '\n' << '\n';
            break;
        }
    }
    else{
        cout << '\n' << "Nie ma takiego adresata." << '\n' << '\n';
    }
    system("pause");
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja(){

    char wybor;

    cout << '\n' << "   >>> MENU  EDYCJA <<<" << '\n';
    cout << "---------------------------" << '\n';
    cout << "Ktore dane zaktualizowac: " << '\n';
    cout << "1 - Imie" << '\n';
    cout << "2 - Nazwisko" << '\n';
    cout << "3 - Numer telefonu" << '\n';
    cout << "4 - Email" << '\n';
    cout << "5 - Adres" << '\n';
    cout << "6 - Powrot " << '\n';
    cout << '\n' << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}

pair <bool, int> AdresatMenedzer::sprawdzCzyIstniejeAdresat(int idEdytowanegoAdresata){

    for (int i = 0; i < adresaci.size(); i++)
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
            return {true,i};
    return {false,0};
}



