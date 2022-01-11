#ifndef VOYANT_H
#define VOYANT_H
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "timer.h"

void initialiser_voyant();

void set_voyant_Charge(led etat);
void set_voyant_Trappe(led etat);
void set_voyant_Defaut(led etat);
void set_voyant_Disponible(led etat);

led get_voyant_Charge();
led get_voyant_Disponible();
led get_voyant_Defaut();

void clignotement_voyant_Charge();
void clignotement_voyant_Defaut();

#endif // VOYANT_H
