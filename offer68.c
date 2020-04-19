#include "common.h"

// 栈结构
typedef struct offer68_stack_t
{
  int data;
  struct offer68_stack_t *next;
} offer68_stack;
// 压栈
int offer68_stack_push(offer68_stack **stack, int val)
{
  offer68_stack *tmp = (offer68_stack*)malloc(sizeof(offer68_stack));
  if (tmp == NULL)
    exit(-1);
  tmp->data = val;
  tmp->next = *stack;
  *stack = tmp;
  return val;
}
// 弹栈
int offer68_stack_pop(offer68_stack **stack)
{
  if (*stack == NULL)
    return -1;
  offer68_stack *p = *stack;
  int val = p->data;
  (*stack) = (*stack)->next;
  free(p);
  p = NULL;
  return val;
}
// 2个栈模拟队列
typedef struct offer68_stack_queue_t
{
  offer68_stack *stack1, *stack2;
} offer68_stack_queue;
// 从队尾入队
int offer68_stack_append_tail(offer68_stack_queue **queue, int val)
{
  if (*queue == NULL)
  {
    *queue = (offer68_stack_queue*)malloc(sizeof(offer68_stack_queue));
    if (*queue == NULL)
      exit(-1);
    (*queue)->stack1 = NULL;
    (*queue)->stack2 = NULL;
  }
  return offer68_stack_push(&((*queue)->stack1), val);
}
/* 出队
栈2为空,则将栈1全部弹栈并入栈到栈2
否则栈2弹栈一个元素就行
*/
int offer68_stack_delete_head(offer68_stack_queue **queue)
{
  if ((*queue)->stack2 == NULL)
  {
    while ((*queue)->stack1 != NULL)
    {
      offer68_stack_push(&((*queue)->stack2), offer68_stack_pop(&((*queue)->stack1)));
    }
  }
  return offer68_stack_pop(&((*queue)->stack2));
}

//------------------------------------------------------------------------------

// 队列结构
typedef struct offer68_queue_t
{
  offer68_stack *head, *tail;
} offer68_queue;
// 入队
int offer68_en_queue(offer68_queue **queue, int val)
{
  if (*queue == NULL)
  {
    // 队列初始化
    *queue = (offer68_queue*)malloc(sizeof(offer68_queue));
    if (*queue == NULL)
      exit(-1);
    (*queue)->head = NULL;
    (*queue)->tail = NULL;
  }

  // 入队时申请一个元素
  offer68_stack *tmp = (offer68_stack*)malloc(sizeof(offer68_stack));
  if (tmp == NULL)
    exit(-1);
  tmp->data = val;
  tmp->next = NULL;

  if ((*queue)->head == NULL)
    (*queue)->head = tmp; // 队列为空时队首指向元素

  if ((*queue)->tail != NULL)
    (*queue)->tail->next = tmp; // 队尾不为空时连接该元素
  (*queue)->tail = tmp; // 队尾指向新的尾元素
  return val;
}
// 出队
int offer68_de_queue(offer68_queue *queue)
{
  if (queue->head == NULL)
    return -1; // 队列为空
  offer68_stack *p = queue->head;
  int val = p->data;
  queue->head = queue->head->next;
  if (queue->head == NULL)
    queue->tail = NULL; // 队列为空,队尾也要置为空
  free(p);
  p = NULL;
  return val;
}
// 打印队列
void offer68_queue_print(const char *topic, offer68_queue *queue)
{
  printf("%s:", topic);
  if (queue != NULL && queue->head != NULL)
  {
    offer68_stack *p = queue->head;
    while (p != NULL)
    {
      printf("%d,", p->data);
      p = p->next;
    }
  }
  printf("\n");
}
// 2个队列模拟栈
typedef struct offer68_queue_stack_t
{
  offer68_queue *queue1, *queue2;
} offer68_queue_stack;
/* 压栈
如果queue2不为空则压栈的元素都入队queue2
否则全都入队queue1
*/
int offer68_queue_push(offer68_queue_stack **stack, int val)
{
  if (*stack == NULL)
  {
    *stack = (offer68_queue_stack*)malloc(sizeof(offer68_queue_stack));
    if (*stack == NULL)
      exit(-1);
    (*stack)->queue1 = NULL;
    (*stack)->queue2 = NULL;
  }
  if ((*stack)->queue2 != NULL && (*stack)->queue2->head !=NULL)
  {
    return offer68_en_queue(&((*stack)->queue2), val);
  }
  return offer68_en_queue(&((*stack)->queue1), val);
}
/* 弹栈
如果queue2不为空则出队queue2,数据入队queue1,queue2的最后一个元素作为栈顶返回
否则出队queue1,数据入队queue2,queue1的最后一个元素作为栈顶返回
*/
int offer68_queue_pop(offer68_queue_stack **stack)
{
  if ((*stack)->queue2 != NULL && (*stack)->queue2->head !=NULL)
  {
    while ((*stack)->queue2->head->next != NULL)
    {
      offer68_en_queue(&((*stack)->queue1), offer68_de_queue((*stack)->queue2));
    }
    return offer68_de_queue((*stack)->queue2);
  }

  while ((*stack)->queue1->head->next != NULL)
  {
    offer68_en_queue(&((*stack)->queue2), offer68_de_queue((*stack)->queue1));
  }
  return offer68_de_queue((*stack)->queue1);
}

void offer68(void)
{
  offer68_stack_queue *sq = NULL;
  int i;
  for (i = 1; i <= 3; ++i)
  {
    offer68_stack_append_tail(&sq, i);
  }
  printf("%d\n", offer68_stack_delete_head(&sq));
  printf("%d\n", offer68_stack_delete_head(&sq));
  offer68_stack_append_tail(&sq, 4);
  printf("%d\n", offer68_stack_delete_head(&sq));
  offer68_stack_append_tail(&sq, 5);
  printf("%d\n", offer68_stack_delete_head(&sq));
  printf("%d\n", offer68_stack_delete_head(&sq));
  printf("------------------------------\n");

  offer68_queue_stack *qs = NULL;
  for (i = 1; i <= 3; ++i)
  {
    offer68_queue_push(&qs, i);
  }
  offer68_queue_print("qs", qs->queue1);
  for (i = 1; i <= 2; ++i)
  {
    printf("%d\n", offer68_queue_pop(&qs));
  }
  offer68_queue_print("qs", qs->queue1);
  for (i = 5; i <= 9; ++i)
  {
    offer68_queue_push(&qs, i);
  }
  offer68_queue_print("qs", qs->queue1);
  for (i = 1; i <= 4; ++i)
  {
    printf("%d\n", offer68_queue_pop(&qs));
  }
  offer68_queue_print("qs", qs->queue1);
}
