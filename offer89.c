#include "common.h"


#define N 64

typedef struct
{
  char data[N];
  char flag[N];
  int result[N];
  int row,col;
} offer89_matrix;

int offer89_Find_Matrix_Path(offer89_matrix *m,const char *str,int n,int i)
{
  if (str[n] == '\0')
  {
    m->result[n] = -1; // 负数表示结束
    return 0;
  }

  int r = i/m->col,c = i%m->col; // 得到行和列
  int tmp = r-1;
  int pos = tmp*m->col+c;
  if (tmp >= 0 && m->flag[pos] == 0 && m->data[pos] == str[n])// 向上查找
  {
    m->flag[pos] = 1; // 标记已找过
    m->result[n] = pos;
    if (0 == offer89_Find_Matrix_Path(m,str,n+1,pos))
      return 0;
  }
  tmp = r+1;
  pos = tmp*m->col+c;
  if (tmp < m->row && m->flag[pos] == 0 && m->data[pos] == str[n]) // 向下查找
  {
    m->flag[pos] = 1; // 标记已找过
    m->result[n] = pos;
    if (0 == offer89_Find_Matrix_Path(m,str,n+1,pos))
      return 0;
  }
  tmp = c-1;
  pos = r*m->col+tmp;
  if (tmp >= 0 && m->flag[pos] == 0 && m->data[pos] == str[n]) // 向左查找
  {
    m->flag[pos] = 1; // 标记已找过
    m->result[n] = pos;
    if (0 == offer89_Find_Matrix_Path(m,str,n+1,pos))
      return 0;
  }
  tmp = c+1;
  pos = r*m->col+tmp;
  if (tmp < m->col && m->flag[pos] == 0 && m->data[pos] == str[n]) // 向右查找
  {
    m->flag[pos] = 1; // 标记已找过
    m->result[n] = pos;
    if (0 == offer89_Find_Matrix_Path(m,str,n+1,pos))
      return 0;
  }
  return -1;
}

// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H
// 我没有用书上的方法,而是自己想出来的
// 思路和书上差不多吧
int offer89_Matrix_Path(offer89_matrix *m,const char *str)
{
  if (m == NULL || str == NULL || m->row < 1 || m->col < 1 || *str == '\0')
    PARAM_ERR(0);

  int i;
  for (i = 0; m->data[i] != '\0'; ++i)
  {
    if (m->data[i] == str[0]) // 第0个字符找到了
    {
      m->flag[i] = 1; // 标记已找过
      m->result[0] = i;
      if (0 == offer89_Find_Matrix_Path(m,str,1,i))
        return 0; // 找到了一条路
    }
  }
  return -1; // 找不到
}

// 机器人运动范围,属于回溯法
// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
int offer89_Moving_Count_Num(int num) // 返回数字个位之和
{
  int ret = 0;
  while (num>0)
  {
    ret += num%10;
    num /= 10;
  }
  return ret;
}

int offer89_Moving_Count_Check(int threshold,int row,int col,int r,int c,char *visited)
{
  if (r >= 0 && r < row && c >= 0 && c < col &&
      (offer89_Moving_Count_Num(r)+offer89_Moving_Count_Num(c)) <= threshold &&
      visited[r*col+c] == 0)
  {
    return 1;
  }
  return 0;
}

int offer89_Moving_Count_Core(int threshold,int row,int col,int r,int c,char *visited)
{
  int count=0;
  if (offer89_Moving_Count_Check(threshold,row,col,r,c,visited) == 1)
  {
    visited[r*col+c] = 1;
    count = 1 + offer89_Moving_Count_Core(threshold,row,col,r-1,c,visited) +
            offer89_Moving_Count_Core(threshold,row,col,r+1,c,visited) +
            offer89_Moving_Count_Core(threshold,row,col,r,c-1,visited) +
            offer89_Moving_Count_Core(threshold,row,col,r,c+1,visited);
  }
  return count;
}

// 传入阈值,行列值
int offer89_Moving_Count(int threshold,int row,int col)
{
  if (threshold < 0 || row <= 0 || col <= 0)
    PARAM_ERR(0);
  char *visited = (char *)malloc(sizeof(char) * row * col);
  MALLOC_ERR(visited);
  memset(visited,0,sizeof(char)*row*col);

  int count = offer89_Moving_Count_Core(threshold,row,col,0,0,visited);
  free(visited);
  return count;
}

void offer89(void)
{
  offer89_matrix m =
  {
    .row = 3,
    .col = 4,
    .data = "abtgcfcsjdeh"
  };
  memset(m.flag,0,N); // 清空标记
  char *str = "hsctbfca";
  offer89_Matrix_Path(&m,str);

  int i;
  for(i=0; m.result[i] >= 0; ++i) // 打印这些点的位置
  {
    printf("[%d,%d]\n",m.result[i]/m.col,m.result[i]%m.col);
  }

  // 机器人运动范围,属于回溯法
  int count = offer89_Moving_Count(10,1,100);
  printf("%d\n",count);
}
