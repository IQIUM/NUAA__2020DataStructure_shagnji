/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-23 09:36:39
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-12-05 10:56:26
 * @FilePath       : \Exercise6\1\graph.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
const int MAX = 100;

class Graph
{
public:
    int vertexNum; /* ͼ����ĸ��� */
    int edgeNum;   /* ͼ�ߵĸ��� */
    char *vertex;  /* ����Ĵ洢 */
    int **edges;   /* �ߵĴ洢 */
    Graph() : vertexNum(0), edgeNum(0), vertex(NULL), edges(NULL) {}
};

Graph *graph = new Graph();

void createGraph()
{
    cout << "�����붥�����ͱ�����  ";
    cin >> graph->vertexNum >> graph->edgeNum;
    graph->vertex = new char[MAX]();
    graph->edges = new int *[MAX];
    for (int i = 0; i < MAX; i++)
    {
        graph->edges[i] = new int[MAX];
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            graph->edges[i][j] = INT_MAX;
        }
    }
    cout << "����������������Ϣ��  ";
    for (int i = 0; i < graph->vertexNum; i++)
    {
        cin >> graph->vertex[i];
    }
    cout << "������ߣ�  \n";
    string edge;
    for (int i = 0; i < graph->edgeNum; i++)
    {
        cin >> edge;
        int x = edge[1] - '0';
        int y = edge[3] - '0';
        if (edge[4] == '>') /* ����ͼ */
        {
            graph->edges[x][y] = 1;
        }
        else if (edge[4] == ')') /* ����ͼ */
        {
            graph->edges[x][y] = 1, graph->edges[y][x] = 1;
        }
        else if (edge[6] == '>') /* ��Ȩ����ͼ */
        {
            graph->edges[x][y] = edge[5] - '0';
        }
        else if (edge[6] == ')') /* ��Ȩ����ͼ */
        {
            graph->edges[x][y] = graph->edges[y][x] = edge[5] - '0';
        }
    }
}

/* ��ȡͼ��ĳһ���ڵ� */
char getVertex(int index)
{
    return graph->vertex[index];
}

/* ���ض���v�ĵ�һ���ڽӵ� */
int firstAdjVex(int index)
{
    int aim = -1;
    for (int i = 0; i < graph->vertexNum; i++)
    {
        if (graph->edges[index][i] != INT_MAX)
        {
            aim = i;
            break;
        }
    }
    return aim;
}

int nextAdjVex(int u, int v)
{
    for (int i = v + 1; i < graph->vertexNum; i++)
    {
        if (graph->edges[u][i] != INT_MAX)
        {
            return i;
        }
    }
    return -1;
}

int getIndexByValue(char ch)
{
    for (int i = 0; i < graph->vertexNum; i++)
    {
        if (graph->vertex[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

/*** 
 * @description:  ������ȱ���
 */
void DFS(bool flags[], int index)
{
    printf("%c ", getVertex(index));
    flags[index] = true;
    int w = firstAdjVex(index);
    while (w != -1)
    {
        if (!flags[w])
        {
            DFS(flags, w);
        }
        w = nextAdjVex(index, w);
    }
}

void DFSTraverse()
{
    bool *flags = new bool[graph->vertexNum]();

    for (int i = 0; i < graph->vertexNum; i++)
    {
        if (!flags[i])
        {
            DFS(flags, i);
        }
    }

    delete[] flags;
}

/*** 
 * @description: ������ȱ���
 */
void BFS(bool flags[], int index)
{
    printf("%c ", getVertex(index));
    flags[index] = true;
    int u = 0, w = 0;

    queue<int> que;
    que.push(index);
    while (!que.empty())
    {
        u = que.front();
        que.pop();
        w = firstAdjVex(u);
        while (w != -1)
        {
            if (!flags[w])
            {
                printf("%c ", getVertex(w));
                flags[w] = true;
                que.push(w);
            }
            w = nextAdjVex(u, w);
        }
    }
}

void BFSTraverse()
{
    bool *flags = new bool[graph->vertexNum]();

    for (int i = 0; i < graph->vertexNum; i++)
    {
        if (!flags[i])
        {
            BFS(flags, i);
        }
    }

    delete[] flags;
}

/*** 
 * @description:  ��ͼ�в���һ���ڵ�
 */
void insertVex(char v)
{
    graph->vertex[graph->vertexNum] = v;
    graph->vertexNum++;
}

/*** 
 * @description: ��ͼ����±�
 */
void insertedge(char u, char w)
{
    int index_u = getIndexByValue(u);
    int index_w = getIndexByValue(w);
    if (index_u != -1 && index_w != -1)
    {
        graph->edges[index_u][index_w] = 1;
        graph->edges[index_w][index_u] = 1;
    }
}

/*** 
 * @description: ɾ���ڵ㼰���Ӧ��
 */
void deleteVex(char ch)
{
    int index = getIndexByValue(ch);
    if (index != -1)
    {
        for (int i = index + 1; i < graph->vertexNum; i++)
        {
            graph->vertex[i - 1] = graph->vertex[i];
        }
        for (int i = 0; i < graph->vertexNum; i++)
        {
            graph->edges[index][i] = 0;
        }
        for (int j = 0; j < graph->vertexNum; j++)
        {
            graph->edges[j][index] = 0;
        }

        graph->vertexNum--;
    }
}

/*** 
 * @description: ɾ����������֮��ı�
 */
void deleteedge(char u, char v)
{
    int index_u = getIndexByValue(u);
    int index_v = getIndexByValue(v);
    if (index_u != -1 && index_v != -1)
    {
        graph->edges[index_u][index_v] = INT_MAX;
        graph->edges[index_v][index_u] = INT_MAX;
    }
}

void deleteGraph()
{
    for (int i = 0; i < MAX; i++)
    {
        delete[] graph->edges[i];
    }
    delete[] graph->edges;
    delete graph;
}

int main()
{
    printf("����ͼ�ĸ��ַ�����\n");
    createGraph();
    printf("��ʼ��ͼ�����  \n");
    printf("\t��ȱ�����  ");
    DFSTraverse();
    printf("\n");
    printf("\t������ȱ�����   ");
    BFSTraverse();
    printf("\n");
    printf("����һ���ڵ� K����ʹ K �� D ��һ���ߣ���ȱ������Ϊ�� ");
    insertVex('K');
    insertedge('D', 'K');
    DFSTraverse();
    printf("\n");
    printf("Ȼ��ɾ��A��C�ıߣ���ȱ������Ϊ��  ");
    deleteedge('A', 'C');
    DFSTraverse();
    printf("\n");
    deleteGraph();
    system("pause");
    return 0;
}
