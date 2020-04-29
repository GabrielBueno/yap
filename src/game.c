#include "game.h"

#include <SDL2/SDL.h>
#include "color.h"

const uint32_t SCREEN_WIDTH  = 800;
const uint32_t SCREEN_HEIGHT = 600;

const GameOperationResult GAME_SUCCESS           = 1;
const GameOperationResult GAME_SDL_INIT_ERROR    = -1;
const GameOperationResult GAME_SCREEN_INIT_ERROR = -2;

const GameState GAME_STATE_CREATED = 1;
const GameState GAME_STATE_RUNNING = 2;
const GameState GAME_STATE_PAUSED  = 3;
const GameState GAME_STATE_ENDED   = 4;

void _init_game_objs(Game* game);
void _update(Game* game);
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

        _update(game);
        _draw(game);
    }
}

void close_game(Game* game) {
    close_screen(&game->screen);

    SDL_Quit();
}

void _draw(Game* game) {
    initialize_drawing(&game->screen);

    Box* boxes[2];

    boxes[0] = &game->player1.body;
    boxes[1] = &game->player2.body;

    Color color;

    color.r = 0xff;
    color.g = 0xff;
    color.b = 0xff;
    color.a = 0xff;

    draw_boxes(&game->screen, boxes, 2, color);

    end_drawing(&game->screen);
}

void _update(Game* game) {

}

void _init_game_objs(Game* game) {
    game->player1.body.width  = 15;
    game->player1.body.height = 50;
    game->player1.body.x      = 20;
    game->player1.body.y      = (SCREEN_HEIGHT / 2) - (game->player1.body.height / 2);

    game->player2.body.width  = 15;
    game->player2.body.height = 50;
    game->player2.body.x      = SCREEN_WIDTH - game->player2.body.width - 20;
    game->player2.body.y      = (SCREEN_HEIGHT / 2) - (game->player2.body.height / 2);
}

void _process_inputs(Game* game) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        if (ev.type == SDL_QUIT)
            game->state = GAME_STATE_ENDED;
    }
}