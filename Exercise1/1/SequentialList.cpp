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
    for (int i = 0; i < 5; ++i)
    {
        *(list.pdata + i) = i + 6;
        list.length++;
    }
}

/* 顺序表的销毁 */
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

/* 顺序表的清空 */
bool clearList(SeqFixedList &list)
{
    list.length = 0;
    return true;
}

/* 顺序表元素的获取 */
bool getElement(SeqFixedList &list, int index, int &ele)
{
    if (index < 1 || index > list.length) /* 索引越界判断 */
    {
        return false;
    }
    ele = *(list.pdata + index - 1);
    return true;
}

/* 顺序表元素查找 */
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

/* 顺序表元素插入 */
bool insertElement(SeqFixedList &list, int index, int ele)
{
    if (index < 1 || index > list.length)
    {
        return false;
    }
    if (list.size <= list.length) /* 如果内存已满，重新开辟空间 */
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
    printf("输入的原始数据为： ");
    listTraverse(list);
    printf("替换第2个数据为100： ");
    int replace = 100;
    setElement(list, 2, replace);
    listTraverse(list);
    printf("获取链表第3个位置的数据： ");
    int ele = 0;
    getElement(list, 3, ele);
    printf(" %d\n", ele);
    printf("找到元素10所在的位置： ");
    int location = -1;
    location = loacteElement(list, 10);
    printf(" %d\n", location);
    printf("100之前的元素为： ");
    int prior = -1;
    priorElement(list, 100, prior);
    printf("%d\n", prior);
    printf("100之后的元素为：  ");
    int next = -1;
    nextElement(list, 100, next);
    printf("%d\n", next);
    printf("在第2个数前面插入 9999 后的顺序表为 ：");
    insertElement(list, 2, 9999);
    listTraverse(list);
    printf("删除顺序表第5位数字9后： ");
    int delEle = -1;
    deleteElement(list, 5, delEle);
    listTraverse(list);
    printf("清空顺序表\n");
    clearList(list);
    printf("此时顺序表的长度为：%d ", getLength(list));
    if (isEmpty(list))
    {
        printf("顺序表为空\n");
    }
    else
    {
        printf("顺序表不为空\n");
    }
    printf("销毁顺序表！");
    destroy(list);

    return 0;
}