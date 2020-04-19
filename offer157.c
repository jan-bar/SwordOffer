#include "common.h"

// 将树转换为镜像,左右对称
void MirrorRecursively(BinaryTreeNode *node)
{
	if (node == NULL)
		return;
	if (node->left == NULL && node->right == NULL)
		return;
	BinaryTreeNode *tmp = node->left;
	node->left = node->right;
	node->right = tmp;

	if (node->left != NULL)
		MirrorRecursively(node->left);
	if (node->right != NULL)
		MirrorRecursively(node->right);
}

int isSymmetrical_t(BinaryTreeNode *node1,BinaryTreeNode *node2)
{
	if (node1 == NULL && node2 == NULL)
		return 0;
	if (node1 == NULL || node2 == NULL)
		return -1;
	if (node1->data != node2->data)
		return -1;
	return isSymmetrical_t(node1->left,node2->right) && isSymmetrical_t(node1->right,node2->left);
}
// 对称的二叉树,左前序和又前序相等
int isSymmetrical(BinaryTreeNode *node)
{
	return isSymmetrical_t(node,node);
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
void offer157()
{
	int pre[]={10,6,4,2,7,8,5,13,14,12,15,17,16,18};
	int mid[]={2,4,7,6,5,8,13,10,15,12,17,14,16,18};
	BinaryTreeNode *t = CreateBinaryTreeByPreAndMidOrder(pre,mid,LEN(pre));
	PrintTree(t);
	printf("--------------\n");
	MirrorRecursively(t);
	PrintTree(t);

	int pre1[]={8,6,5,7,6,7,5};
	int mid1[]={5,6,7,8,7,6,5};
	BinaryTreeNode *t1 = CreateBinaryTreeByPreAndMidOrder(pre1,mid1,LEN(pre1));
	printf("--------------\n");
	PrintTree(t1);
	if (isSymmetrical(t1) == 0)
		printf("isSymmetrical\n");
}
