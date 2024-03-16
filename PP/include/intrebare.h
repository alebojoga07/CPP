#ifndef INTREBARE_H
#define INTREBARE_H

#include <string>
#include <vector>

class Intrebare {
private:
    std::vector<std::string> optiuni;
    std::string raspuns_corect;
    std::string enunt;
    std::string id;

public:
    Intrebare(const std::string& enunt, const std::vector<std::string>& optiuni, const std::string& raspuns_corect, const std::string& id);

    // Settere și gettere pentru membrii privați
    void setEnunt(const std::string& enunt);
    std::string getEnunt() const;

    void setOptiuni(const std::vector<std::string>& optiuni);
    std::vector<std::string> getOptiuni() const;

    void setRaspunsCorect(const std::string& raspuns_corect);
    std::string getRaspunsCorect() const;

    void setId(const std::string& id);
    std::string getId() const;
};

#endif

