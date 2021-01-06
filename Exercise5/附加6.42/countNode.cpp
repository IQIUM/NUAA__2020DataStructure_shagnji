/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-22 18:28:00
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 09:59:27
 * @FilePath       : \Tree\附加6.42\countNode.cpp
 */

#include <cstdio>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

int count = 0;

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
void countNode(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    if (root->left != NULL)
    {
        countNode(root->left);
    }
    if (root->right != NULL)
    {
        countNode(root->right);
    }
}

int main()
{
    /* 测试用例：124#8##5##36##2#9## */
    Node *root = NULL;
    printf("请输入二叉树：  ");
    createBiTree(root);
    countNode(root);
    printf("叶子节点的数目为 %d 个", count);
    return 0;
}