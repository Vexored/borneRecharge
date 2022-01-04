#include "bouton.h"

entrees *io;
int shmid;

void bouton_initialiser(){
	io = access_memoire(&shimd);
	/* associe la zone de memoire partagee au pointeur */
	if (io == NULL) printf("Erreur pas de men sh\n");
}

int bouton_charge(){
	int etat_bouton = io->bouton_charge;
	if(etat_bouton == 1){
		io->bouton_charge = 0;
		return etat_bouton;
	}
	return etat_bouton;
}

int bouton_stop(){
	int etat_bouton = io->bouton_stop;
	if(etat_bouton == 1){
		io->bouton_stop = 0;
		return etat_bouton;
	}
	return etat_bouton;
}
