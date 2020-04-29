#include "player.h"

void update(Player* player, double deltaSecs) {
    update_position(&player->body, deltaSecs);
}

void move_up(Player* player) {
    player->body.vel_x_per_seconds = 0;
    player->body.vel_y_per_seconds = -15;
}

void move_down(Player* player) {
    player->body.vel_x_per_seconds = 0;
    player->body.vel_y_per_seconds = 15;
}

void stop(Player* player) {
    player->body.vel_x_per_seconds = 0;
    player->body.vel_y_per_seconds = 0;
}