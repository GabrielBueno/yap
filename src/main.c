#include <stdio.h>
#include <stdlib.h>

#include "game.h"
// #include "game_object.h"

int main(int argc, char** argv) {
    fprintf(stdout, "Initiating yap!\n");

    Game game;

    if (init_game(&game) < 0) {
        fprintf(stderr, "Something wrong occurred while initializing the game...");
        exit(1);
    }

    run_game(&game);
    close_game(&game);

    // Box box1;
    // Box box2;

    // box1.x = 5;
    // box1.y = 5;
    // box1.width = 10;
    // box1.height = 10;

    // box2.x = 0;
    // box2.y = 0;
    // box2.width = 15;
    // box2.height = 15;

    // fprintf(stdout, "%d\n", collides(&box1, &box2));
    // fprintf(stdout, "%d\n", contains(&box2, &box1));

    return 0;
}