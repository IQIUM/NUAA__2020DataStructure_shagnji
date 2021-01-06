/*
 * @Author: IQIUM
 * @Date: 2020-10-22 16:33:54
 * @LastEditors: IQIUM
 * @LastEditTime: 2020-11-02 08:30:25
 * @FilePath: \List2\1\LinkedList.cpp
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
    srand((int)time(0));
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
            if (q->data < t->data)
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

/* 冒泡排序 */
void bubbleSort(List *list, int length)
{
    Node *p = list->head->next;
    for (int i = 0; i < length - 1; ++i, p = p->next)
    {
        Node *q = list->head->next;
        for (int j = 0; j < length - i - 1; j++, q = q->next)
        {
            if (q->data > q->next->data)
            {
                int tmp = q->data;
                q->data = q->next->data;
                q->next->data = tmp;
            }
        }
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
    List *list = InitLinked();
    printf("原顺序表为：   \n");
    traverse(list);
    printf("================================================\n");
    // printf("选择排序之后的顺序表为：   \n");
    // selectionSort(list);
    printf("冒泡排序之后的顺序表为：    \n");
    bubbleSort(list, MAXSIZE);
    traverse(list);
    return 0;
}
