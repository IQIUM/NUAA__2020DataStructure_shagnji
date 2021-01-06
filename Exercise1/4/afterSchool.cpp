#include <cstdio>
#include <cstdlib>

void goNext(long long int &beforeResult, int mode, int time, int r, int y, int g)
{
    int ryg = r + y + g;
    if (mode == 0) /* ��ͨ��· */
    {
        beforeResult += time;       /* �������ͨ��·��ֱ�Ӽ��뵽ʱ���ܺ��� */
    }
    else if (mode == 1) /* ������ʱ���Ǻ�� */
    {
        int i = 0;
        while (1)
        {
            if (beforeResult < time + ryg * i)          /* �жϣ��Ƿ��ߵ����ߵ���ʱ��Ϊ��� */
            {
                beforeResult = time + ryg * i;          /* ����Ǻ�ƣ���Ҫ����ȴ�ʱ�� */
                return;
            }
            if (beforeResult < time + ryg * i + g)      /* �жϣ��Ƿ��ߵ����ߵ���ʱ��Ϊ�̵� */
            {
                return;
            }
            ++i;
        }
    }
    else if (mode == 2) /* �����ʼ��ʱ���ǻƵ� */
    {
        int i = 0;
        while (1)
        {
            if (beforeResult <= time + r + ryg * i)         /* �� ��� ��˼���� */
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
    else if (mode == 3) /* ������ʱ�����̵� */
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