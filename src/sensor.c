#include "../include/sensor.h"
#include <stdio.h>

void read_sensors(Sensor *s) {
    // Simulation des capteurs
    s->temperature = 25;  // exemple de température simulée
    s->obstacle = 0;      // 0 = pas d'obstacle, 1 = obstacle détecté

    // Affichage des valeurs
    printf("Température lue : %d°C\n", s->temperature);
    printf("Obstacle détecté ? %s\n", s->obstacle ? "Oui" : "Non");
}
