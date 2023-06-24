#include <iostream>
#include <cmath>

class Kwadrat {
private:
    double a;

public:
    Kwadrat(double a = 0) {
        this->a = a;
    }

    double getA() {
        return a;
    }

    double getPole() {
        return a * a;
    }

    void setA(double a) {
        this->a = a;
    }

    friend double obliczPrzekatna(Kwadrat k);
};

double obliczPrzekatna(Kwadrat k) {
    return sqrt(2) * k.a;
}

int main() {
    Kwadrat* kwadraty[5];

    // Tworzenie obiektów
    kwadraty[0] = new Kwadrat(2.5);
    kwadraty[1] = new Kwadrat(3.0);
    kwadraty[2] = new Kwadrat(1.8);
    kwadraty[3] = new Kwadrat(4.2);
    kwadraty[4] = new Kwadrat(2.0);

    // Wyświetlanie danych
    for (int i = 0; i < 5; i++) {
        Kwadrat* kwadrat = kwadraty[i];
        std::cout << "Kwadrat " << i + 1 << ": " << std::endl;
        std::cout << "Bok a: " << kwadrat->getA() << std::endl;
        std::cout << "Pole: " << kwadrat->getPole() << std::endl;
        std::cout << std::endl;
    }

    // Obliczanie przekątnej
    Kwadrat kwadrat1(3.5);
    double przekatna = obliczPrzekatna(kwadrat1);
    std::cout << "Przekątna kwadratu: " << przekatna << std::endl;

    // Zwalnianie pamięci
    for (int i = 0; i < 5; i++) {
        delete kwadraty[i];
    }

    return 0;
}