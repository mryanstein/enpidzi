#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
private: // Dane ukryte przed światem zewnętrznym (Hermetyzacja)
    std::string imie;
    int ocena;

public: // Publiczny interfejs dostępny dla każdego
    // Konstruktor (inicjalizacja za pomocą listy inicjalizacyjnej)
    Student(std::string p_imie, int p_ocena);

    // Gettery (metody stałe - const, bo nie modyfikują stanu obiektu)
    std::string pobierzImie() const;
    int pobierzOcene() const;
};

#endif