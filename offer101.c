#include "common.h"

// �÷����ɱ���nΪ����,�����λ����1�����
int offer101_count_1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

// �÷���ѭ������Ϊ1�ĸ���
// ˼�����n��n-1�Ķ�����ֻ�����һ��1
int offer101_count_2(int n)
{
	int count = 0;
	while (n)
	{
		n &= (n-1);
		count++;
	}
	return count;
}

/*
n��n-1�Ķ����ƹ�ϵ��n�е�һ��1���0��
����������Կ������ܶ�����
*/
void offer101(void)
{
	int n = 0xff1f4;
	printf("%d\n", offer101_count_1(n));
	printf("%d\n", offer101_count_2(n));

	/*
	һ������ж�һ�������ǲ���2�������η�
	*/
	n = 65536;
	if ((n & (n-1)) == 0)
		printf("%d �� 2�������η�\n", n);

	/*
	��������m��n,����Ҫ�ı�m�Ķ����Ʊ�ʾ�еĶ���λ���ܵõ�n
	����10�Ķ����Ʊ�ʾΪ1010,13�Ķ����Ʊ�ʾΪ1101,��Ҫ�ı�3λ
	����������������������(��ͬ���0,��ͬ���1)��Ȼ��ͳ�ƽ����1�ĸ���
	*/
	n = 0xff;
	int m = 0x11;
	printf("%d => %d ��Ҫ�ı�%dλ\n", n,m,offer101_count_2(n^m));
}
