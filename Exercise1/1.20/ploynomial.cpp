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
    int n = 0; /* ����ʽ��ߵĴ��� */
    printf("���������ʽ����ߴ�����  ");
    scanf("%d", &n);
    printf("�����������������ʽ�ӵ�ϵ����");
    int *ploynomial = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", ploynomial + i);
    }
    printf("��������������x��ֵ��  ");
    int x = 0;
    scanf("%d", &x);

    int result = calPolynomial(ploynomial, n, x);
    printf("����ʽ����Ľ��Ϊ��  ");
    printf("%d", result);
    return 0;
}