#include "../include/power.h"
#include <stdio.h>

// Vérifie l'état de la batterie et affiche des alertes
void check_battery(Battery *batt) {
    printf("Niveau batterie : %d%%\n", batt->level);
    printf("Tension : %dmV\n", batt->voltage);

    if (batt->level < 20) {
        printf("⚠️ Alerte : batterie faible !\n");
    }
    if (batt->voltage < 3000) {
        printf("⚠️ Alerte : tension trop basse !\n");
    }
}

// Surveille la batterie et déclenche check_battery
void monitor_power(Battery *batt) {
    // Simulation simple : on peut ici modifier level/voltage pour tester
    check_battery(batt);
}
