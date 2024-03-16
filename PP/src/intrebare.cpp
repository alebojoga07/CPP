#include "intrebare.h"

Intrebare::Intrebare(const std::string& enunt, const std::vector<std::string>& optiuni, const std::string& raspuns_corect, const std::string& id)
    : enunt(enunt), optiuni(optiuni), raspuns_corect(raspuns_corect), id(id) {}

void Intrebare::setEnunt(const std::string& enunt) {
    this->enunt = enunt;
}

std::string Intrebare::getEnunt() const {
    return enunt;
}

void Intrebare::setOptiuni(const std::vector<std::string>& optiuni) {
    this->optiuni = optiuni;
}

std::vector<std::string> Intrebare::getOptiuni() const {
    return optiuni;
}

void Intrebare::setRaspunsCorect(const std::string& raspuns_corect) {
    this->raspuns_corect = raspuns_corect;
}

std::string Intrebare::getRaspunsCorect() const {
    return raspuns_corect;
}

void Intrebare::setId(const std::string& id) {
    this->id = id;
}

std::string Intrebare::getId() const {
    return id;
}
