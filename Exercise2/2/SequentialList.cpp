#include <cstdio>
#include <cstdlib>
#include <time.h>
#define random(x) (rand() % x)
#define MAXSIZE 5

/* 使用顺序结构构建顺序表 */
/* 往顺序表中存入MAXSIE个随机值 */
void initSequential(int *&list)
{
    list = new int[MAXSIZE];
    /* 往顺序表中存储MAXSIZE个数 */
    for (int i = 0; i < MAXSIZE; ++i)
    {
        *(list + i) = random(100);
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

void traverseJoint(int *list)
{
    for (int i = 0; i < MAXSIZE * 2; ++i)
    {
        printf("%d\t", *(list + i));
    }
    printf("\n");
}

void joint(int *&list1, int *list2)
{
    int *tmp = new int[MAXSIZE];
    for (int i = 0; i < MAXSIZE; ++i)
    {
        *(tmp + i) = *(list1 + i);
    }
    delete[] list1;
    list1 = new int[MAXSIZE * 2];
    for (int i = 0; i < MAXSIZE; ++i)
    {
        *(list1 + i) = *(tmp + i);
    }
    delete[] tmp;
    tmp = NULL;
    for (int i = MAXSIZE; i < MAXSIZE * 2; ++i)
    {
        *(list1 + i) = *(list2 + i - MAXSIZE);
    }
}

int main()
{
    srand((int)time(0));
    int *list1 = NULL;
    int *list2 = NULL;
    initSequential(list1);
    initSequential(list2);
    printf("list1和list2拼接之前的数据：  \n");
    traverse(list1);
    traverse(list2);
    printf("===========================================\n");
    printf("拼接之后的数据：   \n");
    joint(list1, list2);
    traverseJoint(list1);
    return 0;
}
