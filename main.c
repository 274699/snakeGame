
#include "snake.h"

int		main(void)
{
	t_snake	*snake;
	int		stop;

	
	stop = 0;
	if (!(snake = (t_snake*)malloc(sizeof(t_snake))))
		return (0);
	snake->pointEated = 1;
	sdlInit(snake);
	setGrid(snake);
	setBody(snake);
	drawGrid(snake);
	//-- move left by default
	snake->move = (t_pos){-1, 0, 0};
	while (!stop)
	{
		while (SDL_PollEvent(&(snake->sdl.e)))
		{
			if (snake->sdl.e.type == SDL_QUIT || snake->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				stop = 1;
			else if (snake->sdl.e.type == SDL_KEYUP)
			{
				if (snake->sdl.e.key.keysym.sym == SDLK_SPACE)
				{
					sdlRenderClear(snake);
					setGrid(snake);
					drawGrid(snake);
				}
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

		
		reDraw(snake);
		sdlRenderClear(snake);
		if (snake->grid[snake->body[0]->y][snake->body[0]->x] == 3)
			snake->pointEated = 1;
		setGrid(snake);
		drawGrid(snake);
		SDL_Delay(350);
//		sdlRender(snake);
	}
	sdlDestroy(snake);
	return (1);
}
