#ifndef BASE_CLIENT
#define BASE_CLIENT

#include <donnees_borne.h>
#include <memoire_borne.h>
#include <stdio.h>
//Inclure le fichier qui contient toutes les librairies

//On défini les fiches clients et la base de donnée
#DEFINE TAILLE_BASE 100
#DEFINE TAILLE_NOM 30
#DEFINE TAILLE_PRENOM 30

typedef struct{
  char[TAILLE_NOM] nom_client;
  char[TAILLE_PRENOM] prenom_client;
  unsigned int age;
  unsigned int numero_carte;
} fiche_client;

typedef struct{
  unsigned int nombre_client;
  fiche_client[TAILLE_BASE] tab_base_donnee;
} base_donnee;

//Méthodes de BASE_CLIENT

//Méthode élementaire'
void creation_base();
int authentifier(int numero_client); //Authentifie les clients
int ajouter_client(); //Lance la séquence d'ajout d'un clients
int supprimer_client(); //Lance la séquence de suppressions d'un clients

#endif
