#ifndef BASE_CLIENT
#define BASE_CLIENT

#include <donnees_borne.h>
#include <memoire_borne.h>
#include <stdio.h>
//Inclure le fichier qui contient toutes les librairies

//On defini les fiches clients et la base de donnée
#define TAILLE_BASE 100
#define TAILLE_NOM 30
#define TAILLE_PRENOM 30

typedef struct{
  char nom_client[TAILLE_NOM];
  char prenom_client[TAILLE_PRENOM];
  int age;
  int numero_carte;
} fiche_client;

typedef struct{
  int nombre_client;
  fiche_client tab_base_donnee[TAILLE_BASE];
} base_donnee;

//Méthodes de BASE_CLIENT

//Méthode élementaire
void creation_base();
int authentifier(int numero_client); //Authentifie les clients
void ajouter_client(); //Lance la séquence d'ajout d'un clients
void supprimer_client(); //Lance la séquence de suppressions d'un clients
int recherche_client(); //Permet de rechercher un client
int recherche_numero(); //Permet de rechercher la disponiblité d'un numéro de carte

#endif
