#include "common.h"


// 选择一个数字,比该数字小的移动到左边,大的移动到右边
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

// 快速排序
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

// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
int offer82_min_number(int *data, int length)
{
  if (data == NULL || length <= 0)
    PARAM_ERR(0);

  int start = 0,end = length-1;
  int mid = start;
  // 如果第一个小于最后一个,则第一个直接就是最小
  while (data[start] >= data[end])
  {
    if (end-start==1)
    {
      mid = end;
      break;
    }
    mid = (end+start)/2;

    // 当前后和中间都相等则说明需要顺序查找
    if (data[start] == data[end] && data[start] >= data[mid])
    {
      mid = data[start]; // 从start开始到end结束
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
  offer82_QuickSort_test(); // 测试快速排序

  int num[] = {8,9,10,11,1,2,3,4,5,6,7};
  int min_pos = offer82_min_number(num, LEN(num));
  printf("offer82_min_number:%d,%d\n",min_pos,num[min_pos]);
}
