
#include "snake.h"

static void	setRandPoint(t_snake *snake)
{
	int	validPlaces;
	int i;
	int j;

	if (snake->pointEated == 1)
	{
		snake->point = (t_pos){rand() % (W - 3) + 1, rand() % (H - 3) + 1, 0};
		if (snake->grid[snake->point.y][snake->point.x] == 1)
		{
			validPlaces = 0;
			for (i = 1; i < (H - 1); i++)
			{
				for (j = 1; j < (W - 1); j++)
				{
					if (snake->grid[i][j] == 0)
						validPlaces++;
				}
			}
			if (validPlaces == 0)
			{
				puts("U WIN");
				exit(0);
			}
			while (snake->grid[snake->point.y][snake->point.x] == 1)
				snake->point = (t_pos){rand() % (W - 3) + 1, rand() % (H - 3) + 1, 0};
		}
		snake->grid[snake->point.y][snake->point.x] = 3;
		snake->pointEated = 0;
	}
	else
		snake->grid[snake->point.y][snake->point.x] = 3;
}

void		drawGrid(t_snake *snake)
{
	SDL_Rect	rect;
	int			x;
	int			y;
	int			i;

	//set body of snake on map
	for (i = 0; snake->body[i] != NULL; i++)
		snake->grid[snake->body[i]->y][snake->body[i]->x] = snake->body[i]->head;

	//set a random point on map
	setRandPoint(snake);
	
	//draw map with snake, borders and rand point
	rect = (SDL_Rect) {0, 0, 20, 20};
	for (y = 0; y < H; y++)
	{
		rect.x = 0;
		for (x = 0; x < W; x++)
		{
			if (snake->grid[y][x] == 0)
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
			else if (snake->grid[y][x] == -1)
			{
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderFillRect(snake->sdl.renderer, &rect);
			}
			else if (snake->grid[y][x] == 1)
			{
				SDL_SetRenderDrawColor(snake->sdl.renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(snake->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
			}
			else if (snake->grid[y][x] == 2)
			{
				SDL_SetRenderDrawColor(snake->sdl.renderer, 20, 255, 0, 255);
				SDL_RenderFillRect(snake->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
			}
			else if (snake->grid[y][x] == 3)
			{
				SDL_SetRenderDrawColor(snake->sdl.renderer, 0, 0, 255, 255);
				SDL_RenderFillRect(snake->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
			}
			SDL_RenderDrawRect(snake->sdl.renderer, &rect);
			rect.x += 20;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
		rect.y += 20;
	}
	SDL_RenderPresent(snake->sdl.renderer);
}
