#include <iostream>
#include <fstream>
#include <vector>
#include "intrebare.h"
#include "test.h"


void rulareTest(const std::string& testId) {
    // Deschideți fișierul cu întrebările testului
    std::ifstream fileIntrebari("statistici.txt");
    if (!fileIntrebari.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului statistici.txt\n";
        return;
    }

    // Căutați testul cu ID-ul specificat
    std::string line;
    bool foundTest = false;
    while (std::getline(fileIntrebari, line)) {
        if (line.find(testId) != std::string::npos) {
            foundTest = true;
            break;
        }
    }
    fileIntrebari.close();

    if (!foundTest) {
        std::cerr << "Nu s-a gasit testul cu ID-ul " << testId << " in fisierul statistici.txt\n";
        return;
    }

    // Afișați întrebările testului și solicitați răspunsurile de la utilizator
    std::cout << "Rularea testului cu ID-ul " << testId << "\n";
    std::cout << "Intrebarile testului:\n";

    std::ifstream fileStatistici("test.txt");
    if (!fileStatistici.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului test.txt\n";
        return;
    }

    bool foundTestStatistici = false;
    while (std::getline(fileStatistici, line)) {
        if (line.find(testId) != std::string::npos) {
            foundTestStatistici = true;
            break;
        }
    }
    fileStatistici.close();

    if (!foundTestStatistici) {
        std::cerr << "Nu s-a gasit testul cu ID-ul " << testId << " in fisierul test.txt\n";
        return;
    }

    // Implementați logica de afișare a întrebărilor din fișierul "intrebari.txt"
    std::ifstream fileIntrebariAfisare("intrebari.txt");
    if (!fileIntrebariAfisare.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului intrebari.txt\n";
        return;
    }

    bool foundTestId = false;
    while (std::getline(fileIntrebariAfisare, line)) {
        if (line.find(testId) != std::string::npos) {
            foundTestId = true;
            continue;
        }
        if (foundTestId && line.empty())
            break;

        if (foundTestId)
            std::cout << line << "\n";
    }
    fileIntrebariAfisare.close();

    // Implementați logica de rulare a testului și afișarea rezultatelor*/
}



void salvareRezultateTest(const std::string& testId) {
    std::string rezultate; // Aici ar trebui să obțineți rezultatele testului

    std::ofstream file("rezultate.txt", std::ios::app);
    if (file.is_open()) {
        file << "Rezultate pentru Test ID: " << testId << "\n";
        file << rezultate << "\n";
        file.close();
        std::cout << "Rezultatele au fost salvate cu succes în fișierul rezultate.txt\n";
    } else {
        std::cerr << "Eroare la deschiderea fișierului rezultate.txt\n";
    }
}


int main2(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Comanda incorecta. Utilizare: ./app_2.exe <comanda>" << std::endl;
        return 1;
    }

    std::string comanda(argv[1]);

    if (comanda == "rularea") {
        if (argc < 3) {
            std::cout << "Comanda incorecta. Utilizare: ./app_2.exe rularea testelor <id>" << std::endl;
            return 1;
        }

        std::string testId(argv[2]);
        rulareTest(testId);
    } else if (comanda == "salvarea") {
        if (argc < 3) {
            std::cout << "Comanda incorecta. Utilizare: ./app_2.exe salvarea rezultatelor <id>" << std::endl;
            return 1;
        }

        std::string testId(argv[2]);
        salvareRezultateTest(testId);
    } else {
        std::cout << "Comanda invalida." << std::endl;
        return 1;
    }

    return 0;
}
