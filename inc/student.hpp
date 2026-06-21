#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
private: 
    // ENKAPSULACJA: Dane prywatne. Dostęp tylko przez metody klasy.
    // Hermetyzacja to szersza koncepcja: "pakowanie" danych i metod w jeden obiekt.
    std::string imie;
    int ocena;

protected:
    // PROTECTED: Dostępne dla samej klasy oraz dla wszystkich jej klas pochodnych.
    // W main() (poza klasami) te dane są niewidoczne.
    int punktyKredytowe;

public:
    // Konstruktor: deklaracja.
    Student(std::string p_imie, int p_ocena);

    // DESTRUKTOR WIRTUALNY: Kluczowy przy dziedziczeniu. 
    // Zapewnia poprawne zwolnienie pamięci obiektu klasy pochodnej, 
    // gdy używamy wskaźnika klasy bazowej.
    virtual ~Student() {}

    // GETTERY (const): Gwarantują, że nie zmienią stanu obiektu.
    std::string pobierzImie() const;
    int pobierzOcene() const;

    // SETTER: Punkt dostępu do modyfikacji prywatnej zmiennej 'ocena'.
    void ustawOcene(int nowaOcena);

    // METODA WIRTUALNA: Pozwala klasie pochodnej nadpisać (override) to zachowanie.
    virtual void wyswietlInfo() const;
};

// DZIEDZICZENIE: Tworzenie klasy pochodnej, która przejmuje (dziedziczy) 
// interfejs i dane klasy bazowej.
class StudentInformatyki : public Student {
public:
    StudentInformatyki(std::string p_imie, int p_ocena);

    // OVERRIDE: Wskazuje kompilatorowi, że ta metoda nadpisuje metodę bazową.
    void wyswietlInfo() const override;
};

#endif