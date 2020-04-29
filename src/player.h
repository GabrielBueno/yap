#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>
#include "game_object.h"

typedef struct player {
    Box body;
    uint32_t score;
} Player;

/*!
 * Updates the player's body, based on its current velocity
 */
void update(Player* player, double deltaSecs);

/*!
 * Adjust the player's body velocity, to make him move up
 */
void move_up(Player* player);

/*!
 * Adjust the player's body velocity, to make him move down
 */
void move_down(Player* player);

/*!
 * Zero the player's velocities
 */
void stop(Player* player);

#endif