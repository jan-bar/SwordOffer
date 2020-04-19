#include "common.h"

// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
int offer96_Max_Product_After_Cut1(int length)
{
  if (length < 2)
    return 0;
  if (length == 2)
    return 1;
  if (length == 3)
    return 2;

  int *products = (int *)malloc(sizeof(int) * (length+1));
  MALLOC_ERR(products);
  products[0] = 0;
  products[1] = 1;
  products[2] = 2;
  products[3] = 3;

  int i,j,max;
  for (i=4; i<=length; ++i)
  {
    max = 0;
    for (j=1; j<=i/2; ++j)
    {
      int product = products[j] * products[i-j];
      if (max < product)
        max = product;
    }
    products[i] = max;
  }
  max = products[length];
  free(products);
  return max;
}

// 贪婪算法,考虑length>=5时要尽可能剪出长度为3的绳子
// 由3*(length-3) >= 2*(length-2)得到
int offer96_Max_Product_After_Cut2(int length)
{
  if (length < 2)
    return 0;
  if (length == 2)
    return 1;
  if (length == 3)
    return 2;

  int timesOf3 = length/3; // 尽可能剪去长度为3的绳子
  // 当绳子最后剩下的长度为4的时候,不能再剪去长度为3的绳子
  // 此时更好的方法是将2个绳子剪成2×2
  if (length - timesOf3*3 == 1)
    timesOf3 -= 1;
  int timesOf2 = (length - timesOf3*3)/2;

  return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));
}

void offer96(void)
{
  int length = 25;
  int max = offer96_Max_Product_After_Cut1(length);
  printf("%d\n",max);

  max = offer96_Max_Product_After_Cut2(length);
  printf("%d\n",max);
}
