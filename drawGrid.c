
#include "snake.h"

void		setGrid(t_snake *snake)
{
	int		i;

	memset(snake->grid, 0, sizeof(snake->grid[0][0]) * W * (H - 1));
	memset(snake->grid[0], -1, sizeof(snake->grid[0][0]) * W);
	memset(snake->grid[H - 1], -1, sizeof(snake->grid[0][0]) * W);
	i = 0;
	while (i < H)
	{
		snake->grid[i][0] = -1;
		snake->grid[i][W - 1] = -1;
		i++;
	}
	
	snake->grid[rand() % H][rand() % W] = 1;
}

void		drawGrid(t_snake *snake)
{
	int		i;
	int		j;
	SDL_Rect	rect;

	rect = (SDL_Rect) {0, 0, 20, 20};
	j = 0;
	while (j < H)
	{
		i = 0;
		rect.x = 0;
		while (i < W)
		{
			if (snake->grid[j][i] == 0)
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
			else if (snake->grid[j][i] == -1)
			{
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderFillRect(snake->sdl.renderer, &rect);
			}
			else if (snake->grid[j][i] == 1)
			{
				SDL_SetRenderDrawColor(snake->sdl.renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(snake->sdl.renderer, &rect);
			}
			SDL_RenderDrawRect(snake->sdl.renderer, &rect);
			rect.x += 20;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
			i++;
		}
		rect.y += 20;
		j++;
	}
	SDL_RenderPresent(snake->sdl.renderer);
}
