
#include "snake.h"

int		main(void)
{
	t_snake	*snake;

	if (!(snake = (t_snake*)malloc(sizeof(t_snake))))
		return (0);
	sdlInit(snake);
	setGrid(snake);
	drawGrid(snake);
	while (1)
	{
		while (SDL_PollEvent(&(snake->sdl.e)))
			if (snake->sdl.e.type == SDL_QUIT || snake->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				return (0);
		drawGrid(snake);
//		sdlRender(snake);
	}
	sdlDestroy(snake);
	return (1);
}
