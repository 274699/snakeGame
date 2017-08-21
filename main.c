
#include "snake.h"

int		main(void)
{
	t_snake	*snake;
	int		stop;

	stop = 0;
	if (!(snake = (t_snake*)malloc(sizeof(t_snake))))
		return (0);
	sdlInit(snake);
	setGrid(snake);
	setBody(snake);
	drawGrid(snake);
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
				{

					reDrawRight(snake);
					sdlRenderClear(snake);
					setGrid(snake);
					drawGrid(snake);
				}
				else if (snake->sdl.e.key.keysym.sym == SDLK_LEFT)
				{
					reDrawLeft(snake);
					sdlRenderClear(snake);
					setGrid(snake);
					drawGrid(snake);
				}
			}
		}
		
//		sdlRender(snake);
	}
	sdlDestroy(snake);
	return (1);
}
