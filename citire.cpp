#include "header.h"

/// Se citeste un cuvant de la tastatura
/// in: vectorul in care e memorat cuvantul
void    citire_cuvant(char cuvant[51])
{
    char    litera;
    int     i;

    system("cls");
    cout << "Introduceti cuvantul: ";
    i = 0;
    while ((litera = getch()) != 13)
    {
        /// Daca s-a apasat backspace se sterge o steluta
        if (litera == '\b' && cuvant[0] != '\0')
        {
            cuvant[i] = '\0';
            if (i != 0)
                i--;
            system("cls");
            cout << "Introduceti cuvantul: ";
            /// Verifica daca mai exista litere in cuvant
            if (strlen(cuvant) > 1)
                for (unsigned int j = 0; j < strlen(cuvant) - 1; j++)
                    cout << '*';
        }
        /// Daca caracterul e litera se adauga in vector
        if (isalpha(litera))
        {
            cout << '*';
            cuvant[i] = litera;
            i++;
        }
    }
    cuvant[i] = '\0';
}

/// Se memoreaza intr-o matrice cuvintele dintr-o anumita categorie din fisier
/// in: categoria din care se alege cuvantul
/// out: un cuvant la intamplare din fisier
char    *citire_fisier(int optiune)
{
    char    matrice[200][51];
    int     n;
    int     random;

    n = 1;
    /// Se deschide fisierul in care se afla cuvintele din categoria selectata
    if (optiune == 1)
    {
        ifstream cit("animale.txt");
        while (cit >> matrice[n])
            n++;
        n--;
    }
    else    if (optiune == 2)
    {
        ifstream cit("legume.txt");
        while (cit >> matrice[n])
            n++;
        n--;
    }
    else    if (optiune == 3)
    {
        ifstream cit("tari.txt");
        while (cit >> matrice[n])
            n++;
        n--;
    }
    /// Se genereaza un numar la intamplare aflat intre 1 si numarul de cuvinte din fisier
    srand (time(0));
    random = rand () % n + 1;
    return (matrice[random]);
}
