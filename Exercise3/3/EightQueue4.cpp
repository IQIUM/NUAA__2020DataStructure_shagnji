/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-08 20:49:27
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-09 23:22:31
 * @FilePath       : \Stack\3\EightQueue4.cpp
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const int num = 8;
int solutionNum = 0;

class Stack
{
public:
    Stack();
    ~Stack();
    void push(int pos);
    void pop();
    int getTop(); /* ��ȡջ��Ԫ�� */
    int length;
    int *data;
    int top;
};

Stack::Stack()
{
    data = new int[num + 1];
    for (int i = 0; i < num + 1; i++)
    {
        data[i] = 0;
    }

    top = -1;
    length = 0;
}

Stack::~Stack()
{
}

void Stack::push(int pos)
{
    data[++top] = pos;
    length++;
}
void Stack::pop()
{
    data[top--] = 0;
    length--;
}
int Stack::getTop()
{
    if (top == -1)
    {
        return -1;
    }
    return data[top];
}
Stack *stack = new Stack();

/*** 
 * @description: �жϵ�ǰҪ�ŵĻʺ��Ƿ���֮ǰ�Ļʺ��ͻ 
 */
bool conflict(int index)
{
    for (int i = 1; i < index; i++)
    {
        if (stack->data[i] == stack->data[index] || abs(index - i) == abs(stack->data[i] - stack->data[index]))
        {
            return false;
        }
    }
    return false;
}

void print()
{
    for (int i = 1; i <= num; i++)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void solve()
{
    int index = 1;
    while (index > 0)
    {
        int position = (index == 1) ? 1 : stack->getTop();

        while (conflict(index) && stack->data[index] <= num)
        {
            stack->data[index]++;
        }
        if (stack->data[index] <= num)
        {
            if (index == num)
            {
                print();
                solutionNum++;
            }
            else
            {
                ++index;
            }
        }
        else
        {
            stack->data[index] = 0;
            --index;
        }
    }
}

void solve(int index)
{
    for (int i = 1; i <= num; ++i)
    {
    }
    
}

int main()
{
    solve();

    printf("��������Ľ������ %d ��", solutionNum);
    return 0;
}