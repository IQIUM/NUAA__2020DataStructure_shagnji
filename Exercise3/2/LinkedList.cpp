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

    /* ��ջ��ѹ��5��Ԫ�� */
    stack->push(10);
    stack->push(11);
    stack->push(20);
    stack->push(33);
    stack->push(29);
    /* ��ȡջ���Ȳ����� */
    printf("ջ�ĳ���Ϊ�� %d\n", stack->getLength());
    stack->stackTraverse();

    /* ��ȡջ��Ԫ�ز����������� */
    printf("ջ��Ԫ��Ϊ��  %d\n", stack->getTop());
    stack->pop();
    stack->pop();
    stack->pop();
    printf("�������������ջ��ջ��Ԫ��Ϊ�� %d\n", stack->getTop());

    /* ���ٲ��� */
    printf("����ջ��������\n");
    stack->destroyStack();
    printf("��ʱջ�ĳ���Ϊ�� %d\n", stack->getLength());
    printf("��ʱջ�Ƿ�Ϊ�գ�   %s", stack->stackEmpty() ? "��" : "��");

    return 0;
}