/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-22 14:12:36
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-22 16:29:09
 * @FilePath       : \Tree\5\NumberOff.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
using namespace std;
int n = 0;
int times[4];

void numberOff() 
{
    int num = 0;    /* 表示每一个叫的数 */
    int sumNum = 0; /* 表示总共喊了几个数 */
    while (sumNum < n)
    {
        num++;
        char ch[1024]; /* 用于int 转化为 string */
        sprintf(ch, "%d", num);

        if (num % 7 == 0 || string(ch).find("7") != -1) /* 如果喊的有7或者是7的倍数 */
        {
            times[num % 4]++;
        }
        else
        {
            sumNum++;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 4; ++i)
    {
        times[i] = 0;
    }
    numberOff();
    for (int i = 1; i < 4; i++)
    {
        printf("%d\n", times[i]);
    }
    printf("%d\n", times[0]);

    return 0;
}