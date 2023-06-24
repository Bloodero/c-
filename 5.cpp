#include <iostream>
#include <cmath>

class kwadrat_v2 {
private:
    double a;

public:
    // Konstruktor z parametrem
    kwadrat_v2(double a = 0.0) : a(a) {}

    // Metoda zwracająca długość boku
    double getA() const {
        return a;
    }

    // Metoda zwracająca przekątną
    double getPrzekatna() const {
        return a * std::sqrt(2);
    }

    // Metoda zmieniająca długość boku
    void setA(double newA) {
        a = newA;
    }

    // Zaprzyjaźniona funkcja, która pomnoży długość boku przez 2
    friend void multiplyByTwo(kwadrat_v2& square) {
        square.a *= 2;
    }
};

int main() {
    // Tworzenie tablicy wskaźników do obiektów klasy "kwadrat_v2"
    kwadrat_v2* squares[5];

    // Tworzenie obiektów i przypisanie do tablicy
    squares[0] = new kwadrat_v2(1.0);
    squares[1] = new kwadrat_v2(2.0);
    squares[2] = new kwadrat_v2(3.0);
    squares[3] = new kwadrat_v2(4.0);
    squares[4] = new kwadrat_v2(5.0);

    // Wywołanie funkcji zaprzyjaźnionej dla każdego obiektu
    for (int i = 0; i < 5; i++) {
        multiplyByTwo(*squares[i]);
    }

    // Wyświetlenie danych obiektów
    for (int i = 0; i < 5; i++) {
        std::cout << "Kwadrat " << i + 1 << ": "
                  << "Bok: " << squares[i]->getA()
                  << ", Przekatna: " << squares[i]->getPrzekatna() << std::endl;
    }

    // Zwolnienie pamięci
    for (int i = 0; i < 5; i++) {
        delete squares[i];
    }

    return 0;
}