#include <cstdio>
#include <cstdlib>
class Node
{
public:
    Node(int data = 0, Node *next = NULL) : data(data), next(next) {}
    int data;
    Node *next;
};

class List
{
public:
    Node *head;
    Node *curNode;
    int length;
};

/* �ڵ�����ĵ�ǰ�ڵ������½ڵ� */
bool insertElemAfterCurNode(List &list, int ele)
{
    Node *tmp = new Node(ele);
    tmp->next = list.curNode->next;
    list.curNode->next = tmp;
    list.length++;
    list.curNode = tmp;
    return true;
}

/* ������ĳ�ʼ�� */
bool InitList(List &list)
{
    list.head = new Node();
    list.curNode = list.head;
    list.length = 0;
    return true;
}

/* ����Ĵ��� */
bool createList(List &list)
{
    insertElemAfterCurNode(list, 6);
    insertElemAfterCurNode(list, 7);
    insertElemAfterCurNode(list, 8);
    insertElemAfterCurNode(list, 9);
    insertElemAfterCurNode(list, 10);
}

/* �������� */
void traverse(List &list)
{
    Node *p = list.head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/* ������ */
void reverse(List &list)
{
    if (list.length <= 1)
    {
        return;
    }

    Node *p = list.head->next;
    Node *q = p->next;

    p->next = NULL;

    while (q->next != NULL)
    {
        Node *tmp = p;
        p = q;
        q = q->next;
        p->next = tmp;
    }
    q->next = p;
    list.head->next = q;
}

int main()
{
    List list;
    InitList(list);
    createList(list);
    printf("ԭʼ���� ");
    traverse(list);
    printf("���ú������ ");
    reverse(list);
    traverse(list);
    return 0;
}