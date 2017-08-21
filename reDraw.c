
#include "snake.h"

void		reDrawRight(t_snake *snake)
{
	int i;
 
	i = 0;
	while(snake->body[i])
		i++;
	snake->body[i] = (t_pos*)malloc(sizeof(t_pos));
	snake->body[i]->x = snake->body[i - 1]->x + 1 ;
	snake->body[i]->y = snake->body[i - 1]->y;
	if (snake->body[i]->x >= W || snake->body[i]->y >= H)
		exit (0);
	
	i = 0;

	free(snake->body[0]);
	i = 0;
	while(snake->body[i])
	{
		snake->body[i] = snake->body[i + 1];
		i++;
	}
}

void		reDrawLeft(t_snake *snake)
{
//	t_pos	*tmp;
	t_pos	*body0;
	int		i;

	int len = 0;
	while(snake->body[len])
		len++;
//	free(snake->body[i - 1]);
//	snake->body[i - 1] = NULL;
//	
//	

	body0 = (t_pos*)malloc(sizeof(t_pos));
	body0->x = snake->body[0]->x - 1 ;
	body0->y = snake->body[0]->y;

	i = 0;
	printf(">>\n");
	while(i < len)
	{
		printf("i=%d x=%d y=%d \n", i, snake->body[i]->x, snake->body[i]->y);
//		tmp = snake->body[i];
		snake->body[i + 1] = snake->body[i];
		i++;
	}
	printf("<<\n");
//	free(snake->body[0]);
	snake->body[0] = body0;
	snake->body[len] = NULL;

	
}
