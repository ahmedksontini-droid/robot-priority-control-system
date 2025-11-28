#ifndef TASKS_H
#define TASKS_H

#include "queue.h"

void add_task(Queue *q, Command cmd);
void execute_tasks(Queue *urgent, Queue *normal);

#endif
