#include "game.h"

#include <SDL2/SDL.h>
#include <stdio.h>

#include "color.h"
#include "game_object.h"

const uint32_t SCREEN_WIDTH  = 800;
const uint32_t SCREEN_HEIGHT = 600;
const double FPS             = 1000 / 60;

const GameOperationResult GAME_SUCCESS           = 1;
const GameOperationResult GAME_SDL_INIT_ERROR    = -1;
const GameOperationResult GAME_SCREEN_INIT_ERROR = -2;

const GameState GAME_STATE_CREATED = 1;
const GameState GAME_STATE_RUNNING = 2;
const GameState GAME_STATE_PAUSED  = 3;
const GameState GAME_STATE_ENDED   = 4;

void _init_game_objs(Game* game);
void _reset_game_objs(Game* game);
void _update(Game* game, uint32_t deltaTicks);
void _process_inputs(Game* game);
void _draw(Game* game);
void _box_to_sdl_rect(Box* src, SDL_Rect* dst);

GameOperationResult init_game(Game* out_game) {
    if (SDL_Init(0) < 0)
        return GAME_SDL_INIT_ERROR;

    if (init_screen("yap", SCREEN_WIDTH, SCREEN_HEIGHT, &out_game->screen) < 0)
        return GAME_SCREEN_INIT_ERROR;

    out_game->state     = GAME_STATE_CREATED;
    out_game->last_tick = SDL_GetTicks();

    return GAME_SUCCESS;
}

void run_game(Game* game) {
    game->state = GAME_STATE_RUNNING;
    _init_game_objs(game);

    while (game->state != GAME_STATE_ENDED) {
        _process_inputs(game);

        if (game->state == GAME_STATE_PAUSED)
            continue;

        if (SDL_GetTicks() - game->last_tick < FPS)
            continue;

        _update(game, SDL_GetTicks() - game->last_tick);
        _draw(game);

        game->last_tick = SDL_GetTicks();
    }
}

void close_game(Game* game) {
    close_screen(&game->screen);

    SDL_Quit();
}

void _draw(Game* game) {
    initialize_drawing(&game->screen);

    Box* boxes[3];

    boxes[0] = &game->player1.body;
    boxes[1] = &game->player2.body;
    boxes[2] = &game->ball.body;

    Color color;

    color.r = 0xff;
    color.g = 0xff;
    color.b = 0xff;
    color.a = 0xff;

    draw_boxes(&game->screen, boxes, 3, color);

    end_drawing(&game->screen);
}

void _update(Game* game, uint32_t delta_ticks) {
    double delta_secs = (double)delta_ticks / 1000;

    update_player(&game->player1, delta_secs, 0, SCREEN_HEIGHT);
    update_player(&game->player2, delta_secs, 0, SCREEN_HEIGHT);
    update_ball(&game->ball, delta_secs,      0, SCREEN_HEIGHT);

    if (box_collides(&game->ball.body, &game->player1.body) || box_collides(&game->ball.body, &game->player2.body))
        game->ball.body.vel_x_per_seconds *= -1.3;

    if (game->ball.body.x <= 0) {
        game->player2.score += 1;
        _reset_game_objs(game);
    }

    if (game->ball.body.x >= SCREEN_WIDTH) {
        game->player1.score += 1;
        _reset_game_objs(game);
    }
}

void _init_game_objs(Game* game) {
    game->player1.body.width  = 15;
    game->player1.body.height = 50;
    game->player1.body.x      = 20;
    game->player1.body.y      = (SCREEN_HEIGHT / 2) - (game->player1.body.height / 2);
    game->player1.score       = 0;

    game->player2.body.width  = 15;
    game->player2.body.height = 50;
    game->player2.body.x      = SCREEN_WIDTH - game->player2.body.width - 20;
    game->player2.body.y      = (SCREEN_HEIGHT / 2) - (game->player2.body.height / 2);
    game->player2.score       = 0;

    game->ball.body.width  = 15;
    game->ball.body.height = 15;
    game->ball.body.x      = (SCREEN_WIDTH  / 2) - (game->ball.body.width  / 2);
    game->ball.body.y      = (SCREEN_HEIGHT / 2) - (game->ball.body.height / 2);

    randomize_angle(&game->ball);

    fprintf(stdout, "Player 1: %d\nPlayer 2: %d\n\n", game->player1.score, game->player2.score);
}

void _reset_game_objs(Game* game) {
    game->player1.body.x = 20;
    game->player1.body.y = (SCREEN_HEIGHT / 2) - (game->player1.body.height / 2);

    game->player2.body.x = SCREEN_WIDTH - game->player2.body.width - 20;
    game->player2.body.y = (SCREEN_HEIGHT / 2) - (game->player2.body.height / 2);

    game->ball.body.x = (SCREEN_WIDTH  / 2) - (game->ball.body.width  / 2);
    game->ball.body.y = (SCREEN_HEIGHT / 2) - (game->ball.body.height / 2);

    randomize_angle(&game->ball);

    fprintf(stdout, "Player 1: %d\nPlayer 2: %d\n\n", game->player1.score, game->player2.score);

    SDL_Delay(1000);
}

void _process_inputs(Game* game) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        if (ev.type == SDL_QUIT)
            game->state = GAME_STATE_ENDED;

        if (ev.type == SDL_KEYDOWN) {
            switch (ev.key.keysym.sym) {
                case SDLK_w:
                    move_player_up(&game->player1);
                    break;

                case SDLK_s:
                    move_player_down(&game->player1);
                    break;

                case SDLK_UP:
                    move_player_up(&game->player2);
                    break;

                case SDLK_DOWN:
                    move_player_down(&game->player2);
                    break;
            }
        }

        if (ev.type == SDL_KEYUP) {
            switch (ev.key.keysym.sym) {
                case SDLK_w:
                case SDLK_s:
                    stop_player(&game->player1);
                    break;  

                case SDLK_UP:
                case SDLK_DOWN:
                    stop_player(&game->player2);
                    break;
            }
        }
    }
}