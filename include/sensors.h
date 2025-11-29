#ifndef SENSORS_H
#define SENSORS_H

// Structure représentant un capteur
typedef struct {
    char name[50];
    float value;
} Sensor;

// Déclaration des fonctions
void initSensor(Sensor *s, const char *name);
void updateSensor(Sensor *s, float newValue);
void printSensor(const Sensor *s);

#endif
