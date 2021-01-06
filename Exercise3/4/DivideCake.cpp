#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int main()
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    queue<int> cakes;
    for (int i = 0; i < n; ++i)
    {
        int weight = 0;
        scanf("%d", &weight);
        cakes.push(weight);
    }

    int sumWeight = 0;
    int countFriend = 0;
    while (!cakes.empty())
    {
        if (cakes.size() == 1)
        {
            countFriend++;
            break;
        }
        int weight = cakes.front();
        cakes.pop();
        sumWeight += weight;
        if (sumWeight >= k)
        {
            countFriend++;
            sumWeight = 0;
        }
    }
    printf("%d", countFriend);
}