#include <bits/stdc++.h>
using namespace std;
int a[1002][1002];
int b[1002];
int counter[1002];
int main()
{
    int n;
    long long sum0 = 0, sum1 = 0, counter1, counter2 = 0, counter3 = 0;
    cin >> n;           /* n表示苹果数量 */
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        for (int j = 0; j < b[i]; j++)
        {
            cin >> a[i][j + 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum1 = a[i][1];
        counter1 = 0;
        for (int j = 2; j <= b[i]; j++)
        {
            if (a[i][j] <= 0)
            {
                sum1 += a[i][j];
            }
            else
            {
                if (sum1 > a[i][j])
                {
                    (counter1 == 1) ? (counter1 = counter1) : (counter1++);
                    counter[i] = 1;
                }
                else
                {
                    counter[i] = 0;
                }
                sum1 = a[i][j];
            }
        }
        counter3 += counter1;
        sum0 += sum1;
    }
    if (n >= 3)
        for (int i = 0; i < n; i++)
            ((counter[((i - 1) + n) % n] == 1) && (counter[(i + n) % n] == 1) && (counter[(i + 1 + n) % n]) == 1) ? (counter2++) : (counter2 = counter2);
    cout << sum0 << " " << counter3 << " " << counter2;
}