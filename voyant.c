#include "voyant.h"


entrees *io;
int shmid;

set_voyant_Charge(led etat){
  io = acces_memoire(&shmid);
  io->led_charge = etat;
}

set_voyant_Disponible(led etat){
  io = acces_memoire(&shmid);
  io->led_dispo = etat;
}
