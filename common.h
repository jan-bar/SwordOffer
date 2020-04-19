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

#define LEN(arr) (sizeof(arr)/sizeof(arr[0])) // 求数组长度
#define PARAM_ERR(exitCode) {printf("Invalid Parameters\n");exit(exitCode);}
#define MALLOC_ERR(ptr) {if (NULL == (ptr)){printf("malloc error\n");exit(-1);}}

int RandomInRange(int start,int end); // 产生start ~ end-1的随机数
void SwapInt(int *a,int *b); // 交换2个传入参数的值
int dequals(double a,double b); // 判断2个浮点数是否相等


#endif // COMMON_H_INCLUDED
