#include "Generateur_save.h"

entrees *io;
int shmid;

void set_gene_pwn(pwm tension){
  io = acces_memoire(&shmid);
  io->gene_pwm = tension
}
void get_gene_u(){
  io = acces_memoire(&shmid);
  return io->gene_u;
}
void set_contacteur_AC(int etat_contacteur){
  io = acces_memoire(&shmid);
  io->contacteur_AC = etat_contacteur;

}

void genCharge(/* arguments */) {

  //Etat initial machine à état
  char etat = 'A';


  while(etat != 'S'){
    switch(etat){
      case 'A': //Attente led_prise

        //Initialisation des voyants
        set_voyant_Charge(ROUGE);

        //Deverouillage de la Prise
        set_prise(VERT);

        //Generer 12V DC
        set_gene_pwn(DC);

        //Attente du branchement de la prise par le client
        while(1){
          //Attente génération 9V DC par le vehicule
          if(get_gene_u() == 9){
            //Changment d'état
            etat = 'B';
          break;
          }
        }
        break;

        case 'B': //Prise branchee

          //Initialisation des voyants
          set_voyant_Trappe(ROUGE);

          //Verouillage de la Prise
          set_prise(OFF);

          //Generation d'un signal 1kHz AC
          set_gene_pwn(AC_1K);

          while(1){
            //Attente génération AC 9V par le vehicule
            if(get_gene_u() == 9){
              //Changement d'état
              etat = 'C';
              break;
            }
          }
          break;

          case 'C': //Attente_S2_vehicule

            //Fermeture contacteur AC
            set_contacteur_AC(1)

            while(1){
              //Attente de la fermeture de S2 par le vehicule
              if(get_gene_u() == 6){
                //Changement d'état
                etat = 'D';
                break;
              }
            }
            break;

          case 'D': //Charge du Vehicule

            //Generation d'une tension avec rapport cyclique variable
            set_gene_pwn(AC_CL)
            while(1){
              //Attente ouverture S2 Vehicule
              if(get_gene_u()== 9){
                  //Changement d'état
                  etat = 'E';
                  break;
              }
            }
            break;

         case 'E': //led_charge

          //Modification Voyant
          set_voyant_Charge(VERT);

          //Ouverture contacteur AC
          set_contacteur_AC(0)

          //On quitte la machine à état
          etat = 'S';
          break;
      }
  }
}

void genReprendre(){ //Etat initial machine à état

  char etatR = 'A';

  while(1){
    switch(etatR){
      case 'A':
        deverouiller_trappe();
        while(1){
          if(get_gene_u()== 12){
              //Changement d'état
              etatR = 'B';
              break;
          }
        }
      case 'B':
        verouiller_trappe();
        set_voyant_Disponible(VERT);
        set_voyant_Charge(OFF);
    }
}
