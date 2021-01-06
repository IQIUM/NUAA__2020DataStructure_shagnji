/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-10 16:04:57
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-10 16:46:15
 * @FilePath       : \Stack\����2.32\createList.cpp
 */

#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *pre;
    Node *next;
};

struct List
{
    Node *head;
};
/*** 
 * @description: ������ʼ��������
 */
void createSignalList(List *&list)
{
    int count = 0;
    list->head = new Node();
    list->head->data = 0;
    Node *p = list->head;
    while (count < 10)
    {
        count++;
        Node *tmp = new Node();
        tmp->data = count;
        p->next = tmp;
        p = tmp;
    }
    p->next = NULL;
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

/*** 
 * @description: ��list��Ϊÿһ���ڵ����ǰ��
 */
void builDubbleList(List *list)
{
    Node *p = list->head;

    while (p->next != NULL)
    {
        p->next->pre = p;
        p = p->next;
    }
}

/*** 
 * @description: ����˫������
 */
void traverseDubbleList(List *list)
{
    Node *p = list->head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p->data != 0)
    {
        printf("%d ", p->data);
        p = p->pre;
    }
    printf("\n");
}
int main()
{
    List *list = new List();
    printf("ԭ����Ϊ��  \n");
    createSignalList(list);
    traverse(list);
    printf("����˫�������  \n");
    builDubbleList(list);
    traverseDubbleList(list);
    return 0;
}