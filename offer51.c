#include "common.h"

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����
// https://github.com/zhedahht/CodingInterviewChinese2/blob/master/05_ReplaceSpaces/ReplaceSpaces.cpp

// �÷�����β����ǰ������������
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
�и�������������A1��A2���ڴ���A1β�����㹻�Ŀռ�����A2
��A1��A2�ϲ������Ҳ���������顣
�ⷨҲ��ʹ��β������ķ���
*/
int *offer51_1(int *num1,int *num2,int n1,int n2)
{
    if (NULL != num1 && NULL != num2 && n1 > 0 && n2 > 0)
    {
        int end = n1-- + n2-- - 1; // �ϲ��������λ��
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
