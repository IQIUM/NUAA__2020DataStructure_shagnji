/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-21 18:33:41
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 09:43:21
 * @FilePath       : \Tree\2\traverseNoRecusion.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <iostream>
#include <utility>
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

/* ���ٶ����� */
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
        root = new Node(ch - '0');
        createBiTree(root->left);
        createBiTree(root->right);
    }
}
/* ǰ��������ǵݹ� */
void preOrder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *tmp = st.top();
        st.pop();
        printf("%d ", tmp->data);
        if (tmp->right != NULL)
        {
            st.push(tmp->right);
        }
        if (tmp->left != NULL)
        {
            st.push(tmp->left);
        }
    }
}

/* ����������ǵݹ� */
void infixOrder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    Node *p = root;
    while (!st.empty())
    {
        if (p != NULL && p->left != NULL)
        {
            st.push(p->left);
            p = p->left;
        }
        else
        {
            p = st.top();
            st.pop();
            printf("%d ", p->data);
            if (p != NULL && p->right != NULL)
            {
                st.push(p->right);
                p = p->right;
            }
            else
            {
                p = NULL;
            }
        }
    }
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<pair<Node *, bool> > st;
    Node *p = root;
    do
    {
        /* ���Ƚ��������ӽڵ�ѭ������ջ�� */
        while (p != NULL)
        {
            st.push(make_pair(p, false));
            p = p->left;
        }
        /* ����������ջ��Ϻ�׼���������ķ��룬����֮ǰ���Ȼ��ÿ���һ��ջ��Ԫ���Ƿ��Ѿ����η��� */
        while (!st.empty())
        {
            pair<Node *, bool> tmp = st.top();
            st.pop();
            if (tmp.second) /* ���ջ��Ԫ���Ѿ����η����ˣ�ֱ����� */
            {
                printf("%d ", tmp.first->data);
            }
            else /* ���û�У�1.�޸ı�־λΪ true 2. ��ʼ���������� */
            {
                tmp.second = true;
                /* ��ջ */
                st.push(tmp);
                /* ���������� */
                p = tmp.first->right;
                break;
            }
        }
    } while (!st.empty());
}

/* ��α��� */
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
int main()
{
    /* ����������124#8##5##36##2#9## */
    BinaryTree *bt = new BinaryTree();
    printf("������Ҫ�����Ķ�������  ");
    createBiTree(bt->root);
    printf("ԭʼ�Ķ�������ǰ�����򡢺��򡢲�α����Ľ��Ϊ��\n");
    printf("ǰ������� ");
    preOrder(bt->root);
    printf("\n");
    printf("��������� ");
    infixOrder(bt->root);
    printf("\n");
    printf("��������� ");
    postOrder(bt->root);
    printf("\n");
    printf("��α���:  ");
    levelOrder(bt->root);
    printf("\n");
}