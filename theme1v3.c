#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVRES 100

typedef struct {
    char titre[100];
    char auteur[100];
    char genre[50];
    int annee;
} Livre;

Livre livres[MAX_LIVRES];
int nombre_livres = 0;

// Fonction pour ajouter un livre
void ajouter_livre() {
    if (nombre_livres == MAX_LIVRES) {
        printf("La limite de stockage des livres est atteinte.\n");
        return;
    }

    printf("Ajouter un nouveau livre\n");

    printf("Titre: ");
    fgets(livres[nombre_livres].titre, sizeof(livres[nombre_livres].titre), stdin);
    strtok(livres[nombre_livres].titre, "\n"); // Supprimer le retour à la ligne

    printf("Auteur: ");
    fgets(livres[nombre_livres].auteur, sizeof(livres[nombre_livres].auteur), stdin);
    strtok(livres[nombre_livres].auteur, "\n"); // Supprimer le retour à la ligne

    printf("Genre: ");
    fgets(livres[nombre_livres].genre, sizeof(livres[nombre_livres].genre), stdin);
    strtok(livres[nombre_livres].genre, "\n"); // Supprimer le retour à la ligne

    printf("Année de publication: ");
    scanf("%d", &livres[nombre_livres].annee);
    getchar(); // Vider le tampon de saisie

    nombre_livres++;

    printf("Livre ajouté avec succès.\n");
}

// Fonction pour afficher la liste des livres
void afficher_livres() {
    printf("Liste des livres :\n");
    for (int i = 0; i < nombre_livres; i++) {
        printf("Livre %d\n", i + 1);
        printf("Titre: %s\n", livres[i].titre);
        printf("Auteur: %s\n", livres[i].auteur);
        printf("Genre: %s\n", livres[i].genre);
        printf("Année de publication: %d\n", livres[i].annee);
        printf("\n");
    }
}

// Fonction pour supprimer un livre
void supprimer_livre() {
    printf("Supprimer un livre\n");
    // Demander l'indice du livre à supprimer

    int indice_livre;
    printf("Entrez l'indice du livre à supprimer: ");
    scanf("%d", &indice_livre);

    if (indice_livre >= 1 && indice_livre <= nombre_livres) {
        for (int i = indice_livre - 1; i < nombre_livres - 1; i++) {
            livres[i] = livres[i + 1];
        }
        nombre_livres--;
        printf("Livre supprimé avec succès.\n");
    } else {
        printf("Indice de livre invalide.\n");
    }
}

// Fonction pour modifier un livre
void modifier_livre() {
    printf("Modifier un livre\n");
    // Demander l'indice du livre à modifier

    int indice_livre;
    printf("Entrez l'indice du livre à modifier: ");
    scanf("%d", &indice_livre);

    if (indice_livre >= 1 && indice_livre <= nombre_livres) {
        printf("Nouvelles informations sur le livre\n");

        printf("Titre: ");
        fgets(livres[indice_livre - 1].titre, sizeof(livres[indice_livre - 1].titre), stdin);
        strtok(livres[indice_livre - 1].titre, "\n"); // Supprimer le retour à la ligne

        printf("Auteur: ");
        fgets(livres[indice_livre - 1].auteur, sizeof(livres[indice_livre - 1].auteur), stdin);
        strtok(livres[indice_livre - 1].auteur, "\n"); // Supprimer le retour à la ligne

        printf("Genre: ");
        fgets(livres[indice_livre - 1].genre, sizeof(livres[indice_livre - 1].genre), stdin);
        strtok(livres[indice_livre - 1].genre, "\n"); // Supprimer le retour à la ligne

        printf("Année de publication: ");
        scanf("%d", &livres[indice_livre - 1].annee);
        getchar(); // Vider le tampon de saisie

        printf("Livre modifié avec succès.\n");
    } else {
        printf("Indice de livre invalide.\n");
    }
}

// Fonction pour afficher les statistiques
void afficher_statistiques() {
    printf("Statistiques :\n");
    printf("Nombre de livres ajoutés : %d\n", nombre_livres);
    printf("\n");
}

// Fonction pour rechercher un livre
void rechercher_livre() {
    printf("Rechercher un livre\n");
    // Demander les critères de recherche (titre, auteur, etc.) et afficher les livres correspondants

    char critere_recherche[100];
    printf("Entrez le critère de recherche : ");
    fgets(critere_recherche, sizeof(critere_recherche), stdin);
    strtok(critere_recherche, "\n"); // Supprimer le retour à la ligne

    int livres_trouves = 0;

    printf("Résultats de recherche :\n");

    for (int i = 0; i < nombre_livres; i++) {
        if (strstr(livres[i].titre, critere_recherche) != NULL ||
            strstr(livres[i].auteur, critere_recherche) != NULL ||
            strstr(livres[i].genre, critere_recherche) != NULL) {
            printf("Livre %d\n", i + 1);
            printf("Titre: %s\n", livres[i].titre);
            printf("Auteur: %s\n", livres[i].auteur);
            printf("Genre: %s\n", livres[i].genre);
            printf("Année de publication: %d\n", livres[i].annee);
            printf("\n");
            livres_trouves++;
        }
    }

    if (livres_trouves == 0) {
        printf("Aucun livre correspondant trouvé.\n");
    }
}

// Fonction pour générer un fichier CSV
void generer_fichier_csv() {
    FILE *fichier_csv = fopen("base_de_donnees.csv", "w");
    if (fichier_csv == NULL) {
        printf("Erreur lors de la création du fichier CSV.\n");
        return;
    }

    fprintf(fichier_csv, "Titre;Auteur;Genre;Année\n");
    for (int i = 0; i < nombre_livres; i++) {
        fprintf(fichier_csv, "%s;%s;%s;%d\n", livres[i].titre, livres[i].auteur, livres[i].genre, livres[i].annee);
    }

    fclose(fichier_csv);

    printf("Fichier CSV généré avec succès.\n");
}

int main() {
    int choix;

    do {
        printf("=== Menu ===\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher la liste des livres\n");
        printf("3. Supprimer un livre\n");
        printf("4. Modifier un livre\n");
        printf("5. Afficher les statistiques\n");
        printf("6. Rechercher un livre\n");
        printf("7. Générer un fichier CSV\n");
        printf("8. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        getchar(); // Vider le tampon de saisie

        switch (choix) {
            case 1:
                ajouter_livre();
                break;
            case 2:
                afficher_livres();
                break;
            case 3:
                supprimer_livre();
                break;
            case 4:
                modifier_livre();
                break;
            case 5:
                afficher_statistiques();
                break;
            case 6:
                rechercher_livre();
                break;
            case 7:
                generer_fichier_csv();
                break;
            case 8:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

        printf("\n");
    } while (choix != 8);

    return 0;
}
