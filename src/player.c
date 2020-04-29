#include "player.h"

void update_player(Player* player, double deltaSecs, double limitTop, double limitBottom) {
    if (player->body.vel_y_per_seconds < 0 && player->body.y <= limitTop)
        stop_player(player);
    else if (player->body.vel_y_per_seconds > 0 && player->body.y + player->body.height >= limitBottom)
        stop_player(player);
    else
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