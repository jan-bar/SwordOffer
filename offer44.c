#include "common.h"

// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
// ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
// ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
// ������ظ�������2����3��
//https://github.com/zhedahht/CodingInterviewChinese2/blob/master/03_02_DuplicationInArrayNoEdit/FindDuplicationNoEdit.cpp

/*
ע��ֻ�ܴ����½ǻ����Ͻǿ�ʼ
��Ϊ�жϴ�С���޷��޳���ǰ���л�����
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
