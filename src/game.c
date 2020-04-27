#include "game.h"

#include <SDL2/SDL.h>

const GameOperationResult GAME_SUCCESS           = 1;
const GameOperationResult GAME_SDL_INIT_ERROR    = -1;
const GameOperationResult GAME_SCREEN_INIT_ERROR = -2;

const GameState GAME_STATE_CREATED = 1;
const GameState GAME_STATE_RUNNING = 2;
const GameState GAME_STATE_PAUSED  = 3;
const GameState GAME_STATE_ENDED   = 4;

void _draw(Game* game);
void _update(Game* game);
void _process_inputs(Game* game);

GameOperationResult init_game(Game* out_game) {
    if (SDL_Init(0) < 0)
        return GAME_SDL_INIT_ERROR;

    if (init_screen("yap", 800, 600, &out_game->screen) < 0)
        return GAME_SCREEN_INIT_ERROR;

    out_game->state     = GAME_STATE_CREATED;
    out_game->last_tick = SDL_GetTicks();

    return GAME_SUCCESS;
}

void run_game(Game* game) {
    game->state = GAME_STATE_RUNNING;

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

}

void _update(Game* game) {

}

void _process_inputs(Game* game) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        if (ev.type == SDL_QUIT)
            game->state = GAME_STATE_ENDED;
    }
}