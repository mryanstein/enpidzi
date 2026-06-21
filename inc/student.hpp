#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
private: 
    std::string imie;
    int ocena;
    // TODO 1a: Dodaj prywatne pole 'int wiek'

protected:
    int punktyKredytowe;

public:
    Student(std::string p_imie, int p_ocena);
    virtual ~Student() {}

    std::string pobierzImie() const;
    int pobierzOcene() const;
    void ustawOcene(int nowaOcena);

    // TODO 1b: Zadeklaruj publiczny getter i setter dla wieku:
    // int pobierzWiek() const;
    // void ustawWiek(int nowyWiek);

    virtual void wyswietlInfo() const;
};

class StudentInformatyki : public Student {
// TODO 2a: Dodaj prywatne pole 'std::string ulubionyJezyk'
public:
    // TODO 2b: Zmień konstruktor tak, aby przyjmował trzeci parametr: 'std::string p_jezyk'
    StudentInformatyki(std::string p_imie, int p_ocena);

    void wyswietlInfo() const override;
};

#endif