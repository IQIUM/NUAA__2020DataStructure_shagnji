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
    int num = 0;    /* ��ʾÿһ���е��� */
    int sumNum = 0; /* ��ʾ�ܹ����˼����� */
    while (sumNum < n)
    {
        num++;
        char ch[1024]; /* ����int ת��Ϊ string */
        sprintf(ch, "%d", num);

        if (num % 7 == 0 || string(ch).find("7") != -1) /* ���������7������7�ı��� */
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