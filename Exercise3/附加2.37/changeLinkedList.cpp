/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-10 16:50:21
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-10 17:47:15
 * @FilePath       : \Stack\����2.37\changeLinkedList.cpp
 */
#include <cstdio>
#include <cstdlib>
using namespace std;
const int NodeNum = 7; /* ��ʾһ�������нڵ�ĸ��� */

class Node
{
public:
    Node(int data = 0) : data(data), next(NULL), pre(NULL) {}
    int data;
    Node *next;
    Node *pre;
};

class List
{
public:
    List()
    {
        head = new Node();
        length = 0;
    }
    Node *head;
    int length;
};

void createSingleLinkedList(List *list)
{
    int count = 0;
    Node *p = list->head;
    while (count < NodeNum)
    {
        count++;
        Node *tmp = new Node(count);
        p->next = tmp;
        p->next->pre = p;
        list->length++;
        p = tmp;
    }
    p->next = NULL;
}

void traverse(List *list)
{
    Node *p = list->head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/*** 
 * @description: ���¹�������
 */
void selectRebuild(List *list)
{
    Node *p = list->head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *tail = p;
    int count = list->length;
    while (p->pre != NULL)
    {
        if (count % 2 == 0 && count != NodeNum)
        {
            Node *aft = p->next;
            Node *bef = p->pre;
            Node *cur = p;
            p = p->pre;
            count--;
            bef->next = aft;
            aft->pre = bef;
            tail->next = cur;
            cur->pre = tail;
            cur->next = NULL;
            tail = cur;
        }
        else
        {
            p = p->pre;
            count--;
        }
    }
}

int main()
{
    List *list = new List();
    printf("������˫������Ϊ�� \n");
    createSingleLinkedList(list);
    traverse(list);
    printf("���¹������˫������Ϊ�� \n");
    selectRebuild(list);
    traverse(list);
    return 0;
}