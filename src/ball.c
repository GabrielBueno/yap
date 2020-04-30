#include "ball.h"

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

#include "game_object.h"

double  _rad(double deg);
int32_t _deg_noise(uint32_t limit);
void    _update_vel(Ball* ball);

void randomize_angle(Ball* ball) {
	srand(time(NULL));

	ball->degrees = (90 * (rand() % 4) - 45) + _deg_noise(30);
	_update_vel(ball);
}

void flip_angle(Ball* ball) {
	ball->degrees = (ball->degrees + 90) + _deg_noise(10);
	_update_vel(ball);
}

void update_ball(Ball* ball, double delta_secs, uint32_t top_limit, uint32_t bottom_limit) {
	if (ball->body.vel_y_per_seconds > 0 && ball->body.y + ball->body.height >= bottom_limit) 
		ball->body.vel_y_per_seconds *= -1;
	

	if (ball->body.vel_y_per_seconds < 0 && ball->body.y <= top_limit) 
		ball->body.vel_y_per_seconds *= -1;

	update_position(&ball->body, delta_secs);
}

double _rad(double deg) {
	return deg * (M_PI / 180);
}

int32_t _deg_noise(uint32_t limit) {
	srand(time(NULL));
	return (rand() % (limit * 2)) - limit;
}

void _update_vel(Ball* ball) {
	ball->body.vel_x_per_seconds = 500 * cos(_rad(ball->degrees));
	ball->body.vel_y_per_seconds = 500 * sin(_rad(ball->degrees));
}