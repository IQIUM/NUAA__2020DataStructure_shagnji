#include <cstdio>
#include <cstdlib>

int calPolynomial(int *ploynoimal, int n, int x)
{
    int count = 0;
    int result = 0;

    for (int i = 0; i <= n; i++)
    {
        int tmp = 1;
        for (int j = 1; j <= i; ++j)
        {
            tmp *= x;
            count++;
        }
        result += *(ploynoimal + i) * tmp;
    }

    return result;
}

int main()
{
    int n = 0; /* 多项式最高的次数 */
    printf("请输入多项式的最高次数：  ");
    scanf("%d", &n);
    printf("请依次输入各个次数式子的系数：");
    int *ploynomial = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", ploynomial + i);
    }
    printf("请输入你想代入的x的值：  ");
    int x = 0;
    scanf("%d", &x);

    int result = calPolynomial(ploynomial, n, x);
    printf("多项式计算的结果为：  ");
    printf("%d", result);
    return 0;
}