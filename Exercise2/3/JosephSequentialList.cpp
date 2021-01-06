#include <cstdio>
#include <cstdlib>

/* 构建顺序表 */
int *initSequentialList(int n)
{
    int *list = new int[n];

    for (int i = 1; i <= n; ++i)
    {
        *(list + i - 1) = i;
    }

    return list;
}

void Joseph(int *list, int n, int m)
{
    int count = 0;
    int countPersonOut = 0;
    int index = 0;
    /* 将出局者的数值定义为 -1 */
    while (countPersonOut < n - 1)
    {
        if (*(list + index) == -1)
        {
            index++;
            if (index >= n)
            {
                index = 0;
            }
            continue;
        }
        count++;
        if (count == m)
        {
            printf("%d  ", *(list + index));
            *(list + index) = -1;
            countPersonOut++;
            count = 0;
        }
        ++index;
        if (index >= n)
        {
            index = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (*(list + i) != -1)
        {
            printf("%d   ", *(list + i));
            break;
        }
    }
}

int main()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int *list = initSequentialList(n);
    Joseph(list, n, m);
}