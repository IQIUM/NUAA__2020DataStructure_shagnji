#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
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
    insertElemAfterCurNode(list, 11);
    insertElemAfterCurNode(list, 12);
    insertElemAfterCurNode(list, 8);
    insertElemAfterCurNode(list, 6);
    insertElemAfterCurNode(list, 11);
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

/* ɾ���������ظ���Ԫ�� */
void deleteRepetition(List &list)
{
    vector<int> vec;
    int count = 0;
    Node *p = list.head;
    Node *q = p->next;

    while (q != NULL)
    {
        int i = 0;
        for (i = 0; i < count; ++i)
        {
            if (q->data == vec[i])
            {
                break;
            }
        }
        if (i == count)
        {
            vec.push_back(q->data);
            count++;
            p = q;
            q = q->next;
        }
        else
        {
            Node *tmp = q;
            p->next = q->next;
            q = q->next;
            delete tmp;
        }
    }
}

int main()
{
    List list;
    InitList(list);
    createList(list);
    printf("ԭʼ���� ");
    traverse(list);
    printf("ɾ���ظ�Ԫ�غ������ ");
    deleteRepetition(list);
    traverse(list);
    return 0;
}