/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-14 21:46:25
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-16 15:05:50
 * @FilePath       : \Exercise4\2\findSaddlePoint.cpp
 */

#include <cstdio>
#include <cstdlib>
#include <utility>
using namespace std;

int rows = 0;
int cols = 0;
/*** 
 * @description: �жϵ�ǰ���Ƿ�Ϊ����
 */
bool complex(int **matrix, int i, int j)
{
    for (int k = 0; k < rows; k++)
    {
        if (matrix[i][k] < matrix[i][j])
        {
            return false;
        }
    }
    for (int k = 0; k < cols; k++)
    {
        if (matrix[k][j] > matrix[i][j])
        {
            return false;
        }
    }
    return true;
}

void findSaddlePoint(int **matrix)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (complex(matrix, i, j))
            {
                printf("�� %d ����������� �� %d �У�%d �У�ֵΪ��%d \n", ++count, i + 1, j + 1, matrix[i][j]);
            }
        }
    }
}

int main()
{
    printf("���������������������� \n");
    scanf("%d %d", &rows, &cols);
    int **matrix = new int *[rows];
    for (int i = 0; i < cols; i++)
    {
        *(matrix + i) = new int[cols];
    }
    printf("��������������ݣ�  \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", *(matrix + i) + j);
        }
    }

    findSaddlePoint(matrix);

    return 0;
}