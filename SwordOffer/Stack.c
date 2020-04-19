#include "../common.h"

int Stack_Pop(Stack **s)
{
	if (*s == NULL)
		return FALSE;
	Stack *tmp = *s;
	int top = tmp->data;
	*s = (*s)->next;
	free(tmp);
	return top;
}

int Stack_Push(Stack **s,int val)
{
	Stack *tmp = (Stack*)malloc(sizeof(Stack));
	MALLOC_ERR(tmp);
	tmp->data = val;
	tmp->next = *s;
	*s = tmp;
	return val;
}

bool Stack_Empty(Stack *s)
{
	return s == NULL;
}

int Stack_Top(Stack *s)
{
	if (s == NULL)
		return FALSE;
	return s->data;
}

void Stack_Print(Stack *s)
{
	while (s != NULL)
	{
		printf("%d,", s->data);
		s = s->next;
	}
	printf("\n");
}
