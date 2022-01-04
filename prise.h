#ifndef PRISE_H
#define PRISE_H
#include <donnees_borne.h>
#include <memoire_borne.h>

void initialiser_prise();


void verouiller_trappe();
void deverouiller_trappe();
void set_prise(led etat);

#endif // PRISE_H
