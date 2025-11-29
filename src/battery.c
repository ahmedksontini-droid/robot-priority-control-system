#include "../include/battery.h"
#include <stdio.h>

void check_battery(Battery *batt) {
    if (batt->level < 20) {
        printf("⚠️ Batterie faible: %d%%\n", batt->level);
    } else {
        printf("Batterie OK: %d%%\n", batt->level);
    }
}
