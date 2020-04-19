#include "common.h"

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。
//https://github.com/zhedahht/CodingInterviewChinese2/blob/master/03_02_DuplicationInArrayNoEdit/FindDuplicationNoEdit.cpp

/*
注意只能从左下角或右上角开始
因为判断大小后无法剔除当前的行或者列
*/
int offer44_0(int *num,int row,int col,int x)
{
    if (NULL != num && row > 0 &&col >0)
    {
        int i = row-1,j = 0,t;
        while (i>=0 && j < col)
        {
            t = *(num + i*col + j);
            if (x == t)
            {
                printf("row:%d,col:%d\n", i+1, j+1);
                return 0;
            }
            else if (x > t)
            {
                j++;
            }
            else
            {
                i--;
            }
        }
    }
    return -1;
}

void offer44(void)
{
    int num[] =
    {
        1,2,8,9,
        2,4,9,12,
        4,7,10,13,
        6,8,11,15
    };
    offer44_0(num,4,4,7);
    offer44_0(num,4,4,1);
    offer44_0(num,4,4,15);
    offer44_0(num,4,4,16);
    offer44_0(num,4,4,5);
}
