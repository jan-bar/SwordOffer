#include "common.h"

/*
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/03_01_DuplicationInArray/FindDuplication.cpp
面试题3（一）：找出数组中重复的数字
题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
那么对应的输出是重复的数字2或者3。
考虑点:
1.长度为n的数组中包含一个或多个重复的数字
2.数组中不包含重复的数字
3.无效输入(如空指针,长度为n的数组中包含0~n-1之外的数字)
*/

// 返回:0=正常,1=参数错误
int offer39_check(int *num, int n)
{
    if (NULL == num || n < 2)
    {
        return -1; // 此时一定不存在重复数字
    }
    for (int i = 0; i < n; ++i)
    {
        if (num[i] < 0 || num[i] >= n)
        {
            return -1;
        }
    }
    return 0;
}

/*
生成长度为n的临时数组tmp
扫描一次num，得到的值在tmp对应下标的值加1
最后检查tmp元素值大于1的就是重复数字
*/
int offer39_0(int *num,int n)
{
    if (offer39_check(num, n) != 0)
    {
        printf("input error!\n");
        return -1;
    }

    int *tmp = (int*)malloc(n*sizeof(int));
    if (NULL == tmp)
    {
        return -1;
    }
    memset(tmp, 0, n*sizeof(int));

    for (int i=0; i<n; ++i)
    {
        tmp[ num[i] ]++;
    }

    printf("offer39_0 is dup:");
    for (int i=0; i<n; ++i)
    {
        if (tmp[i] > 1)
        {
            printf("%d,",i);
        }
    }
    printf("\n");
    return 0;
}

/*
遍历num,下标i和num[i]不相等就交换num[i]和num[num[i]]
直到找到num[i]=num[num[i]]及找到1个重复数字
*/
int offer39_1(int *num,int n)
{
    if (offer39_check(num, n) != 0)
    {
        printf("input error!\n");
        return -1;
    }

    printf("offer39_1 is dup:");
    for (int i=0; i<n; ++i)
    {
        while (i != num[i])
        {
            if (num[i] == num[num[i]])
            {
                printf("%d,", num[i]);
                break;
            }
            int t  = num[i];
            num[i] = num[t];
            num[t] = t;
        }
    }
    printf("\n");
    return 0;
}

void offer39(void)
{
    int num[] = {2,3,4,0,2,5,3};
    int n = LEN(num);
    offer39_0(num, n);
    offer39_1(num, n);

    offer39_0(NULL, n);
    offer39_1(num, 0);

    int num1[] = {2,3,1,0,2,10,5,3};
    offer39_0(num1, 8);
}
