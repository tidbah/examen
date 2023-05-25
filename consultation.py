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

consulter_fichier_csv()
