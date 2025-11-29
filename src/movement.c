#include "../include/movement.h"
#include <stdio.h>
#include <unistd.h> // pour sleep

void move_robot(Command cmd) {
    switch (cmd.type) {
        case FORWARD:
            printf("Le robot avance à la vitesse %d pendant %d secondes\n", cmd.speed, cmd.duration);
            sleep(cmd.duration);
            break;
        case BACKWARD:
            printf("Le robot recule à la vitesse %d pendant %d secondes\n", cmd.speed, cmd.duration);
            sleep(cmd.duration);
            break;
        case TURN_LEFT:
            printf("Le robot tourne à gauche pendant %d secondes\n", cmd.duration);
            sleep(cmd.duration);
            break;
        case TURN_RIGHT:
            printf("Le robot tourne à droite pendant %d secondes\n", cmd.duration);
            sleep(cmd.duration);
            break;
        case EMERGENCY_STOP:
            printf("Arrêt d'urgence activé !\n");
            break;
        default:
            printf("Commande inconnue\n");
            break;
    }
}
