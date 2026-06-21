#include "../inc/Student.hpp"
#include <iostream>

Student::Student(std::string p_imie, int p_ocena, int p_wiek) 
    : imie(p_imie), ocena(p_ocena), punktyKredytowe(0), wiek(p_wiek) 
{
    if (ocena < 1) ocena = 1;
}

std::string Student::pobierzImie() const { return imie; }
int Student::pobierzOcene() const { return ocena; }

void Student::ustawOcene(int nowaOcena) {
    if(nowaOcena >= 1 && nowaOcena <= 5) {
        ocena = nowaOcena;
    }
}

int Student::pobierzWiek() const { return wiek; }

void Student::ustawWiek(int nowyWiek) {
    if(nowyWiek > 0) {
        wiek = nowyWiek;
    }
}

void Student::wyswietlInfo() const {
    std::cout << "Student: " << imie << ", Ocena: " << ocena << ", Wiek: " << wiek << std::endl;
}

StudentInformatyki::StudentInformatyki(std::string p_imie, int p_ocena, int p_wiek, std::string p_jezyk) 
    : Student(p_imie, p_ocena, p_wiek), ulubionyJezyk(p_jezyk) {}

void StudentInformatyki::wyswietlInfo() const {
    Student::wyswietlInfo();
    punktyKredytowe += 10;
    std::cout << "Student Informatyki: " << pobierzImie() 
              << " [Punkty: " << punktyKredytowe << ", Ulubiony język: " << ulubionyJezyk << "]" << std::endl;
}