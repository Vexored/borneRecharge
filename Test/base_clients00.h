#ifndef BASE_CLIENT
#define BASE_CLIENT

//Inclure le fichier qui contient toutes les librairies

//On défini les fiches clients et la base de donnée

typedef struct{
  char[30] nom_client;
  char[30] prenom_client;
  unsigned int age;
  unsigned int numero_carte;
} fiche_client;

typedef struct{
  unsigned int nombre_client;
  fiche_client* tab_base_donnee;
} base_donnee;

//Méthodes de BASE_CLIENT

//Méthode élementaire'

int authentifier(int numero_client); //Authentifie les clients
int ajouter_client(); //Lance la séquence d'ajout d'un clients
int supprimer_client(); //Lance la séquence de suppressions d'un clients

#endif
