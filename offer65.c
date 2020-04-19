#include "common.h"

typedef struct offer65_tree_node_t
{
    int data;
    struct offer65_tree_node_t *left;
    struct offer65_tree_node_t *right;
    struct offer65_tree_node_t *parent;
} offer65_tree_node;

offer65_tree_node* offer65_CreateBinaryTreeNode(int value)
{
    offer65_tree_node* pNode = (offer65_tree_node*)malloc(sizeof(offer65_tree_node));
    if (NULL == pNode)
    {
        exit(-1); // 申请内存失败
    }
    pNode->data  = value;
    pNode->left  = NULL;
    pNode->right = NULL;
    pNode->parent = NULL;

    return pNode;
}

void offer65_ConnectTreeNodes(offer65_tree_node* pParent, offer65_tree_node* pLeft, offer65_tree_node* pRight)
{
    if(pParent != NULL)
    {
        pParent->left = pLeft;
        pParent->right = pRight;

        if (pLeft != NULL)
        {
            pLeft->parent = pParent;
        }
        if (pRight != NULL)
        {
            pRight->parent = pParent;
        }
    }
}

void offer65_PrintTreeNode(const offer65_tree_node* pNode)
{
    if(pNode != NULL)
    {
        printf("node = %d\t", pNode->data);
        if(pNode->left != NULL)
            printf("left = %d\t", pNode->left->data);
        else
            printf("left = NULL\t");

        if(pNode->right != NULL)
            printf("right = %d\t", pNode->right->data);
        else
            printf("right = NULL\t");
    }
    else
    {
        printf("node = NULL\t");
    }
    printf("\n");
}

void offer65_PrintTree(const offer65_tree_node* pRoot)
{
    offer65_PrintTreeNode(pRoot);

    if(pRoot != NULL)
    {
        if(pRoot->left != NULL)
            offer65_PrintTree(pRoot->left);

        if(pRoot->right != NULL)
            offer65_PrintTree(pRoot->right);
    }
}

void offer65_DestroyTree(offer65_tree_node* pRoot)
{
    if(pRoot != NULL)
    {
        offer65_tree_node* left = pRoot->left;
        offer65_tree_node* right = pRoot->right;

        free(pRoot);
        pRoot = NULL;

        offer65_DestroyTree(left);
        offer65_DestroyTree(right);
    }
}


// 中序打印
void offer65_print_Inoder(const offer65_tree_node *node)
{
    if (node->left != NULL)
        offer65_print_Inoder(node->left);

    printf("%d,", node->data);

    if (node->right != NULL)
        offer65_print_Inoder(node->right);
}
/*
面试题8：二叉树的下一个结点
题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/08_NextNodeInBinaryTrees/NextNodeInBinaryTrees.cpp
*/
offer65_tree_node *offer65_get_next(offer65_tree_node *node)
{
    if (node != NULL)
    {
        if (node->right != NULL)
        { // 找右子树的最左子树
            offer65_tree_node *tmp = node->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            return tmp;
        }
        else if (node->parent != NULL)
        { // 父元素的是父父元素的左子树则结果是父元素
            offer65_tree_node *cur = node;
            offer65_tree_node *parent = node->parent;
            while (parent != NULL && cur == parent->right)
            {
                cur = parent;
                parent = parent->parent;
            }
            return parent;
        }
    }
    return NULL;
}

void offer65_test0(offer65_tree_node *src)
{
    offer65_tree_node *tmp = offer65_get_next(src);
    if (tmp != NULL)
        printf("t%d next is t%d\n", src->data, tmp->data);
    else
        printf("t%d next is NULL\n", src->data);
}

/*
          10
      /       \
     6         14
   /   \      /  \
  4     8    12  16
 / \   / \   / \   \
2   7 5  13 15  17  18
*/
void offer65(void)
{
    offer65_tree_node *t10 = offer65_CreateBinaryTreeNode(10);
    offer65_tree_node *t6  = offer65_CreateBinaryTreeNode(6);
    offer65_tree_node *t14 = offer65_CreateBinaryTreeNode(14);
    offer65_tree_node *t4  = offer65_CreateBinaryTreeNode(4);
    offer65_tree_node *t8  = offer65_CreateBinaryTreeNode(8);
    offer65_tree_node *t12 = offer65_CreateBinaryTreeNode(12);
    offer65_tree_node *t16 = offer65_CreateBinaryTreeNode(16);
    offer65_tree_node *t2  = offer65_CreateBinaryTreeNode(2);
    offer65_tree_node *t7  = offer65_CreateBinaryTreeNode(7);
    offer65_tree_node *t5  = offer65_CreateBinaryTreeNode(5);
    offer65_tree_node *t13 = offer65_CreateBinaryTreeNode(13);
    offer65_tree_node *t15 = offer65_CreateBinaryTreeNode(15);
    offer65_tree_node *t17 = offer65_CreateBinaryTreeNode(17);
    offer65_tree_node *t18 = offer65_CreateBinaryTreeNode(18);

    offer65_ConnectTreeNodes(t10, t6, t14);
    offer65_ConnectTreeNodes(t6, t4, t8);
    offer65_ConnectTreeNodes(t14, t12, t16);
    offer65_ConnectTreeNodes(t4, t2, t7);
    offer65_ConnectTreeNodes(t8, t5, t13);
    offer65_ConnectTreeNodes(t12, t15, t17);
    offer65_ConnectTreeNodes(t16, NULL, t18);

    printf("---------------------------------------------------------------\n");
    offer65_PrintTree(t10);
    printf("---------------------------------------------------------------\n");
    offer65_print_Inoder(t10);
    printf("\n");

    offer65_test0(t17);

    offer65_DestroyTree(t10);
}
