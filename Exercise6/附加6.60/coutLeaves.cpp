/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-25 20:28:22
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 10:45:11
 * @FilePath       : \Exercise6\����6.60\coutLeaves.cpp
 */
/*** 
     * @Author         : IQIUM
     * @Date           : 2020-11-25 20:28:22
     * @LastEditors    : IQIUM
     * @LastEditTime   : 2020-11-26 10:44:54
     * @FilePath       : \Exercise6\����6.60\coutLeaves.cpp
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

Node *root = NULL;

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

int count = 0;

void countLeaves(Node *root)
{
    if (root->child == NULL)
    {
        count++;
    }
    if (root->child != NULL)
    {
        countLeaves(root->child);
    }
    if (root->brother != NULL)
    {
        countLeaves(root->brother);
    }
}

int main()
{
    /* ���Ժ����ֵ���Ϊ��1248##5##36#29##### */
    printf("�����뺢��-�ֵ�����   ");
    createChildBrotherTree(root);
    countLeaves(root);
    printf("������Ҷ�ӽڵ����Ϊ�� %d ��", count);
    return 0;
}