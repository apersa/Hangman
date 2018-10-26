#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

void    meniu_aplicatie();
void    afisare_meniu();
void    jucator_vs_jucator();
void    citire_cuvant(char cuvant[51]);
void    transformare_cuvant(char cuvant[51]);
void    afisare_informatii_joc();
void    jucator_vs_computer();
void    afisare_categorie();
void    afisare_cuvant(char cuvant[51]);
int     completare_litere(char cuvant_citit[51], char cuvant_spanzuratoare[51]);
int     verificare_underline(char cuvant_spanzuratoare[51]);
int     verificare_litera(char litere_folosite[26], char litera);
void    citire_fisier(int optiune, char cuvant_fisier[51]);

#endif // HEADER_H_INCLUDED
