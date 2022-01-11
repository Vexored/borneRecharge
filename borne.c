#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>

#include "lecteurcarte.h"
#include "base_client.h"
#include "voyant.h"
#include "bouton.h"
#include "Generateur_save.h"
#include "timer.h"
#include "prise.h"

void initialisation(){
  lecteurcarte_initialiser();
  creation_base();
  initialiser_bouton();
  initialiser_prise();
  timer_initialiser();
  initialiser_gene_pwn();
  initialiser_voyant();

}

int main(){

  int etat = 0;
  int etat_base = 0;
  initialisation();

  while(1){
    switch(etat){
      case 0:
        printf("Interface borne de recharge:\n");
        printf("1 - Mode Gestion Base Client\n");
        printf("2 - Mode Borne\n");
        scanf("%i",&etat);
        break;
      case 1:
        //Mode Gestion
        while(etat_base != 3){
          switch(etat_base){
            case 0:
              printf("#---------------------------#\n");
              printf("Gestion Base Client:\n");
              printf("1 - Ajouter client\n");
              printf("2 - Supprimer client\n");
              printf("3 - Quitter interface\n");
              scanf("%i",&etat_base);
              break;

            case 1:
              ajouter_client();
              etat_base = 0;
              break;

            case 2:
              supprimer_client();
              etat_base = 0;
              break;


          }
        }
        etat = 0;
        break;
      case 2:
      printf("#---------------------------#\n");
        printf("Mode Borne\n");
        lecteurcarte_lire_carte();
        printf("Fin Mode Borne\n");
        etat = 0;
        break;

    }
  }
}
