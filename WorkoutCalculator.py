
def menu():
    while True:
        menuView(["MASSIMALE TEORICO","CARICO LAVORO","VOLUME ALLENAMENTO","USCITA"])
        inp = userIntegerInput("SCELTA: ")

        if inp == 1:
            print(round(calcoloMassimale()))
        elif inp == 2:
            print(round(calcoloReps()))
        elif inp == 3:
            print(round(volume()))
        elif inp == 4:
            print("Arrivederci")
            break
        else:
            print("Errore")

def calcoloMassimale():
    kg = userIntegerInput("Inserisci il carico usato: ")
    reps = userIntegerInput("Inserisci le ripetizioni fatte: ")
    return float(kg) / (1.0278 - (0.0278 * float(reps)))

def calcoloReps():
    massimale = userIntegerInput("Inserisci il massimale: ")
    reps = userIntegerInput("Inserisci le ripetizioni da fare: ")
    return massimale * (1 - (reps / 40))

def volume():
    kg = userIntegerInput("Inserisci il carico usato: ")
    reps = userIntegerInput("Reps totali: ")
    return kg * float(reps)

def menuView(list):
    print("MENU")
    for (i, item) in enumerate(list, start=1):
        print(i,"-", item)

def userIntegerInput(string):
    return int(input(string))

menu()