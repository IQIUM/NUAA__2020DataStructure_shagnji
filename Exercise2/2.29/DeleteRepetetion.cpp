/*
 * @Author: IQIUM
 * @Date: 2020-10-22 16:04:07
 * @LastEditors: IQIUM
 * @LastEditTime: 2020-11-03 16:56:27
 * @FilePath: \List2\2.29\DeleteRepetetion.cpp
 */
#include <cstdio>
#include <cstdlib>

int deleteRepetition(int *arrayA, int *arrayB, int *arrayC, bool *flags, int lengthA, int lengthB, int lengthC)
{
    for (int i = 0; i < lengthA; i++)
    {
        bool flag = false;
        for (int j = 0; j < lengthB; j++)
        {
            if (arrayB[j] == arrayA[i])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            for (int j = 0; j < lengthC; j++)
            {
                if (arrayC[j] == arrayA[i])
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
        {
            flags[i] = true;
        }
    }
    int count = 0;
    for (int i = 0; i < lengthA; ++i)
    {
        if (!flags[i])
        {
            count++;
        }
    }

    return count;
}

void traverse(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d  ", *(array + i));
    }
    printf("\n");
}

int main()
{
    int *arrayA = new int[10];
    for (int i = 0; i < 10; i++)
    {
        *(arrayA + i) = i + 1;
    }
    printf("数组A为： \n");
    traverse(arrayA, 10);
    int *arrayB = new int[4];
    for (int i = 0; i < 4; i++)
    {
        *(arrayB + i) = i + 4;
    }
    printf("数组B为： \n");
    traverse(arrayB, 4);
    int *arrayC = new int[3];
    *(arrayC + 0) = 5;
    *(arrayC + 1) = 7;
    *(arrayC + 2) = 10;

    printf("数组C为： \n");
    traverse(arrayC, 3);
    bool *flags = new bool[10];
    for (int i = 0; i < 10; i++)
    {
        flags[i] = false;
    }
    int count = deleteRepetition(arrayA, arrayB, arrayC, flags, 10, 4, 3);
    int *tmp = new int[count];
    int curIndex = 0;
    for (int i = 0; i < 10; i++)
    {
        if (!flags[i])
        {
            tmp[curIndex++] = arrayA[i];
        }
    }

    delete[] arrayA;
    arrayA = tmp;
    tmp = NULL;
    printf("A - B ∩ C后的A为：  \n ");
    for (int i = 0; i < count; i++)
    {
        printf("%d  ", arrayA[i]);
    }
    return 0;
}