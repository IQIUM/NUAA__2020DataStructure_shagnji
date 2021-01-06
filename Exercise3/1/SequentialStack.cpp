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

    /* 栈初始化 */
    void initStack()
    {
        stack = new int[STACKINITSIZE];
        size = STACKINCREMENT;
        base = -1;
        top = -1;
    }

    /* 栈销毁 */
    void destroyStack()
    {
        if (stack != NULL)
        {
            delete[] stack;
            stack = NULL;
        }
        base = top = size = 0;
    }

    /* 栈清空 */
    void clearStack()
    {
        top = base;
    }

    /* 访问栈顶元素 */
    int getTop()
    {
        if (base == top)
        {
            return -1;
        }
        return *(stack + top);
    }

    /* 压栈 */
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

    /* 弹栈 */
    void pop()
    {
        if (base == top)
        {
            return;
        }
        --top;
    }

    /* 判断栈是否为空 */
    bool stackEmpty()
    {
        return base == top;
    }

    /* 获取栈的长度 */
    int getLength()
    {
        return top - base;
    }

    /* 遍历栈 */
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