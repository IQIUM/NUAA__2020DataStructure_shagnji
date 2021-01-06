/*** 
 * @Author         : IQIUM
 * @Date           : 2020-10-25 15:56:54
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-09 08:51:27
 * @FilePath       : \Stack\3\EightQuene1.cpp
 */

#include <cstdio>
#include <cstdlib>
#define num 4
static int count = 0;
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

void slove(int position[], int index)
{
    if (index > num)
    {
        print(position);
        ++count;
        return;
    }
    position[index]++;
    while (!check(position, index) && position[index] <= num)
    {
        position[index]++;
    }
    if (position[index] <= num)
    {
        slove(position, ++index);
    }
    else
    {
        position[index] = 0;
        slove(position, --index);
    }
}

int main()
{
    int position[num + 1];
    for (int i = 1; i < num + 1; ++i)
    {
        for (int j = 0; j < num + 1; j++)
        {
            position[j] = 0;
        }

        slove(position, i);
    }
    return 0;
}