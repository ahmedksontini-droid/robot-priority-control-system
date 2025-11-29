#include "../include/logger.h"
#include <stdio.h>
#include <time.h>

// Log d'une commande dans le fichier "logs/journal_robot.txt"
void log_command(Command cmd) {
    FILE *file = fopen("logs/journal_robot.txt", "a");
    if (!file) {
        perror("Erreur ouverture fichier journal");
        return;
    }

    // Obtenir l'heure actuelle
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char timeStr[26];
    strftime(timeStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    const char *typeStr;
    switch (cmd.type) {
        case FORWARD:        typeStr = "Avancer"; break;
        case BACKWARD:       typeStr = "Reculer"; break;
        case TURN_LEFT:      typeStr = "Tourner gauche"; break;
        case TURN_RIGHT:     typeStr = "Tourner droite"; break;
        case EMERGENCY_STOP: typeStr = "Arrêt urgence"; break;
        default:             typeStr = "Inconnu"; break;
    }

    const char *priorityStr = (cmd.priority == NORMAL) ? "Normale" : "Urgente";

    fprintf(file, "[%s] Commande : %s | Durée : %ds | Vitesse : %d | Priorité : %s\n",
            timeStr, typeStr, cmd.duration, cmd.speed, priorityStr);

    fclose(file);
}
