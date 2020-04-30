#ifndef BALL_H
#define BALL_H

#include "game_object.h"

typedef struct ball {
	Box    body;
	double degrees;
} Ball;

void randomize_angle(Ball* ball);
void flip_angle(Ball* ball);
void update_ball(Ball* ball, double delta_secs, uint32_t top_limit, uint32_t bottom_limit);

#endif