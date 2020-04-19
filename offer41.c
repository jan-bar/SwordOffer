#include "common.h"

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。
// https://github.com/zhedahht/CodingInterviewChinese2/blob/master/03_02_DuplicationInArrayNoEdit/FindDuplicationNoEdit.cpp

// 统计num中从s到e的数字个数
int offer41_count(int *num, int n,int s, int e)
{
    if (NULL == num)
    {
        return 0;
    }
    int c = 0;
    for(int i=0; i < n; ++i)
    {
        if (num[i]>=s && num[i]<=e)
        {
            c++;
        }
    }
    return c;
}

/*
二分查找，出现数字多的那一半一定有重复数字
*/
int offer41_0(int *num, int n)
{
    if (NULL == num || n < 2)
    {
        printf("input error\n");
        return -1;
    }
    int s = 1,e = n-1;
    while (s <= e)
    {
        int mid = (e-s)/2 + s;
        int c = offer41_count(num,n,s,mid);
        if (e == s)
        {
            if (c > 1)
            {
                printf("%d is dup\n", s);
                return s;
            }
            else
            {
                break;
            }
        }
        if (c > (mid-s+1))
        {
            e = mid;
        }
        else
        {
            s = mid+1;
        }
    }
    return -1;
}

void offer41(void)
{
    int num[] = {2,3,5,4,3,2,6,7};
    offer41_0(num, LEN(num));
}
