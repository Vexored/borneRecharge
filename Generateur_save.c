#include "Generateur_save.h"
#include <unistd.h>

entrees *io;
int shmid;

void initialiser_gene_pwn(){
  io = acces_memoire(&shmid);
  /* associe la zone de memoire partagee au pointeur */
  if (io == NULL) printf("Erreur pas de men sh\n");
}
/*
void set_gene_pwn(pwm tension){
  io->gene_pwm = tension
}
void get_gene_u(){
  return io->gene_u;
}
void set_contacteur_AC(int etat_contacteur){
  io->contacteur_AC = etat_contacteur;

}
*/
void genCharge(/* arguments */) {

  //Etat initial machine à état
  char etat = 'A';


  while(etat != 'S'){
  	sleep(0.5);
    switch(etat){
      case 'A': //Attente led_prise

        //Initialisation des voyants
        set_voyant_Charge(ROUGE);

        //Deverouillage de la Prise
        deverouiller_trappe();


        //Generer 12V DC
        io->gene_pwm = DC;

        //Attente du branchement de la prise par le client
        while(io->gene_u != 9){

            //Attente génération 9V DC par le vehicule
			sleep(0.5);
            //Changment d'état
            etat = 'B';
          }

        break;

        case 'B': //Prise branchee

          //Initialisation des voyants
          set_prise(VERT);

          //Verouillage de la Prise
           verouiller_trappe();


          //Generation d'un signal 1kHz AC
          io->gene_pwm = AC_1K;

          while(1){
            //Attente génération AC 9V par le vehicule
            sleep(0.5);
            if(io->gene_u == 9){

              //Changement d'état
              etat = 'C';
              break;
            }
          }
          break;

          case 'C': //Attente_S2_vehicule

            //Fermeture contacteur AC
            io->contacteur_AC = 1;

            while(1){
              //Attente de la fermeture de S2 par le vehicule
				sleep(0.5);
              if(io->gene_u == 6){

                //Changement d'état
                etat = 'D';
                break;
              }
            }
            break;

          case 'D': //Charge du Vehicule

            //Generation d'une tension avec rapport cyclique variable
            io->gene_pwm = AC_CL;
            while(1){
            sleep(0.5);
              //Attente ouverture S2 Vehicule
              if(io->gene_u == 9 || bouton_stop() == 1){

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
          io->contacteur_AC = 0;

          //On quitte la machine à état
          etat = 'S';
          break;
      }
  }
}

void genReprendre(){ //Etat initial machine à état

  char etatR = 'A';

  while(etatR != 'C'){
  	sleep(0.5);
    switch(etatR){
      case 'A':
        deverouiller_trappe();
        while(io->gene_u != 12){
        sleep(0.5);

              etatR = 'B';

        }
        break;

      case 'B':
        verouiller_trappe();
        set_prise(OFF);
        set_voyant_Disponible(VERT);
        set_voyant_Charge(OFF);
        etatR = 'C';
        break;
    }
}
}
