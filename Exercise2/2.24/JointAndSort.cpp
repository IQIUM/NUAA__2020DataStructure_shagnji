/*
 * @Author: IQIUM
 * @Date: 2020-11-03 16:23:23
 * @LastEditors: IQIUM
 * @LastEditTime: 2020-11-03 16:28:08
 * @FilePath: \List2\2.24\JointAndSort.cpp
 */
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
    int begin = random(100);
    while (i < MAXSIZE)
    {
        Node *tmp = new Node(begin++);
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
/* 选择排序 */
void selectionSort(List *list)
{
    Node *p = list->head->next;
    while (p != NULL)
    {
        Node *t = p;
        Node *q = p->next;
        while (q != NULL)
        {
            if (q->data > t->data)
            {
                t = q;
            }
            q = q->next;
        }
        /* 交换 */
        if (t != q)
        {
            int tmp = p->data;
            p->data = t->data;
            t->data = tmp;
        }

        p = p->next;
    }
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
    printf("================================================\n");
    printf("排序之后的顺序表为：   \n");
    selectionSort(list1);
    traverse(list1);
    return 0;
}
