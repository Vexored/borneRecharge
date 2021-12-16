#include <donnees_borne.h>
#include <memoire_borne.h>

entrees *io;
int shmid;


void verouiller_trappe(){
  set_prise(VERT);
}
void deverouiller_trappe(){
  set_prise(OFF);
}
void set_prise(led etat){
  io = acces_memoire(&shmid);
  io->led_prise = etat;
}
