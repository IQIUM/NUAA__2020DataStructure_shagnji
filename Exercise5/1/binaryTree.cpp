/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-21 14:47:10
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 09:39:12
 * @FilePath       : \Tree\1\binaryTree.cpp
 */

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
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

/* ��ʼ�������� */
void InitBiTree(BinaryTree *&bt)
{
    bt->root = NULL;
}

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

/* ��ն�����������������Ϊ���� */
void clearBiTree(BinaryTree *&bt)
{
    bt->root = NULL;
}

/* �ж϶������Ƿ�Ϊ�� */
bool BiTreeEmpty(BinaryTree *&bt)
{
    return bt->root == NULL;
}

/* ������������ */
int BiTreeDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftDepth = BiTreeDepth(root->left);
    int rightDepth = BiTreeDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

/* ���ض������ĸ�Ԫ�� */
Node *getRoot(BinaryTree *bt)
{
    return bt->root;
}

/* ���ؽڵ� CUR ��ֵ */
int getValue(Node *root, Node *node)
{
    if (root == node)
    {
        return root->data;
    }
    if (root->left != NULL)
    {
        return getValue(root->left, node);
    }
    if (root->right != NULL)
    {
        return getValue(root->right, node);
    }
    return -1;
}

/* ��� cur �ڵ�ĸ���� */
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

/* ���� cur �ڵ������ */
Node *getLeftChild(Node *root, Node *cur)
{
    if (root == cur)
    {
        return root->left;
    }
    Node *leftRes = NULL;
    Node *rightRes = NULL;
    if (root->left != NULL)
    {
        leftRes = getLeftChild(root->left, cur);
    }
    if (root->right != NULL)
    {
        rightRes = getLeftChild(root->right, cur);
    }
    return leftRes != NULL ? leftRes : (rightRes != NULL) ? rightRes : NULL;
}

/* ��ȡ�Һ��� */
Node *getRightChild(Node *root, Node *cur)
{
    if (root == cur)
    {
        return root->right;
    }
    Node *leftRes = NULL;
    Node *rightRes = NULL;
    if (root->left != NULL)
    {
        leftRes = getRightChild(root->left, cur);
    }
    if (root->right != NULL)
    {
        rightRes = getRightChild(root->right, cur);
    }
    return leftRes != NULL ? leftRes : (rightRes != NULL) ? rightRes : NULL;
}

/* �����ֵ� */
Node *getLeftBrother(Node *root, Node *cur)
{
    Node *parent = getParent(root, cur);
    return parent == NULL ? NULL : parent->left;
}

/* �����ֵ� */
Node *getRightBrother(Node *root, Node *cur)
{
    Node *parent = getParent(root, cur);
    return parent == NULL ? NULL : parent->right;
}

/* ������� */
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* ������� */
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

/* ������� */
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

Node *getNodeByValue(Node *root, int value)
{
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *tmp = que.front();
        que.pop();
        if (tmp->data == value)
        {
            return tmp;
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
    return NULL;
}

/* �ڵ㸳ֵ */
void assign(Node *root, int preValue, int value)
{
    Node *cur = getNodeByValue(root, preValue);
    if (cur != NULL)
    {
        cur->data = value;
    }
}

/* �������� */
void insertChild(Node *root, int curValue, int lr, Node *ctoadd)
{
    Node *cur = getNodeByValue(root, 6);
    if (lr == 1)    /* ���������� */
    {
        Node *rightNode = cur->right;
        cur->right = ctoadd;
        ctoadd->right = rightNode;
    }
    else    /* ���������� */
    {
        Node *leftNode = cur->left;
        cur->left = ctoadd;
        ctoadd->right = leftNode;
    }
}

void deleteChild(Node *root, Node *cur, int lr)
{
    if (lr) /* ɾ�������� */
    {
        DestroyBiTree(cur->right);
        cur->right = NULL;
    }
    else /* ɾ�������� */
    {
        DestroyBiTree(cur->left);
        cur->left = NULL;
    }
}

int main()
{
    /* ����������124#8##5##36##2#9## */
    printf("������и��������Ĳ��ԣ�\n");
    BinaryTree *bt = new BinaryTree();
    InitBiTree(bt);
    printf("������Ҫ������������  ");
    createBiTree(bt->root);
    printf("ԭʼ�Ķ�������ǰ�����򡢺�������Ľ��Ϊ��\n");
    preOrder(bt->root);
    printf("\n");
    infixOrder(bt->root);
    printf("\n");
    postOrder(bt->root);
    printf("\n");
    printf("\n");
    printf("ԭʼ�������ĸ߶�Ϊ��%d\n", BiTreeDepth(bt->root));
    printf("��ȡ����������ֵ�� %d\n", getRoot(bt)->data);
    printf("��ʱ�������Ƿ�Ϊ�գ� %s \n\n", BiTreeEmpty(bt) ? "Ϊ��" : "��Ϊ��");
    printf("������ֵΪ3�Ľڵ�Ϊ������ȡ�������ҽڵ㡢����㡢�ֵܽڵ�\n");
    Node *node = getNodeByValue(bt->root, 3);
    printf("����ֵΪ�� %d, �Һ���ֵΪ�� %d\n", getLeftChild(bt->root, node)->data, getRightChild(bt->root, node)->data);
    printf("�����Ϊ�� %d , �ֵܽڵ�Ϊ %d\n\n", getParent(bt->root, node)->data, getLeftBrother(bt->root, node)->data);
    printf("��ֵΪ5�Ľڵ��޸�Ϊ999��ǰ�����:  ");
    assign(bt->root, 5, 999);
    preOrder(bt->root);
    printf("\n");

    Node *tmp = new Node(1000);
    printf("�ڽڵ�6�ĺ�������ҽڵ��ǰ������� ");
    insertChild(bt->root, 6, 1, tmp);
    preOrder(bt->root);
    printf("\n");

    printf("ɾ�����ڵ����������ǰ��������Ϊ�� ");
    deleteChild(bt->root, bt->root, 1);
    preOrder(bt->root);
    printf("\n");
    printf("���ٶ�����������");
    DestroyBiTree(bt->root);
    system("pause");
    
    return 0;
}