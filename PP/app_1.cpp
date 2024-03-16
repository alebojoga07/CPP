#include <iostream>
#include <fstream>
#include <vector>
#include "intrebare.h"
#include "test.h"

void creareTest(const std::string& nume) {
    std::ofstream file("teste.txt", std::ios::app);
    if (file.is_open()) {
        file << "Nume test: " << nume << "\n";
        file.close();
        std::cout << "Testul a fost creat cu succes!\n";
    } else {
        std::cerr << "Eroare la deschiderea fisierului teste.txt\n";
    }
}

void adaugareIntrebareTest(const std::string& intrebareId, const std::string& testId) {
    std::ifstream intrebariFile("intrebari.txt");
    std::ofstream testeFile("teste.txt", std::ios::app);
    if (intrebariFile.is_open() && testeFile.is_open()) {
        std::string line;
        bool foundIntrebare = false;
        while (std::getline(intrebariFile, line)) {
            if (line.find("ID: " + intrebareId) != std::string::npos) {
                testeFile << "Intrebare adaugata la Test ID: " << testId << "\n";
                testeFile << line << "\n";
                foundIntrebare = true;
                break;
            }
        }
        intrebariFile.close();
        testeFile.close();

        if (foundIntrebare) {
            std::cout << "Intrebarea cu ID-ul " << intrebareId << " a fost adaugata la Test ID: " << testId << "\n";
        } else {
            std::cerr << "Nu s-a gasit intrebarea cu ID-ul " << intrebareId << "\n";
        }
    } else {
        std::cerr << "Eroare la deschiderea fisierelor intrebari.txt sau teste.txt\n";
    }
}

void vizualizareStatistici() {
    std::ifstream file("statistici.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    } else {
        std::cerr << "Eroare la deschiderea fisierului statistici.txt\n";
    }
}


int main1(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Comanda incorecta. Utilizare: ./app_1.exe <comanda>" << std::endl;
        return 1;
    }

    std::string comanda(argv[1]);

    if (comanda == "creare") {
        if (argc < 3) {
            std::cout << "Comanda incorecta. Utilizare: ./app_1.exe creare <nume>" << std::endl;
            return 1;
        }

        std::string nume(argv[2]);
        creareTest(nume);
    } else if (comanda == "adaugare") {
        if (argc < 4) {
            std::cout << "Comanda incorecta. Utilizare: ./app_1.exe adaugare intreb test <intreb id> <test id>" << std::endl;
            return 1;
        }

        std::string intrebareId(argv[3]);
        std::string testId(argv[4]);
        adaugareIntrebareTest(intrebareId, testId);
    } else if (comanda == "vizualizare") {
        vizualizareStatistici();
    } else {
        std::cout << "Comanda invalida." << std::endl;
        return 1;
    }

    return 0;
}

