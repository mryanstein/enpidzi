#include <iostream>
#include <cassert>
#include "inc/Student.hpp"

int main() {
    std::cout << "--- URUCHAMIANIE TESTÓW POJĘĆ C++ ---\n" << std::endl;

    // ==========================================
    // TEST 1: Enkapsulacja (Zadania TODO 1a - 1e)
    // ==========================================
    /*
    std::cout << "[Test 1] Sprawdzanie enkapsulacji (wiek)..." << std::endl;
    Student testStudent("Kamil", 4);
    
    testStudent.ustawWiek(21);
    assert(testStudent.pobierzWiek() == 21 && "BŁĄD: Getter lub setter wieku nie działa!");

    testStudent.ustawWiek(-5);
    assert(testStudent.pobierzWiek() == 21 && "BŁĄD: Setter przyjął ujemny wiek! Brak walidacji danych.");
    
    std::cout << " -> Wizualne sprawdzenie metody wyswietlInfo() (powinna pokazać wiek):" << std::endl;
    testStudent.wyswietlInfo();
    std::cout << "[OK] Test Enkapsulacji zakończony pomyślnie.\n" << std::endl;
    */


    // ==========================================
    // TEST 2: Dziedziczenie i Polimorfizm (Zadania TODO 2 oraz 3)
    // ==========================================
    /*
    std::cout << "[Test 2] Sprawdzanie dziedziczenia i polimorfizmu..." << std::endl;
    
    // Tworzymy obiekt za pomocą wskaźnika klasy bazowej (Polimorfizm)
    // Konstruktor powinien teraz przyjmować 3 argumenty: imie, ocena, język
    Student* infStudent = new StudentInformatyki("Tomasz", 5, "C++");
    
    std::cout << " -> Pierwsze wywołanie (powinno wywołać bazowe info + język + punkty: 10):" << std::endl;
    infStudent->wyswietlInfo(); 
    
    std::cout << " -> Drugie wywołanie (punkty powinny wzrosnąć do 20 dzięki 'protected'):" << std::endl;
    infStudent->wyswietlInfo();
    
    delete infStudent;
    std::cout << "[OK] Test Dziedziczenia i Polimorfizmu zakończony." << std::endl;
    */

    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "Jeśli odkomentowane testy przeszły bez komunikatów 'BŁĄD' " << std::endl;
    std::cout << "oraz program się nie scrashował, zadania zostały wykonane poprawnie!" << std::endl;
    
    return 0;
}