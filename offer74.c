#include "common.h"

// 求斐波那契第n个数,循环
long long offer74_fibonacci0(unsigned n)
{
  if (n <= 1)
    return n;
  long long f0 = 0,f1 = 1, fn;
  while (--n)
  {
    fn = f0 + f1;
    f0 = f1;
    f1 = fn;
  }
  return fn;
}

// 求斐波那契第n个数,递归(n大了后会有很多重复运算,不推荐)
long long offer74_fibonacci1(unsigned n)
{
  return n <= 1 ? n : offer74_fibonacci1(n-1)+offer74_fibonacci1(n-2);
}

//-----------------------------------------------
// 矩阵乘方的计算方式
typedef struct Matrix2By2_t
{
  long long m00,m01,m10,m11;
} Matrix2By2;

// 初始化一个矩阵
Matrix2By2 *InitMatrix(long long m00,long long m01,long long m10,long long m11)
{
  Matrix2By2 *matrix = (Matrix2By2*)malloc(sizeof(Matrix2By2));
  if (NULL == matrix)
    exit(-1);

  matrix->m00 = m00;
  matrix->m01 = m01;
  matrix->m10 = m10;
  matrix->m11 = m11;
  return matrix;
}

// 2个矩阵相乘,释放内存时注意2个矩阵相同的情况
Matrix2By2 *MatrixMultiply(Matrix2By2 *matrix1,Matrix2By2 *matrix2)
{
  Matrix2By2 *tmp = (Matrix2By2*)malloc(sizeof(Matrix2By2));
  if (NULL == tmp)
    exit(-1);

  tmp->m00 = matrix1->m00 * matrix2->m00 + matrix1->m01 * matrix2->m10;
  tmp->m01 = matrix1->m00 * matrix2->m01 + matrix1->m01 * matrix2->m11;
  tmp->m10 = matrix1->m10 * matrix2->m00 + matrix1->m11 * matrix2->m10;
  tmp->m11 = matrix1->m10 * matrix2->m01 + matrix1->m11 * matrix2->m11;

  if (NULL != matrix1)
    free(matrix1);
  if (matrix1 != matrix2 && NULL != matrix2)
    free(matrix2);
  matrix1 = NULL;
  matrix2 = NULL;
  return tmp;
}

// 计算斐波那契结果
Matrix2By2 *MatrixPower(unsigned n)
{
  if (n <= 0)
    exit(-1);

  Matrix2By2 *matrix;
  if (n == 1)
  {
    matrix = InitMatrix(1,1,1,0);
  }
  else if (n%2 == 0)
  {
    matrix = MatrixPower(n/2);
    matrix = MatrixMultiply(matrix, matrix);
  }
  else if (n%2 == 1)
  {
    matrix = MatrixPower((n-1)/2);
    matrix = MatrixMultiply(matrix, matrix);
    matrix = MatrixMultiply(matrix, InitMatrix(1,1,1,0));
  }

  return matrix;
}

// 矩阵法计算
long long offer74_fibonacci2(unsigned n)
{
  if (n <= 1)
    return n;

  Matrix2By2 *tmp = MatrixPower(n - 1);
  long long r = tmp->m00;
  if (NULL != tmp)
    free(tmp);
  return r;
}

// 打印函数
void offer74_fibonacci_print(const char *topic, unsigned n, long long f(unsigned))
{
  printf("%s : ", topic);
  for (unsigned i = 0; i < n; ++i)
  {
    printf("%I64d,", f(i));
  }
  printf("\n");
}

void offer74(void)
{
  unsigned n = 20;

  offer74_fibonacci_print("fibonacci0", n, offer74_fibonacci0);
  offer74_fibonacci_print("fibonacci1", n, offer74_fibonacci1);
  offer74_fibonacci_print("fibonacci2", n, offer74_fibonacci2);
}
