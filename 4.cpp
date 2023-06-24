#include <iostream>

class Prostokat {
private:
    double a;
    double b;

public:
    // Konstruktor z parametrami i listą inicjalizującą
    Prostokat(double a_val, double b_val) : a(a_val), b(b_val) {}

    // Konstruktor domyślny
    Prostokat() : a(0), b(0) {}

    // Metoda .getA() zwracająca długość boku a
    double getA() {
        return a;
    }

    // Metoda .getB() zwracająca długość boku b
    double getB() {
        return b;
    }

    // Metoda .setA() ustawiająca długość boku a na wartość podaną w parametrze
    void setA(double a_val) {
        a = a_val;
    }

    // Metoda .setB() ustawiająca długość boku b na wartość podaną w parametrze
    void setB(double b_val) {
        b = b_val;
    }

    // Przyjaźń: funkcja zwiększająca wartości pól "a" i "b" o wartość podaną w parametrze
    friend void zwieksz(Prostokat& prostokat, double wartosc);
};

// Definicja funkcji zaprzyjaźnionej
void zwieksz(Prostokat& prostokat, double wartosc) {
    prostokat.a += wartosc;
    prostokat.b += wartosc;
}

int main() {
    Prostokat prostokaty[5];

    // Tworzenie obiektów klasy Prostokat
    prostokaty[0] = Prostokat(2.5, 3.5);
    prostokaty[1] = Prostokat(1.0, 4.0);
    prostokaty[2] = Prostokat(3.2, 2.8);
    prostokaty[3] = Prostokat(5.0, 2.0);
    prostokaty[4] = Prostokat(2.0, 2.0);

    // Wywołanie funkcji zaprzyjaźnionej do zwiększenia wartości pól "a" i "b" dla pierwszego prostokąta
    zwieksz(prostokaty[0], 1.5);

    // Wyświetlanie długości boków prostokątów
    for (int i = 0; i < 5; i++) {
        std::cout << "Prostokat " << i+1 << ": a = " << prostokaty[i].getA() << ", b = " << prostokaty[i].getB() << std::endl;
    }

    return 0;
}