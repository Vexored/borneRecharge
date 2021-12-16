#include <unistd.h>
#include "lecteurcarte.h"

void lecteurcarte_initialiser()
{
}

void lecteurcarte_lire_carte(){
  unsigned short int numero_carte;
  //Si la borne est disponible
  if(get_voyant_Disponible == VERT){
    if(carte_inseree()){
      //Lancement du timer
      //Verification avec numero_carte
      if(1){
        //On fait clignoter le bouton 8s
        clignotement_voyant_Charge();
        //Tant qu'il y a le timer, on attend appuie bouton
        while(true){
          if(bouton_charge() == 1){
            set_voyant_Disponible(ROUGE);
            genCharge();
            break;
          }
          else{//Erreur authentification
            clignotement_voyant_Defaut();
            break;
          }
        }
      }
      else{//Erreur authentification
        clignotement_voyant_Defaut();
      }
    }
  }
  //Si borne non disponible
  else{
    if(carte_inseree){ //Si une carte inséré
      if(1){ //Si client authentifier
        if(get_voyant_Charge() == VERT){ //Si la charge n'est pas active -> Charge terminé ou STOP
        //UC Reprendre vehicule
        }
      }
    }
    else{//Erreur authentification
    clignotement_voyant_Defaut();
  }

  }
}
