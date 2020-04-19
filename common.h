#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>

typedef int bool;
#define TRUE  1
#define FALSE 0

#include "./SwordOffer/BinaryTree.h"
#include "./SwordOffer/Stack.h"

#define LEN(arr) (sizeof(arr)/sizeof(arr[0])) // �����鳤��
#define PARAM_ERR(exitCode) {printf("Invalid Parameters\n");exit(exitCode);}
#define MALLOC_ERR(ptr) {if (NULL == (ptr)){printf("malloc error\n");exit(-1);}}

int RandomInRange(int start,int end); // ����start ~ end-1�������
void SwapInt(int *a,int *b); // ����2�����������ֵ
int dequals(double a,double b); // �ж�2���������Ƿ����


#endif // COMMON_H_INCLUDED
