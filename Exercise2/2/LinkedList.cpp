#include <cstdio>
#include <cstdlib>
#include <time.h>
#define random(x) (rand() % x)
#define MAXSIZE 10
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

List *InitLinked()
{
    List *list = new List();
    Node *head = new Node();
    list->head = head;
    int i = 0;
    Node *p = head;
    while (i < MAXSIZE)
    {
        Node *tmp = new Node(random(100));
        p->next = tmp;
        p = tmp;
        ++i;
    }
    return list;
}

/* 数据拼接 */
void joint(List *list1, List *list2)
{
    Node *p = list1->head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    /* 复制一份list2 */
    Node *q = list2->head->next;
    Node *newHead = new Node();
    Node *newCur = newHead;
    while (q != NULL)
    {
        Node *tmp = new Node(q->data);
        newCur->next = tmp;
        newCur = tmp;
        q = q->next;
    }
    p->next = newHead->next;
    delete newHead;
    newHead = NULL;
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
    srand((int)time(0));
    List *list1 = InitLinked();
    List *list2 = InitLinked();
    printf("原顺序表为：   \n");
    traverse(list1);
    traverse(list2);
    printf("================================================\n");
    printf("拼接之后的顺序表为：   \n");
    joint(list1, list2);
    traverse(list1);
    return 0;
}
