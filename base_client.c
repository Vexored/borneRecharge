#include "base_client.h"
//Besoin de définir une base de donnée statique

//Fonction initialisation
base_donnee base_borne;
//Création de la base de données
void creation_base(){
  base_borne.nombre_client = 0;
  int i = 0;

  for(i = 0; i < 100; i++){

    base_borne.tab_base_donnee[i].numero_carte = -1; //Permet de savoir si c'est une fiche client attribué ou non
  }
}



//Méthode publique
int authentifier(int numero_client){

  int i = 0;

  for(i = 0; i < base_borne.nombre_client; ++i){
    if(base_borne.tab_base_donnee[i].numero_carte == numero_client){

      printf("Client %d trouvé dans la base de données !\n", base_borne.nombre_client);
      printf("Nom: %s\n",base_borne.tab_base_donnee[i].nom_client);
      printf("Prenom :%s\n",base_borne.tab_base_donnee[i].prenom_client);
      printf("Age: %i\n", base_borne.tab_base_donnee[i].age);
      printf("Numero de carte: %i\n", base_borne.tab_base_donnee[i].numero_carte);
      //Séquence d'affichage des informations du clients
      //...

      return 1; //Le client est authentifier
    }
  }
  return 0; //Erreur d'identifiaction
}


void ajouter_client(){

	int numero_carte = 0;
  printf("Veuillez insérer les informations du client et la carte :\n");
  attente_insertion_carte();
  numero_carte = lecture_numero_carte();
  if(recherche_numero(numero_carte) != -1){

  printf("Nom: ");
  scanf("%29s",base_borne.tab_base_donnee[base_borne.nombre_client].nom_client);
  printf("Prénom: ");
  scanf("%29s",base_borne.tab_base_donnee[base_borne.nombre_client].prenom_client);
  printf("Age: ");
  scanf("%i", &(base_borne.tab_base_donnee[base_borne.nombre_client].age));
  printf("Numéro de carte: %i", numero_carte);
  base_borne.tab_base_donnee[base_borne.nombre_client].numero_carte = numero_carte;
  printf("Saisie du client terminé !\n");
printf("Client n°%i ajouter ! Veuillez enlever la carte", base_borne.nombre_client);
base_borne.nombre_client = base_borne.nombre_client +1;}

	else{
	printf("Numéro déja utilisé ! Veuillez enlever la carte\n");}

  attente_retrait_carte();
}

void supprimer_client(){
  int index = 0;
  int numero_carte = 0;
  printf("Veuillez insérer la carte :\n");
  attente_insertion_carte();
  numero_carte = lecture_numero_carte();
  index = recherche_client(numero_carte);
  if(index == -1){
    printf("Impossible de supprimer un client inconnu !\n");
  }
  else{
  base_borne.tab_base_donnee[index].numero_carte = -1;
  printf("Client %i supprimé.\n", numero_carte);
  }
  printf("Veuillez retirer la carte\n");
  attente_retrait_carte();
}

int recherche_client(int numero_carte){
  int i = 0;
  for(i = 0; i < base_borne.nombre_client; ++i){
    if(base_borne.tab_base_donnee[i].numero_carte == numero_carte){
      return i;
    }
  }
  printf("Numéro de carte introuvable !\n");
  return -1; // Utilisateur introuvable
}

int recherche_numero(int numero_carte){
  int i = 0;
  for(i = 0; i < base_borne.nombre_client; ++i){
    if(base_borne.tab_base_donnee[i].numero_carte == numero_carte){
      return i;
    }
  }
  printf("Numero deja utilisé\n");
  return -1; // Utilisateur introuvable
}
//On réorganise la base de donnée, si on enlève un client,
//on déplace chaque élément du tableau a son indice -1 a partir du client supprimer.
// int reorganisation_base(int numero_client){
//   int i = 0;
//
//   for(i = numero_client - 1; i < base_borne.nombre_client - 1; ++i){
//     base_borne.tab_base_donnee[i] = base_borne.tab_base_donnee[i + 1];
//   }
//   return 1;
// }
//
// //On augmente ou on réduit la taille du tableau de X case.
// int reallocation_base(int action){
//   //On incrémente, sinon on décremente en fonction de allocation
//   if(action == 0){
//     printf("Erreur: Reallocation inutile");
//     return 0;
//   }
//   base_borne.nombre_client = base_borne.nombre_client + action;
//   base_borne.tab_base_donnee = malloc((base_borne.nombre_client + 1) * sizeof(fiche_client));
//   if(base_borne.tab_base_donnee == NULL){
//     printf("Erreur critique: Réallocation mémoire pour la base donnée à échouer.");
//     printf("Arrêt du programme...\n");
//     exit(0);
//   }
//   return 1;
// }
