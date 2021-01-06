/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-17 17:10:00
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-17 17:43:52
 * @FilePath       : \Exercise4\3.28\initQueue.cpp
 */
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() {}
    Node(int data) : data(data) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

typedef struct list
{
    Node *head;
    int length;
} Queue;

void initQueue(Queue *&q)
{
    q->head = new Node(0);
    q->length = 0;
    q->head->next = q->head;
}

/* ����в��� */
void enterQueue(Queue *&queue, int num)
{
    Node *p = queue->head;
    int count = 0;
    while (count < queue->length)
    {
        p = p->next;
        ++count;
    }
    Node *tmp = new Node(num);
    p->next = tmp;
    tmp->next = queue->head->next;
    queue->length++;
}

/* �����в��� */
int popQueue(Queue *&queue)
{
    Node *p = queue->head;
    int count = 0;
    while (count < queue->length - 1)
    {
        p = p->next;
        ++count;
    }
    Node *q = p->next;
    p->next = queue->head->next;

    int num = q->data;
    delete q;
    queue->length--;
    return num;
}

/* �������� */
void traverse(Queue *queue)
{
    Node *p = queue->head;
    int count = 0;
    while (count < queue->length)
    {
        p = p->next;
        ++count;
        printf("%d  ", p->data);
    }
    printf("\n");
}

int main()
{
    Queue *queue = new Queue();
    initQueue(queue);
    for (int i = 1; i <= 5; i++)
    {
        printf("%d��Ӻ�Ķ���Ϊ��  ", i);
        enterQueue(queue, i);
        traverse(queue);
    }
    printf("===============================================\n");
    for (int i = 0; i < 5; i++)
    {
        printf("����Ԫ��Ϊ��%d  ", popQueue(queue));
        printf("��ʱ����Ϊ�� ");
        traverse(queue);
    }

    delete queue;

    return 0;
}