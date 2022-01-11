#include "prise.h"

entrees *io;
int shmid;

void initialiser_prise(){
  io = acces_memoire(&shmid);
  /* associe la zone de memoire partagee au pointeur */
  if (io == NULL) printf("Erreur pas de men sh\n");
}

void verouiller_trappe(){
  io->led_trappe=OFF;
}
void deverouiller_trappe(){
  io->led_trappe=VERT;
}
void set_prise(led etat){
  io->led_prise = etat;
}
