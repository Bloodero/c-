#include <iostream>
#include <cmath>

class Obszar {
private:
    double pole;

public:
    // Konstruktor z parametrem
    Obszar(double p = 0.0) : pole(p) {}

    // Metoda getPole() zwracająca pole powierzchni
    double getPole() const {
        return pole;
    }

    // Metoda setPole() zmieniająca pole powierzchni
    void setPole(double p) {
        pole = p;
    }

    // Zaprzyjaźniona funkcja wyliczająca bok kwadratu
    friend double wyliczBok(const Obszar& obszar);
};

// Implementacja zaprzyjaźnionej funkcji wyliczającej bok kwadratu
double wyliczBok(const Obszar& obszar) {
    return std::sqrt(obszar.pole);
}

int main() {
    // Tworzenie tablicy 5 elementów klasy Obszar
    Obszar obszary[5];

    // Przykład użycia konstruktora z parametrem
    Obszar obszar1(10.5);
    std::cout << "Obszar 1: " << obszar1.getPole() << " m2" << std::endl;
    std::cout << "Bok kwadratu: " << wyliczBok(obszar1) << " m" << std::endl;

    // Przykład użycia domyślnego konstruktora
    Obszar obszar2;
    std::cout << "Obszar 2: " << obszar2.getPole() << " m2" << std::endl;
    std::cout << "Bok kwadratu: " << wyliczBok(obszar2) << " m" << std::endl;

    // Przykład użycia metody setPole()
    obszar2.setPole(7.8);
    std::cout << "Obszar 2 po zmianie: " << obszar2.getPole() << " m2" << std::endl;
    std::cout << "Bok kwadratu: " << wyliczBok(obszar2) << " m" << std::endl;

    return 0;
}