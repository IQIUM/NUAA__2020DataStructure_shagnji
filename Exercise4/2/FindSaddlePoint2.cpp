/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-14 22:11:33
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-16 14:57:48
 * @FilePath       : \Exercise4\2\FindSaddlePoint2.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

int rows = 0;
int cols = 0;

void findSaddlePoint(int **matrix)
{
    int *rowMin = new int[rows]();
    int *colMax = new int[cols]();
    for (int i = 0; i < rows; i++)
    {
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                minIndex = j;
            }
        }
        rowMin[i] = minIndex;
    }
    for (int i = 0; i < cols; i++)
    {
        int max = INT_MIN;
        int maxIndex = -1;
        for (int j = 0; j < rows; j++)
        {
            if (matrix[j][i] > max)
            {
                max = matrix[j][i];
                maxIndex = j;
            }
        }
        colMax[i] = maxIndex;
    }
    /* 找两个数组的相同数 */ 
    
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            
            if (i == colMax[j] && rowMin[i] == j)
            {
                printf("第 %d 个马鞍点出现在 第 %d 行，%d 列 \n", ++count, i + 1, j + 1);
            }
        }
    }

}

int main()
{
    printf("请输入矩阵的行数和列数： \n");
    scanf("%d %d", &rows, &cols);
    int **matrix = new int *[rows];
    for (int i = 0; i < cols; i++)
    {
        *(matrix + i) = new int[cols];
    }
    printf("请输入数组的数据：  \n");
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