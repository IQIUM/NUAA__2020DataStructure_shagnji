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
};

/* 构建循环链表 */
List *initLinkedList(int n)
{
    List *list = new List();
    Node *head = new Node();
    list->head = head;
    int i = 0;
    Node *p = head;
    while (i < n)
    {
        Node *tmp = new Node(i + 1);
        p->next = tmp;
        p = tmp;
        ++i;
    }
    p->next = head->next;
    return list;
}

void Joseph(List *list, int m)
{
    Node *p = list->head;
    Node *q = p->next;
    int count = 0;
    while (p != q)
    {
        count++;
        if (count == m)
        {
            printf("%d  ", q->data);
            Node *tmp = q;
            p->next = q->next;
            q = q->next;
            if (list->head->next = tmp)
            {
                list->head->next = q;
            }
            delete tmp;
            tmp = NULL;
            count = 0;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
    printf("%d  ", list->head->next->data);
}

void traverse(List *list)
{
    Node *p = list->head->next;
    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    List *list = initLinkedList(n);
    Joseph(list, m);
}