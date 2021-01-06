/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-22 10:17:14
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 09:56:28
 * @FilePath       : \Tree\3\deleteRootTree.cpp
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

BinaryTree *bt = new BinaryTree();

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

/* 层次遍历 */
void levelOrder(Node *root)
{
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *tmp = que.front();
        que.pop();
        printf("%d ", tmp->data);
        if (tmp->left != NULL)
        {
            que.push(tmp->left);
        }
        if (tmp->right != NULL)
        {
            que.push(tmp->right);
        }
    }
}

/* 求得 cur 节点的父结点 */
Node *getParent(Node *root, Node *cur)
{
    if (cur == root)
    {
        return NULL;
    }
    if (cur == root->left || cur == root->right)
    {
        return root;
    }
    Node *leftRes = NULL;
    Node *rightRes = NULL;

    if (root->left != NULL)
    {
        leftRes = getParent(root->left, cur);
    }
    if (root->right != NULL)
    {
        rightRes = getParent(root->right, cur);
    }
    return leftRes != NULL ? leftRes : (rightRes != NULL) ? rightRes : NULL;
}

/* 删除以 2 为根节点的子树 */
void deleteRootTree(Node *root, int value)
{

    if (root == NULL)
    {
        return;
    }
    if (root->data == value)
    {
        Node *parent = getParent(bt->root, root);
        if (root == parent->left)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        DestroyBiTree(root);
    }
    else
    {
        deleteRootTree(root->left, value);
        deleteRootTree(root->right, value);
    }
}

int main()
{
    /* 测试用例：124#8##5##36##2#9## */
    printf("请输入二叉树：   ");
    createBiTree(bt->root);
    printf("删除之前的二叉树层次遍历： ");
    levelOrder(bt->root);
    printf("\n");
    printf("删除以2为根节点的树之后遍历： ");
    deleteRootTree(bt->root, 2);
    levelOrder(bt->root);
    printf("\n");
    system("pause");
    return 0;
}