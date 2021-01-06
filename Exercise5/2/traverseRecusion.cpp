/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-21 14:47:10
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 09:48:29
 * @FilePath       : \Tree\2\traverseRecusion.cpp
 */

#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data = 0, Node *left = NULL, Node *right = NULL) : data(data), left(left), right(right) {}
};

class BinaryTree
{
public:
    Node *root;
};

/* 销毁二叉树 */
void DestroyBiTree(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        DestroyBiTree(root->left);
    }
    if (root->right != NULL)
    {
        DestroyBiTree(root->right);
    }
    delete root;
}

/* 创建二叉树 */
void createBiTree(Node *&root)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ' || ch == '0' || ch == '#')
    {
        root = NULL;
    }
    else
    {
        root = new Node(ch - '0');
        createBiTree(root->left);
        createBiTree(root->right);
    }
}
/* 先序遍历 */
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* 中序遍历 */
void infixOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        infixOrder(root->left);
    }
    printf("%d ", root->data);
    if (root->right != NULL)
    {
        infixOrder(root->right);
    }
}

/* 后序遍历 */
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        postOrder(root->left);
    }
    if (root->right != NULL)
    {
        postOrder(root->right);
    }
    printf("%d ", root->data);
}


    
int main()
{
    /* 测试用例：124#8##5##36##2#9## */
    BinaryTree *bt = new BinaryTree();
    printf("请输入要构建的二叉树：  ");
    createBiTree(bt->root);
    printf("原始的二叉树的前序、中序、后序遍历的结果为：\n");
    preOrder(bt->root);
    printf("\n");
    infixOrder(bt->root);
    printf("\n");
    postOrder(bt->root);
    printf("\n");
    
    DestroyBiTree(bt->root);
    return 0;
}