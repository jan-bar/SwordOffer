#include "common.h"

/*
			{a^(n/2) * a^(n/2)              n为偶数
a^n = |
			{a^((n-1)/2) * a^((n-1)/2) * a  n为奇数
exp>>1 : 表示 [exp/2],位移比除法更快
exp & 0x1 == 1 : 二进制0位为1表示奇数,为0表示偶数
本方法使用递归来求解(指数为正整数才行),保证乘法次数最少
*/
double offer110_PowerWithUnsignedExponent(double base,unsigned int exp)
{
  if (exp == 0)
    return 1;
  if (exp == 1)
    return base;
  double result = offer110_PowerWithUnsignedExponent(base,exp>>1);
  result *= result;
  if ((exp & 0x1) == 1)
    result *= base;
  return result;
}

/*
(base^exp)
需要考虑exp<0,exp=0,exp=1,exp>0
还需要考虑base=0 & exp<0时会出现对0求倒数,属于异常

当exp<0时,先求(-exp)次方再将结果求倒数
*/
int offer110_invalidInput = 0;
double offer110_power_func(double base,int exp)
{
  if (dequals(base, 0.0) && exp < 0)
  {
    offer110_invalidInput = 1;
    return 0.0;
  }

  unsigned int absExp = (unsigned int)exp;
  if (exp < 0)
    absExp = (unsigned int)(-exp);

  double result = offer110_PowerWithUnsignedExponent(base, absExp);
  if (exp < 0)
    result = 1.0/result;
  return result;
}

void offer110(void)
{
  double b = 2;
  int e = 10;

  double result = offer110_power_func(b,e);
  if (offer110_invalidInput == 1)
  {
    // 根据全局变量判断参数错误
    printf("invalidInput\n");
    return;
  }
  printf("%lf^%d = %lf\n",b,e,result);
}
