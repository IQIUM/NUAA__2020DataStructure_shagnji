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
 * @Description: �����нڵ���ѡ������û�и��ڵ㣬��Ȩֵ��С�������ڵ�s1,s2
 * @param: hufTree:��Žڵ�
 * @param: n:�ڵ����
 * @param: s1��Ȩֵ��Сֵ���� ����
 * @param: s2:Ȩֵ��Сֵ���� ����
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

    /* 1. ��ʼ�� */
    for (int i = 1; i <= n; i++)
    {
        hufTree[i].weight = w[i];
        hufTree[i].parent = 0;
        hufTree[i].left = 0;
        hufTree[i].right = 0;
    }

    /* 2. ������������ */
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
    /* ��ȡ����������(�����ȡ) */
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
    printf("������Ȩֵ������  ");
    scanf("%d", &n);
    int *weight = new int[n + 1];
    printf("����������Ȩֵ��  ");
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", weight + i);
    }
    Node *hufTree = NULL;
    string *code;
    Hufcode(n, weight, hufTree, code);

    for (int i = 1; i <= n; i++)
    {
        cout << "ȨֵΪ��  " << weight[i] << "  �Ĺ��������룺 " << code[i] << endl;
    }

    delete[] hufTree;
    delete[] code;
    return 0;
}