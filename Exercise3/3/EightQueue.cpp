/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-09 23:23:14
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-10 13:50:04
 * @FilePath       : \Stack\3\EightQueue.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int num = 8;
int solutionNum = 0;
class Stack
{
public:
    Stack();
    ~Stack();
    void push(int pos);
    void pop();
    int getTop(); /* 获取栈顶元素 */
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

    top = 0;
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
    return data[top];
}

Stack *stack = new Stack();

/* 判断当前位置是否与栈中其它元素冲突 */
/* j 表示当前皇后可能坐的位置 */
bool isConflict(int index, int j)
{
    for (int i = 1; i < index; i++)
    {
        if (stack->data[i] == j || abs(index - i) == abs(stack->data[i] - j))
        {
            return true;
        }
    }
    return false;
}

void print()
{
    for (int i = 1; i <= num; i++)
    {
        printf("%d  ", stack->data[i]);
    }
    printf("\n");
}

void Solution(int index)
{
    if (index > num)
    {
        print();
        solutionNum++;
        return;
    }
    for (int i = 1; i <= num; i++)
    {
        if (!isConflict(index, i))
        {
            stack->push(i);
            Solution(index + 1);
            stack->pop();
        }
    }
}

int main()
{
    Solution(1);
    printf("最终共有 %d 种结果.\n", solutionNum);
    return 0;
}