#include <iostream>
#include "inc/Student.hpp"

int main() {
    Student* s = new StudentInformatyki("Jan", 5, 20, "C++");
    s->wyswietlInfo();

    Student m("Anna", 4, 20);
    m.wyswietlInfo();
    
    delete s;
    return 0;
}