#include "header.h"

/// Meniul aplicatiei
void    meniu_aplicatie()
{
    char    tasta;
    int     optiune;

    do
    {
        system("cls");
        afisare_meniu();
        cout << "Introduceti o optiune: ";
        tasta = getch();
        cout << endl;
        if (!(tasta >= '1' && tasta <= '4'))
        {
            system("cls");
            cout << "Ati introdus un caracter gresit." << endl;
            cout << "Introduceti orice tasta pentru a continua ";
        }
        else
        {
            optiune = tasta - '0';
            switch(optiune)
            {
                case 1: jucator_vs_jucator();
                    break;
                case 2: jucator_vs_computer();
                    break;
                case 3: afisare_informatii_joc();
                    break;
                case 4: break;
            }
        }
        if (tasta != '4')
            getch();
    }while (optiune != 4);
    cout << "\nCredits: Alex Persa | e-mail: alex.persa28@yahoo.com" << endl;
}

int main()
{
    meniu_aplicatie();
    return 0;
}
