/*** 
 * @Author         : IQIUM
 * @Date           : 2020-10-26 08:12:23
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-12 08:27:33
 * @FilePath       : \Exercise4\1\sparseMatrix.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define NUM 6
#define MAXSIZE 256
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

ostream &operator<<(ostream &cout, Triple &tri)
{
    cout << tri.i << "  " << tri.j << "  " << tri.value;
    return cout;
}

/* 构建稀疏矩阵 */
void initSparseMatrix(int matrix[][NUM], SparseMatrix *spMatrix)
{
    for (int i = 0; i < NUM; ++i)
    {
        for (int j = 0; j < NUM; j++)
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
void columnTranspose(SparseMatrix *spMatrix)
{
    for (int i = 0; i < NUM; ++i)
    {
    }
}

int main()
{
    cout << "请输入矩阵的行数和列数：  " << endl;
    int cols = 0,rows = 0;
    
    int matrix[NUM][NUM];

    SparseMatrix *spMatrix = new SparseMatrix();
    for (int i = 0; i < NUM; ++i)
    {
        for (int j = 0; j < NUM; j++)
        {
            cin >> matrix[i][j];
        }
    }

    initSparseMatrix(matrix, spMatrix);
    traverse(spMatrix);
    cout << spMatrix->num << endl;
    return 0;
} 