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
    for (int i = 0; i < 5; ++i)
    {
        *(list.pdata + i) = i + 6;
        list.length++;
    }
}

/* ˳�������� */
bool destroy(SeqFixedList &list)
{
    if (list.pdata != NULL)
    {
        delete list.pdata;
        list.pdata = NULL;
    }
    list.length = 0;
    list.size = 0;
    return true;
}

/* ˳������� */
bool clearList(SeqFixedList &list)
{
    list.length = 0;
    return true;
}

/* ˳���Ԫ�صĻ�ȡ */
bool getElement(SeqFixedList &list, int index, int &ele)
{
    if (index < 1 || index > list.length) /* ����Խ���ж� */
    {
        return false;
    }
    ele = *(list.pdata + index - 1);
    return true;
}

/* ˳���Ԫ�ز��� */
int loacteElement(SeqFixedList &list, int ele)
{
    for (int i = 0; i < list.length; ++i)
    {
        if (*(list.pdata + i) == ele)
        {
            return (i + 1);
        }
    }
    return -1;
}

/* ˳���Ԫ�ز��� */
bool insertElement(SeqFixedList &list, int index, int ele)
{
    if (index < 1 || index > list.length)
    {
        return false;
    }
    if (list.size <= list.length) /* ����ڴ����������¿��ٿռ� */
    {
        int *tmp = NULL;
        tmp = new int[LISTINTSIZE + LISTINCREMENT];
        for (int i = 0; i < list.length; ++i)
        {
            *(tmp + i) = *(list.pdata + i);
        }
        delete[] list.pdata;
        list.pdata = tmp;
        list.size += LISTINCREMENT;
        tmp = NULL;
    }
    for (int i = list.length - 1; i >= index - 1; --i)
    {
        *(list.pdata + i + 1) = *(list.pdata + i);
    }
    *(list.pdata + index - 1) = ele;
    list.length++;
    return true;
}

/* ˳���ɾ���ڵ� */
bool deleteElement(SeqFixedList &list, int index, int &ele)
{
    if (index < 1 || index > list.length) /* ����Խ���ж� */
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

bool isEmpty(SeqFixedList &list)
{
    return list.length == 0;
}

int getLength(SeqFixedList &list)
{
    return list.length;
}

bool priorElement(SeqFixedList &list, int curElement, int &preElement)
{
    if (*(list.pdata) == curElement)
    {
        return false;
    }
    for (int i = 1; i < list.length; ++i)
    {
        if (*(list.pdata + i) == curElement)
        {
            preElement = *(list.pdata + i - 1);
            return true;
        }
    }
    return false;
}

bool nextElement(SeqFixedList &list, int curElement, int &nextElement)
{
    if (*(list.pdata + list.length - 1) == curElement)
    {
        return false;
    }
    for (int i = 0; i < list.length - 1; ++i)
    {
        if (*(list.pdata + i) == curElement)
        {
            nextElement = *(list.pdata + i + 1);
            return true;
        }
    }
    return false;
}

void listTraverse(SeqFixedList &list)
{
    for (int i = 0; i < list.length; ++i)
    {
        printf("%d  ", *(list.pdata + i));
    }
    printf("\n");
}

bool setElement(SeqFixedList &list, int index, int &ele)
{
    if (index < 1 || index > list.length)
    {
        return false;
    }
    int tmp = *(list.pdata + index - 1);
    *(list.pdata + index - 1) = ele;
    ele = tmp;
    return true;
}

int main()
{
    SeqFixedList list;
    InitList(list);
    createList(list);
    printf("�����ԭʼ����Ϊ�� ");
    listTraverse(list);
    printf("�滻��2������Ϊ100�� ");
    int replace = 100;
    setElement(list, 2, replace);
    listTraverse(list);
    printf("��ȡ�����3��λ�õ����ݣ� ");
    int ele = 0;
    getElement(list, 3, ele);
    printf(" %d\n", ele);
    printf("�ҵ�Ԫ��10���ڵ�λ�ã� ");
    int location = -1;
    location = loacteElement(list, 10);
    printf(" %d\n", location);
    printf("100֮ǰ��Ԫ��Ϊ�� ");
    int prior = -1;
    priorElement(list, 100, prior);
    printf("%d\n", prior);
    printf("100֮���Ԫ��Ϊ��  ");
    int next = -1;
    nextElement(list, 100, next);
    printf("%d\n", next);
    printf("�ڵ�2����ǰ����� 9999 ���˳���Ϊ ��");
    insertElement(list, 2, 9999);
    listTraverse(list);
    printf("ɾ��˳����5λ����9�� ");
    int delEle = -1;
    deleteElement(list, 5, delEle);
    listTraverse(list);
    printf("���˳���\n");
    clearList(list);
    printf("��ʱ˳���ĳ���Ϊ��%d ", getLength(list));
    if (isEmpty(list))
    {
        printf("˳���Ϊ��\n");
    }
    else
    {
        printf("˳���Ϊ��\n");
    }
    printf("����˳���");
    destroy(list);

    return 0;
}