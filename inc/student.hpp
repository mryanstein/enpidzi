#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
private: 
    std::string imie;
    int ocena;
    int wiek;

protected:
    int punktyKredytowe;

public:
    Student(std::string p_imie, int p_ocena);
    virtual ~Student() {}

    std::string pobierzImie() const;
    int pobierzOcene() const;
    void ustawOcene(int nowaOcena);
    int pobierzWiek() const;
    void ustawWiek(int nowyWiek);
    virtual void wyswietlInfo() const;
};

class StudentInformatyki : public Student {
private:
    std::string ulubionyJezyk;
public:
    StudentInformatyki(std::string p_imie, int p_ocena, std::string p_jezyk);

    void wyswietlInfo() const override;
};

#endif