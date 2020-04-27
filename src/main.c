#include <stdio.h>
#include <stdlib.h>

#include "game.h"

int main(int argc, char **argv) {
    fprintf(stdout, "Initiating yap!\n");

    Game game;

    if (init_game(&game) < 0) {
        fprintf(stderr, "Something wrong occurred while initializing the game...");
        exit(1);
    }

    run_game(&game);
    close_game(&game);

    return 0;
}