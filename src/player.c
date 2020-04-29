#include "player.h"

void update_player(Player* player, double deltaSecs) {
    update_position(&player->body, deltaSecs);
}

void move_player_up(Player* player) {
    player->body.vel_x_per_seconds = 0;
    player->body.vel_y_per_seconds = -200;
}

void move_player_down(Player* player) {
    player->body.vel_x_per_seconds = 0;
    player->body.vel_y_per_seconds = 200;
}

void stop_player(Player* player) {
    player->body.vel_x_per_seconds = 0;
    player->body.vel_y_per_seconds = 0;
}