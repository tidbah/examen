"""
Créer un script Python pour consulter la base de données des livres.

Les fonctionnalités attendues sont les suivantes :

- Afficher les informations sur l'ensemble des livres, y compris le titre, l'auteur, le genre et l'année de publication.
"""

import csv

def consulter_fichier_csv():
    try:
        with open("base_de_donnees.csv", "r") as fichier_csv:
            lecteur_csv = csv.DictReader(fichier_csv, delimiter=";")
            for ligne in lecteur_csv:
                print("Titre :", ligne["Titre"])
                print("Auteur :", ligne["Auteur"])
                print("Genre :", ligne["Genre"])
                print("Année de publication :", ligne["Année"])
                print()
    except FileNotFoundError:
        print("Le fichier CSV n'a pas été trouvé.")

def afficher_signature():
    print("***************************************")
    print("* Tidjane BAH M2 IRS                  *")
    print("***************************************")

afficher_signature()

while True:
    print("=== Menu ===")
    print("1. Consulter la liste des livres")
    print("2. Quitter")
    choix = input("Entrez votre choix : ")

    if choix == "1":
        consulter_fichier_csv()
    elif choix == "2":
        print("Au revoir !")
        break
    else:
        print("Choix invalide. Veuillez réessayer.")

    print()
