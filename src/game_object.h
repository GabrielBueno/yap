#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <stdint.h>

#include "color.h"

typedef struct box {
    uint32_t x;
    uint32_t y;
    uint32_t width;
    uint32_t height;
    double   rotation;
    Color    color;
} Box;

/*
 * Checks if one box collides with another box 
 */
uint8_t collides(Box* target, Box* dest);

/*
 * Checks if one box is in the boundaries of another box 
 */
uint8_t contains(Box* container, Box* contained);

#endif