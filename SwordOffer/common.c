#include "../common.h"


// ����start ~ end-1�������
int RandomInRange(int start,int end)
{
  static int num = INT_MIN;
  if (num == INT_MIN)
  {
    // ȷ���������������ֻ��ִ��1��
    srand((unsigned int)time(NULL));
  }
  num = rand() % (end-start);
  return num + start;
}

// ����2�����������ֵ
void SwapInt(int *a,int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

// �ж�2���������Ƿ����
int dequals(double a,double b)
{
  return fabs(a-b) < 0.000001;
}
