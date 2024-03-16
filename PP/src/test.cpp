#include "test.h"

Test::Test(const std::string& nume, const std::string& id)
    : nume(nume), id(id) {}

void Test::setNume(const std::string& nume) {
    this->nume = nume;
}

std::string Test::getNume() const {
    return nume;
}

void Test::setIntrebari(const std::vector<Intrebare>& intrebari) {
    this->intrebari = intrebari;
}

std::vector<Intrebare> Test::getIntrebari() const {
    return intrebari;
}

void Test::setId(const std::string& id) {
    this->id = id;
}

std::string Test::getId() const {
    return id;
}
