
#include "snake.h"

static void	setDefault(t_snake *snake, int *pause, int *stop)
{
	snake->move = (t_pos){-1, 0, 0};
	snake->pointEated = 1;
	*pause = 0;
	*stop = 0;
	sdlInit(snake);
	setGrid(snake);
	setBody(snake);
	drawGrid(snake);
}

int		main(void)
{
	t_snake	*snake;
	int		stop;
	int		pause;

	if (!(snake = (t_snake*)malloc(sizeof(t_snake))))
		return (0);
	setDefault(snake, &pause, &stop);
	while (!stop)
	{
		while (SDL_PollEvent(&(snake->sdl.e)))
		{
			if (snake->sdl.e.type == SDL_QUIT ||
				snake->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				stop = 1;
			else if (snake->sdl.e.type == SDL_KEYUP)
			{
				if (snake->sdl.e.key.keysym.sym == SDLK_SPACE)
					pause = (pause == 1) ? 0 : 1;
				else if (snake->sdl.e.key.keysym.sym == SDLK_RIGHT)
					snake->move = (t_pos){1, 0, 0};
				else if (snake->sdl.e.key.keysym.sym == SDLK_LEFT)
					snake->move = (t_pos){-1, 0, 0};
				else if (snake->sdl.e.key.keysym.sym == SDLK_UP)
					snake->move = (t_pos){0, -1, 0};
				else if (snake->sdl.e.key.keysym.sym == SDLK_DOWN)
					snake->move = (t_pos){0, 1, 0};
			}
		}
		if (pause == 0)
		{
			snakeReDraw(snake);
			sdlRenderClear(snake);
			if (snake->grid[snake->body[0]->y][snake->body[0]->x] == 3)
				snake->pointEated = 1;
			setGrid(snake);
			drawGrid(snake);
			SDL_Delay(350);
		}
	}
	sdlDestroy(snake);
	return (1);
}
