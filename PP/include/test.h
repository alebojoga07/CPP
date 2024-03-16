#ifndef TEST_H
#define TEST_H

#include <string>
#include <vector>
#include "intrebare.h"

class Test {
private:
    std::string nume;
    std::vector<Intrebare> intrebari;
    std::string id;

public:
    Test(const std::string& nume, const std::string& id);

    // Settere și gettere pentru membrii privați
    void setNume(const std::string& nume);
    std::string getNume() const;

    void setIntrebari(const std::vector<Intrebare>& intrebari);
    std::vector<Intrebare> getIntrebari() const;

    void setId(const std::string& id);
    std::string getId() const;
};

#endif // TEST_H

