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
      timer_raz();
      //Verification avec numero_carte
      if(1){
        //On fait clignoter le bouton 8s
        clignotement_voyant_Charge();
        //Tant qu'il y a le timer, on attend appuie bouton
        while(timer_valeur < 60000000){
            if(bouton_charge() == 1){
              //On attend le retrait de la carte
              attente_retrait_carte();
              //Voyant disponible Rouge
              set_voyant_Disponible(ROUGE);
              //Lancement de la charge
              genCharge();
              break;
            }
          }        }
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
    if(carte_inseree()){ //Si une carte inséré
      if(1){
        //Si client authentifier
        if(get_voyant_Charge() == VERT){ //Si la charge n'est pas active -> Charge terminé ou STOP
          //UC Reprendre vehicule
          genReprendre();
        }
      }
    }
    else{//Erreur authentification
    clignotement_voyant_Defaut();
    }
  }
  //Ajout supprime client
}
