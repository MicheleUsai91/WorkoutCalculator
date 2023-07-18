import utils

def calcoloMassimale():
    kg = utils.userStringInput("Inserisci il carico usato: ")
    reps = utils.userStringInput("Inserisci le ripetizioni fatte: ")
    return round(float(kg) / (1.0278 - (0.0278 * float(reps))))

def calcoloReps():
    massimale = utils.userStringInput("Inserisci il massimale: ")
    reps = utils.userStringInput("Inserisci le ripetizioni da fare: ")
    return round(massimale * (1 - (reps / 40)))

def volume():
    kg = utils.userStringInput("Inserisci il carico usato: ")
    reps = utils.userStringInput("Reps totali: ")
    return round(kg * float(reps))

def weightConverter(weight, lbsToKg):
    if lbsToKg:
        return round(weight / 2.2046)
    else:
        return round(weight * 2.2046)
