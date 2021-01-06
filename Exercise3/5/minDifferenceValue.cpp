#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
/* 获取最小差值 */
int getMinDifferenceValue(int *num, int n)
{
    int minDV = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (abs(*(num + i) - *(num + j)) < minDV)
            {
                minDV = abs(*(num + i) - *(num + j));
            }
        }
    }
    return minDV;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int *num = new int[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", num + i);
    }
    int result = getMinDifferenceValue(num, n);
    printf("%d", result);
    return 0;
}