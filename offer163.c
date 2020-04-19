#include "common.h"


void PrintMatrixInCircle(int *num,int columns,int rows,int start)
{
	int endX = columns-1-start;
	int endY = rows-1-start;
	int i;
	for (i=start;i<=endX;++i)
	{
		printf("%d,",num[start*columns+i]);
	}
	if (start < endY)
	{
		for (i=start+1;i<=endY;++i)
		{
			printf("%d,",num[i*columns+endX]);
		}
	}
	if (start < endX && start < endY)
	{
		for (i=endX-1;i>=start;--i)
		{
			printf("%d,",num[endY*columns+i]);
		}
	}
	if (start < endX && start < endY-1)
	{
		for (i=endY-1;i>=start+1;--i)
		{
			printf("%d,",num[endY*columns+i]);
		}
	}
}

void PrintMatrixClovkwisely(int *num,int columns,int rows)
{
	if (num == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while (columns > start*2 && rows > start*2)
	{
		PrintMatrixInCircle(num,columns,rows,start);
		++start;
	}
}

void offer163()
{
	int num[] = {
		1,2,3,4,
		5,6,7,8,
		9,10,11,12,
		13,14,15,16,
	};
	PrintMatrixClovkwisely(num,4,4);
}
