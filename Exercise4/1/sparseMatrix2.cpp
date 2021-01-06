/*** 
 * @Author         : IQIUM
 * @Date           : 2020-10-26 08:12:23
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-14 21:42:18
 * @FilePath       : \Exercise4\1\sparseMatrix2.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
const int MAXSIZE = 100;
class SparseMatrix;
using namespace std;
int cols = 0;
int rows = 0;

class Triple
{
public:
    int i;
    int j;
    int value;
    friend ostream &operator<<(ostream &cout, Triple &tri);
};

class SparseMatrix
{
public:
    SparseMatrix() : num(0) {}
    Triple arr[MAXSIZE];
    int num; /* 非零元素的个数 */
};

SparseMatrix *spMatrix = new SparseMatrix();

ostream &operator<<(ostream &cout, Triple &tri)
{
    cout << tri.i << "  " << tri.j << "  " << tri.value;
    return cout;
}

/* 构建稀疏矩阵 */
void initSparseMatrix(int **matrix)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0) /* 找到非零元素 */
            {
                (spMatrix->arr)[spMatrix->num].i = i;
                (spMatrix->arr)[spMatrix->num].j = j;
                (spMatrix->arr)[spMatrix->num].value = matrix[i][j];
                (spMatrix->num)++;
            }
        }
    }
}

/* 遍历稀疏矩阵 */
void traverse(SparseMatrix *spMatrix)
{
    for (int i = 0; i < spMatrix->num; ++i)
    {
        cout << (spMatrix->arr)[i] << endl;
    }
}

/* 列序遍历转置 */
void columnTranspose(SparseMatrix *spMatrix, SparseMatrix *b)
{
    int &count = b->num;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < spMatrix->num; j++)
        {
            if (spMatrix->arr[j].j == i)
            {
                b->arr[count].i = spMatrix->arr[j].j;
                b->arr[count].j = spMatrix->arr[j].i;
                b->arr[count].value = spMatrix->arr[j].value;
                count++;
            }
        }
    }
}

/* 快速遍历转置 */
void fastTranspose(SparseMatrix *spMatrix, SparseMatrix *b)
{
    b->num = spMatrix->num;
    int *rowNum = new int[spMatrix->num]();
    int *rowStart = new int[spMatrix->num]();

    for (int i = 0; i < spMatrix->num; i++)
    {
        rowNum[spMatrix->arr[i].j]++;
    }
    for (int i = 1; i < spMatrix->num; i++)
    {
        rowStart[i] = rowNum[i - 1] + rowStart[i - 1];
    }
    for (int i = 0; i < spMatrix->num; i++)
    {
        int q = rowStart[spMatrix->arr[i].j];
        b->arr[q].i = spMatrix->arr[i].j;
        b->arr[q].j = spMatrix->arr[i].i;
        b->arr[q].value = spMatrix->arr[i].value;

        rowStart[spMatrix->arr[i].j]++;
    }
}

int main()
{
    cout << "请输入矩阵的行数和列数：  " << endl;
    cin >> rows >> cols;
    int **matrix = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        *(matrix + i) = new int[cols];
    }
    printf("请输入稀疏数组的数据：  \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> *(*(matrix + i) + j);
        }
    }
    printf("\n原三元组为：   :\n");
    initSparseMatrix(matrix);
    traverse(spMatrix);
    SparseMatrix *b = new SparseMatrix();
    printf("\n置换后的三元组为：   :\n");
    fastTranspose(spMatrix, b);
    traverse(b);

    return 0;
}