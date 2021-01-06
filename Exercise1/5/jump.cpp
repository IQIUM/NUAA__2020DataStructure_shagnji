#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int calScore(queue<int> &q)
{
    int result = 0;
    int count = 0; /* 记录2连续出现的次数 */
    while (1)
    {
        int cur = q.front();
        q.pop();
        if (cur == 0)
        {
            break;
        }
        else if (cur == 1)
        {
            result++;
            count = 0;
        }
        else if (cur == 2)
        {
            count++;
            result += 2 * count;
        }
    }

    return result;
}

int main()
{
    int num = -1;
    queue<int> q;
    do
    {
        scanf("%d ", &num);
        q.push(num);
        if (num == 0)
        {
            break;
        }
    } while (1);
    int result = calScore(q);
    printf("%d", result);
    return 0;
}