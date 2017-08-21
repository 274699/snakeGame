
#include "snake.h"

void		drawGrid(t_snake *snake)
{
	int		i;
	int		j;
	SDL_Rect	rect;
	
	rect = (SDL_Rect) {0, 0, 20, 20};
	
//	SDL_SetRenderDrawColor(snake->sdl.renderer, 255, 255, 255, 255);
//	SDL_RenderDrawRect(snake->sdl.renderer, &rect);
//	SDL_RenderFillRect(snake->sdl.renderer, &rect);

	
	i = 0;
	while (i < WID)
	{
		j = 0;
		rect.x = 0;
		while (j < HEIG)
		{
			SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
			SDL_RenderDrawRect(snake->sdl.renderer, &rect);
			rect.x += 20;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
			j++;
		}
		rect.y += 20;
		i++;
	}
	
	SDL_RenderPresent(snake->sdl.renderer);
}

int		main(void)
{
	t_snake	*snake;

	if (!(snake = (t_snake*)malloc(sizeof(t_snake))))
		return (0);
	sdlInit(snake);
	drawGrid(snake);
	while (1)
	{
		while (SDL_PollEvent(&(snake->sdl.e)))
			if (snake->sdl.e.type == SDL_QUIT || snake->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				return (0);
//		sdlRender(snake);
	}
	sdlDestroy(snake);
	return (1);
}
