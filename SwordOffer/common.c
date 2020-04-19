#include "../common.h"


// 产生start ~ end-1的随机数
int RandomInRange(int start,int end)
{
  static int num = INT_MIN;
  if (num == INT_MIN)
  {
    // 确保重置随机数种子只会执行1次
    srand((unsigned int)time(NULL));
  }
  num = rand() % (end-start);
  return num + start;
}

// 交换2个传入参数的值
void SwapInt(int *a,int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

// 判断2个浮点数是否相等
int dequals(double a,double b)
{
  return fabs(a-b) < 0.000001;
}
