//Biorytm - pobieranie aktualnego czasu w postaci struktury
// i użycie go do obliczania biorytmu

#include <iostream>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <cstdlib>

//typ wyliczeniowy, okreslający rodzaj biorytmu
enum BIORYTHM{BIO_PHYSICAL = 23,
              BIO_EMOTIONAL = 28,
              BIO_INTELECTUAL = 33};

// pi
const double PI = 3.1415926538;

//--------------------------------------------------

//funkcja wyliczająca dany rodzaj biorytmu
double Biorytm(double fDni, BIORYTHM Cykl){
    return 100 * sin ((2 * PI / Cykl) * fDni);
}

//funkcja main
int main(){
    /* trzy struktury, przechowujące datę urodzin, aktualny czas oraz różnicę pomiędzy nimi*/
    tm DataUrodzenia = {0,0,0,0,0,0,0,0,0};
    tm AktualnyCzas = {0,0,0,0,0,0,0,0,0};
    tm RoznicaCzasu = {0,0,0,0,0,0,0,0,0};

    /* pytamu uzytkownika o date urodzenia */

    std::cout << "Podaj date urodzenia" << std::endl;

    //dzien
    std::cout << "- dzien: ";
    std::cin >> DataUrodzenia.tm_mday;

    // miesiac - bo musimy odjac 1, bo uzytkownik poda go w systemie 1 .. 12
    std::cout << "- miesiac: ";
    std::cin >> DataUrodzenia.tm_mon;
    DataUrodzenia.tm_mon--;

    //rok - tutaj natomiast musimy odjac 1900
    std::cout << "- rok: ";
    std::cin >> DataUrodzenia.tm_year;
    DataUrodzenia.tm_year -= 1900;

    /*obliczamy liczbe przezytych dni*/
    //pobieramy aktualny czas w postaci struktury
    time_t Czas = time(NULL);
    AktualnyCzas = *localtime(&Czas);

    //obliczamy różnicę między nim a datą urodzenia
    RoznicaCzasu.tm_mday = AktualnyCzas.tm_mday - DataUrodzenia.tm_mday;
    RoznicaCzasu.tm_mon = AktualnyCzas.tm_mon - DataUrodzenia.tm_mon;
    RoznicaCzasu.tm_year = AktualnyCzas.tm_year - DataUrodzenia.tm_year;

    //przeliczamy to na dni
    double fPrzezyteDni = RoznicaCzasu.tm_year * 365.25 + RoznicaCzasu.tm_mon * 30.4375
                            + RoznicaCzasu.tm_mday;

    /* obliczamy biorytm i wyswietlamy go */
    // oto i on
    std::cout << std::endl;
    std::cout << "Twoj biorytm" << std::endl;
    std::cout << "- fizyczny: " << Biorytm(fPrzezyteDni, BIO_PHYSICAL) << std::endl;
    std::cout << "- emocjonalny: " << Biorytm(fPrzezyteDni, BIO_EMOTIONAL) << std::endl;
    std::cout << "- intelektualny: " << Biorytm(fPrzezyteDni, BIO_INTELECTUAL) << std::endl;

    //czekamy na dowolny klawisz
    getch();

}
