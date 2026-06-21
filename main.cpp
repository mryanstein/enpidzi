#include <iostream>
#include "inc/Student.hpp"

int main() {
    Student s("Jan", 5);
    std::cout << "Student: " << s.pobierzImie() << ", Ocena: " << s.pobierzOcene() << std::endl;
    
    // błąd kompilacji: s.ocena = 2; // Nie mamy dostępu, bo jest private!
    return 0;
}