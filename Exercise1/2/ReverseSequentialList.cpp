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

/* ˳���ĳ�ʼ�� */
bool InitList(SeqFixedList &list)
{
    list.pdata = new int[LISTINTSIZE];
    list.length = 0;
    list.size = LISTINTSIZE;
    return true;
}

/* ˳���Ĵ��� */
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

/* ˳���ĵ��� */
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
    printf("ԭ����˳���Ϊ�� ");
    listTraverse(list);
    reverse(list);
    printf("���ú��˳���Ϊ��  ");
    listTraverse(list);
}
