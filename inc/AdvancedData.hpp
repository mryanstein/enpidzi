#ifndef ADVANCED_DATA_HPP
#define ADVANCED_DATA_HPP

#include <iostream>
#include <string>
#include <memory>

class AdvancedData {
private:
    std::string name;
    int* rawBuffer; // Surowy wskaźnik do dynamicznej alokacji [cite: 143]

public:
    // 1. LISTA INICJALIZACYJNA [cite: 94]
    AdvancedData(std::string n);

    // 2. DESTRUKTOR [cite: 23, 106]
    ~AdvancedData();

    // 3. KONSTRUKTOR KOPIUJĄCY i =DELETE [cite: 104, 114]
    // Celowo blokujemy kopiowanie tego obiektu, kompilator zwróci błąd, jeśli spróbujesz to skopiować.
    AdvancedData(const AdvancedData& other) = delete;
    AdvancedData& operator=(const AdvancedData& other) = delete;

    // 4. KONSTRUKTOR PRZENOSZĄCY [cite: 139]
    // Argument to '&&', czyli referencja do r-wartości (np. obiektu tymczasowego).
    // 'noexcept' oznacza, że obiecujemy kompilatorowi nie rzucać wyjątków (optymalizacja).
    AdvancedData(AdvancedData&& other) noexcept;

    // 5. STAŁA METODA [cite: 33]
    void display() const;

    // TODO 3: W pliku CPP znajduje się metoda modifyBuffer. Zobacz, że wskaźnik 'this' można wykorzystać
    // do odwołania się do bieżącego obiektu, ale w stałej metodzie (np. display) nie można przez niego modyfikować pól!
};

// 6. INTELIGENTNE WSKAŹNIKI [cite: 165, 168]
void runSmartPointersDemo();

#endif