#include <cstdio>
#include <cstdlib>

class Node
{
public:
    Node(int data = 0) : data(data), next(NULL) {}
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    int length;
    void initStack()
    {
        head = new Node();
        length = 0;
    }
    void destroyStack()
    {
        Node *p = head;
        Node *q = head->next;
        while (q != NULL)
        {
            Node *tmp = q;
            p->next = q->next;
            q = q->next;
            delete tmp;
            tmp = NULL;
        }
        length = 0;
    }
    void clearStack()
    {
        head->next = NULL;
        length = 0;
    }
    int getTop()
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        return p->data;
    }
    void push(int data)
    {
        Node *tmp = new Node(data);
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
        length++;
    }
    void pop()
    {
        Node *p = head;
        Node *q = head->next;
        while (q->next != NULL)
        {
            p = q;
            q = q->next;
        }

        p->next = NULL;
        length--;
        delete q;
        q = NULL;
    }
    bool stackEmpty()
    {
        return length == 0;
    }
    void stackTraverse()
    {
        Node *p = head->next;
        while (p != NULL)
        {
            printf("%d  ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    int getLength()
    {
        return length;
    }
};

int main()
{
    LinkedList *stack = new LinkedList();
    stack->initStack();

    /* 往栈中压入5个元素 */
    stack->push(10);
    stack->push(11);
    stack->push(20);
    stack->push(33);
    stack->push(29);
    /* 获取栈长度并遍历 */
    printf("栈的长度为： %d\n", stack->getLength());
    stack->stackTraverse();

    /* 获取栈顶元素并弹出三个数 */
    printf("栈顶元素为：  %d\n", stack->getTop());
    stack->pop();
    stack->pop();
    stack->pop();
    printf("弹出三个数后的栈的栈顶元素为： %d\n", stack->getTop());

    /* 销毁操作 */
    printf("销毁栈！！！！\n");
    stack->destroyStack();
    printf("此时栈的长度为： %d\n", stack->getLength());
    printf("此时栈是否为空？   %s", stack->stackEmpty() ? "是" : "否");

    return 0;
}