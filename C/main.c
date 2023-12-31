#include <stdio.h>
#include <stdbool.h>

int getInt(const char s[]);
float getFloat(const char s[]);
void calcoloMassimale();
void calcoloReps();
void volume();
void weightConverter(float factor);

int main() {
    const char *const menuItems[] = {
        "MASSIMALE TEORICO",
        "CARICO LAVORO",
        "VOLUME ALLENAMENTO",
        "LBS -> KG",
        "KG -> LBS",
        "USCITA"
    };
    int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
    int choice = 0;
    const float lbsToKgFactor = 1.0 / 2.2046;

    while (choice != 5) {
        printf("\n========== MENU ==========\n");
        for (int i = 0; i < menuSize; i++) {
            printf("%d - %s\n", i, menuItems[i]);
        }
        printf("==========================\n");

        choice = getInt("SCELTA");

        switch (choice) {
            case 0:
                calcoloMassimale();
                break;
            case 1:
                calcoloReps();
                break;
            case 2:
                volume();
                break;
            case 3:
                weightConverter(lbsToKgFactor);
                break;
            case 4:
                weightConverter(1.0 / lbsToKgFactor);
                break;
            case 5:
                printf("Uscita...\n");
                break;
            default:
                printf("Errore. Inserire un numero tra 1 e 6.\n");
                break;
        }
    }
    return 0;
}

int getInt(const char s[]) {
    int x;
    bool validInput = false;
    do {
        printf("%s: ", s);
        if (scanf("%d", &x) == 1) {
            validInput = true;
        } else {
            printf("Input non valido. Riprova.\n");
            while (getchar() != '\n');
        }
    } while (!validInput);
    while (getchar() != '\n');
    return x;
}

float getFloat(const char s[]) {
    float x;
    bool validInput = false;
    do {
        printf("%s: ", s);
        if (scanf("%f", &x) == 1) {
            validInput = true;
        } else {
            printf("Input non valido. Riprova.\n");
            while (getchar() != '\n');
        }
    } while (!validInput);
    while (getchar() != '\n');
    return x;
}

void calcoloMassimale() {
    float kg = getFloat("PESO");
    int reps = getInt("REPS");
    float repsFloat = (float)reps;
    float res = kg / (1.0278 - (0.0278 * repsFloat));
    printf("MASSIMALE: %.2f\n", res);
}

void calcoloReps() {
    float max = getFloat("PESO");
    int reps = getInt("REPS");
    float repsFloat = (float)reps;
    float res = max * (1.0 - (repsFloat / 40.0));
    printf("CARICO DI LAVORO: %.2f\n", res);
}

void volume() {
    float kg = getFloat("PESO");
    int reps = getInt("REPS");
    float repsFloat = (float)reps;
    float res = kg * repsFloat;
    printf("VOLUME: %.2f\n", res);
}

void weightConverter(float factor) {
    float weight = getFloat("PESO");
    float res = weight * factor;
    char *resString = factor == 1.0 ? "KG: " : "LBS: ";
    printf("%s%.2f\n", resString, res);
}