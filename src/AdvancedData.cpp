#include "AdvancedData.hpp"

// Konstruktor z listą inicjalizacyjną
AdvancedData::AdvancedData(std::string n) : name(n) {
    // Alokacja za pomocą słowa 'new' [cite: 147, 149]
    rawBuffer = new int[10]; 
    for(int i = 0; i < 10; ++i) rawBuffer[i] = i;
    std::cout << "-> Utworzono zasob dla: " << name << std::endl;
}

// Destruktor
AdvancedData::~AdvancedData() {
    if (rawBuffer != nullptr) {
        // Zwalnianie dynamicznie zaalokowanej pamięci [cite: 148, 151, 152]
        delete[] rawBuffer; 
        rawBuffer = nullptr; // Dobra praktyka chroniąca przed "wiszącym wskaźnikiem" [cite: 157]
        std::cout << "-> Zniszczono zasob i zwolniono pamiec dla: " << name << std::endl;
    }
}

// Konstruktor Przenoszący (Zawłaszczanie zasobów) [cite: 133, 136]
AdvancedData::AdvancedData(AdvancedData&& other) noexcept : name(std::move(other.name)), rawBuffer(other.rawBuffer) {
    // Przeniesienie praw własności[cite: 136, 137]. Zostawiamy 'other' w pustym, ale bezpiecznym stanie.
    other.rawBuffer = nullptr; 
    std::cout << "-> Przeniesiono (MOVE) zasob do nowego wlasciciela z: " << name << std::endl;
}

// Stała metoda nie może zmienić pól obiektu
void AdvancedData::display() const {
    std::cout << "Obiekt [" << this->name << "]" << std::endl; // użycie wskaźnika 'this' [cite: 116]
}


// --- DEMO SMART POINTERÓW ---
class DummyObj {
public:
    DummyObj() { std::cout << " DummyObj utworzony\n"; }
    ~DummyObj() { std::cout << " DummyObj usunięty\n"; }
};

void runSmartPointersDemo() {
    std::cout << "\n--- DEMO STD::UNIQUE_PTR ---" << std::endl;
    {
        // unique_ptr zarządza pamięcią bez ryzyka wycieku. [cite: 165]
        // Tylko on jeden posiada ten zasób.
        std::unique_ptr<DummyObj> ptr1 = std::make_unique<DummyObj>();
        
        // std::unique_ptr<DummyObj> ptr2 = ptr1; // <- TO SPOWODUJE BŁĄD KOMPILACJI (zakaz kopiowania)
        // Możemy go tylko przenieść (std::move).
        std::unique_ptr<DummyObj> ptr3 = std::move(ptr1); 
        std::cout << " Posiadaczem zasobu jest teraz ptr3.\n";
    } // Po wyjściu z zakresu (nawiasu), destruktor DummyObj wywoła się sam automatycznie!

    std::cout << "\n--- DEMO STD::SHARED_PTR ---" << std::endl;
    {
        std::shared_ptr<DummyObj> shared1;
        {
            // shared_ptr umożliwia współdzielenie z wbudowanym licznikiem [cite: 168, 169]
            std::shared_ptr<DummyObj> shared2 = std::make_shared<DummyObj>();
            shared1 = shared2; // Można kopiować, licznik rośnie do 2.
            std::cout << " Licznik odwolan: " << shared1.use_count() << "\n";
        } // shared2 ginie, ale obiekt zostaje, bo shared1 nadal istnieje (licznik = 1)
        
        std::cout << " Wyszlismy z wewnetrznego bloku. Licznik: " << shared1.use_count() << "\n";
    } // Tutaj ginie shared1, licznik spada do 0 -> zasób jest ostatecznie kasowany.
}