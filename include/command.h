#ifndef COMMAND_H
#define COMMAND_H

typedef enum {
    FORWARD,
    BACKWARD,
    TURN_LEFT,
    TURN_RIGHT,
    EMERGENCY_STOP
} CommandType;

typedef enum {
    NORMAL,
    URGENT
} Priority;

typedef struct {
    CommandType type;
    int duration;   // en secondes
    int speed;      // unité arbitraire
    Priority priority;
} Command;

#endif
