/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-23 09:32:45
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 10:36:18
 * @FilePath       : \Exercise6\4\printLevel.cpp
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

queue<Node *> res;
void BFS(int level)
{
    queue<pair<Node *, int> > que;
    que.push(make_pair(root, 1));
    while (!que.empty())
    {
        Node *tmp = que.front().first;
        int curLevel = que.front().second;
        que.pop();
        if (level == curLevel)
        {
            res.push(tmp);
        }
        if (tmp->child != NULL)
        {
            que.push(make_pair(tmp->child, curLevel + 1));
        }
        if (tmp->brother != NULL)
        {
            que.push(make_pair(tmp->brother, curLevel));
        }
    }
}

int main()
{
    /* ���Ժ����ֵ���Ϊ��1248##5##36#29##### */
    printf("�����뺢��-�ֵ�����   ");
    createChildBrotherTree(root);
    int level = 0;

    while (1)
    {
        printf("��������Ҫ�鿴�ڵ�Ĳ㣺  ");
        scanf("%d", &level);
        if (level == -1)
        {
            break;
        }
        BFS(level);
        printf("�� %d ���Ԫ��Ϊ�� ", level);
        while (!res.empty())
        {
            Node *tmp = res.front();
            res.pop();
            printf("%d ", tmp->data);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}