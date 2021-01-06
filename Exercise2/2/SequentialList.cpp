#include <cstdio>
#include <cstdlib>
#include <time.h>
#define random(x) (rand() % x)
#define MAXSIZE 5

/* ʹ��˳��ṹ����˳��� */
/* ��˳����д���MAXSIE�����ֵ */
void initSequential(int *&list)
{
    list = new int[MAXSIZE];
    /* ��˳����д洢MAXSIZE���� */
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
    printf("list1��list2ƴ��֮ǰ�����ݣ�  \n");
    traverse(list1);
    traverse(list2);
    printf("===========================================\n");
    printf("ƴ��֮������ݣ�   \n");
    joint(list1, list2);
    traverseJoint(list1);
    return 0;
}
