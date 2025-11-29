#include "../include/queue.h"
#include <stdlib.h>
#include <stdio.h>

// Initialise une file vide
void init_queue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Ajoute une commande à la file
void enqueue(Queue *q, Command cmd) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Erreur allocation mémoire");
        return;
    }
    newNode->cmd = cmd;
    newNode->next = NULL;

    if (q->rear == NULL) { // file vide
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Retire et retourne la commande en tête de file
Command dequeue(Queue *q) {
    if (is_empty(q)) {
        fprintf(stderr, "Erreur : file vide\n");
        Command emptyCmd;
        emptyCmd.type = EMERGENCY_STOP;
        emptyCmd.duration = 0;
        emptyCmd.speed = 0;
        emptyCmd.priority = NORMAL;
        return emptyCmd;
    }

    Node *temp = q->front;
    Command cmd = temp->cmd;
    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return cmd;
}

// Vérifie si la file est vide
int is_empty(Queue *q) {
    return (q->front == NULL);
}
