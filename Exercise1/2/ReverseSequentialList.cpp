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
}

void listTraverse(SeqFixedList &list)
{
    for (int i = 0; i < list.length; ++i)
    {
        printf("%d  ", *(list.pdata + i));
    }
    printf("\n");
}

/* 顺序表的倒置 */
void reverse(SeqFixedList &list)
{
    for (int i = 0; i < list.length / 2; ++i)
    {
        int &a = *(list.pdata + i);
        int &b = *(list.pdata + list.length - i - 1);
        a = a ^ b;
        b = b ^ a;
        a = a ^ b;
    }
}

int main()
{
    SeqFixedList list;
    InitList(list);
    createList(list);
    printf("原来的顺序表为： ");
    listTraverse(list);
    reverse(list);
    printf("倒置后的顺序表为：  ");
    listTraverse(list);
}
