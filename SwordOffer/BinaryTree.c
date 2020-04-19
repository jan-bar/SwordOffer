#include "../common.h"

// 创建一个节点
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
  BinaryTreeNode* pNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
  if (NULL == pNode)
  {
    exit(-1); // 申请内存失败
  }
  pNode->data  = value;
  pNode->left  = NULL;
  pNode->right = NULL;

  return pNode;
}
// 连接左右子树到根节点上
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
  if(pParent != NULL)
  {
    pParent->left = pLeft;
    pParent->right = pRight;
  }
}
/*
根据前序+中序还原二叉树
1. 根据前序序列的第一个元素建立根结点；
2. 在中序序列中找到该元素，确定根结点的左右子树的中序序列；
3. 在前序序列中确定左右子树的前序序列；
4. 由左子树的前序序列和中序序列建立左子树；
5. 由右子树的前序序列和中序序列建立右子树。
*/
BinaryTreeNode *create_binary_tree(
  int *start_preorder,int *end_preorder,
  int *start_inorder,int *end_inorder
)
{
  int rootVal = *start_preorder;
  BinaryTreeNode *root = CreateBinaryTreeNode(rootVal);

  if (start_preorder == end_preorder)
  {
    if (start_inorder == end_inorder && *start_preorder == *start_inorder)
    {
      return root;
    }
    else
    {
      printf("Invalid input.\n");
      exit(-1);
    }
  }
  // 在中序遍历序列中找到根节点的值
  int *rootInorder = start_inorder;
  while (rootInorder <= end_inorder && *rootInorder != rootVal)
  {
    ++rootInorder;
  }

  if (rootInorder == end_inorder && *rootInorder != rootVal)
  {
    printf("Invalid input.\n");
    exit(-1);
  }

  int leftLength = rootInorder - start_inorder;
  int *leftPreorderEnd = start_preorder + leftLength;
  if (leftLength > 0)
  {
    //构建左子树
    root->left = create_binary_tree(start_preorder+1,leftPreorderEnd,start_inorder,rootInorder-1);
  }
  if (leftLength < end_preorder-start_preorder)
  {
    //构建右子树
    root->right = create_binary_tree(leftPreorderEnd+1,end_preorder,rootInorder+1,end_inorder);
  }
  return root;
}
// 根据前序+中序还原二叉树
BinaryTreeNode *CreateBinaryTreeByPreAndMidOrder(int *pre,int *mid,int length)
{
  return create_binary_tree(pre, pre+length-1, mid, mid+length-1);
}
// 打印一个节点
void PrintTreeNode(const BinaryTreeNode* pNode)
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
// 打印整个数
void PrintTree(const BinaryTreeNode* pRoot)
{
  PrintTreeNode(pRoot);

  if(pRoot != NULL)
  {
    if(pRoot->left != NULL)
      PrintTree(pRoot->left);

    if(pRoot->right != NULL)
      PrintTree(pRoot->right);
  }
}

/* mode:
PREORDER => 前序打印
MIDORDER => 中序打印
AFTORDER => 后序打印
*/
void Print_Tree_Mode(BinaryTreeNode *node, int mode)
{
  if (mode == PREORDER)
  {
    printf("%d,", node->data);
  }
  if (node->left != NULL)
  {
    Print_Tree_Mode(node->left, mode);
  }
  if (mode == MIDORDER)
  {
    printf("%d,", node->data);
  }
  if (node->right != NULL)
  {
    Print_Tree_Mode(node->right, mode);
  }
  if (mode == AFTORDER)
  {
    printf("%d,", node->data);
  }
}

// 比较两个二叉树是否相同
int CompareTree(BinaryTreeNode *t1,BinaryTreeNode *t2)
{
  if (t1 != NULL && t2 != NULL)
  {
    // printf("l:%d,r:%d\n",t1->data,t2->data);
    if (t1->data != t2->data)
    {
      return -1;
    }

    if (0 != CompareTree(t1->left, t2->left))
    {
      return -1;
    }

    if (0 != CompareTree(t1->right, t2->right))
    {
      return -1;
    }
    return 0;
  }
  else if (t1 == NULL && t2 == NULL)
  {
    return 0;
  }
  return -1;
}
// 回收整个数
void DestroyTree(BinaryTreeNode* pRoot)
{
  if(pRoot != NULL)
  {
    BinaryTreeNode* left = pRoot->left;
    BinaryTreeNode* right = pRoot->right;

    free(pRoot);
    pRoot = NULL;

    DestroyTree(left);
    DestroyTree(right);
  }
}
