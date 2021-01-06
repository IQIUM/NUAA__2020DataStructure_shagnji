/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-25 22:45:09
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 10:47:17
 * @FilePath       : \Exercise6\����6.62\getDeoth.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
using namespace std;

class Node
{
public:
    int data;
    Node *child;
    Node *brother;
    Node(int data) : data(data), child(NULL), brother(NULL) {}
};

/*** 
 * @description: �����ֵ����Ĺ���
 */
void createChildBrotherTree(Node *&root)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ' || ch == '#')
    {
        root = NULL;
    }
    else
    {
        root = new Node(ch - '0');
        createChildBrotherTree(root->child);
        createChildBrotherTree(root->brother);
    }
}

Node *root = NULL;

int getDepth(Node *root)
{
    if (root->child == NULL)
    {
        return 1;
    }
    int childDepth = 0;
    int brotherDepth = 0;
    if (root->child != NULL)
    {
        childDepth = getDepth(root->child);
    }
    if (root->brother != NULL)
    {
        brotherDepth = getDepth(root->brother);
    }
    return (childDepth > brotherDepth ? childDepth : brotherDepth) + 1;
}

int main()
{
    /* ���Ժ����ֵ���Ϊ��1248##5##36#29##### */
    printf("�����뺢��-�ֵ�����   ");
    createChildBrotherTree(root);
    int depth = getDepth(root);
    printf("���������Ϊ�� %d ", depth);
    return 0;
}