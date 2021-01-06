#include <cstdio>
#include <cstdlib>
#include <cmath>
class Section
{
public:
    int start;
    int end;
};

/* 计算是否有共同区间 */
bool isCommonSection(Section s1, Section s2)
{
    return (s1.start <= s2.start && s1.end > s2.start) || (s2.start <= s1.start && s2.end > s1.start);
}

/* 取公共区间 */
int getCommonSection(Section s1, Section s2)
{
    int sum = s1.end - s1.start + s2.end - s2.start;
    int sum1 = 0;
    if (s1.end > s2.end)
    {
        if (s1.start < s2.start)
        {
            sum1 = s1.end - s1.start;
        }
        else
        {
            sum1 = s1.end - s2.start;
        }
    }
    else
    {
        if (s1.start < s2.start)
        {
            sum1 = s2.end - s1.start;
        }
        else
        {
            sum1 = s2.end - s2.start;
        }
    }

    return sum - sum1;
}

int CalCommonSection(Section *xh, Section *xw, int n)
{
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (isCommonSection(*(xh + i), *(xw + j))) /* 如果二者有共同区间 */
            {
                result += getCommonSection(*(xh + i), *(xw + j));
            }
        }
    }
    return result;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    Section *xh = new Section[n];
    Section *xw = new Section[n];
    for (int i = 0; i < n; ++i)
    {
        int start = 0, end = 0;
        scanf("%d %d", &start, &end);
        (xh + i)->start = start;
        (xh + i)->end = end;
    }

    for (int i = 0; i < n; ++i)
    {
        int start = 0, end = 0;
        scanf("%d %d", &start, &end);
        (xw + i)->start = start;
        (xw + i)->end = end;
    }

    int result = CalCommonSection(xh, xw, n);
    printf("%d\n", result);
}