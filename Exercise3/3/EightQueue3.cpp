/*** 
 * @Author         : IQIUM
 * @Date           : 2020-10-25 19:27:10
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-09 14:21:22
 * @FilePath       : \Stack\3\EightQueue3.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define num 8
/* 检查在放入第index行后的数据是否可以满足条件 */
bool check(int position[], int index)
{
    for (int i = 1; i < index; ++i)
    {
        if (position[i] == position[index] || abs(index - i) == abs(position[index] - position[i]))
        {
            return false;
        }
    }
    return true;
}

void print(int position[])
{
    for (int i = 1; i < num + 1; ++i)
    {
        printf("%d  ", position[i]);
    }
    printf("\n");
}

void slove(int position[])
{
    int count = 0; /* 记录共有几种放皇后的方法 */
    int index = 1; /* 作为第n个皇后的索引值 */
    while (index > 0)
    {
        position[index]++;

        /* 寻找当前适合摆放的皇后的位置位置 */
        while (!check(position, index) && position[index] <= num)
        {
            position[index]++;
        }

        /* 检查放的位置是否越界 */
        if (position[index] <= num) /* 如果没有越界 */
        {
            if (index == num) /* 此时的情况是最后一个皇后也找到了放的位置，那么就可以输出了 */
            {
                print(position);
                count++;
            }
            else
            {
                ++index;
            }
        }
        else /* 如果越界，回溯 */
        {
            position[index] = 0; /* 回溯前重置当前皇后 */
            --index;             /* 回溯到上一个皇后 */
        }
    }
    printf("%d\n", count);
}

int main()
{
    int position[num + 1];
    for (int i = 0; i < num + 1; ++i)
    {
        position[i] = 0;
    }
    slove(position);
    return 0;
}