#include "voyant.h"


entrees *io;
int shmid;

void initialiser_voyant(){
  io = acces_memoire(&shmid);
  /* associe la zone de memoire partagee au pointeur */
  if (io == NULL) printf("Erreur pas de men sh\n");
  set_voyant_Disponible(VERT);
}


void set_voyant_Charge(led etat){
  io->led_charge = etat;
}

void set_voyant_Disponible(led etat){
  io->led_dispo = etat;
}
void set_voyant_Defaut(led etat){
  io->led_defaut = etat;
}

void set_voyant_Trappe(led etat){
  io->led_defaut = etat;
}
led get_voyant_Charge(){
  return io->led_charge;
}
led get_voyant_Disponible(){
  return io->led_dispo;
}
led get_voyant_Defaut(){
  return io->led_defaut;
}

void clignotement_voyant_Charge(){
  timer_raz();
  set_voyant_Charge(VERT);
  while(timer_valeur()< 8){ //On effectue le clignotement pendant 8s
    if(timer_valeur()%2){ //On éteint/Allume
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
  while(timer_valeur()< 8){ //On effectue le clignotement pendant 8s
    if(timer_valeur()%2){ //On éteint/Allume
      if(get_voyant_Defaut() == ROUGE){ //Si le voyant est allumé, alors on l'éteint
        set_voyant_Defaut(OFF);
      }
      else{ //Si le voyant est éteint alors on l'allume
        set_voyant_Defaut(ROUGE);
      }
    }
  }
}
