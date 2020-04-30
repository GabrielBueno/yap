#ifndef BALL_H
#define BALL_H

#include "game_object.h"

typedef struct ball {
	Box    body;
	double degrees;
} Ball;

void randomize_angle(Ball* ball);
void bounce_ball(Ball* ball);

#endif