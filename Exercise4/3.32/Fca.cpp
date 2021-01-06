/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-17 17:57:00
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-21 14:23:14
 * @FilePath       : \Exercise4\3.32\Fca.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Queue
{
public:
    int k; /* 循环队列的容量 */
    int *arr;
    int front;
    int wear;

    Queue(int k) : k(k), front(0), wear(0)
    {
        arr = new int[k + 1];
    }
    void push(int value) /* 队列push函数 */
    {
        arr[wear] = value;

        wear = (wear + 1) % k;
        if (wear == front)
        {
            front = (front + 1) % k;
        }
    }
};

/*** 
 * @description: 遍历队列
 */
void traverse(Queue *que)
{
    int index = que->wear;
    while (index != (que->wear + que->k - 1) % (que->k))
    {
        printf("%d ", que->arr[index]);
        index = (index + 1) % (que->k);
    }
    printf("%d ", que->arr[index]);
}

void calFac(int k, int max, Queue *que)
{
    int index = 1;
    int value = 0;
    while (value <= max)
    {
        if (index <= k)
        {
            que->push(index < k ? 0 : 1);
            index++;
        }
        else
        {
            /* 后面的值就是整个循环队列的值 */
            value = 0;
            for (int i = 0; i < que->k; i++)
            {
                value += que->arr[i];
            }
            que->push(value);
            index++;
        }
    }
}

int main()
{
    int k = 0;
    printf("请输入K阶斐波那契数列的k的值：  ");
    scanf("%d", &k);
    int max = 0;
    printf("请输入max的值：  ");
    scanf("%d", &max);

    Queue *que = new Queue(k);
    calFac(k, max, que);
    traverse(que);
    return 0;
}