#include "../include/tasks.h"
#include "../include/executor.h"
#include "../include/logger.h"
#include <stdio.h>

// Ajoute une commande à une file
void add_task(Queue *q, Command cmd) {
    enqueue(q, cmd);
    printf("Tâche ajoutée : type %d, durée %d, vitesse %d, priorité %d\n",
           cmd.type, cmd.duration, cmd.speed, cmd.priority);
}

// Exécute toutes les tâches avec priorité aux urgentes
void execute_tasks(Queue *urgent, Queue *normal) {
    while (!is_empty(urgent) || !is_empty(normal)) {
        if (!is_empty(urgent)) {
            Command cmd = dequeue(urgent);
            printf("[URGENT] ");
            execute_command(cmd);
            log_command(cmd);
        } else if (!is_empty(normal)) {
            Command cmd = dequeue(normal);
            printf("[NORMAL] ");
            execute_command(cmd);
            log_command(cmd);
        }
    }
}
