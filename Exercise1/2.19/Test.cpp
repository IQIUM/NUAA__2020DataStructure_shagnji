#include <iostream>
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
    List(Node *head = NULL) : head(head) {}
    void InitList() /* 初始化链表 */
    {
        int i = 10;

        Node *p = head;
        while (i <= 25)
        {
            Node *node = new Node(i);
            p->next = node;
            p = node;
            ++i;
        }
    }
    Node *head;
};

void delSection(List *list, int mink, int maxk)
{
    Node *p = list->head;
    Node *q = p->next;
    while (q != NULL)
    {
        if (mink <= q->data && q->data <= maxk)
        {
            Node *tmp = q;
            q = q->next;
            p->next = q;
            delete tmp;
            tmp = NULL;
        }
        else
        {
            p = q;
            q = q->next;                                                         ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
        }
    }
}

void traverse(List *list)
{
    Node *p = list->head->next;
    while (p != NULL)
    {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node();
    List *list = new List(head);
    list->InitList();
    cout << "原始链表为： \n";
    traverse(list);
    cout << "===================================" << endl;
    printf("删除20到25的数后的链表为：  \n");
    delSection(list, 20, 25);
    traverse(list);
    return 0;
}