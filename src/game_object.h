#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <stdint.h>

#include "color.h"

typedef struct box {
    double x;
    double y;
    double width;
    double height;
    double vel_x_per_seconds;
    double vel_y_per_seconds;
    double   rotation;
    Color    color;
} Box;

/*!
 * Checks if one box collides with another box 
 */
uint8_t box_collides(Box* target, Box* dest);

/*!
 * Checks if one box is in the boundaries of another box 
 */
uint8_t box_contains(Box* container, Box* contained);

/*!
 * Updates the position of a box after a delta time, in seconds
 */
void update_position(Box* box, double secs);

#endif