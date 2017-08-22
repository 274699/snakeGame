
#include "snake.h"

void	sdlInit(t_snake *snake)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	snake->sdl.window = SDL_CreateWindow("Snake", 300, 300, WID, HEIG,
			SDL_WINDOW_OPENGL);
	snake->sdl.renderer = SDL_CreateRenderer(snake->sdl.window, -1,
			SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(snake->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(snake->sdl.renderer);
}

void	sdlDestroy(t_snake *snake)
{
	SDL_DestroyRenderer(snake->sdl.renderer);
	SDL_DestroyWindow(snake->sdl.window);
	SDL_Quit();
}

void	sdlRenderClear(t_snake *snake)
{
	SDL_SetRenderDrawColor(snake->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(snake->sdl.renderer);
}
