#ifndef SENSOR_H
#define SENSOR_H

typedef struct {
    int temperature;
    int obstacle;   // 0 = pas d'obstacle, 1 = obstacle détecté
} Sensor;

void read_sensors(Sensor *s);

#endif
