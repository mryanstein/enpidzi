#include <iostream>
#include <string>
#include <vector>

#include "ModernUtils.hpp"
#include "AdvancedData.hpp"

void displayMenu() {
    std::cout << "\n====================================\n";
    std::cout << "    C++ MASTER FRAMEWORK (MENU)     \n";
    std::cout << "====================================\n";
    std::cout << "1. Szablony, Przeciazanie, Range-for\n";
    std::cout << "2. Wyrazenia Lambda\n";
    std::cout << "3. Pamiec: Konstruktor Przenoszacy (Semantyka Move)\n";
    std::cout << "4. Pamiec: Inteligentne Wskazniki (Smart Pointers)\n";
    std::cout << "0. Wyjscie\n";
    std::cout << "Wybierz opcje: ";
}

int main() {
    int choice = -1;

    while (choice != 0) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Blad wejscia! Wpisz liczbe.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                std::cout << "\n--- Szablony i Przeciazanie ---\n";
                int a = 10;
                printElement(a); // wywołanie pierwszej wersji
                
                std::vector<double> v = {1.1, 2.2, 3.3};
                printElement(v); // wywołanie przeciążonej wersji
                
                // Tutaj przetestuj TODO 1 i TODO 2!
                break;
            }
            case 2:
                runLambdaExample();
                break;
            case 3: {
                std::cout << "\n--- Semantyka Move ---\n";
                // Tworzymy obiekt tymczasowy i natychmiast go przenosimy (wywoła się std::move)
                AdvancedData d1("Zasob_A");
                d1.display();

                // To wykorzysta konstruktor przenoszący!
                AdvancedData d2 = std::move(d1); 
                d2.display();
                
                // Uwaga: po uzyciu std::move, d1 jest w stanie pustym, nie należy go używać.
                break;
            }
            case 4:
                runSmartPointersDemo();
                break;
            case 0:
                std::cout << "Zamykanie frameworka. Powodzenia w dalszej nauce!\n";
                break;
            default:
                std::cout << "Nieznana opcja. Sprobuj ponownie.\n";
        }
    }

    return 0;
}