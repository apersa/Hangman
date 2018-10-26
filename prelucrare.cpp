#include "header.h"

/// Transforma literele mari ale unui cuvant in litere mici
/// in: cuvantul
void    transformare_cuvant(char cuvant[256])
{
    unsigned int    i;

    for (i = 0; i < strlen(cuvant); i++)
        if (cuvant[i] >= 'A' && cuvant[i] <= 'Z')
            cuvant[i] = tolower(cuvant[i]);
}

/// Se cauta in cuvantul citit daca exista o litera si se completeaza in cuvantul afisat pe ecran
/// in: cuvantul citit, cuvantul afisat pe ecran, litera, vietile
void    modificare_cuvant_spanzuratoare(char cuvant_citit[256], char cuvant_spanzuratoare[256], char litera, int &vieti)
{
    unsigned int    i;
    int             ok;

    ok = 0;
    for (i = 1; i < strlen(cuvant_citit) - 1; i++)
        if (cuvant_citit[i] == litera)
        {
            cuvant_spanzuratoare[i] = litera;
            ok = 1;
        }
    /// Daca nu s-a gasit litera in cuvant, vietile scad
    system("cls");
    if (ok == 0)
    {
        vieti--;
        cout << "Litera nu exista in cuvant." << endl << endl;
        cout << "Cuvantul este: ";
        afisare_cuvant(cuvant_spanzuratoare);
    }
    else if (verificare_underline(cuvant_spanzuratoare))
    {
        cout << "Felicitari! Ati ghicit o litera." << endl;
        cout << "\nCuvantul modificat este: ";
        afisare_cuvant(cuvant_spanzuratoare);
    }
}

/// Se completeaza literele in cuvantul format din underline
/// in: cuvantul citit, cuvantul afisat pe ecran format din "_"
/// out: 1 in cazul in care cuvantul a fost ghicit
///      0 in cazul in care cuvantul nu a fost ghicit
int    completare_litere(char cuvant_citit[51], char cuvant_spanzuratoare[51])
{
    char    litere_folosite[26];
    char    litera;
    int     vieti;
    int     i;
    int     n;

    vieti = 8;
    /// Completam cuvantul care se va afisa pe ecran cu underline ("_") in afara de locurile in care prima si ultima litera mai apar in cuvant
    n = strlen(cuvant_spanzuratoare) - 1;
    for (i = 1; i < n; i++)
        if ((cuvant_spanzuratoare[0] != cuvant_spanzuratoare[i]) && (cuvant_spanzuratoare[n] != cuvant_spanzuratoare[i]))
            cuvant_spanzuratoare[i] = '_';
    litere_folosite[0] = cuvant_spanzuratoare[0];
    litere_folosite[1] = cuvant_spanzuratoare[n];
    litere_folosite[2] = '\0';
    system("cls");
    cout << "Cuvantul este: ";
    afisare_cuvant(cuvant_spanzuratoare);
    cout << endl;
    if (litere_folosite[0] != litere_folosite[1])
        cout << "Introduceti o litera diferita de '" << litere_folosite[0] << "' si '" << litere_folosite[1] << "' pentru a ghici cuvantul: ";
    else
        cout << "Introduceti o litera diferita de '" << litere_folosite[0] << "' pentru a ghici cuvantul: ";
    i = 2;
    while (vieti && verificare_underline(cuvant_spanzuratoare))
    {
        litera = getch();
        litera = tolower(litera);
        /// Se pun doar litere mici in vectorul de litere folosite
        if (!(isalpha(litera)))
        {
            system("cls");
            cout << "Introduceti doar litere mici" << endl << endl;
            cout << "Cuvantul este: ";
            afisare_cuvant(cuvant_spanzuratoare);
        }
        else    if (verificare_litera(litere_folosite, litera))
        {
            litere_folosite[i] = litera;
            i++;
            litere_folosite[i] = '\0';
            modificare_cuvant_spanzuratoare(cuvant_citit, cuvant_spanzuratoare, litera, vieti);
        }
        else
        {
            system("cls");
            cout << "Litera a mai fost introdusa o data." << endl << endl;
            cout << "Cuvantul este: ";
            afisare_cuvant(cuvant_spanzuratoare);
        }
        if (verificare_underline(cuvant_spanzuratoare))
        {
            cout << "\nMai aveti " << vieti << " vieti la dispozitie." << endl << endl;
            cout << "Literele folosite sunt: ";
            for (unsigned int j = 0; j < strlen(litere_folosite); j++)
                cout << litere_folosite[j] << ' ';
            cout << "\n\nIntroduceti o litera diferita fata de cele folosite pentru a ghici cuvantul: ";
        }
    }
    system("cls");
    cout << "Jocul s-a incheiat!" << endl << endl;
    cout << "Cuvantul era: " << cuvant_citit << endl << endl;
    if (vieti == 0)
        return (0);
    else
        return (1);
}

/// Se citesc numele jucatorilor si incepe jocul
void    jucator_vs_jucator()
{
    char    jucator_1[51];
    char    jucator_2[51];
    char    cuvant_citit[51];
    char    cuvant_spanzuratoare[51];

    system("cls");
    cout << "Jucator_1 (cel care scrie cuvantul): ";
    cin.getline(jucator_1, 51);
    cout << endl;
    cout << "Jucator_2 (cel care ghiceste cuvantul): ";
    cin.getline(jucator_2, 51);
    cout << endl << endl;
    citire_cuvant(cuvant_citit);
    /// Se transforma literele mari in litere mici
    transformare_cuvant(cuvant_citit);
    strcpy(cuvant_spanzuratoare, cuvant_citit);
    if (completare_litere(cuvant_citit, cuvant_spanzuratoare))
        cout << "Jucatorul " << jucator_2 << " a castigat!" << endl << endl;
    else
        cout << "Jucatorul " << jucator_1 << " a castigat!" << endl << endl;
    cout << "Felicitari!!!" << endl << endl;
    cout << "Introduceti orice tasta pentru a reveni la meniul principal ";
}

/// Se alege categoria din care este cuvantul si incepe jocul
void    jucator_vs_computer()
{
    char    tasta;
    char    cuvant_fisier[51];
    char    cuvant_spanzuratoare[51];
    int     optiune;

    do
    {
        system("cls");
        afisare_categorie();
        cout << "Introduceti o optiune: ";
        tasta = getch();
        cout << endl;
        /// Se verifica daca tasta introdusa corespunde cu cerintele
        if (!(tasta >= '1' && tasta <= '3'))
        {
            system("cls");
            cout << "Ati introdus un caracter gresit." << endl;
            cout << "Introduceti orice tasta pentru a continua ";
        }
        else
            optiune = tasta - '0';
    }while (optiune != 1 && optiune != 2 && optiune != 3);
    /// In cuvant_fisier se memoreaza cuvantul care urmeaza a fi ghicit
    citire_fisier(optiune, cuvant_fisier);
    strcpy(cuvant_spanzuratoare, cuvant_fisier);
    if (completare_litere(cuvant_fisier, cuvant_spanzuratoare))
        cout << "Felicitari!!! Ati gastigat." << endl << endl;
    else
        cout << "Din pacate ati pierdut." << endl << endl;
    cout << "Introduceti orice tasta pentru a reveni la meniul principal ";
}
