#include <iostream>
#include <limits>

int getInt(const std::string& s);
float getFloat(const std::string& s);
void calcoloMassimale();
void calcoloReps();
void volume();
void weightConverter(float factor);

int main() {
    const std::string menuItems[] = {
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
        std::cout << "\n========== MENU ==========\n";
        for (int i = 0; i < menuSize; i++) {
            std::cout << i << " - " << menuItems[i] << '\n';
        }
        std::cout << "==========================\n";

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
                std::cout << "Uscita...\n";
                break;
            default:
                std::cout << "Errore. Inserire un numero tra 1 e 6.\n";
                break;
        }
    }
    return 0;
}

int getInt(const std::string& s) {
    int x;
    bool validInput = false;
    do {
        std::cout << s << ": ";
        if (std::cin >> x) {
            validInput = true;
        } else {
            std::cout << "Input non valido. Riprova.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!validInput);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return x;
}

float getFloat(const std::string& s) {
    float x;
    bool validInput = false;
    do {
        std::cout << s << ": ";
        if (std::cin >> x) {
            validInput = true;
        } else {
            std::cout << "Input non valido. Riprova.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!validInput);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return x;
}

void calcoloMassimale() {
    float kg = getFloat("PESO");
    int reps = getInt("REPS");
    float repsFloat = static_cast<float>(reps);
    float res = kg / (1.0278 - (0.0278 * repsFloat));
    std::cout << "MASSIMALE: " << res << '\n';
}

void calcoloReps() {
    float max = getFloat("PESO");
    int reps = getInt("REPS");
    float repsFloat = static_cast<float>(reps);
    float res = max * (1.0 - (repsFloat / 40.0));
    std::cout << "CARICO DI LAVORO: " << res << '\n';
}

void volume() {
    float kg = getFloat("PESO");
    int reps = getInt("REPS");
    float repsFloat = static_cast<float>(reps);
    float res = kg * repsFloat;
    std::cout << "VOLUME: " << res << '\n';
}

void weightConverter(float factor) {
    float weight = getFloat("PESO");
    float res = weight * factor;
    std::string resString = (factor == 1.0) ? "KG: " : "LBS: ";
    std::cout << resString << res << '\n';
}