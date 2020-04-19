#include "common.h"


bool isPopOrder(const int *push,const int *pop,int length)
{
	if (push == NULL || pop == NULL || length <= 0)
		return FALSE;
	Stack *s = NULL;
	int pop_i = 0;
	for (pop_i=0;pop_i<length;++pop_i)
	{
		if (Stack_Empty(s) && )
	}
}

void offer169()
{
	int push[] = {1,2,3,4,5};
	int pop[] = {4,5,3,2,1};
	if (isPopOrder(push,pop,LEN(push)))
		printf("ok\n");
}
