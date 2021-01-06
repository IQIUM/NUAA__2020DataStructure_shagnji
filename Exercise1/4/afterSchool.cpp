#include <cstdio>
#include <cstdlib>

void goNext(long long int &beforeResult, int mode, int time, int r, int y, int g)
{
    int ryg = r + y + g;
    if (mode == 0) /* 普通道路 */
    {
        beforeResult += time;       /* 如果是普通道路，直接加入到时间总和中 */
    }
    else if (mode == 1) /* 出发的时候是红灯 */
    {
        int i = 0;
        while (1)
        {
            if (beforeResult < time + ryg * i)          /* 判断，是否走到且走到的时候为红灯 */
            {
                beforeResult = time + ryg * i;          /* 如果是红灯，需要加入等待时间 */
                return;
            }
            if (beforeResult < time + ryg * i + g)      /* 判断，是否走到且走到的时候为绿灯 */
            {
                return;
            }
            ++i;
        }
    }
    else if (mode == 2) /* 如果初始的时候是黄灯 */
    {
        int i = 0;
        while (1)
        {
            if (beforeResult <= time + r + ryg * i)         /* 与 红灯 意思相似 */
            {
                beforeResult = time + r + ryg * i;
                return;
            }
            if (beforeResult <= time + r + g + ryg * i)
            {
                return;
            }
            ++i;
        }
    }
    else if (mode == 3) /* 出发的时候是绿灯 */
    {
        int i = 0;
        while (1)
        {
            if (beforeResult <= time + ryg * i)
            {
                return;
            }
            if (beforeResult <= time + y + r + ryg * i)
            {
                beforeResult = time + y + r + ryg * i;
                return;
            }
            ++i;
        }
    }
}

int main()
{
    int r = 0, y = 0, g = 0;
    long long int n = 0;
    scanf("%d %d %d", &r, &y, &g);
    scanf("%lld", &n);
    long long int result = 0;
    for (long long int i = 0; i < n; ++i)
    {
        int k = 0, t = 0;
        scanf("%d %d", &k, &t);
        goNext(result, k, t, r, y, g);
    }
    printf("%d", result);
    return 0;
}