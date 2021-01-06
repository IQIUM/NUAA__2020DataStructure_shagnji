#include <cstdio>
#include <cstdlib>
#define STACKINITSIZE 256
#define STACKINCREMENT 128

class SequentialStack
{
public:
    int *stack;
    int base;
    int top;
    int size;

    /* ջ��ʼ�� */
    void initStack()
    {
        stack = new int[STACKINITSIZE];
        size = STACKINCREMENT;
        base = -1;
        top = -1;
    }

    /* ջ���� */
    void destroyStack()
    {
        if (stack != NULL)
        {
            delete[] stack;
            stack = NULL;
        }
        base = top = size = 0;
    }

    /* ջ��� */
    void clearStack()
    {
        top = base;
    }

    /* ����ջ��Ԫ�� */
    int getTop()
    {
        if (base == top)
        {
            return -1;
        }
        return *(stack + top);
    }

    /* ѹջ */
    void push(int data)
    {
        if (top == size)
        {
            int *tmp = new int[STACKINITSIZE];
            for (int i = 0; i < STACKINITSIZE; ++i)
            {
                *(tmp + i) = *(stack + i);
            }
            delete[] stack;
            stack = new int[STACKINITSIZE + STACKINCREMENT];
            for (int i = 0; i < STACKINITSIZE; ++i)
            {
                *(stack + i) = *(tmp + i);
            }
            delete[] tmp;
            size = STACKINITSIZE + STACKINCREMENT;
        }
        *(stack + ++top) = data;
    }

    /* ��ջ */
    void pop()
    {
        if (base == top)
        {
            return;
        }
        --top;
    }

    /* �ж�ջ�Ƿ�Ϊ�� */
    bool stackEmpty()
    {
        return base == top;
    }

    /* ��ȡջ�ĳ��� */
    int getLength()
    {
        return top - base;
    }

    /* ����ջ */
    void stackTraverse()
    {
        for (int i = 0; i <= top; ++i)
        {
            printf("%d  ", *(stack + i));
        }
        printf("\n");
    }
};

int main()
{
    SequentialStack *stack = new SequentialStack();
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