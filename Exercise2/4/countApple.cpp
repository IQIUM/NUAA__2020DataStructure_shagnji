#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Tree
{
public:
    Tree(int no = 0, int count = 0, Tree *next = NULL) : no(no), count(count), next(next), isFalled(false) {}
    int no;
    int count;
    bool isFalled; /* 用于判断苹果树是否有掉苹果的情况 */
    Tree *next;
};

class List
{
public:
    List(int num) : num(num)
    {
        head = new Tree();
        Tree *p = head;
        int i = 0;
        do
        {
            ++i;
            Tree *tmp = new Tree(i, 0);
            p->next = tmp;
            p = tmp;
        } while (i < num);
        p->next = head->next;
    }

    /* 统计所有树上苹果的数量 */
    void countApple(vector<int> &count)
    {
        Tree *p = head->next;

        int countApple = 0;
        int countFalled = 0;
        int index = 1;
        while (index <= num)
        {
            countApple += p->count;
            if (p->isFalled)
            {
                countFalled++;
            }
            p = p->next;
            ++index;
        }
        count.push_back(countApple);
        count.push_back(countFalled);

        int countSeq = 0;
        Tree *pBefore = NULL;
        int i = 1;
        while (i < num)
        {
            p = p->next;
            ++i;
        }
        pBefore = p;
        p = head->next;
        Tree *pAfter = p->next;
        i = 1;
        while (i <= num)
        {
            if (pBefore->isFalled && p->isFalled && pAfter->isFalled)
            {
                countSeq++;
            }
            pBefore = p;
            p = pAfter;
            pAfter = pAfter->next;
            ++i;
        }
        count.push_back(countSeq);
    }

    int num;
    Tree *head;
};

Tree *getLoaction(List *list, int index) /*根据当前的序号获取第index棵树 */
{
    Tree *p = list->head;
    int i = 0;
    do
    {
        p = p->next;
        ++i;
    } while (i < index);
    return p;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    List *list = new List(n);
    for (int i = 1; i <= n; ++i)
    {
        int m = 0;
        scanf("%d", &m);
        Tree *p = getLoaction(list, i);

        for (int j = 1; j <= m; ++j) /* j 表示操作的第几棵树 */
        {
            int oper = -1;
            scanf("%d", &oper);
            /* 对操作正负进行判断 */
            if (j == 1 && oper > 0) /*初始化树上原来的苹果个数 */
            {
                p->count = oper;
            }
            else if (oper < 0) /* 疏果操作 */
            {
                p->count += oper;
            }
            else if (oper > 0 && j != 1) /* 当前小明第2次重新统计苹果的数量 */
            {
                if (p->count > oper)
                {
                    p->isFalled = true;
                }
                p->count = oper;
            }
        }
    }
    vector<int> count;
    list->countApple(count);
    printf("%d %d %d", count[0], count[1], count[2]);
    return 0;
}