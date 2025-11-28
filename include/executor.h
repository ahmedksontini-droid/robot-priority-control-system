#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "queue.h"

void execute_command(Command cmd);
void process_queue(Queue *urgent, Queue *normal);

#endif
