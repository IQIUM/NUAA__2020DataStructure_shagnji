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
/* ����ڷ����index�к�������Ƿ������������ */
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
    int count = 0; /* ��¼���м��ַŻʺ�ķ��� */
    int index = 1; /* ��Ϊ��n���ʺ������ֵ */
    while (index > 0)
    {
        position[index]++;

        /* Ѱ�ҵ�ǰ�ʺϰڷŵĻʺ��λ��λ�� */
        while (!check(position, index) && position[index] <= num)
        {
            position[index]++;
        }

        /* ���ŵ�λ���Ƿ�Խ�� */
        if (position[index] <= num) /* ���û��Խ�� */
        {
            if (index == num) /* ��ʱ����������һ���ʺ�Ҳ�ҵ��˷ŵ�λ�ã���ô�Ϳ�������� */
            {
                print(position);
                count++;
            }
            else
            {
                ++index;
            }
        }
        else /* ���Խ�磬���� */
        {
            position[index] = 0; /* ����ǰ���õ�ǰ�ʺ� */
            --index;             /* ���ݵ���һ���ʺ� */
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