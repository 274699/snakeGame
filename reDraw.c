
#include "snake.h"

void		reDrawRight(t_snake *snake)
{
	//-------->>>>>>>>>
	int i;
	int	len;

	len = 0;
	i = 0;

	while(snake->body[i])
		i++;
	snake->body[i] = (t_pos*)malloc(sizeof(t_pos));
	snake->body[i]->x = snake->body[i - 1]->x + 1 ;
	snake->body[i]->y = snake->body[i - 1]->y;
	if (snake->body[i]->x >= (W - 1) || snake->body[i]->y >= (H - 1))
		exit (0);
	
	free(snake->body[0]);
	while(len < i)
	{
		printf("%d %d\n", len, snake->body[len + 1]->head);
		snake->body[len] = snake->body[len + 1];
		snake->body[len]->head = 1;
		len++;
	}
	snake->body[i]->head = 2;
	snake->body[len] = NULL;

}

void		reDrawLeft(t_snake *snake)
{
	//--------<<<<<<<<<
	t_pos	*body0;

	int len = 0;
	while(snake->body[len])
		len++;

	body0 = (t_pos*)malloc(sizeof(t_pos));
	body0->x = snake->body[0]->x - 1 ;
	body0->y = snake->body[0]->y;
	body0->head = 2;

	if (snake->body[0]->x <= 1 || snake->body[0]->y <= 1)
		exit (0);
	len--;
	free(snake->body[len]);
	while(len >= 1)
	{
		snake->body[len] = snake->body[len - 1];
		snake->body[len]->head = 1;
		len--;
	}
	snake->body[0] = body0;
}

void		reDrawUp(t_snake *snake)
{
	t_pos	*body0;

//	^
//	^
//	^
	int len = 0;
	while(snake->body[len])
		len++;

	body0 = (t_pos*)malloc(sizeof(t_pos));
	body0->x = snake->body[0]->x;
	body0->y = snake->body[0]->y - 1;
	body0->head = 2;
	if (snake->body[0]->y <= 1)
		exit (0);
	len--;
	free(snake->body[len]);
	while(len)
	{
		snake->body[len] = snake->body[len - 1];
		snake->body[len]->head = 1;
		len--;
	}
	snake->body[0] = body0;
}

void		reDrawDown(t_snake *snake)
{
	t_pos	*body0;

	int len = 0;
	while(snake->body[len])
		len++;

	body0 = (t_pos*)malloc(sizeof(t_pos));
	body0->x = snake->body[0]->x;
	body0->y = snake->body[0]->y + 1;
	body0->head = 2;
	if (snake->body[0]->y >= (H - 1))
		exit (0);
	len--;
	free(snake->body[len]);
	while(len)
	{
		snake->body[len] = snake->body[len - 1];
		snake->body[len]->head = 1;
		len--;
	}
	snake->body[0] = body0;
}
