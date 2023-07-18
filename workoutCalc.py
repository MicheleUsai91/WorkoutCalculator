import utils

def calcoloMassimale():
    kg = utils.userStringInput("Inserisci il carico usato: ")
    reps = utils.userIntegerInput("Inserisci le ripetizioni fatte: ")
    return round(float(kg) / (1.0278 - (0.0278 * float(reps))), 2)

def calcoloReps():
    massimale = utils.userStringInput("Inserisci il massimale: ")
    reps = utils.userIntegerInput("Inserisci le ripetizioni da fare: ")
    return round(float(massimale) * (1 - (float(reps) / 40)), 2)

def volume():
    kg = utils.userStringInput("Inserisci il carico usato: ")
    reps = utils.userIntegerInput("Reps totali: ")
    return round(float(kg) * float(reps), 2)

def weightConverter(weight, lbsToKg):
    if lbsToKg:
        return round(float(weight) / 2.2046, 2)
    else:
        return round(float(weight) * 2.2046, 2)
