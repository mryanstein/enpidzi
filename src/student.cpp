#include "../inc/Student.hpp"

// Użycie listy inicjalizacyjnej (zagadnienie 43 z bazy)
Student::Student(std::string p_imie, int p_ocena) : imie(p_imie), ocena(p_ocena) {}

std::string Student::pobierzImie() const {
    return imie;
}

int Student::pobierzOcene() const {
    return ocena;
}