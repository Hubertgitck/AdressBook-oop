#include "AdresatMenedzer.h"


using namespace std;


void AdresatMenedzer::dodajAdresata(){
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
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
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else{
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat){
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu(){
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()){
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

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
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow){

    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku(){

    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()){
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

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
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::usunAdresata(){

    int idUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
        if (itr -> pobierzId() == idUsuwanegoAdresata){
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't' lub 'n' jesli chcesz anulowac ";
            znak = metodyPomocnicze.wczytajZnak();
            if (znak == 't'){
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat ZOSTAL usuniety" << endl << endl;
                system("pause");
                return 0;
            }
            else{
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false){
        cout << endl << "Nie ma adresata o podanym ID("<< idUsuwanegoAdresata<< ") w twojej ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
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

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    auto [czyIstniejeAdresat,indeksAdresata] = sprawdzCzyIstniejeAdresat(idEdytowanegoAdresata);

    char wybor;

    if (czyIstniejeAdresat == true){

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
            cout << endl << "Powrot do menu uzytkownika" << endl << endl;
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
            break;
        }
    }
    else{
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja(){

    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}

pair <bool, int> AdresatMenedzer::sprawdzCzyIstniejeAdresat(int idEdytowanegoAdresata){

    for (int i = 0; i < adresaci.size(); i++)
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
            return {true,i};
    return {false,0};
}



