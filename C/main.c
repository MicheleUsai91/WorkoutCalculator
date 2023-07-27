#include <stdio.h>

int getInt(char s[]);
float getFloat(char s[]);
void calcoloMassimale();
void calcoloReps();
void volume();
void weightConverter(int lbsToKg);

int main() {
    const char *menuItems[] = {
        "MASSIMALE TEORICO",
        "CARICO LAVORO",
        "VOLUME ALLENAMENTO",
        "LBS -> KG",
        "KG -> LBS",
        "USCITA"
    };
    int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
    int choice = 0;

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

int getInt(char s[]) {
    int x;
    printf("%s: ", s);
    scanf("%d", &x);
    while (getchar() != '\n');
    return x;
}

float getFloat(char s[]) {
    float weight;
    printf("%s: ", s);
    scanf("%f", &weight);
    while (getchar() != '\n');
    return weight;
}

void calcoloMassimale() {
    float kg = getFloat("PESO");
    int reps = getInt("REPS");
    float res = kg / (1.0278 - (0.0278 * (float)reps));
    printf("MASSIMALE: %.2f\n", res);
}

void calcoloReps() {
    float max = getFloat("PESO");
    int reps = getInt("REPS");
    float res = max * (1 - ((float)reps / 40));
    printf("CARICO DI LAVORO: %.2f\n", res);
}

void volume() {
    float kg = getFloat("PESO");
    int reps = getInt("REPS");
    float res = kg * (float)reps;
    printf("VOLUME: %.2f\n", res);
}

void weightConverter(int lbsToKg) {
    float weight = getFloat("PESO");
    float res = lbsToKg == 1 ? weight / 2.2046 : weight * 2.2046;
    char *resString = lbsToKg == 1 ? "KG: " : "LBS: ";
    printf("%s%.2f\n", resString, res);
}