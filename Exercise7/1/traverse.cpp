/***
 * @Author         : IQIUM
 * @Date           : 2020-12-05 10:56:53
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-12-07 08:55:35
 * @FilePath       : \Exercise7\1\traverse.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10000;

class ArcNode {
  public:
    int no;
    int weight;
    ArcNode *next;
    ArcNode() : next(NULL) {}
};

class VexNode /* 表头节点 */
{
  public:
    char data;
    ArcNode *next;
};

class Graph {
  public:
    VexNode vexs[MAX];
    int vertexNum;
    int edgeNum;
};

Graph *graph = new Graph();

void createGraph() {
    cout << "\n请输入顶点数和边数：";
    cin >> graph->vertexNum >> graph->edgeNum;
    cout << "\n请输入顶点信息：";
    for (int i = 0; i < graph->vertexNum; i++) {
        cin >> graph->vexs[i].data;
        graph->vexs[i].next = NULL;
    }
    cout << "\n请输入边：\n";
    ArcNode *p;
    string edge;

    for (int i = 0; i < graph->edgeNum; i++) {
        cin >> edge;
        p = new ArcNode();
        int x = edge[1] - '0';
        int y = edge[3] - '0';

        if (edge[4] == '>') /* 有向无权图 */
        {
            p->no = y;
            p->weight = 1;
            p->next = graph->vexs[x].next;
            graph->vexs[x].next = p;
        } else if (edge[4] == ')') /* 无向无权图 */
        {
            p->no = y;
            p->weight = 1;
            p->next = graph->vexs[x].next;
            graph->vexs[x].next = p;
            p = new ArcNode;
            p->no = x;
            p->weight = 1;
            p->next = graph->vexs[y].next;
            graph->vexs[y].next = p;
        } else if (edge[6] == '>') /* 有向带权有向图 */
        {
            p->no = y;
            p->weight = edge[5] - '0';
            p->next = graph->vexs[x].next;
            graph->vexs[x].next = p;
        } else if (edge[6] == ')') {
            p->no = y;
            p->weight = edge[5] - '0';
            p->next = graph->vexs[x].next;
            graph->vexs[x].next = p;
            p = new ArcNode;
            p->no = x;
            p->weight = 1;
            p->next = graph->vexs[y].next;
            graph->vexs[y].next = p;
        }
    }
}

char getVex(int index) { return graph->vexs[index].data; }

int getIndex(char ch) {
    for (int i = 0; i < graph->vertexNum; i++) {
        if (graph->vexs[i].data == ch) {
            return i;
        }
    }
    return -1;
}

/*
 * @Description: 获取index 的第一个相邻节点
 * @param:
 * @return:
 */
int getFristNeightbor(int index) {
    ArcNode *p = graph->vexs[index].next;
    if (p != NULL) {
        return p->no;
    }
    return -1;
}

int getNextNeightbor(int w, int i) {
    ArcNode *p = graph->vexs[w].next;
    while (p != NULL) {
        if (p->no != w && p->no != i) {
            return p->no;
        }
        p = p->next;
    }
    return -1;
}

void DFS(int index, bool isVisited[]) {
    isVisited[index] = true;
    cout << getVex(index) << "  ";
    ArcNode *p = graph->vexs[index].next;
    while (p != NULL) {
        if (!isVisited[p->no] && graph->vexs[p->no].data != '\0') {
            DFS(p->no, isVisited);
        }
        p = p->next;
    }
}

void DFS() {
    bool *isVisited = new bool[graph->vertexNum]();
    for (int i = 0; i < graph->vertexNum; i++) {
        if (!isVisited[i] && graph->vexs[i].data != '\0') {
            DFS(i, isVisited);
        }
    }
    delete[] isVisited;
}

void BFS() {
    int queue[MAX];
    int front = 0;
    int rear = 0;
    bool *isVisited = new bool[graph->vertexNum]();

    queue[rear++] = 0;
    while (front != rear) {
        int x = queue[front++];
        isVisited[x] = true;
        cout << getVex(x) << "  ";
        ArcNode *p = graph->vexs[x].next;
        while (p != NULL) {
            if (!isVisited[p->no] && graph->vexs[p->no].data != '\0') {
                queue[rear++] = p->no;
            }
            p = p->next;
        }
    }

    delete[] isVisited;
}

void deleteVertex(char ch) {
    int no = getIndex(ch);
    graph->vexs[no].data = '\0';
    ArcNode *p = NULL;
    while (graph->vexs[no].next != NULL) {
        p = graph->vexs[no].next->next;
        delete graph->vexs[no].next;
        graph->vexs[no].next = p;
    }
    // graph->vertexNum--;
    cout << "\n顶点删除成功！！" << endl;
}

int main() {
    cout << "下面测试图的方法： \n";
    vector<vector<int> > v;
    createGraph();
    cout << "深度遍历： ";
    DFS();
    cout << "\n广度遍历：  ";
    BFS();
    return 0;
}