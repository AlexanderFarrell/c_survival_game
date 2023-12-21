#ifndef AREA_H_H
#define AREA_H_H

typedef struct Area Area;
struct Area {
    char * name;
    int health_delta;
    int hunger_delta;
};

#endif