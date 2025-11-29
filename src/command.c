#include "../include/command.h"
#include <stdio.h>

// Affiche les informations d'une commande
void printCommand(const Command *cmd) {
    const char *typeStr;
    switch (cmd->type) {
        case FORWARD:        typeStr = "Avancer"; break;
        case BACKWARD:       typeStr = "Reculer"; break;
        case TURN_LEFT:      typeStr = "Tourner à gauche"; break;
        case TURN_RIGHT:     typeStr = "Tourner à droite"; break;
        case EMERGENCY_STOP: typeStr = "Arrêt d'urgence"; break;
        default:             typeStr = "Inconnu"; break;
    }

    const char *priorityStr = (cmd->priority == NORMAL) ? "Normale" : "Urgente";

    printf("Commande : %s | Durée : %ds | Vitesse : %d | Priorité : %s\n",
           typeStr, cmd->duration, cmd->speed, priorityStr);
}

// Initialise une commande avec les paramètres donnés
void initCommand(Command *cmd, CommandType type, int duration, int speed, Priority priority) {
    cmd->type = type;
    cmd->duration = duration;
    cmd->speed = speed;
    cmd->priority = priority;
}
