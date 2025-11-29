#include "../include/executor.h"
#include "../include/movement.h"  // pour move_forward, turn_left, etc.
#include <stdio.h>
#include <unistd.h>  // pour sleep

// Exécute une seule commande
void execute_command(Command cmd) {
    switch (cmd.type) {
        case FORWARD:
            move_forward(cmd.speed);
            sleep(cmd.duration);
            break;
        case BACKWARD:
            printf("Le robot recule à la vitesse %d pendant %d secondes\n", cmd.speed, cmd.duration);
            sleep(cmd.duration);
            break;
        case TURN_LEFT:
            turn_left();
            sleep(cmd.duration);
            break;
        case TURN_RIGHT:
            turn_right();
            sleep(cmd.duration);
            break;
        case EMERGENCY_STOP:
            stop();
            break;
        default:
            printf("Commande inconnue\n");
            break;
    }
}

// Traite les files : priorité aux commandes urgentes
void process_queue(Queue *urgent, Queue *normal) {
    while (!is_empty(urgent) || !is_empty(normal)) {
        if (!is_empty(urgent)) {
            Command cmd = dequeue(urgent);
            printf("[URGENT] ");
            execute_command(cmd);
        } else if (!is_empty(normal)) {
            Command cmd = dequeue(normal);
            printf("[NORMAL] ");
            execute_command(cmd);
        }
    }
}
