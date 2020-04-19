#include "common.h"

/*
����ǰ��+����ԭ������
1. ����ǰ�����еĵ�һ��Ԫ�ؽ�������㣻
2. �������������ҵ���Ԫ�أ�ȷ�������������������������У�
3. ��ǰ��������ȷ������������ǰ�����У�
4. ����������ǰ�����к��������н�����������
5. ����������ǰ�����к��������н�����������
*/
BinaryTreeNode *offer62_create_0(
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
    // ����������������ҵ����ڵ��ֵ
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
        //����������
        root->left = offer62_create_0(start_preorder+1,leftPreorderEnd,start_inorder,rootInorder-1);
    }
    if (leftLength < end_preorder-start_preorder)
    {
        //����������
        root->right = offer62_create_0(leftPreorderEnd+1,end_preorder,rootInorder+1,end_inorder);
    }
    return root;
}

/*
��������+����ԭ������
1. ���ݺ������е����һ��Ԫ�ؽ�������㣻
2. �������������ҵ���Ԫ�أ�ȷ�������������������������У�
3. �ں���������ȷ�����������ĺ������У�
4. ���������ĺ������к��������н�����������
5. ���������ĺ������к��������н���������
*/
BinaryTreeNode *offer62_create_1(
    int *start_inorder,int *end_inorder,
    int *start_afterorder,int *end_afterorder
)
{
    int rootVal = *end_afterorder;
    BinaryTreeNode *root = CreateBinaryTreeNode(rootVal);

    if (start_afterorder == end_afterorder)
    {
        if (start_inorder == end_inorder && *start_afterorder == *start_inorder)
        {
            return root;
        }
        else
        {
            printf("Invalid input 1.\n");
            exit(-1);
        }
    }

    // ����������������ҵ����ڵ��ֵ
    int *rootInorder = start_inorder;
    while (rootInorder <= end_inorder && *rootInorder != rootVal)
    {
        ++rootInorder;
    }

    if (rootInorder == end_inorder && *rootInorder != rootVal)
    {
        printf("Invalid input 2.\n");
        exit(-1);
    }

    int leftLength = rootInorder - start_inorder;
    int *leftAfterorderEnd = start_afterorder + leftLength;
    if (leftLength > 0)
    {
        //����������
        root->left = offer62_create_1(start_inorder,rootInorder-1,start_afterorder,leftAfterorderEnd-1);
    }
    if (leftLength < end_afterorder-start_afterorder)
    {
        //����������
        root->right = offer62_create_1(rootInorder+1,end_inorder,leftAfterorderEnd,end_afterorder-1);
    }
    return root;
}

// mode:0(����ǰ��+����ԭ),1(��������+����ԭ)
BinaryTreeNode *offer62_create_check(int *a,int *b,int length,int mode)
{
    if (NULL == a || NULL == b || length < 1)
    {
        return NULL;
    }
    if (mode == 0)
    {
        return offer62_create_0(a, a+length-1, b, b+length-1);
    }
    return offer62_create_1(a, a+length-1, b, b+length-1);
}

// �������ǰ��������������
BinaryTreeNode *offer62_BinaryTreeAfterOrder(int *preorder,int *inorder,int length)
{
    if (length == 0)
    {
        return NULL;
    }
    BinaryTreeNode *node = CreateBinaryTreeNode(*preorder);

    int rootIndex = 0;
    for (; rootIndex < length; rootIndex++)
    {
        if (inorder[rootIndex] == *preorder)
        {
            break;
        }
    }

    node->left = offer62_BinaryTreeAfterOrder(preorder + 1,inorder, rootIndex);
    node->right = offer62_BinaryTreeAfterOrder(preorder + rootIndex + 1,inorder + rootIndex + 1, length - rootIndex - 1);
    printf("%d,", node->data);
    free(node);
    return NULL;
}
// �����������ͺ������ǰ��
BinaryTreeNode *offer62_BinaryTreePreOrder(int *inorder,int *afterorder,int length)
{
    if (length == 0)
    {
        return NULL;
    }
    int rootVal = *(afterorder + length - 1);
    BinaryTreeNode *node = CreateBinaryTreeNode(rootVal);

    int rootIndex = 0;
    for (; rootIndex < length; rootIndex++)
    {
        if (inorder[rootIndex] == rootVal)
        {
            break;
        }
    }

    printf("%d,", node->data);
    node->left = offer62_BinaryTreePreOrder(inorder, afterorder, rootIndex);
    node->right = offer62_BinaryTreePreOrder(inorder + rootIndex + 1,afterorder + rootIndex, length - rootIndex - 1);
    free(node);
    return NULL;
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
// ����ǰ��+����ԭ�Ķ�����,�Լ�����ǰ��+����ֱ�ӵõ�����
BinaryTreeNode *offer62_test_0(void)
{
    int preorder[] = {10,6,4,2,7,8,5,13,14,12,15,17,16,18};
    int inorder[]  = {2,4,7,6,5,8,13,10,15,12,17,14,16,18};
    BinaryTreeNode *tree = offer62_create_check(preorder, inorder, LEN(preorder), 0);
    printf("--------------------------------------------------------------\n");
    PrintTree(tree);

    printf("Orderings:\n");
    Print_Tree_Mode(tree, AFTORDER); // ���Ի�ԭ������Ȼ���ӡ����
    printf("\n");
    offer62_BinaryTreeAfterOrder(preorder, inorder, LEN(preorder)); // ֱ�Ӵ�ӡ����
    printf("\n--------------------------------------------------------------\n");
    return tree;
}
// ��������+����ԭ�Ķ�����,�Լ���������+����ֱ�ӵõ�ǰ����
BinaryTreeNode *offer62_test_1(void)
{
    int inorder[]     = {2,4,7,6,5,8,13,10,15,12,17,14,16,18};
    int afterorder[]  = {2,7,4,5,13,8,6,15,17,12,18,16,14,10};
    BinaryTreeNode *tree = offer62_create_check(inorder, afterorder, LEN(inorder), 1);
    printf("--------------------------------------------------------------\n");
    PrintTree(tree);

    Print_Tree_Mode(tree, PREORDER); // ���Ի�ԭ������Ȼ���ӡǰ����
    printf("\n");
    offer62_BinaryTreePreOrder(inorder, afterorder, LEN(inorder));
    printf("\n--------------------------------------------------------------\n");
    return tree;
}

void offer62(void)
{
    BinaryTreeNode *t1 = offer62_test_0();
    BinaryTreeNode *t2 = offer62_test_1();

    // �Ƚ� ǰ��+���� �� ����+���� ��ԭ�Ķ������Ƿ���ͬ
    printf("CompareTree t1,t2: %d\n", CompareTree(t1, t2));

    DestroyTree(t1);
    DestroyTree(t2);
}
