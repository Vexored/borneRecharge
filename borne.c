#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>

#include "lecteurcarte.h"
#include "base_client.h"

void initialisation(){
  lecteurcarte_initialiser();
  creation_base();

}

int main(){

  int etat = 0;
  int etat_base = 0;
  initialisation();
  while(1){
    swtich(etat){
      case 0:
        printf("Interface borne de recharge:\n");
        printf("1 - Mode Gestion Base Client\n");
        printf("2 - Mode Borne\n");
        scanf("%d",&etat);
        break;
      case 1:
        //Mode Gestion
        while(etat_base != 3){
          swtich(etat_base){
            case 0:
              printf("#---------------------------#\n")
              printf("Gestion Base Client:\n");
              printf("1 - Ajouter client\n");
              printf("2 - Supprimer client\n");
              printf("3 - Quitter interface");
              scanf("%d",&etat_base);
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
