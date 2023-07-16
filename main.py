import utils
import workoutCalc

def menu():
    while True:
        menuView(["MASSIMALE TEORICO","CARICO LAVORO","VOLUME ALLENAMENTO","LBS -> KG","USCITA"])
        inp = utils.userIntegerInput("SCELTA: ")

        if inp == 1:
            max = workoutCalc.calcoloMassimale()
            print(max)
        elif inp == 2:
            print(workoutCalc.calcoloReps())
        elif inp == 3:
            print(workoutCalc.volume())
        elif inp == 4:
            weight = utils.userIntegerInput("Lbs: ")
            print(workoutCalc.lbsToKg(weight))
        elif inp == 5:
            print("Arrivederci")
            break
        else:
            print("Errore")

def menuView(list):
    print("MENU")
    for (i, item) in enumerate(list, start=1):
        print(i,"-", item)

menu()