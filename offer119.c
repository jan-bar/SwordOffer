#include "common.h"

typedef struct offer119_node_t
{
  int data;
  struct offer119_node_t *next;
} offer119_node;

offer119_node *create_offer119_node(int *data,int len)
{
  int i = 0;
  offer119_node *node =  NULL;
  for (; i<len; ++i)
  {
    offer119_node *p = (offer119_node*)malloc(sizeof(offer119_node));
    MALLOC_ERR(p);
    p->data = data[i];
    p->next = node;
    node = p;
  }
  return node;
}

void offer119_print(offer119_node *node)
{
  while (node != NULL)
  {
    printf("%d,",node->data);
    node = node->next;
  }
  printf("\n");
}

// 遍历链表删除
int offer119_del_data(offer119_node **node,int del)
{
  if (node == NULL || *node == NULL)
    return 0; // 空链表
  offer119_node *p = *node;
  if ((*node)->data == del)
  {
  	*node = (*node)->next;
  	free(p);
  	return 0; // 头部为删除的数据
  }
  offer119_node *q = p->next;
  while (q != NULL && q->data != del)
  {
  	p=p->next;
  	q=q->next;
  }
  if (q == NULL)
		return 1; // 没有要删除的数据
  p->next = q->next;
  free(q);
  return 0;
}

int offer119_del_node(offer119_node **node,offer119_node *del)
{
  if (node == NULL || *node == NULL || del == NULL)
    return 0;
  if (*node == del)
  {
    *node = (*node)->next;
  	free(del);
  	return 0; // 头部为删除的数据
  }
  offer119_node *p = *node;
  if (del->next == NULL)
  {
    while (p->next != del)
    {
      p=p->next;
    }
    p->next = NULL;
    free(del);
    return 0;// 删除尾部节点
  }
  p = del->next;
  del->data = p->data;
  del->next = p->next;
  free(p);
  return 0;
}

void offer119()
{
  int data[] = {1,2,3,4,5,6,7};
  offer119_node *node =  create_offer119_node(data,LEN(data));
  offer119_print(node);
  offer119_del_data(&node,4);
  offer119_print(node);

  offer119_del_node(&node,node->next->next->next->next->next);
  offer119_print(node);

  int preorder[] = {10,6,4,2,7,8,5,13,14,12,15,17,16,18};
    int inorder[]  = {2,4,7,6,5,8,13,10,15,12,17,14,16,18};
    BinaryTreeNode *aa= CreateBinaryTreeByPreAndMidOrder(preorder,inorder,LEN(inorder));
    PrintTree(aa);

}
