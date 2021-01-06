/*
 * @Author: IQIUM
 * @Date: 2020-10-22 16:04:07
 * @LastEditors: IQIUM
 * @LastEditTime: 2020-11-02 08:32:04
 * @FilePath: \List2\1\SequentialList.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <time.h>
#define random(x) (rand() % x)
#define MAXSIZE 10

/* 使用顺序结构构建顺序表 */
/* 往顺序表中存入MAXSIE个随机值 */
void initSequential(int *&list)
{
    srand((int)time(0));
    list = new int[MAXSIZE];
    /* 往顺序表中存储MAXSIZE个数 */
    for (int i = 0; i < MAXSIZE; ++i)
    {
        *(list + i) = random(100);
    }
}

/* 选择排序 */
void selectionSort(int *&list)
{
    for (int i = 0; i < MAXSIZE - 1; ++i)
    {
        int k = i;
        for (int j = k + 1; j < MAXSIZE; ++j)
        {
            if (*(list + j) < *(list + k))
            {
                k = j;
            }
        }
        if (k != i) /* 交换 */
        {
            int &a = *(list + k);
            int &b = *(list + i);
            a = a ^ b;
            b = b ^ a;
            a = a ^ b;
        }
    }
}

/* 冒泡排序 */
void bubbuleSort(int *list)
{
    for (int i = 0; i < MAXSIZE - 1; ++i)
    {
        for (int j = 0; j < MAXSIZE - i - 1; ++j)
        {
            if (*(list + j) > *(list + j + 1))
            {
                int &a = *(list + j);
                int &b = *(list + j + 1);
                a = a ^ b;
                b = b ^ a;
                a = a ^ b;
            }
        }
    }
}

void traverse(int *list)
{
    for (int i = 0; i < MAXSIZE; ++i)
    {
        printf("%d\t", *(list + i));
    }
    printf("\n");
}

int main()
{
    int *array = NULL;
    initSequential(array);
    printf("原顺序表为： \n");
    traverse(array);
    printf("===========================================\n");
    printf("通过选择排序后的顺序表： \n");
    selectionSort(array);
    traverse(array);
    /* printf("===========================================\n");
    printf("通过冒泡排序后的顺序表： \n");
    bubbuleSort(array);
    traverse(array); */

    return 0;
}