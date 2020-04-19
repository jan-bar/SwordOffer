#include "common.h"

// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
// ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
// ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
// ������ظ�������2����3��
// https://github.com/zhedahht/CodingInterviewChinese2/blob/master/03_02_DuplicationInArrayNoEdit/FindDuplicationNoEdit.cpp

// ͳ��num�д�s��e�����ָ���
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
���ֲ��ң��������ֶ����һ��һ�����ظ�����
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
