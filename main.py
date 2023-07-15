import utils
import workoutCalc
import csv
from prettytable import PrettyTable

def menu():
    while True:
        menuView(["MASSIMALE TEORICO","CARICO LAVORO","VOLUME ALLENAMENTO","LBS -> KG","VEDI MASSIMALI","USCITA"])
        inp = utils.userIntegerInput("SCELTA: ")

        if inp == 1:
            max = workoutCalc.calcoloMassimale()
            print(max)
            x = utils.userIntegerInput("Vuoi salvare il massimale?\n0 - NO\n1 - SI\nScelta: ")
            if x == 1:
                salvaMax(max)
        elif inp == 2:
            print(workoutCalc.calcoloReps())
        elif inp == 3:
            print(workoutCalc.volume())
        elif inp == 4:
            weight = utils.userIntegerInput("Lbs: ")
            print(workoutCalc.lbsToKg(weight))
        elif inp == 5:
            printMax()
        elif inp == 6:
            print("Arrivederci")
            break
        else:
            print("Errore")

def menuView(list):
    print("MENU")
    for (i, item) in enumerate(list, start=1):
        print(i,"-", item)

def salvaMax(max):
    esercizio = utils.userStringInput("Inserisci l'esercizio: ")
    with open("max.csv", "w") as maxCsv:
        campi = ["ESERCIZIO","MASSIMALE"]
        maxCsv = csv.DictWriter(maxCsv, fieldnames=campi)
        maxCsv.writeheader()
        maxCsv.writerow({"ESERCIZIO" : esercizio, "MASSIMALE" : max})

def printMax():
    with open("max.csv", "r") as maxCsv:
        reader = csv.reader(maxCsv)
        header = next(reader)
        table = PrettyTable()
        table.field_names = header
        for row in reader:
            table.add_row(row)
        print(table)

menu()