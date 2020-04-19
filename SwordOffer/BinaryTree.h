#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode_t
{
    int data;
    struct BinaryTreeNode_t *left;
    struct BinaryTreeNode_t *right;
}BinaryTreeNode;

#define PREORDER 0 // «∞–Ú
#define MIDORDER 1 // ÷––Ú
#define AFTORDER 2 // ∫Û–Ú

BinaryTreeNode* CreateBinaryTreeNode(int value);
BinaryTreeNode* CreateBinaryTreeByPreAndMidOrder(int *pre,int *mid,int length);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(const BinaryTreeNode* pNode);
void PrintTree(const BinaryTreeNode* pRoot);
void Print_Tree_Mode(BinaryTreeNode *node, int mode);
int CompareTree(BinaryTreeNode *t1,BinaryTreeNode *t2);
void DestroyTree(BinaryTreeNode* pRoot);

#endif // BINARYTREE_H_INCLUDED
