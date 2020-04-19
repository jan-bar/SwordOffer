#include "common.h"


// ѡ��һ������,�ȸ�����С���ƶ������,����ƶ����ұ�
int offer82_Partition(int *data,int length,int start,int end)
{
  if (data == NULL || length <= 0 || start < 0 || end >= length)
    PARAM_ERR(0);

  int index = RandomInRange(start,end);
  SwapInt(&data[index], &data[end]);

  int small = start-1;
  for (index=start; index<end; index++)
  {
    if (data[index]<data[end])
    {
      ++small;
      if (small!=index)
      {
        SwapInt(&data[index], &data[small]);
      }
    }
  }
  ++small;
  SwapInt(&data[small], &data[end]);
  return small;
}

// ��������
void offer82_QuickSort(int *data,int length,int start,int end)
{
  if (start==end)
    return;
  int index = offer82_Partition(data,length,start,end);
  if (index>start)
    offer82_QuickSort(data,length,start,index-1);
  if (index<end)
    offer82_QuickSort(data,length,index+1,end);
}

void offer82_QuickSort_test()
{
#define N 40
  int i,num[N];
  for (i=0; i<N; ++i)
  {
    num[i] = RandomInRange(1,100);
    printf("%d,",num[i]);
  }
  printf("\n");

  offer82_QuickSort(num,N,0,N-1);

  for (i=0; i<N; ++i)
  {
    printf("%d,",num[i]);
  }
  printf("\n");
}

// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء���������
// {3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��
int offer82_min_number(int *data, int length)
{
  if (data == NULL || length <= 0)
    PARAM_ERR(0);

  int start = 0,end = length-1;
  int mid = start;
  // �����һ��С�����һ��,���һ��ֱ�Ӿ�����С
  while (data[start] >= data[end])
  {
    if (end-start==1)
    {
      mid = end;
      break;
    }
    mid = (end+start)/2;

    // ��ǰ����м䶼�����˵����Ҫ˳�����
    if (data[start] == data[end] && data[start] >= data[mid])
    {
      mid = data[start]; // ��start��ʼ��end����
      for (++start; start<=end; ++start)
        if (data[start] < mid)
          mid = start;
      return mid;
    }

    if (data[mid] >= data[start])
    {
      start = mid;
    }
    else if (data[mid] <= data[end])
    {
      end = mid;
    }
  }
  return mid;
}

void offer82(void)
{
  offer82_QuickSort_test(); // ���Կ�������

  int num[] = {8,9,10,11,1,2,3,4,5,6,7};
  int min_pos = offer82_min_number(num, LEN(num));
  printf("offer82_min_number:%d,%d\n",min_pos,num[min_pos]);
}
