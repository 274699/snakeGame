
#include "snake.h"

void snakeReDraw(t_snake *snake)
{
	t_pos	*body0;
	int		len;

	body0 = (t_pos*)malloc(sizeof(t_pos));
	body0->x = snake->body[0]->x + snake->move.x;
	body0->y = snake->body[0]->y + snake->move.y;
	body0->head = 2;
	if (snake->body[0]->x <= 0 || snake->body[0]->x >= (W - 1) || snake->body[0]->y <= 0 || snake->body[0]->y >= (H - 1))
	{
		SDL_Delay(1000);
		sdlDestroy(snake);
		puts("U eat Border");
		exit (0);
	}
	if (snake->grid[body0->y][body0->x] == 1)
	{
		SDL_Delay(1000);
		sdlDestroy(snake);
		puts("U Eat Yourself");
		exit (0);
	}
	len = 0;
	while (snake->body[len])
		len++;
	if (snake->grid[body0->y][body0->x] != 3)
	{
		len--;
		free(snake->body[len]);
	}
	while (len > 0)
	{
		snake->body[len] = snake->body[len - 1];
		snake->body[len]->head = 1;
		len--;
	}
	snake->body[0] = body0;
}
