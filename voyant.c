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
set_voyant_Defaut(led etat){
  io = acces_memoire(&shmid);
  io->led_defaut = etat;
}
led get_voyant_Charge(){
  io = acces_memoire(&shmid);
  return io->led_charge;
}
led get_voyant_Disponible(){
  io = acces_memoire(&shmid);
  return io->led_dispo;
}
led get_voyant_Defaut(){
  io = acces_memoire(&shmid);
  return io->led_defaut;
}

void clignotement_voyant_Charge(){
  timer_raz();
  set_voyant_Charge(VERT);
  while(timer_valeur()< 8000000){ //On effectue le clignotement pendant 8s
    if(timer_valeur%500000){ //On éteint/Allume toute les 0.5secondes
      if(get_voyant_Charge() == VERT){ //Si le voyant est allumé, alors on l'éteint
        set_voyant_Charge(OFF);
      }
      else{ //Si le voyant est éteint alors on l'allume
        set_voyant_Charge(VERT);
      }
    }
  }
}
void clignotement_voyant_Defaut(){
  timer_raz();
  set_voyant_Defaut(ROUGE);
  while(timer_valeur()< 8000000){ //On effectue le clignotement pendant 8s
    if(timer_valeur%500000){ //On éteint/Allume toute les 0.5secondes
      if(get_voyant_Defaut() == ROUGE){ //Si le voyant est allumé, alors on l'éteint
        set_voyant_Defaut(OFF);
      }
      else{ //Si le voyant est éteint alors on l'allume
        set_voyant_Defaut(ROUGE);
      }
    }
  }
}
