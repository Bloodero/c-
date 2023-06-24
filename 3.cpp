#include <iostream>
#include <cmath>

class Kwadrat {
private:
    double a;

public:
    // Konstruktor z parametrami
    Kwadrat(double a) : a(a) {}

    // Konstruktor domyślny
    Kwadrat() : a(0) {}

    // Metoda zwracająca długość boku
    double getA() {
        return a;
    }

    // Metoda zwracająca pole kwadratu
    double getPole() {
        return a * a;
    }

    // Metoda zmieniająca długość boku
    void setA(double newA) {
        a = newA;
    }

    // Przyjaźń z funkcją obliczającą przekątną
    friend double obliczPrzekatna(Kwadrat& k);
};

// Funkcja obliczająca przekątną kwadratu
double obliczPrzekatna(Kwadrat& k) {
    return k.a * sqrt(2);
}

int main() {
    // Tworzenie tablicy wskaźników do obiektów klasy Kwadrat
    Kwadrat* tablica[5];

    // Tworzenie obiektów i przypisywanie ich do tablicy
    tablica[0] = new Kwadrat(2.5);
    tablica[1] = new Kwadrat(3.0);
    tablica[2] = new Kwadrat(1.8);
    tablica[3] = new Kwadrat(4.2);
    tablica[4] = new Kwadrat(2.0);

    // Wywołanie metody getA() dla każdego obiektu i wyświetlenie długości boku
    for (int i = 0; i < 5; i++) {
        std::cout << "Bok kwadratu " << i+1 << ": " << tablica[i]->getA() << std::endl;
    }

    // Wywołanie metody getPole() dla każdego obiektu i wyświetlenie pola kwadratu
    for (int i = 0; i < 5; i++) {
        std::cout << "Pole kwadratu " << i+1 << ": " << tablica[i]->getPole() << std::endl;
    }

    // Zmiana długości boku dla wybranego kwadratu
    tablica[0]->setA(5.7);
    std::cout << "Nowa długość boku kwadratu 1: " << tablica[0]->getA() << std::endl;

    // Obliczenie przekątnej dla wybranego kwadratu
    double przekatna = obliczPrzekatna(*(tablica[3]));
    std::cout << "Przekątna kwadratu 4: " << przekatna << std::endl;

    // Zwolnienie pamięci zajmowanej przez obiekty
    for (int i = 0; i < 5; i++) {
        delete tablica[i];
    }

    return 0;
}