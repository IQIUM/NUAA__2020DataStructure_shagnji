/*** 
 * @Author         : IQIUM
 * @Date           : 2020-10-23 18:45:00
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-16 15:34:34
 * @FilePath       : \Exercise4\4\BuyTickets.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

int seats[20][6]; /* 座位第一列表示剩下座位的个数 */
    
/* 初始化座位 */
void initSeats()
{
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            seats[i][j] = 0;
        }
        seats[i][0] = 5;
    }
}

/* 分配座位 */
void divideSeats(int num, vector<vector<int> > &choose, int index)
{
    int i = 0;
    for (i = 0; i < 20; ++i)
    {
        if (seats[i][0] >= num) /* 给定座位 */
        {
            int count = 0;
            for (int j = 1; j <= 5 && count < num; ++j)
            {
                if (seats[i][j] == 0)
                {
                    count++;
                    seats[i][j] = 1;
                    choose[index].push_back(i * 5 + j);
                }
            }
            seats[i][0] -= num;
            break;
        }
    }
    if (i == 20) /* 单独寻找座位 */
    {
        for (int i = 0; i < 20; ++i)
        {
            if (seats[i][0] > 0) /* 有座位就做 */
            {
                for (int j = 1; j <= 5 && num > 0; ++j)
                {
                    if (seats[i][j] == 0)
                    {
                        seats[i][j] = 1;
                        num--;
                        choose[index].push_back(i * 5 + j);
                    }
                }
            }
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    initSeats();
    int count = 0;
    vector<vector<int> > choose(n);
    for (int i = 0; i < n; ++i)
    {
        int numPerson = 0;
        scanf("%d", &numPerson);
        divideSeats(numPerson, choose, i);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < choose[i].size(); ++j)
        {
            printf("%d ", choose[i][j]);
        }
        printf("\n");
    }
    return 0;
}