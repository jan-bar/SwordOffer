#include "common.h"

/*
			{a^(n/2) * a^(n/2)              nΪż��
a^n = |
			{a^((n-1)/2) * a^((n-1)/2) * a  nΪ����
exp>>1 : ��ʾ [exp/2],λ�Ʊȳ�������
exp & 0x1 == 1 : ������0λΪ1��ʾ����,Ϊ0��ʾż��
������ʹ�õݹ������(ָ��Ϊ����������),��֤�˷���������
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
��Ҫ����exp<0,exp=0,exp=1,exp>0
����Ҫ����base=0 & exp<0ʱ����ֶ�0����,�����쳣

��exp<0ʱ,����(-exp)�η��ٽ��������
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
    // ����ȫ�ֱ����жϲ�������
    printf("invalidInput\n");
    return;
  }
  printf("%lf^%d = %lf\n",b,e,result);
}
