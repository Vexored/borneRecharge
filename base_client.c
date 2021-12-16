#include "base_client.h"
//Besoin de définir une base de donnée statique

//Fonction initialisation
base_donnee base_borne;
//Création de la base de données
void creation_base(){
  base_borne.nombre_client = 0;
  int i = 0;

  for(i = 0; 0 < BASE_CLIENT; ++i){
    base_borne.tab_base_donnee.numero_carte = -1; //Permet de savoir si c'est une fiche client attribué ou non
  }
  return 1;
}



//Méthode publique
int authentifier(int numero_client){

  int i = 0;

  for(i = 0; i < base_borne.nombre_client; ++i){
    if(base_borne.tab_base_donnee[i].numero_carte == numero_client){

      printf("Client %d trouvé dans la base de données !\n", base_borne.nombre_client);
      printf("Nom: %s\n",base_borne.tab_base_donnee[i].nom);
      printf("Prenom :%s\n",base_borne.tab_base_donnee[i].prenom);
      printf("Age: %i\n", base_borne.tab_base_donnee[i].age);
      printf("Numero de carte: %i\n");
      //Séquence d'affichage des informations du clients
      //...

      return 1; //Le client est authentifier
    }
  }
  return 0; //Erreur d'identifiaction
}

fiche_client* creation_fiche_client(){
  fiche_client client;

  printf("Veuillez insérer les informations du client :\n");
  printf("Nom: ");
  scanf("%s\n", client.nom_client);
  printf("Prénom: ");
  scanf("%s\n", client.prenom_client);
  printf("Age: ");
  scanf("%i\n", client.age);
  printf("Numéro de carte: ");
  scanf("%i\n", client.numero_carte);
  printf("Saisie du client terminé !\n");

}

void ajouter_client(){
  tab_base_donnee[tab_base_donnee.nombre_client - 1] = creation_fiche_client();
  printf("Client n°i ajouter !", base_borne.tab_base_donnee[base_borne.nombre_client - 1].nombre_client);
  return 1;
}

void supprimer_client(int numero_carte){
  int index = 0;

  index = recherche_client(numero_carte);
  if(index == -1){
    printf("Impossible de supprimer un client inconnu !\n");
    return 0;
  }
  base_borne.tab_base_donnee[i].numero_carte == -1;
  printf("Client %i supprimé.\n", numero_carte);
}

int recherche_client(int numero_carte){
  int i = 0
  for(i = 0; i < base_borne.nombre_client; ++i){
    if(base_borne.tab_base_donnee.numero_carte == numero_carte){
      return i;
    }
  }
  printf("Numéro de carte introuvable !\n");
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
