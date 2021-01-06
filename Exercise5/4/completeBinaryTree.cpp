/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-22 11:10:32
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 09:49:36
 * @FilePath       : \Tree\4\completeBinaryTree.cpp
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

/* ���������� */
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
        root = new Node(ch + '0');
        createBiTree(root->left);
        createBiTree(root->right);
    }
}

bool isCompleteBinaryTree(Node *root)
{
    queue<Node *> que;
    bool flag = false;
    que.push(root);
    while (!que.empty())
    {
        Node *tmp = que.front();
        que.pop();
        if (flag && (root->left != NULL || root->right != NULL))
        {
            return false;
        }

        /* ��ֻ��һ���ڵ������� */
        /* 1. ���ӽ�� */
        if ((tmp->left != NULL && tmp->right == NULL))
        {
            flag = true;
        }
        else if (tmp->right != NULL && tmp->left == NULL) /* 2. ���ӽڵ� */
        {
            return false;
        }

        if (tmp->left != NULL)
        {
            que.push(tmp->left);
        }
        if (tmp->right != NULL)
        {
            que.push(tmp->right);
        }
    }
    return true;
}

int main()
{
    /* ����������124#8##5##36##2#9## */
    printf("�������������   ");
    createBiTree(bt->root);
    printf("%s ��ȫ������\n", isCompleteBinaryTree(bt->root) ? "��" : "����");

    return 0;
}