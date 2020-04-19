#include "common.h"


// 这是我没看答案写出来的
void offer114_print_1(int n)
{
  char *number = (char *)malloc(sizeof(char) * (n+1));
  MALLOC_ERR(number);
  memset(number,'0',n);
  number[n] = 0; // 初始化字符串,并写结束符

  int i,flag = n-1; // flag表示最高位位置
  while (flag >= 0)
  {
    printf("%s,",number+flag);
    for (i=n-1 ; i>=0; i--)
    {
      number[i]++;
      if (number[i] > '9')
        number[i] = '0';
      else // 没有进位
        break;
    }
    if (i < flag)
      flag--; // 最高位有进位
  }
  free(number);
  printf("\n");
}

/*
返回-1表示输入异常
返回+/-表示正数负数
*/
char offer114_get_opt(char *num)
{
  int i;
  char opt = '+'; // 默认为正数
  if (num[0] == '-' || num[0] == '+')
  {
    opt = num[0]; // 保存符号
    for (i = 1; num[i] != 0; i++)
    {
      num[i-1] = num[i];
    }
    num[i-1] = 0; // 去除符号位
  }

  for (i = 0; num[i] != 0; i++)
  {
    if (num[i] > '9' || num[i] < '0')
      return -1; // 输入异常
  }
  return opt;
}

// 2个相同符号的数相加
void offer114_add_pos(char opt,char *a,char *b,char *c)
{
  int la = strlen(a) - 1;
  int lb = strlen(b) - 1;
  int lc = la > lb ? la : lb;
  lc++; // 预留符号位

  char bit = 0;
  for (; lc >= 0; lc--)
  {
    if (la >= 0)
      c[lc] += a[la--] - '0';
    if (lb >= 0)
      c[lc] += b[lb--] - '0';

    c[lc] += bit + '0';
    if (c[lc] > '9')
    {
      bit = 1;
      c[lc] -= 10; // 本位取个位数
    }
    else
      bit = 0;
  }

  if (c[0] != '0') // 有进位,后移1位
  {
    for (lc = strlen(c); lc > 0; lc--)
      c[lc] = c[lc-1];
  }
  c[0] = opt; // 填上符号
}

// 2个不同符号的数相加
// 绝对值大的 - 绝对值小的,符号看绝对值大的那个
int offer114_add_sub(char opt_a,char opt_b,char *a,char *b,char *c)
{
  int lmax = strlen(a) - 1;
  int lmin = strlen(b) - 1;
  char *max = a,*min = b,opt = opt_a;
  if (lmax < lmin || (lmax == lmin && strcmp(a,b) < 0))
  {
    max = b;
    min = a;
    opt = opt_b;
    lmax ^= lmin;
    lmin ^= lmax;
    lmax ^= lmin;
  }
  // a + b,大的数决定符号
  char bit = 0;
  for (; lmax >= 0; lmax--)
  {
    if (lmin >= 0)
      c[lmax] = max[lmax] - min[lmin--] - bit + '0';
    else
      c[lmax] = max[lmax] - bit;

    if (c[lmax] < '0')
    {
      bit = 1; // 向高位借位
      c[lmax] += 10; // 得到个位数
    }
    else
      bit = 0;
  }

  if (c[0] != '0') // 最高位被借位了
  {
    for (lmax = strlen(c); lmax > 0; lmax--)
      c[lmax] = c[lmax-1];
  }
  c[0] = opt; // 填上符号
  return 0;
}

/*
++,+-,-+,--
加法有上面四种情况
*/
int offer114_add(char *a,char *b,char *c)
{
	char *ta = (char *)malloc(sizeof(char) * (1+strlen(a)));
	MALLOC_ERR(ta);
	char *tb = (char *)malloc(sizeof(char) * (1+strlen(b)));
	MALLOC_ERR(tb);
	strcpy(ta,a);
	strcpy(tb,b); // 备份a,b,因为要修改数据
  char opt_a = offer114_get_opt(ta);
  char opt_b = offer114_get_opt(tb);
  if (opt_a < 0 || opt_b < 0)
    return -1; // 输入有误

  if (opt_a == opt_b)
    offer114_add_pos(opt_a,ta,tb,c);
  else
    offer114_add_sub(opt_a,opt_b,ta,tb,c);
	free(ta);
	free(tb);
  return 0;
}

void offer114(void)
{
  int n = 2;
  offer114_print_1(n);

#define N 32
  char a[N] = "34875658762354823564";
  char b[N] = "-445454452344";
  char c[N] = {0};

  n = offer114_add(a,b,c);
  if (n == 0)
    printf("%s + %s = %s\n",a,b,c);
	else
		printf("input error!\n");
}
