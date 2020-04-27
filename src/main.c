#include <stdio.h>
#include <stdlib.h>

#include "screen.h"

int main(int argc, char **argv) {
    printf("Hello, world!\n");

    Screen screen;

    if (init_screen("Yet Another Pong", 800, 600, &screen) < 0) {
        fprintf(stderr, "Something wrong ocurred while initalizating the video system");
        exit(1);
    }

    

    close_screen(&screen);

    return 0;
}