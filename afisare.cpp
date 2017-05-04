#include "header.h"

/// Se afiseaza meniul aplicatiei
void    afisare_meniu()
{
    cout << "########################" << endl;
    cout << "#    Spanzuratoarea    #" << endl;
    cout << "########################" << endl;
    cout << endl;
    cout << "1) Jucator_1 vs Jucator_2" << endl;
    cout << "2) Jucator vs Computer" << endl;
    cout << "3) Informatii despre joc" << endl;
    cout << "4) Iesire" << endl << endl;
}

/// Se afiseaza informatii despre joc
void    afisare_informatii_joc()
{

    system("cls");
    cout << "Spanzuratoarea este un joc in care trebuie sa fie ghicit un cuvant." << endl << endl;
    getch();
    cout << "1) Jucator_1 vs Jucator_2" << endl;
    cout << "Jucator_1 introduce un cuvant de la tastatura, iar Jucator_2 incearca sa ghiceasca cuvantul." << endl << endl;
    getch();
    cout << "2) Jucator vs Computer" << endl;
    cout << "Jucatorul trebuie sa aleaga o categorie din care va primi un cuvant, iar apoi sa-l ghiceasca." << endl << endl;
    getch();
    cout << "Reguli generale: " << endl << endl;
    cout << "   -Cuvantul este reprezentat printr-un sir de linii." << endl;
    cout << "   -Fiecare linie reprezinta o litera a cuvantului." << endl;
    cout << "   -Cuvintele trebuie ghicite sugerand litere." << endl;
    cout << "   -Daca o litera este ghicita va fi completata in toate locurile in care apare." << endl;
    cout << "   -Literele sugerate nu se contorizeaza daca sunt scrise de 2 ori." << endl;
    cout << "   -Jucatorul are 8 vieti la dispozitie." << endl << endl;
    cout << "Apasa orice tasta pentru a reveni la meniul principal ";
}

/// Se afiseaza categoriile de cuvinte
void    afisare_categorie()
{
    cout << "Categoriile disponibile: " << endl;
    cout << "1) Animale" << endl;
    cout << "2) Legume" << endl;
    cout << "3) Tari" << endl << endl;
}

void    afisare_cuvant(char cuvant[51])
{
    unsigned int i;

    for (i = 0; i < strlen(cuvant); i++)
        cout << cuvant[i] << ' ';
    cout << endl;
}
