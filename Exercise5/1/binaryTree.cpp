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

/* 初始化二叉树 */
void InitBiTree(BinaryTree *&bt)
{
    bt->root = NULL;
}

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

/* 清空二叉树，将二叉树置为空树 */
void clearBiTree(BinaryTree *&bt)
{
    bt->root = NULL;
}

/* 判断二叉树是否为空 */
bool BiTreeEmpty(BinaryTree *&bt)
{
    return bt->root == NULL;
}

/* 求二叉树的深度 */
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

/* 返回二叉树的根元素 */
Node *getRoot(BinaryTree *bt)
{
    return bt->root;
}

/* 返回节点 CUR 的值 */
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

/* 返回 cur 节点的左孩子 */
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

/* 获取右孩子 */
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

/* 求左兄弟 */
Node *getLeftBrother(Node *root, Node *cur)
{
    Node *parent = getParent(root, cur);
    return parent == NULL ? NULL : parent->left;
}

/* 求右兄弟 */
Node *getRightBrother(Node *root, Node *cur)
{
    Node *parent = getParent(root, cur);
    return parent == NULL ? NULL : parent->right;
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

/* 节点赋值 */
void assign(Node *root, int preValue, int value)
{
    Node *cur = getNodeByValue(root, preValue);
    if (cur != NULL)
    {
        cur->data = value;
    }
}

/* 插入子树 */
void insertChild(Node *root, int curValue, int lr, Node *ctoadd)
{
    Node *cur = getNodeByValue(root, 6);
    if (lr == 1)    /* 插入左子树 */
    {
        Node *rightNode = cur->right;
        cur->right = ctoadd;
        ctoadd->right = rightNode;
    }
    else    /* 插入右子树 */
    {
        Node *leftNode = cur->left;
        cur->left = ctoadd;
        ctoadd->right = leftNode;
    }
}

void deleteChild(Node *root, Node *cur, int lr)
{
    if (lr) /* 删除右子树 */
    {
        DestroyBiTree(cur->right);
        cur->right = NULL;
    }
    else /* 删除左子树 */
    {
        DestroyBiTree(cur->left);
        cur->left = NULL;
    }
}

int main()
{
    /* 测试用例：124#8##5##36##2#9## */
    printf("下面进行各个方法的测试！\n");
    BinaryTree *bt = new BinaryTree();
    InitBiTree(bt);
    printf("请输入要构建二叉树：  ");
    createBiTree(bt->root);
    printf("原始的二叉树的前序、中序、后序遍历的结果为：\n");
    preOrder(bt->root);
    printf("\n");
    infixOrder(bt->root);
    printf("\n");
    postOrder(bt->root);
    printf("\n");
    printf("\n");
    printf("原始二叉树的高度为：%d\n", BiTreeDepth(bt->root));
    printf("获取二叉树根的值： %d\n", getRoot(bt)->data);
    printf("此时二叉树是否为空？ %s \n\n", BiTreeEmpty(bt) ? "为空" : "不为空");
    printf("现在以值为3的节点为例，获取它的左右节点、父结点、兄弟节点\n");
    Node *node = getNodeByValue(bt->root, 3);
    printf("左孩子值为： %d, 右孩子值为： %d\n", getLeftChild(bt->root, node)->data, getRightChild(bt->root, node)->data);
    printf("父结点为： %d , 兄弟节点为 %d\n\n", getParent(bt->root, node)->data, getLeftBrother(bt->root, node)->data);
    printf("把值为5的节点修改为999后前序遍历:  ");
    assign(bt->root, 5, 999);
    preOrder(bt->root);
    printf("\n");

    Node *tmp = new Node(1000);
    printf("在节点6的后面添加右节点后前序遍历： ");
    insertChild(bt->root, 6, 1, tmp);
    preOrder(bt->root);
    printf("\n");

    printf("删除根节点的右子树，前序遍历结果为： ");
    deleteChild(bt->root, bt->root, 1);
    preOrder(bt->root);
    printf("\n");
    printf("销毁二叉树！！！");
    DestroyBiTree(bt->root);
    system("pause");
    
    return 0;
}