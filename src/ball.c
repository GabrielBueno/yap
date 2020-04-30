#include "ball.h"

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

double  _rad(double deg);
int32_t _deg_noise(uint32_t limit);
void    _update_vel(Ball* ball, double radians);

void randomize_angle(Ball* ball) {
	srand(time());

	ball->dregrees = 90 * (rand() % 4) + _deg_noise(30);
	_update_vel(ball);
}

void bounce_ball(Ball* ball) {

}

double _rad(double deg) {
	return deg * (M_PI / 180);
}

int32_t _deg_noise(uint32_t limit) {
	srand(time());
	return (rand() % (limit * 2)) - limit;
}

void _update_vel(Ball* ball) {
	ball->body.vel_x_per_seconds = cos(_rad(ball->radians));
	ball->body.vel_y_per_seconds = sin(_rad(ball->radians));
}