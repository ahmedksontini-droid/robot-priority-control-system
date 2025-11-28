#ifndef BATTERY_H
#define BATTERY_H

typedef struct {
    int level;      // niveau batterie %
    int voltage;    // tension mV
} Battery;

void check_battery(Battery *batt);

#endif
