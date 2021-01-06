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

/* ʹ��˳��ṹ����˳��� */
/* ��˳����д���MAXSIE�����ֵ */
void initSequential(int *&list)
{
    srand((int)time(0));
    list = new int[MAXSIZE];
    /* ��˳����д洢MAXSIZE���� */
    for (int i = 0; i < MAXSIZE; ++i)
    {
        *(list + i) = random(100);
    }
}

/* ѡ������ */
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
        if (k != i) /* ���� */
        {
            int &a = *(list + k);
            int &b = *(list + i);
            a = a ^ b;
            b = b ^ a;
            a = a ^ b;
        }
    }
}

/* ð������ */
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
    printf("ԭ˳���Ϊ�� \n");
    traverse(array);
    printf("===========================================\n");
    printf("ͨ��ѡ��������˳��� \n");
    selectionSort(array);
    traverse(array);
    /* printf("===========================================\n");
    printf("ͨ��ð��������˳��� \n");
    bubbuleSort(array);
    traverse(array); */

    return 0;
}