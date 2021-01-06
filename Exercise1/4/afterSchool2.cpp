#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void goNext(long long int &beforeResult, int mode, long long int time, int r, int y, int g)
{
    int ryg = r + y + g;
    if (mode == 0) /* 普通道路 */
    {
        beforeResult += time;
        return;
    }
    else if (mode == 1) /* 出发的时候是红灯 */
    {
        long long int sum = r - time + beforeResult;
        long long int circleTime = sum % ryg;
        if (circleTime < r)
        {
            beforeResult += r - circleTime;
        }
        else if (circleTime >= g + r)
        {
            beforeResult += ryg - circleTime + r;
        }
    }
    else if (mode == 2) /* 如果初始的时候是黄灯 */
    {
        long long int sum = ryg - time + beforeResult;
        long long int circleTime = sum % ryg;
        if (circleTime < r)
        {
            beforeResult += r - circleTime;
        }
        else if (circleTime >= r + g)
        {
            beforeResult += ryg - circleTime + r;
        }
    }
    else if (mode == 3) /* 出发的时候是绿灯 */
    {
        long long int sum = r + g - time + beforeResult;
        long long int circleTime = sum % ryg;
        if (circleTime < r)
        {
            beforeResult += r - circleTime;
        }
        else if (circleTime >= g + r)
        {
            beforeResult += ryg - circleTime + r;
        }
    }
}

int main()
{
    int r = 0, y = 0, g = 0;
    int n = 0;
    scanf("%d %d %d", &r, &y, &g);
    scanf("%d", &n);
    long long int result = 0;
    for (int i = 0; i < n; ++i)
    {
        int k = 0;
        long long int t = 0;
        cin >> k;
        cin >> t;
        goNext(result, k, t, r, y, g);
    }
    printf("%lld", result);
    return 0;
}
