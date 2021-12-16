#include <donnees_borne.h>
#include <memoire_borne.h>

entrees *io;
int shmid;
int depart_timer;

void timer_initialiser(){
	io=acces_memoire(&shmid);
	/* associe la zone de memoire partagee au pointeur */
	if (io==NULL) printf("Erreur pas de mem sh\n");
	depart_timer=io->timer_sec;
}

void timer_raz(){
	io=acces_memoire(&shmid);//lié le simulateur et initialisation du timer
	depart_timer = io->timer_sec;
}
int timer_valeur(){
	return ((io->timer_sec) - depart_timer);
}
