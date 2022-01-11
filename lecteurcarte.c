#include "lecteurcarte.h"

void lecteurcarte_initialiser()
{
initialisations_ports();
}

void lecteurcarte_lire_carte(){
  int numero_carte = 0; //numero client actuel
  //Cycle charge
  while(1){
  //Si la borne est disponible
  if(get_voyant_Disponible() == VERT){
    if(carte_inseree()){
      //Lancement du timer
      timer_raz();
      //Verification avec numero_carte
      if(authentifier(lecture_numero_carte())){
	numero_carte = lecture_numero_carte();
        //On fait clignoter le bouton 8s
        clignotement_voyant_Charge();
        //Tant qu'il y a le timer, on attend appuie bouton
        while(timer_valeur() < 60){
            if(bouton_charge() == 1){
              //On attend le retrait de la carte
              attente_retrait_carte();
              //Voyant disponible Rouge
              set_voyant_Disponible(ROUGE);
              //Lancement de la charge
              genCharge();
              break;
            }
          }
          }
      else{//Erreur authentification
        clignotement_voyant_Defaut();
        attente_retrait_carte();
      }
    }
  }
  //Si borne non disponible
  else{
    if(carte_inseree()){ //Si une carte inséré
      if(numero_carte == lecture_numero_carte()){
        //Si client authentifier
        if(get_voyant_Charge() == VERT){ //Si la charge n'est pas active -> Charge terminé ou STOP
          //UC Reprendre vehicule
          attente_retrait_carte();
          genReprendre();
          break;
        }
      }
    }
    else{//Erreur authentification
    clignotement_voyant_Defaut();
    attente_retrait_carte();
    }
  }
  }
}
