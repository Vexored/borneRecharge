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
get_voyant_Charge(){
  io = acces_memoire(&shmid);
  return io->led_charge;
}
get_voyant_Disponible(){
  io = acces_memoire(&shmid);
  return io->led_dispo;
}
