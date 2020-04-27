#include "screen.h"

// Const definitions
const ScreenOperationResult RENDERER_CREATION_ERROR    = -3;
const ScreenOperationResult WINDOW_CREATION_ERROR      = -2;
const ScreenOperationResult VIDEO_INITIALIZATION_ERROR = -1;
const ScreenOperationResult SCREEN_SUCCESS             = 1;

ScreenOperationResult init_screen(const char* title, uint16_t width, uint16_t height, Screen* out_screen) {
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
        return VIDEO_INITIALIZATION_ERROR;

    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    if (window == NULL)
        return WINDOW_CREATION_ERROR;

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
        return RENDERER_CREATION_ERROR;

    out_screen->width    = width;
    out_screen->height   = height;
    out_screen->window   = window;
    out_screen->renderer = renderer;

    return SCREEN_SUCCESS;
}

ScreenOperationResult close_screen(const Screen* const screen) {
    SDL_DestroyRenderer(screen->renderer);
    SDL_DestroyWindow(screen->window);

    return SCREEN_SUCCESS;
}

