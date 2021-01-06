#include <cstdio>
#include <cstdlib>

class Node
{
public:
    int data;
    Node *next;

    Node(int data = 0, Node *next = NULL);
    ~Node();
};

Node::Node(int data, Node *next) : data(data), next(next)
{
}

Node::~Node()
{
}

class List
{
public:
    List();
    ~List();
    void initList();

    Node *head;
};

List::List()
{
    head = new Node();
}

List::~List()
{
}

void List::initList()
{
    Node *p = head;
    int count = 0;
    while (count < 10)
    {
        Node *tmp = new Node(count + 1);
        p->next = tmp;
        p = tmp;
        count++;
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

void createList1(List *list)
{
    Node *p = list->head;
    int num = 4;
    while (num < 7)
    {
        Node *tmp = new Node(num);
        p->next = tmp;
        p = tmp;
        num++;
    }
}

void createList2(List *list)
{
    Node *p = list->head;
    int num = 9;
    while (num < 12)
    {
        Node *tmp = new Node(num);
        p->next = tmp;
        p = tmp;
        num++;
    }
}

void deleteRepetition(List *list, List *list1, List *list2)
{
    Node *bef = list->head;
    Node *p = list->head->next;
    Node *k = list2->head->next;
    while (p != NULL)
    {
        bool flag = false;
        int curValue = p->data;
        Node *q = list1->head->next;
        while (q != NULL)
        {
            if (q->data == curValue)
            {
                flag = true;
                break;
            }
            q = q->next;
        }
        if (flag) /* 删除当前节点 */
        {
            Node *tmp = p;
            bef->next = p->next;
            p = p->next;
            delete tmp;
            tmp = NULL;
        }
        else
        {
            bef = p;
            p = p->next;
        }
    }
    p = list->head->next;
    while (p != NULL)
    {
        bool flag = false;
        int curValue = p->data;
        Node *k = list2->head->next;
        while (k != NULL)
        {
            if (k->data == curValue)
            {
                flag = true;
                break;
            }
            k = k->next;
        }
        if (flag) /* 删除当前节点 */
        {
            Node *tmp = p;
            bef->next = p->next;
            p = p->next;
            delete tmp;
            tmp = NULL;
        }
        else
        {
            bef = p;
            p = p->next;
        }
    }
}

int main()
{
    List *list = new List();
    /* 构建链表1 */
    list->initList();
    printf("原来的链表为：  \n");
    traverse(list);
    printf("=====================================================\n");
    /* 构建重复链表2 */
    List *list1 = new List();
    List *list2 = new List();
    createList1(list1);
    createList2(list2);
    printf("链表list1为：   \n");
    traverse(list1);
    printf("链表list1为：   \n");
    traverse(list2);
    printf("=====================================================\n");
    printf("删除后的链表为:   \n");
    deleteRepetition(list, list1, list2);
    traverse(list);
    return 0;
}