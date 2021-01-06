/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-25 12:46:25
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-25 19:44:45
 * @FilePath       : \Exercise6\5\tetris.cpp
 */
#include <cstdio>
#include <cstdlib>
using namespace std;

int matrix[18][10];
int diamonds[4][4];
int col = -1;
int row = 0;

/* 下移函数 */
void downMove()
{
    for (int i = row + 3; i >= row; --i)
    {
        for (int j = col - 1; j < col + 3; j++)
        {
            if (matrix[i][j] == 1) /* 值为1的数开始下移 */
            {
                matrix[i + 1][j] = 1;
                matrix[i][j] = 0;
            }
        }
    }
    row++;
}

void initMove()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][col + j - 1] = diamonds[i][j];
        }
    }
}

bool isConfict()
{
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (diamonds[i][j] == 1)
            {
                if (matrix[row + i + 1][col - 1 + j] == 2)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void traverse()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void change()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][j] = 2;
            }
        }
    }
}

bool groosy()
{
    for (int i = col - 1; i < col + 3; i++)
    {
        if (matrix[14][i] == 1)
        {
            return true;
        }
    }
    return false;
}

void returnChange()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matrix[i][j] == 2)
            {
                matrix[i][j] = 1;
            }
        }
    }
}

void Tetris()
{
    change();
    initMove();
    while (1)
    {
        if (isConfict() || groosy())
        {
            returnChange();
            return;
        }
        else
        {
            downMove();
        }
    }
}

int main()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 15; i < 18; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &diamonds[i][j]);
        }
    }
    scanf("%d", &col);
    Tetris();
    traverse();
    system("pause");
    return 0;
}