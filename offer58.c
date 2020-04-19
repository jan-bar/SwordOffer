#include "common.h"

typedef struct offer58_node_t
{
    int data;
    struct offer58_node_t *next;
}offer58_node;

offer58_node *offer58_create(int *num,int n)
{
    if (NULL != num && n > 0)
    {
        offer58_node *Head = NULL, *p;
        for (int i=0;i < n;++i)
        {
            p = (offer58_node *)malloc(sizeof(offer58_node));
            if (NULL == p)
            {
                exit(-1);
            }
            p->data = num[i];
            p->next = Head;
            Head = p; // 链表头插入数据
        }
        return Head;
    }
    return NULL;
}

void offer58_print(offer58_node *p)
{
    while (p != NULL)
    {
        printf("%d,", p->data);
        p = p->next;
    }
    printf("\n");
}

/*
反转打印可考虑使用栈结构
这里我使用数组临时保存数据,然后倒序打印
*/
void offer58_print_reverse_0(offer58_node *head)
{
    int i = 0;
    offer58_node *p = head;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }

    int *tmp = (int*)malloc(i * sizeof(int));
    if (NULL == tmp)
    {
        exit(-1);
    }

    i = 0;
    p = head;
    while (p != NULL)
    {
        tmp[i++] = p->data;
        p = p->next;
    }

    while (i > 0)
    {
        i--;
        printf("%d,", tmp[i]);
    }
    printf("\n");
    free(tmp);
}

/*
根据递归的特性编写如下代码
*/
void offer58_print_reverse_1(offer58_node *head)
{
    if (head != NULL)
    {
        if (head->next != NULL)
        { // 该判断可以不要,去掉会多一次递归调用
            offer58_print_reverse_1(head->next);
        }
        printf("%d,", head->data);
    }
}

void offer58(void)
{
    int num[] = {1,2,3,4,5,6,7,8,9,10,11};
    offer58_node *Head = offer58_create(num, LEN(num));
    offer58_print(Head);
    offer58_print_reverse_0(Head);
    offer58_print_reverse_1(Head);

    offer58_node *p = Head, *q;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    Head = p = q = NULL;
}
