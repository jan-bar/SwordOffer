#include "common.h"

// ������14��������
// ��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
// ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
// ���Ƕ��٣����統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
// ʱ�õ����ĳ˻�18��
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

// ̰���㷨,����length>=5ʱҪ�����ܼ�������Ϊ3������
// ��3*(length-3) >= 2*(length-2)�õ�
int offer96_Max_Product_After_Cut2(int length)
{
  if (length < 2)
    return 0;
  if (length == 2)
    return 1;
  if (length == 3)
    return 2;

  int timesOf3 = length/3; // �����ܼ�ȥ����Ϊ3������
  // ���������ʣ�µĳ���Ϊ4��ʱ��,�����ټ�ȥ����Ϊ3������
  // ��ʱ���õķ����ǽ�2�����Ӽ���2��2
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
