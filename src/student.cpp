#include "../inc/Student.hpp"
#include <iostream>

// LISTA INICJALIZACYJNA (: ... ):
// 1. Zmienne const i referencje MUSZĄ być tu inicjalizowane (nie można wewnątrz {}).
// 2. Wywołanie konstruktora klasy bazowej musi być tu.
// 3. Jest wydajniejsza – zmienne są tworzone od razu z wartościami,
//    a nie tworzone (domyślnie) i potem nadpisywane (przypisanie w {}).
Student::Student(std::string p_imie, int p_ocena) 
    : imie(p_imie), ocena(p_ocena), punktyKredytowe(0) 
{
    // CIAŁO KONSTRUKTORA {}:
    // Tu umieszczamy logikę, która wymaga wykonania kodu, 
    // np. sprawdzanie poprawności danych:
    if (ocena < 1) ocena = 1;
}

std::string Student::pobierzImie() const { return imie; }
int Student::pobierzOcene() const { return ocena; }

// SETTER: Kontroluje, co trafia do prywatnej zmiennej.
void Student::ustawOcene(int nowaOcena) {
    if(nowaOcena >= 1 && nowaOcena <= 5) {
        ocena = nowaOcena;
    }
}

void Student::wyswietlInfo() const {
    std::cout << "Student: " << imie << ", Ocena: " << ocena << std::endl;
}

// KLASA POCHODNA - wywołanie konstruktora bazowego:
StudentInformatyki::StudentInformatyki(std::string p_imie, int p_ocena) 
    : Student(p_imie, p_ocena) {}

void StudentInformatyki::wyswietlInfo() const {
    // Mamy dostęp do 'punktyKredytowe', bo jest protected.
    std::cout << "Student Informatyki: " << pobierzImie() 
              << " [Punkty: " << punktyKredytowe << "]" << std::endl;
}