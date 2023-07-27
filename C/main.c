#include <stdio.h>

void showMenu();
int getUserChoice();
int getReps();
float getWeight();
void calcoloMassimale();
void calcoloReps();
void volume();
void weightConverter(int lbsToKg);

int main() {
    int choice = 0;

    while (choice != 5) {
        showMenu();
        choice = getUserChoice();

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
                weightConverter(1);
                break;
            case 4:
                weightConverter(0);
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

void showMenu() {
    const char *menuItems[] = {
        "MASSIMALE TEORICO",
        "CARICO LAVORO",
        "VOLUME ALLENAMENTO",
        "LBS -> KG",
        "KG -> LBS",
        "USCITA"
    };
    int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
    printf("\n========== MENU ==========\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d - %s\n", i, menuItems[i]);
    }
    printf("==========================\n");
}

int getUserChoice() {
    int choice;
    printf("SCELTA: ");
    scanf("%d", &choice);
    while (getchar() != '\n');
    return choice;
}

int getReps() {
    int reps;
    printf("REPS: ");
    scanf("%d", &reps);
    while (getchar() != '\n');
    return reps;
}

float getWeight() {
    float weight;
    printf("PESO: ");
    scanf("%f", &weight);
    while (getchar() != '\n');
    return weight;
}

void calcoloMassimale() {
    float kg = getWeight();
    int reps = getReps();
    float res = kg / (1.0278 - (0.0278 * (float)reps));
    printf("MASSIMALE: %.2f\n", res);
}

void calcoloReps() {
    float max = getWeight();
    int reps = getReps();
    float res = max * (1 - ((float)reps / 40));
    printf("CARICO DI LAVORO: %.2f\n", res);
}

void volume() {
    float kg = getWeight();
    int reps = getReps();
    float res = kg * (float)reps;
    printf("VOLUME: %.2f\n", res);
}

void weightConverter(int lbsToKg) {
    float weight = getWeight();
    float res = lbsToKg == 1 ? weight / 2.2046 : weight * 2.2046;
    char *resString = lbsToKg == 1 ? "KG: " : "LBS: ";
    printf("%s%.2f\n", resString, res);
}