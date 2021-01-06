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
/* 前序遍历：非递归 */
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

/* 中序遍历：非递归 */
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
        /* 首先将树的左子节点循环放入栈中 */
        while (p != NULL)
        {
            st.push(make_pair(p, false));
            p = p->left;
        }
        /* 左子树放入栈完毕后，准备右子树的放入，放入之前首先还得考虑一下栈顶元素是否已经二次访问 */
        while (!st.empty())
        {
            pair<Node *, bool> tmp = st.top();
            st.pop();
            if (tmp.second) /* 如果栈顶元素已经二次访问了，直接输出 */
            {
                printf("%d ", tmp.first->data);
            }
            else /* 如果没有，1.修改标志位为 true 2. 开始访问右子树 */
            {
                tmp.second = true;
                /* 入栈 */
                st.push(tmp);
                /* 访问右子树 */
                p = tmp.first->right;
                break;
            }
        }
    } while (!st.empty());
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
int main()
{
    /* 测试用例：124#8##5##36##2#9## */
    BinaryTree *bt = new BinaryTree();
    printf("请输入要构建的二叉树：  ");
    createBiTree(bt->root);
    printf("原始的二叉树的前序、中序、后序、层次遍历的结果为：\n");
    printf("前序遍历： ");
    preOrder(bt->root);
    printf("\n");
    printf("中序遍历： ");
    infixOrder(bt->root);
    printf("\n");
    printf("后序遍历： ");
    postOrder(bt->root);
    printf("\n");
    printf("层次遍历:  ");
    levelOrder(bt->root);
    printf("\n");
}