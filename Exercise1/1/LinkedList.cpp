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
    Node *curNode;
    int length;
};

bool insertElemAfterCurNode(List &list, int ele);

/* 单链表的初始化 */
bool InitList(List &list)
{
    list.head = new Node();
    list.curNode = list.head;
    list.length = 0;
    return true;
}

/* 链表的创建 */
bool createList(List &list)
{
    insertElemAfterCurNode(list, 6);
    insertElemAfterCurNode(list, 7);
    insertElemAfterCurNode(list, 8);
    insertElemAfterCurNode(list, 9);
    insertElemAfterCurNode(list, 10);
}

/* 单链表的销毁 */
bool destroyList(List &list)
{
    Node *p = list.head;
    while (list.head->next != NULL)
    {
        p = list.head->next;
        list.head->next = p->next;
        delete p;
    }
    delete list.head;
    list.head = NULL;
    list.curNode = NULL;
    list.length = 0;
    return true;
}

/* 清空链表 */
bool clearList(List &list)
{
    list.length = 0;
    return true;
}

/* 判断链表是否为空 */
bool isEmpty(List &list)
{
    return list.length == 0;
}

/* 获取链表的长度 */
int getListLength(List &list)
{
    return list.length;
}

/* 单链表元素的获取：寻找链表第index个元素并存入到ele中 */
bool getElement(List &list, int index, int &ele)
{
    if (index < 1 || index > list.length)
    {
        return false;
    }
    Node *p = list.head;
    int j = 0;
    while (j < index)
    {
        p = p->next;
        ++j;
    }
    ele = p->data;
    list.curNode = p;
    return true;
}

/* 找到参数ele在链表中的位置 */
int loacteElement(List &list, int &ele)
{
    Node *p = list.head;
    int i = 0;

    while (p->next != NULL)
    {
        p = p->next;
        ++i;
        if (p->data == ele)
        {
            return i;
        }
    }
    return -1;
}

/* 找到链表顶点ele的前驱元素 */
bool getPriorElement(List &list, int ele, int &pre)
{
    /* 如果链表只有一个数据，以空返回 */
    if (list.length <= 1)
    {
        return false;
    }

    Node *p = list.head;
    Node *q = p->next;

    while (q != NULL)
    {
        if (q->data == ele)
        {
            pre = p->data;
            return true;
        }
        p = q;
        q = p->next;
    }
    return false;
}

/* 找到链表顶点ele的后驱元素 */
bool getNextElement(List &list, int ele, int &next)
{
    Node *q = list.head->next;

    while (q != NULL)
    {
        if (q->data == ele)
        {
            if (q->next != NULL)
            {
                next = q->next->data;
                return true;
            }
        }
        q = q->next;
    }
    return false;
}

/* 遍历链表 */
void traverse(List &list)
{
    Node *p = list.head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int getCurNode(List &list)
{
    return list.curNode->data;
}

/* 将链表中第index个元素替换为ele */
bool setElement(List &list, int index, int ele)
{
    if (index < 1 || index > list.length)
    {
        return false;
    }
    Node *p = list.head->next;
    int i = 1;
    while (i < index)
    {
        p = p->next;
        ++i;
    }
    p->data = ele;
    return true;
}

/* 在单链表的当前节点后插入新节点 */
bool insertElemAfterCurNode(List &list, int ele)
{
    Node *tmp = new Node(ele);
    tmp->next = list.curNode->next;
    list.curNode->next = tmp;
    list.length++;
    return true;
}

/* 在单链表当前节点后删除后续节点，并放入e中 */
bool deleteElemAfterNode(List &list, int &e)
{
    if (list.curNode->next == NULL)
    {
        return false;
    }
    e = list.curNode->next->data;
    Node *tmp = list.curNode->next;
    list.curNode->next = tmp->next;
    delete tmp;
    tmp = NULL;
    list.length--;
    return true;
}

int main()
{
    List list;

    printf("单链表初始化和创建： ");
    InitList(list);
    createList(list);
    traverse(list);

    printf("获取位置为3的数： ");
    int ele = 0;
    getElement(list, 3, ele);
    printf("%d\n", ele);

    printf("获取链表长度: %d\n", getListLength(list));

    int pre = 0, next = 0;
    getPriorElement(list, 8, pre);
    getNextElement(list, 8, next);
    printf("获取8前一个数和后一个数： %d 和 %d \n", pre, next);

    printf("当前节点为： %d \n", getCurNode(list));

    printf("在当前节点后插入-1: ");
    insertElemAfterCurNode(list, -1);
    traverse(list);

    printf("删除当前节点之后的节点： ");
    int delNum = 9;
    deleteElemAfterNode(list, delNum);
    traverse(list);

    printf("销毁链表!!! \n");
    destroyList(list);
    printf("链表是否为空？: ");
    if (isEmpty)
    {
        printf("为空！！！\n");
    }
    else
    {
        printf("不为空！！！\n");
    }
    return 0;
}