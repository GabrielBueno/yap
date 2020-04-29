#include "game_object.h"

uint8_t collides(Box* target, Box* dest) {
    uint8_t collides_in_x = 0;
    uint8_t collides_in_y = 0;

    if (dest->x <= target->x && dest->x + dest->width >= target->x)
        collides_in_x = 1;

    if (dest->x >= target->x && dest->x <= target->x + target->width)
        collides_in_x = 1;

    if (dest->y <= target->y && dest->y + dest->height >= target->y)
        collides_in_y = 1;

    if (dest->y >= target->y && dest->y <= target->y + target->height)
        collides_in_y = 1;

    return collides_in_x && collides_in_y;
}

uint8_t contains(Box* container, Box* contained) {
    if (container->x <= contained->x && container->x + container->width >= contained->x + contained->width)
        if (container->y <= contained->y && container->y + container->height >= contained->y + contained->height)
            return 1;

    return 0;
}

void update_position(Box* box, double secs) {
    box->x += box->vel_x_per_seconds * secs;
    box->y += box->vel_y_per_seconds * secs;
}