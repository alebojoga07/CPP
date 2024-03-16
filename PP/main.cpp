#include <iostream>
#include <stdlib.h>
#include <conio.h>

// Funcția pentru gestionarea testelor din app_1
extern void creareTest(const std::string& nume);
extern void adaugareIntrebareTest(const std::string& intrebareId, const std::string& testId);
extern void vizualizareStatistici();

// Funcția pentru interacțiunea cu testele din app_2
extern void rulareTest(const std::string& testId);
extern void salvareRezultateTest(const std::string& testId);

int main()
{
    std::string command;
    while (true)
    {
        std::cout << "Introduceti numarul aplicatiei dorite: \n";
        std::cout << "1. Gestionarea testelor\n";
        std::cout << "2. Interactiunea cu testele\n";
        std::cout << "3. 'q' pentru a iesi\n";
        std::cin >> command;
        system("cls");

        if (command == "1")
        {
            std::cout << "Aplicatia 1 - Gestionarea testelor\n";
            std::cout << "Introduceti comanda:\n";
            std::cout << "1. Creare\n";
            std::cout << "2. Adaugare\n";
            std::cout << "3. Statistici\n";
            std::cout << "4. 'q' pentru a iesi\n";
            std::cin >> command;

            if (command == "creare")
            {
                std::string nume;
                std::cout << "Introduceti numele noului test: ";
                std::cin >> nume;
                creareTest(nume);

            }
            else if (command == "adaugare")
            {
                std::string intrebareId, testId;
                std::cout << "Introduceti ID-ul intrebarii si ID-ul testului in care sa fie adăugata intrebarea: ";
                std::cin >> intrebareId >> testId;
                adaugareIntrebareTest(intrebareId, testId);

            }
            else if (command == "statistici")
            {
                vizualizareStatistici();

            }
            else if (command == "q")
            {
                break;
            }
            else
            {
                std::cout << "Comanda invalida!\n";
            }
        }
        else if (command == "2")
        {
            std::cout << "Aplicația 2 - Interactiunea cu testele\n";
            std::cout << "Introduceti comanda: \n";
            std::cout << "1. Rulare\n";
            std::cout << "2. Salvare\n";
            std::cout << "3. 'q' pentru a iesi\n";
            std::cin >> command;


            if (command == "rulare")
            {
                std::string testId;
                std::cout << "Introduceti ID-ul testului pe care doriti sa il rulati: ";
                std::cin >> testId;
                rulareTest(testId);
            }
            else if (command == "salvare")
            {
                std::string testId;
                std::cout << "Introduceti ID-ul testului pentru care doriti sa il salvati: ";
                std::cin >> testId;
                salvareRezultateTest(testId);
            }
            else if (command == "q")
            {
                break;
            }
            else
            {
                std::cout << "Comanda invalida!\n";
            }
        }
        else if (command == "q")
        {
            break;
        }
        else
        {
            std::cout << "Comanda invalida!\n";
        }

        std::cout << "\n";
        getch();
        system("cls");

    }
    return 0;
}
