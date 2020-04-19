#include "common.h"

// 该方法可避免n为负数,及最高位等于1的情况
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

// 该方法循环次数为1的个数
// 思想就是n和n-1的二进制只差最后一个1
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
n和n-1的二进制关系是n中的一个1变成0了
根据这个特性可以做很多事情
*/
void offer101(void)
{
	int n = 0xff1f4;
	printf("%d\n", offer101_count_1(n));
	printf("%d\n", offer101_count_2(n));

	/*
	一条语句判断一个整数是不是2的整数次方
	*/
	n = 65536;
	if ((n & (n-1)) == 0)
		printf("%d 是 2的整数次方\n", n);

	/*
	输入整数m和n,计算要改变m的二进制表示中的多少位才能得到n
	比如10的二进制表示为1010,13的二进制表示为1101,需要改变3位
	本题可以求这两个数的异或(相同变成0,不同变成1)，然后统计结果中1的个数
	*/
	n = 0xff;
	int m = 0x11;
	printf("%d => %d 需要改变%d位\n", n,m,offer101_count_2(n^m));
}
