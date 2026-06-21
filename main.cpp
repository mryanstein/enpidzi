#include <iostream>
#include "inc/Student.hpp"

int main() {
    // Polimorfizm dynamiczny (T0-24-3): 
    // Wskaźnik klasy bazowej wskazuje na obiekt klasy pochodnej
    Student* s = new StudentInformatyki("Jan", 5);
    
    // Dzięki metodzie wirtualnej wywoła się wersja dla StudentInformatyki
    s->wyswietlInfo(); 
    
    delete s;
    return 0;
}