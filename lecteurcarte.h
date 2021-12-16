#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include <unistd.h>
#include "base_client.h"
#include "bouton.h"
#include "Generateur_save.h"
#include "voyant.h"

void lecteurcarte_initialiser();
void lecteurcarte_lire_carte();

#endif // LECTEURCARTE_H
