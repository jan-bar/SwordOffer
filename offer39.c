#include "common.h"

/*
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/03_01_DuplicationInArray/FindDuplication.cpp
������3��һ�����ҳ��������ظ�������
��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
��ô��Ӧ��������ظ�������2����3��
���ǵ�:
1.����Ϊn�������а���һ�������ظ�������
2.�����в������ظ�������
3.��Ч����(���ָ��,����Ϊn�������а���0~n-1֮�������)
*/

// ����:0=����,1=��������
int offer39_check(int *num, int n)
{
    if (NULL == num || n < 2)
    {
        return -1; // ��ʱһ���������ظ�����
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
���ɳ���Ϊn����ʱ����tmp
ɨ��һ��num���õ���ֵ��tmp��Ӧ�±��ֵ��1
�����tmpԪ��ֵ����1�ľ����ظ�����
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
����num,�±�i��num[i]����Ⱦͽ���num[i]��num[num[i]]
ֱ���ҵ�num[i]=num[num[i]]���ҵ�1���ظ�����
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
