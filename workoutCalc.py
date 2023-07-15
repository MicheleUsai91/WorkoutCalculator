import utils

def calcoloMassimale():
    kg = utils.userIntegerInput("Inserisci il carico usato: ")
    reps = utils.userIntegerInput("Inserisci le ripetizioni fatte: ")
    return round(float(kg) / (1.0278 - (0.0278 * float(reps))))

def calcoloReps():
    massimale = utils.userIntegerInput("Inserisci il massimale: ")
    reps = utils.userIntegerInput("Inserisci le ripetizioni da fare: ")
    return round(massimale * (1 - (reps / 40)))

def volume():
    kg = utils.userIntegerInput("Inserisci il carico usato: ")
    reps = utils.userIntegerInput("Reps totali: ")
    return round(kg * float(reps))

def lbsToKg(weight):
    return round(weight / 2.2046)