#include "../include/robot.h"
#include <stdio.h>

// Initialise le robot
void init_robot(Robot *r) {
    // Initialiser la batterie
    r->battery.level = 100;
    r->battery.voltage = 4000;

    // Initialiser les files de commandes
    init_queue(&r->normalQueue);
    init_queue(&r->urgentQueue);

    // Initialiser les capteurs
    r->sensors.temperature = 25;  // valeur simulée
    r->sensors.obstacle = 0;

    printf("Robot initialisé : batterie à %d%%, tension %dmV, capteurs prêts.\n",
           r->battery.level, r->battery.voltage);
}
