/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-10 20:45:21
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-11 14:34:18
 * @FilePath       : \Stack\addFreq.cpp
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
    Node *p = list->head->next;
    for (int i = 0; i < list->length - 1; i++, p = p->next)
    {
        Node *q = list->head->next;
        for (int j = 0; j < list->length - i - 1; j++, q = q->next)
        {
            if (q->freq < q->next->freq)
            {
                int tmp = q->data;
                q->data = q->next->data;
                q->next->data = tmp;
                int freqTmp = q->freq;
                q->freq = q->next->freq;
                q->next->freq = freqTmp;
            }
        }
    }
}

void LocateElem(List *list, int x)
{
    Node *p = list->head->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            p->freq++;
            sort(list);
            return;
        }
        p = p->next;
    }
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
    printf("访问5：\n");
    LocateElem(list, 5);
    traverse(list);
    printf("访问两次8后：  \n");
    LocateElem(list, 8);
    LocateElem(list, 8);
    traverse(list);
    printf("访问三次10后：  \n");
    for (int i = 0; i < 3; i++)
    {
        LocateElem(list, 10);
    }

    traverse(list);
    return 0;
}