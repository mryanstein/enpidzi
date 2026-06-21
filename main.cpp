#include <iostream>
#include "inc/Student.hpp"

int main() {
    Student* s = new StudentInformatyki("Jan", 5);
    s->wyswietlInfo();

    Student m("Anna", 4);
    m.wyswietlInfo();
    
    delete s;
    return 0;
}