#ifndef MODERN_UTILS_HPP
#define MODERN_UTILS_HPP

#include <iostream>
#include <vector>
#include <algorithm>

// 1. SZABLONY FUNKCJI (Generyczność) [cite: 15, 27]
// Umożliwiają pisanie jednej funkcji, która przyjmie dowolny typ 'T'.
template <typename T>
void printElement(const T& element) {
    std::cout << "Element: " << element << std::endl;
}

// 2. PRZECIĄŻANIE FUNKCJI [cite: 25]
// Ta sama nazwa funkcji, inne argumenty. Tutaj dla wektorów.
template <typename T>
void printElement(const std::vector<T>& vec) {
    std::cout << "Wektor zawiera: ";
    
    // 3. RANGE-BASED FOR LOOP [cite: 75, 76] i AUTO [cite: 238]
    // Pętla "foreach". Używamy 'const auto&' aby nie kopiować elementów i ich nie modyfikować.
    for (const auto& item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// TODO 1: Napisz własny szablon funkcji "addValues(T a, T b)", który zwraca sumę a i b.
// TODO 2: Przetestuj w main.cpp używając typów int oraz double.

void runLambdaExample() {
    std::vector<int> numbers = {1, 5, 2, 8, 3};
    int threshold = 4;

    // 4. WYRAŻENIE LAMBDA [cite: 77]
    // [] - lista przechwytywania (capture list). [&] przechwytuje wszystko przez referencję, 
    // [=] przez wartość. [threshold] przechwytuje konkretną zmienną.
    // () - argumenty lambdy.
    auto count = std::count_if(numbers.begin(), numbers.end(), [threshold](int n) {
        return n > threshold;
    });

    std::cout << "\n--- TEST LAMBDY ---" << std::endl;
    std::cout << "Liczb wiekszych od " << threshold << " jest: " << count << std::endl;
}

#endif