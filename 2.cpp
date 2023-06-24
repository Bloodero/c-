#include <iostream>

class Prostokat {
private:
    double a;
    double b;

public:
    // Konstruktor z parametrami
    Prostokat(double a, double b) : a(a), b(b) {}

    // Konstruktor domyślny
    Prostokat() : a(0), b(0) {}

    // Metody getA() i getB() zwracające długości boków
    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    // Metody setA() i setB() zmieniające długości boków
    void setA(double newA) {
        a = newA;
    }

    void setB(double newB) {
        b = newB;
    }

    // Deklaracja funkcji zaprzyjaźnionej
    friend void zwiekszBoki(Prostokat& prostokat, double wartosc);
};

// Definicja funkcji zaprzyjaźnionej
void zwiekszBoki(Prostokat& prostokat, double wartosc) {
    prostokat.a += wartosc;
    prostokat.b += wartosc;
}

int main() {
    Prostokat prostokaty[5];  // Tablica 5 prostokątów

    // Inicjalizacja prostokątów
    prostokaty[0] = Prostokat(2, 3);
    prostokaty[1] = Prostokat(4, 5);
    prostokaty[2] = Prostokat(1, 1);
    prostokaty[3] = Prostokat(6, 7);
    prostokaty[4] = Prostokat(3, 4);

    // Wywołanie funkcji zaprzyjaźnionej dla pierwszego prostokąta
    zwiekszBoki(prostokaty[0], 1.5);

    // Wyświetlenie długości boków pierwszego prostokąta
    std::cout << "Boki prostokata 0: a = " << prostokaty[0].getA() << ", b = " << prostokaty[0].getB() << std::endl;

    return 0;
}