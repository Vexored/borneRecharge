#include "bouton.h"

entrees *io;
int shmid;

int bouton_charge(){
	io = access_memoire(&shimd);
	int etat_bouton = io->bouton_charge;
	io->bouton_charge = 0;
	return etat_bouton;
}

int bouton_stop(){
	io = access_memoire(&shimd);
	int etat_bouton = io->bouton_stop;
	io->bouton_stop = 0;
	return etat_bouton;
}
