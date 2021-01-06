#include <cstdio>
#include <cstdlib>
#include <conio.h>
#define LISTINTSIZE 256
#define LISTINCREMENT 128

typedef struct SeqFixedList
{
    int *pdata;
    int size;
    int length;
} SeqFixedList;

/* 顺序表的初始化 */
bool InitList(SeqFixedList &list)
{
    list.pdata = new int[LISTINTSIZE];
    list.length = 0;
    list.size = LISTINTSIZE;
    return true;
}

/* 顺序表的创建 */
void createList(SeqFixedList &list)
{
    for (int i = 0; i < 6; ++i)
    {
        *(list.pdata + i) = i + 6;
        list.length++;
    }
    *(list.pdata + 6) = 6;
    *(list.pdata + 7) = 9;
    *(list.pdata + 8) = 10;
    list.length += 3;
}

void listTraverse(SeqFixedList &list)
{
    for (int i = 0; i < list.length; ++i)
    {
        printf("%d  ", *(list.pdata + i));
    }
    printf("\n");
}

/* 顺序表删除节点 */
bool deleteElement(SeqFixedList &list, int index, int &ele)
{
    if (index < 1 || index > list.length) /* 索引越界判断 */
    {
        return false;
    }
    ele = *(list.pdata + index - 1);
    for (int i = index - 1; i < list.length; ++i)
    {
        *(list.pdata + i) = *(list.pdata + i + 1);
    }
    list.length--;
    return true;
}

void deleteRepetition(SeqFixedList &list)
{
    int *tmp = new int[list.length];
    int count = 0;
    for (int i = 0; i < list.length; ++i)
    {
        int j = 0;
        for (j = 0; j < count; ++j)
        {
            if (*(list.pdata + i) == *(tmp + j))
            {
                break;
            }
        }
        if (j == count)
        {
            tmp[count++] = *(list.pdata + i);
        }
    }
    int *t = new int[count];
    for (int i = 0; i < count; ++i)
    {
        *(t + i) = *(tmp + i);
    }
    delete[] tmp;
    delete[] list.pdata;
    list.pdata = t;
    list.length = count;
    t = NULL;
    tmp = NULL;
}

int main()
{
    SeqFixedList list;
    InitList(list);
    createList(list);
    printf("原来的顺序表为： ");
    listTraverse(list);
    printf("删除重复数后的顺序表为： ");
    deleteRepetition(list);
    listTraverse(list);
}
