#include "../include/sensors.h"
#include <stdio.h>
#include <string.h>

// Initialise un capteur avec un nom et valeur 0
void initSensor(Sensor *s, const char *name) {
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0'; // sécurité
    s->value = 0.0f;
}

// Met à jour la valeur d'un capteur
void updateSensor(Sensor *s, float newValue) {
    s->value = newValue;
}

// Affiche l'état du capteur
void printSensor(const Sensor *s) {
    printf("Capteur %s : %.2f\n", s->name, s->value);
}
