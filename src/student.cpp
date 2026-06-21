#include "../inc/Student.hpp"
#include <iostream>

Student::Student(std::string p_imie, int p_ocena) 
    : imie(p_imie), ocena(p_ocena), punktyKredytowe(0) 
{
    if (ocena < 1) ocena = 1;
    // TODO 1c: W liście inicjalizacyjnej (wyżej) przypisz do pola 'wiek' wartość p_wiek (którą musisz dodać do parametrów konstruktora) 
    // lub ustaw tutaj domyślną wartość, np. 19.
}

std::string Student::pobierzImie() const { return imie; }
int Student::pobierzOcene() const { return ocena; }

void Student::ustawOcene(int nowaOcena) {
    if(nowaOcena >= 1 && nowaOcena <= 5) {
        ocena = nowaOcena;
    }
}

// TODO 1d: Zaimplementuj pobierzWiek() oraz ustawWiek(int nowyWiek).
// W setterze zabezpiecz kod przed ustawieniem wieku mniejszego lub równego 0.

void Student::wyswietlInfo() const {
    std::cout << "Student: " << imie << ", Ocena: " << ocena << std::endl;
    // TODO 1e: Zmodyfikuj tę linię, aby wyświetlała również wiek studenta.
}

// TODO 2c: Zaktualizuj definicję konstruktora poniżej (dodaj p_jezyk) 
// i przypisz go do nowego pola w liście inicjalizacyjnej.
StudentInformatyki::StudentInformatyki(std::string p_imie, int p_ocena) 
    : Student(p_imie, p_ocena) {}

void StudentInformatyki::wyswietlInfo() const {
    // TODO 3: Zmodyfikuj tę funkcję, aby:
    // a) Wywoływała najpierw oryginalną metodę z klasy bazowej za pomocą Student::wyswietlInfo()
    // b) Zwiększała zmienną 'punktyKredytowe' o 10 przy każdym wywołaniu (masz do niej dostęp, bo jest protected)
    // c) Wypisywała na ekranie ulubiony język programowania oraz aktualną liczbę punktów.
    std::cout << "Student Informatyki: " << pobierzImie() 
              << " [Punkty: " << punktyKredytowe << "]" << std::endl;
}