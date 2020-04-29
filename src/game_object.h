#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <stdint.h>

#include "color.h"

typedef struct box {
    uint32_t x;
    uint32_t y;
    uint32_t width;
    uint32_t height;
    uint32_t vel_x_per_seconds;
    uint32_t vel_y_per_seconds;
    double   rotation;
    Color    color;
} Box;

/*!
 * Checks if one box collides with another box 
 */
uint8_t collides(Box* target, Box* dest);

/*!
 * Checks if one box is in the boundaries of another box 
 */
uint8_t contains(Box* container, Box* contained);

/*!
 * Updates the position of a box after a delta time, in seconds
 */
void update_position(Box* box, double secs);

#endif