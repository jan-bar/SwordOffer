#include "common.h"

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
// https://github.com/zhedahht/CodingInterviewChinese2/blob/master/05_ReplaceSpaces/ReplaceSpaces.cpp

// 该方法从尾部向前遍历填入数据
char *offer51_0(char *str,int n)
{
    if (NULL == str || n <= 0)
    {
        printf("input error\n");
        return NULL;
    }

    int i,len_str = 0,len_space = 0;
    for (i = 0; str[i] != '\0'; ++i)
    {
        len_str++;
        if (str[i] == ' ')
        {
            len_space++;
        }
    }

    int len_new = len_str + len_space*2;
    if (len_new > n)
    {
        printf("new string over length\n");
        return NULL;
    }

    for (; len_str >= 0 && len_new > len_str; --len_str)
    {
        if (str[len_str] == ' ')
        {
            str[len_new--] = '0';
            str[len_new--] = '2';
            str[len_new--] = '%';
        }
        else
        {
            str[len_new--] = str[len_str];
        }
    }
    return str;
}

/*
有个两个排序数组A1和A2，内存在A1尾部有足够的空间容纳A2
将A1和A2合并，结果也是排序数组。
解法也是使用尾部插入的方法
*/
int *offer51_1(int *num1,int *num2,int n1,int n2)
{
    if (NULL != num1 && NULL != num2 && n1 > 0 && n2 > 0)
    {
        int end = n1-- + n2-- - 1; // 合并后最后存放位置
        while (n1 >= 0 && n2 >= 0)
        {
            if (num1[n1] > num2[n2])
            {
                num1[end--] = num1[n1--];
            }
            else
            {
                num1[end--] = num2[n2--];
            }
        }
        return num1;
    }
    return NULL;
}

#define OFFER51_STR_MAX 64
void offer51(void)
{
    char str[OFFER51_STR_MAX] = "  We  are    happy   ";
    printf("%s\n", offer51_0(str, OFFER51_STR_MAX));

    strcpy(str, "Wearehappy");
    printf("%s\n", offer51_0(str, OFFER51_STR_MAX));

    strcpy(str, "");
    printf("%s\n", offer51_0(str, OFFER51_STR_MAX));

    strcpy(str, " ");
    printf("%s\n", offer51_0(str, OFFER51_STR_MAX));

    strcpy(str, "    ");
    printf("%s\n", offer51_0(str, OFFER51_STR_MAX));

    int num1[OFFER51_STR_MAX] = {1,4,5,7,10,11,14,18};
    int num2[] = {2,4,6,8,10,12,13,20};
    offer51_1(num1, num2, 8, LEN(num2));
    for (int i=0;num1[i] != 0;++i)
    {
        printf("%d,", num1[i]);
    }
    printf("\n");
}
