
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
	
//	snake->grid[10][8] = 3;

}

void		setBody(t_snake *snake)
{
	if (snake->body[0] == NULL)
	{
		snake->body[0] = (t_pos*)malloc(sizeof(t_pos));
		snake->body[0]->x = 12;
		snake->body[0]->y = 10;
		snake->body[0]->head = 2;

		
		snake->body[1] = (t_pos*)malloc(sizeof(t_pos));
		snake->body[1]->x = 13;
		snake->body[1]->y = 10;
		snake->body[1]->head = 1;
		
		snake->body[2] = (t_pos*)malloc(sizeof(t_pos));
		snake->body[2]->x = 14;
		snake->body[2]->y = 10;
		snake->body[2]->head = 1;
		
		snake->body[3] = (t_pos*)malloc(sizeof(t_pos));
		snake->body[3]->x = 14;
		snake->body[3]->y = 10;
		snake->body[3]->head = 1;
		
		snake->body[4] = NULL;
	}
}




void		drawGrid(t_snake *snake)
{
	int		i;
	int		j;
	SDL_Rect	rect;
	
	
	i = 0;
	while(snake->body[i] != NULL)
	{
		snake->grid[snake->body[i]->y][snake->body[i]->x] = snake->body[i]->head;
		i++;
	}

	
	if(snake->pointEated == 1)
	{
		snake->point.x = rand() % (W - 3) + 1;
		snake->point.y = rand() % (H - 3) + 1;
		if (snake->grid[snake->point.y][snake->point.x] == 1)
		{
			int zeros;
			zeros = 0;
				for(int i =0; i < H; i++)
				{
					for(int j =0; j < W; j++)
					{
						if (snake->grid[i][j] == 0)
						zeros++;
					}
					printf("\n");
				}
			if (zeros == 0)
			{
				puts("U WIN");
				exit (0);
			}
				
			
			while (snake->grid[snake->point.y][snake->point.x] == 1)
			{
				snake->point.x = rand() % (W - 3) + 1;
				snake->point.y = rand() % (H - 3) + 1;
			}
		}
			
		

		snake->grid[snake->point.y][snake->point.x] = 3;
		snake->pointEated = 0;
	}
	else
		snake->grid[snake->point.y][snake->point.x] = 3;
	

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
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
			}
			else if (snake->grid[j][i] == 2)
			{
				
				SDL_SetRenderDrawColor(snake->sdl.renderer, 20, 255, 0, 255);
				SDL_RenderFillRect(snake->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
			}
			else if (snake->grid[j][i] == 3)
			{
				
				SDL_SetRenderDrawColor(snake->sdl.renderer, 0, 0, 255, 255);
				SDL_RenderFillRect(snake->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(snake->sdl.renderer, 50, 50, 50, 255);
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
