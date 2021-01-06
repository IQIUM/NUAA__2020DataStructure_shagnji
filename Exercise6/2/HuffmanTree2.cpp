/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-30 09:02:45
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-12-07 08:04:16
 * @FilePath       : \Exercise6\2\HuffmanTree2.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
    unsigned int weight;
    unsigned int parent;
    unsigned int left;
    unsigned int right;
};

/* 
 * @Description: 在现有节点中选择两个没有父节点，且权值最小的两个节点s1,s2
 * @param: hufTree:存放节点
 * @param: n:节点个数
 * @param: s1：权值最小值所在 索引
 * @param: s2:权值次小值所在 索引
 * @return: void
*/
void select_two_small(Node *hufTree, int n, int &s1, int &s2)
{
    int *a = new int[n + 1];
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        if (hufTree[i].parent == 0)
        {
            a[j++] = hufTree[i].weight;
        }
    }
    /* sort */
    for (int i = 1; i < j - 1; ++i)
    {
        for (int k = i + 1; k < j; ++k)
        {
            if (a[i] > a[k])
            {
                int tmp = a[i];
                a[i] = a[k];
                a[k] = tmp;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[1] == hufTree[i].weight && hufTree[i].parent == 0)
        {
            s1 = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[2] == hufTree[i].weight && hufTree[i].parent == 0 && i != s1)
        {
            s2 = i;
            break;
        }
    }
    delete[] a;
}

void reverse(string &str)
{
    string tmp = "";
    for (int i = str.size() - 1; i >= 0; i--)
    {
        tmp += str[i];
    }
    str = tmp;
}

void Hufcode(int n, int *w, Node *&hufTree, string *&code)
{
    if (n <= 1)
    {
        return;
    }
    hufTree = new Node[2 * n];
    if (hufTree == NULL)
    {
        exit;
    }

    /* 1. 初始化 */
    for (int i = 1; i <= n; i++)
    {
        hufTree[i].weight = w[i];
        hufTree[i].parent = 0;
        hufTree[i].left = 0;
        hufTree[i].right = 0;
    }

    /* 2. 构建哈夫曼树 */
    for (int i = n + 1; i < 2 * n; i++)
    {
        int s1 = 0;
        int s2 = 0;
        select_two_small(hufTree, i - 1, s1, s2);
        hufTree[i].weight = hufTree[s1].weight + hufTree[s2].weight;
        hufTree[i].left = s1;
        hufTree[i].right = s2;
        hufTree[s1].parent = i;
        hufTree[s2].parent = i;
        hufTree[i].parent = 0;
    }

    /* for (int i = 1; i < 2 * n; i++)
    {
        printf("%d %d %d %d\n", hufTree[i].weight, hufTree[i].parent, hufTree[i].left, hufTree[i].right);
    } */
    /* 获取哈夫曼编码(逆向获取) */
    code = new string[n + 1];
    for (int i = 1; i <= n; i++)
    {
        string tmp = "";
        int t = i;
        while (hufTree[t].parent != 0)
        {
            if (t == hufTree[hufTree[t].parent].left)
            {
                tmp += "0";
            }
            else
            {
                tmp += "1";
            }
            t = hufTree[t].parent;
        }
        reverse(tmp);
        *(code + i) = tmp;
    }
}

int main()
{
    int n = 0;
    printf("请输入权值个数：  ");
    scanf("%d", &n);
    int *weight = new int[n + 1];
    printf("请依次输入权值：  ");
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", weight + i);
    }
    Node *hufTree = NULL;
    string *code;
    Hufcode(n, weight, hufTree, code);

    for (int i = 1; i <= n; i++)
    {
        cout << "权值为：  " << weight[i] << "  的哈夫曼编码： " << code[i] << endl;
    }

    delete[] hufTree;
    delete[] code;
    return 0;
}