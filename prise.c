#include "prise.h"

entrees *io;
int shmid;

void initialiser_prise(){
  io = access_memoire(&shimd);
  /* associe la zone de memoire partagee au pointeur */
  if (io == NULL) printf("Erreur pas de men sh\n");
}

void verouiller_trappe(){
  set_prise(VERT);
}
void deverouiller_trappe(){
  set_prise(OFF);
}
void set_prise(led etat){
  io->led_prise = etat;
}
