#include "player.h"

void update_player(Player* player, double delta_secs, double limit_top, double limit_bottom) {
    if (player->body.vel_y_per_seconds < 0 && player->body.y <= limit_top)
        stop_player(player);
    else if (player->body.vel_y_per_seconds > 0 && player->body.y + player->body.height >= limit_bottom)
        stop_player(player);
    else
        update_position(&player->body, delta_secs);
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