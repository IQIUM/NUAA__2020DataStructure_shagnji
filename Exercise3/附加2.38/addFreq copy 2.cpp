/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-10 20:45:21
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-10 21:40:16
 * @FilePath       : \Stack\附加2.38\addFreq.cpp
 */
#include <cstdio>
#include <cstdlib>
using namespace std;
const int NodeNum = 10;
class Node
{
public:
    Node(int data = 0) : data(data), next(NULL), pre(NULL), freq(0) {}
    int data;
    Node *next;
    Node *pre;
    int freq;
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

/*** 
 * @description: 根据访问频率排序
 */
void sort(List *list)
{
    Node *bef1 = list->head;
    Node *p = bef1->next;
    while (p != NULL)
    {
        Node *k = p;
        Node *bef2 = p;
        Node *q = p->next;
        while (q != NULL)
        {
            if (q->freq > k->freq)
            {
                k = q;
            }
            bef2 = q;
            q = q->next;
        }
        if (k != p)
        {
            Node *tail1 = p;
            Node *tail2 = k;
            bef1->next = k;
            k->next = tail1->next;
            bef2->next = p;
            p->next = tail2->next;
        }
        p = p->next;
    }
}

void LocateElem(List *list, int x)
{
}

void addElem(List *list, int value)
{
    Node *tmp = new Node(value);
    tmp->freq = 10;
    Node *p = list->head->next;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
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

int main()
{
    List *list = new List();
    createSingleLinkedList(list);
    traverse(list);
    printf("==========================\n");
    addElem(list, 11);
    traverse(list);
    sort(list);
    traverse(list);
    return 0;
}