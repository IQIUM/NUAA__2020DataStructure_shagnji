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

bool insertElemAfterCurNode(List &list, int ele);

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

/* ����������� */
bool destroyList(List &list)
{
    Node *p = list.head;
    while (list.head->next != NULL)
    {
        p = list.head->next;
        list.head->next = p->next;
        delete p;
    }
    delete list.head;
    list.head = NULL;
    list.curNode = NULL;
    list.length = 0;
    return true;
}

/* ������� */
bool clearList(List &list)
{
    list.length = 0;
    return true;
}

/* �ж������Ƿ�Ϊ�� */
bool isEmpty(List &list)
{
    return list.length == 0;
}

/* ��ȡ����ĳ��� */
int getListLength(List &list)
{
    return list.length;
}

/* ������Ԫ�صĻ�ȡ��Ѱ�������index��Ԫ�ز����뵽ele�� */
bool getElement(List &list, int index, int &ele)
{
    if (index < 1 || index > list.length)
    {
        return false;
    }
    Node *p = list.head;
    int j = 0;
    while (j < index)
    {
        p = p->next;
        ++j;
    }
    ele = p->data;
    list.curNode = p;
    return true;
}

/* �ҵ�����ele�������е�λ�� */
int loacteElement(List &list, int &ele)
{
    Node *p = list.head;
    int i = 0;

    while (p->next != NULL)
    {
        p = p->next;
        ++i;
        if (p->data == ele)
        {
            return i;
        }
    }
    return -1;
}

/* �ҵ�������ele��ǰ��Ԫ�� */
bool getPriorElement(List &list, int ele, int &pre)
{
    /* �������ֻ��һ�����ݣ��Կշ��� */
    if (list.length <= 1)
    {
        return false;
    }

    Node *p = list.head;
    Node *q = p->next;

    while (q != NULL)
    {
        if (q->data == ele)
        {
            pre = p->data;
            return true;
        }
        p = q;
        q = p->next;
    }
    return false;
}

/* �ҵ�������ele�ĺ���Ԫ�� */
bool getNextElement(List &list, int ele, int &next)
{
    Node *q = list.head->next;

    while (q != NULL)
    {
        if (q->data == ele)
        {
            if (q->next != NULL)
            {
                next = q->next->data;
                return true;
            }
        }
        q = q->next;
    }
    return false;
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

int getCurNode(List &list)
{
    return list.curNode->data;
}

/* �������е�index��Ԫ���滻Ϊele */
bool setElement(List &list, int index, int ele)
{
    if (index < 1 || index > list.length)
    {
        return false;
    }
    Node *p = list.head->next;
    int i = 1;
    while (i < index)
    {
        p = p->next;
        ++i;
    }
    p->data = ele;
    return true;
}

/* �ڵ�����ĵ�ǰ�ڵ������½ڵ� */
bool insertElemAfterCurNode(List &list, int ele)
{
    Node *tmp = new Node(ele);
    tmp->next = list.curNode->next;
    list.curNode->next = tmp;
    list.length++;
    return true;
}

/* �ڵ�����ǰ�ڵ��ɾ�������ڵ㣬������e�� */
bool deleteElemAfterNode(List &list, int &e)
{
    if (list.curNode->next == NULL)
    {
        return false;
    }
    e = list.curNode->next->data;
    Node *tmp = list.curNode->next;
    list.curNode->next = tmp->next;
    delete tmp;
    tmp = NULL;
    list.length--;
    return true;
}

int main()
{
    List list;

    printf("�������ʼ���ʹ����� ");
    InitList(list);
    createList(list);
    traverse(list);

    printf("��ȡλ��Ϊ3������ ");
    int ele = 0;
    getElement(list, 3, ele);
    printf("%d\n", ele);

    printf("��ȡ������: %d\n", getListLength(list));

    int pre = 0, next = 0;
    getPriorElement(list, 8, pre);
    getNextElement(list, 8, next);
    printf("��ȡ8ǰһ�����ͺ�һ������ %d �� %d \n", pre, next);

    printf("��ǰ�ڵ�Ϊ�� %d \n", getCurNode(list));

    printf("�ڵ�ǰ�ڵ�����-1: ");
    insertElemAfterCurNode(list, -1);
    traverse(list);

    printf("ɾ����ǰ�ڵ�֮��Ľڵ㣺 ");
    int delNum = 9;
    deleteElemAfterNode(list, delNum);
    traverse(list);

    printf("��������!!! \n");
    destroyList(list);
    printf("�����Ƿ�Ϊ�գ�: ");
    if (isEmpty)
    {
        printf("Ϊ�գ�����\n");
    }
    else
    {
        printf("��Ϊ�գ�����\n");
    }
    return 0;
}