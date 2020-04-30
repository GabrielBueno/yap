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
void update_player(Player* player, double delta_secs, double limit_top, double limit_bottom);

/*!
 * Adjust the player's body velocity, to make him move up
 */
void move_player_up(Player* player);

/*!
 * Adjust the player's body velocity, to make him move down
 */
void move_player_down(Player* player);

/*!
 * Zero the player's velocities
 */
void stop_player(Player* player);

#endif