#ifndef ROBOT_H
#define ROBOT_H

#include "battery.h"
#include "queue.h"
#include "sensor.h"

typedef struct {
    Battery battery;
    Queue normalQueue;
    Queue urgentQueue;
    Sensor sensors;
} Robot;

void init_robot(Robot *r);

#endif
