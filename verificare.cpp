#include "header.h"

/// Se verifica daca intr-un cuvant exista underline ("_")
/// in: cuvantul
/// out: 1 in cazul in care mai exista underline
///      0 in cazul in care nu mai exista underline
int    verificare_underline(char cuvant_spanzuratoare[256])
{
    if (strchr(cuvant_spanzuratoare, '_'))
        return (1);
    return (0);
}

/// Se verifica daca o litera exista intr-un cuvant
/// in: cuvantul, litera
/// out: 0 in cazul in care exista
///      1 in cazul in care nu exista
int    verificare_litera(char litere_folosite[26], char litera)
{
    if (strchr(litere_folosite, litera))
        return (0);
    return (1);
}
